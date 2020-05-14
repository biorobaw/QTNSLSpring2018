/* SCCS  @(#)nsl_system.C	1.1---95/10/13--16:37:16 */
//
//	nsl_system.C
//
#include "nsl_kernel.h"
#include "nsl_system.h"
#include "nsl_file.h"
#include "nsl_file_manager.h"
#include "nsl_base_list.h"
#include "nsl_diff_manager.h"
#include "nsl_interpreter.h"
#include "nsl_model.h"
#include "nsl_thresh_library.h"
#include "nsl_diff_method.h"
#include "nsl_diff.h"
#include "nsl_base.h"
#include "nsl_num_library.h"
#include <stdio.h>
#include <string.h>

typedef nsl_base_list nsl_list;

extern nsl_model* NSL_MAIN_MODEL;
extern nsl_model* NSL_APPLICATION_MODEL;

extern int NSLoutput(const char*, int);
extern int NSLoutput(const char*);
extern int NSLoutput(const char *, const char *);

int TRAIN_FG = 0;

extern int nsl_rint(num_type s);

nsl_system::nsl_system() : nsl_public("system"), model("model",this,1),
	simDelta("simDelta",this,1), simEndTime("simEndTime",this,1),
	trainDelta("trainDelta",this,1), trainEndTime("trainEndTime",this,1),
	simSysTime("simSysTime",this,1), trainSysTime("trainSysTime",this,1),
	simCurrentTime("simCurrentTime",this,1),
	trainCurrentTime("trainCurrentTime",this,1),
	simAccumCurrentTime("simAccumCurrentTime",this,1),
	trainAccumCurrentTime("trainAccumCurrentTime",this,1),
	simEpochStep("simEpochStep",this,1), simEpochSteps("simEpochSteps",this,1),
	trainEpochStep("trainEpochStep",this,1), trainEpochSteps("trainEpochSteps",this,1)
{
	init_system();
}
nsl_system::~nsl_system()
{
	delete model_list;
	delete proc_list;
	delete file_type_list;
	delete diff_method_list;
	delete diff_model_list;
	delete thresh_lib_list;
	delete fm;
}

extern void NSLinit(int,char**);
extern void NSLmain(int,char**);

int nsl_system::init_system()
{
	if (SYSTEM == NULL)
	{
		SYSTEM = this; // from nsl_root
		NSL_SYSTEM = this;
	}

	set_base_type("system");
	set_name("system");
	m_parent = this;

#ifndef _NSL_PROMPTS
	setSimEndTime(10.f);
#endif

  	simSysTime = 0.0;
 	trainSysTime = 0.0;
 	resetSimTime();
 	resetTrainTime();
	simDelta = 0.1;
	trainDelta = 0.1;
	simEpochStep = 0;
	simEpochSteps = 1;
	trainEpochStep = 0;
	trainEpochSteps = 1;
	setSimEndTime((float)20.0); //HARDCODED SET THE SIM END TIME, REMOVE THIS FOR NON-BETA TEST VERSIONS -bn7
	setTrainEndTime((float)20.0);

	xsystem_fg = NSL_OFF;

	model_application_total = 0;
	model_application_list = new nsl_list("model_application_list");

	model_total = 0;
	model_list = new nsl_list("model_list");

	proc_total = 0;
	proc_list = new nsl_list("proc");

	file_type_total = 0;
	file_type_list = new nsl_list("file_type");

	diff_method_total = 0;
	diff_method_list = new nsl_list("diff_method");

	diff_model_total = 0;
	diff_model_list = new nsl_list("diff_model");

	thresh_lib_total = 0;
	thresh_lib_list = new nsl_list("thresh_lib");

	fm = new nsl_file_manager;

	DIFFM = new nsl_diff_manager("diff_manager",this); // initialize global diff manager

	m_children_list->append(data_list);
	m_children_list->append(model_list);
	m_children_list->append(model_application_list);
	m_children_list->append(proc_list);
	m_children_list->append(file_type_list);
 	m_children_list->append(diff_method_list);
 	m_children_list->append(thresh_lib_list);
 	m_children_list->append(fm);
   	m_children_list->append(DIFFM);

//#ifndef __GNUG__
//	log.attach(1); // set log to standard output
//#endif

	if (NSL_DIFF == NULL)
	{
		NSL_DIFF = new nsl_diff("diff",DIFFM,0);
		add_data(NSL_DIFF);
//		cmd_out("nsl_system:Initializing NSL_DIFF...");
 	}

	if (INTERPRETER == NULL)
	{
		INTERPRETER = new nsl_interpreter;
		NSL_INTERPRETER = INTERPRETER;
//		cmd_out("nsl_system:Initializing NSL_INTERPRETER...");
	}

	char* env = getenv("NSL_DIR");
	if (env != NULL)
		strcpy(nsl_dir,env);
	else
	{
//		cmd_error("NSL_DIR not set\nUse `setenv NSL_DIR *dir*'");
		strcpy(nsl_dir,".");
	}

	return 1;
}

// simulation

void nsl_system::setSimTimeStep(int i)
{
	simCurrentTimeStep = i;
	simCurrentTime = simCurrentTimeStep*simDelta;
}
void nsl_system::setSimTime(int i) // called from 'run'
{
	simCurrentTimeStep = i;
	simCurrentTime = simCurrentTimeStep*simDelta;
}
void nsl_system::setSimTime(float i)
{
	simCurrentTime = i;
	simCurrentTimeStep = (int) nsl_rint(simCurrentTime.get_value()/simDelta.get_value());
}
void nsl_system::setSimEndTimeStep(int i)
{
	simEndTimeStep = i;
	simEndTime = simEndTimeStep*simDelta;
}
void nsl_system::setSimEndTime(float i)
{
	simEndTime = i;
	simEndTimeStep = (int) nsl_rint(simEndTime.get_value()/simDelta.get_value());
}
void nsl_system::setSimAccumTime(float f) // called from 'run'
{
	simAccumCurrentTime = f;
	simAccumCurrentTimeStep = (int) nsl_rint(simAccumCurrentTime.get_value()/simDelta.get_value());
}
void nsl_system::resetSimTime()
{
	simCurrentTimeStep = 0;
	simCurrentTime = 0.0;
}

void nsl_system::incrSimTime()
{
	++simCurrentTimeStep;
	simCurrentTime = simCurrentTimeStep*simDelta;
}

// train

void nsl_system::setTrainTimeStep(int i)
{
	trainCurrentTimeStep = i;
	trainCurrentTime = trainCurrentTimeStep*trainDelta;
}
void nsl_system::setTrainTime(int i) // called from 'run'
{
	trainCurrentTimeStep = i;
	trainCurrentTime = trainCurrentTimeStep*trainDelta;
}
void nsl_system::setTrainTime(float i)
{
	trainCurrentTime = i;
	trainCurrentTimeStep = (int) nsl_rint(trainCurrentTime.get_value()/trainDelta.get_value());
}
void nsl_system::setTrainEndTimeStep(int i)
{
	trainEndTimeStep = i;
	trainEndTime = trainEndTimeStep*trainDelta;
}
void nsl_system::setTrainEndTime(float i)
{
	trainEndTime = i;
	trainEndTimeStep = (int) nsl_rint(trainEndTime.get_value()/trainDelta.get_value());
}
void nsl_system::setTrainAccumTime(float f) // called from 'run'
{
	trainAccumCurrentTime = f;
	trainAccumCurrentTimeStep = (int) nsl_rint(trainAccumCurrentTime.get_value()/trainDelta.get_value());
}

void nsl_system::resetTrainTime()
{
	trainCurrentTimeStep = 0;
	trainCurrentTime = 0.0;

	trainAccumCurrentTimeStep = 0;
	trainAccumCurrentTime = 0.0;
}

void nsl_system::incrTrainTime()
{
	++trainCurrentTimeStep;
	trainCurrentTime = trainCurrentTimeStep*trainDelta;
	if (trainCurrentTime.get_value() >= trainEndTime.get_value()) {
		trainCurrentTimeStep = 0;
		trainCurrentTime = 0.0;
	}

	++trainAccumCurrentTimeStep;
	trainAccumCurrentTime = trainAccumCurrentTimeStep*trainDelta;
}

// add model
int nsl_system::add_model(nsl_model* model)
{
	model->set_index(++model_total);
	model_list->append(model);
	model->set_m_parent(this);

	set_ptr(model); // OBJ = modelprint

	return model_total;
}
nsl_model* nsl_system::get_model(const int mindex)
{
	return (nsl_model*) model_list->get_by_index(mindex);
}

/* AW99

nsl_model* nsl_system::get_model(const char* fullstr)
{
	nsl_string mname;
	const char *str,*pname;

 	int mlen = strlen(fullstr); // full length

      	if ((str = (char *) strchr(fullstr,'.')) != NULL)
	{
		pname = str + 1; 	// path after first model name
		int plen = strlen(str); // extra path length
		strncpy(mname,fullstr,mlen-plen); // model name
		mname[mlen-plen]='\0';
	}
	else
	{
		strcpy(mname,fullstr);
		pname = 0;
	}

	nsl_model* model = (nsl_model*) model_list->get_by_name(mname);

	if (pname != NULL && model != NULL)
		model = model->get_model(pname); // modify to always do it from system

	return model;
}
*/
int nsl_system::addApplicationModel(nsl_model* model)
{
	model->set_index(++model_application_total);
	model_application_list->append(model);
	model->set_m_parent(this);

//	set_ptr(model); // OBJ = modelprint

	return model_application_total;
}

nsl_model* nsl_system::getApplicationModel(const char* str)
{
	nsl_model* mod;

	if (str != NULL)
		mod = (nsl_model*) model_application_list->get_by_name(str);
	else
		mod = (nsl_model*) model_application_list->get_by_index(1);

	return mod;
}
int nsl_system::makeModelInstance()
{
	int fg = 0;

	NSL_APPLICATION_MODEL = (nsl_model*) getApplicationModel(getAppModel());
	if  (NSL_APPLICATION_MODEL != NULL)
	{
			NSLoutput("Instantiating model: ",model.get_value());
			NSL_MAIN_MODEL = NSL_APPLICATION_MODEL->makeInstance();
			fg = 1;
	}
	else
			NSLoutput("Null Application");

	return fg;
}
int nsl_system::add_diff_method(nsl_diff_method* d)
{
	d->set_index(++diff_method_total);
	diff_method_list->append(d);
//	d->set_m_parent(this);

	return diff_method_total;
}

nsl_diff_method* nsl_system::get_diff_method(const char* mname)
{
	return (nsl_diff_method*) diff_method_list->get_by_name(mname);
}

int nsl_system::add_diff_model(nsl_diff* d)
{
	d->set_index(++diff_model_total);
	diff_model_list->append(d);
//	d->set_m_parent(this);

	return diff_model_total;
}

nsl_diff* nsl_system::get_diff_model(const char* mname)
{
	return (nsl_diff*) diff_model_list->get_by_name(mname);
}

int nsl_system::add_thresh_lib(nsl_thresh_library* d)
{
	d->set_index(++thresh_lib_total);
	thresh_lib_list->append(d);
//	d->set_m_parent(this);

	return thresh_lib_total;
}

nsl_thresh_library* nsl_system::get_thresh_lib(const char* mname)
{
	return (nsl_thresh_library*) thresh_lib_list->get_by_name(mname);
}

int nsl_system::init()
{
	nsl_model* model;

	model_list->wind_up();
	// initiating models (SYS_MODULE)
	while ((model = (nsl_model*) model_list->next()) != NULL)
		model->init();

	return 1;
}

// add proc
 
int nsl_system::insert_proc(nsl_function* m)
{
	proc_list->wind_up();
	proc_list->set_index(++proc_total);
	proc_list->insert(m);
	proc_list->set_m_parent(this);

 	return proc_total;
}
int nsl_system::add_proc(nsl_function* m)
{
	proc_list->set_index(++proc_total);
	proc_list->append(m);
	proc_list->set_m_parent(this);

 	return proc_total;
}
int nsl_system::init_proc()
{
 	if (proc_list != NULL)
	{
	    proc_list->wind_up();
	    nsl_function* m;
	    while (m = (nsl_function*) proc_list->next())
		((nsl_function*) m)->exec(); // global
	}
	else
	   cmd_out("NULL 'nsl_proc_list'");

	return 1;
}

// get model

nsl_function* nsl_system::get_proc(const char* mname)
{
	return (nsl_function*) proc_list->get_by_name(mname);
}
nsl_function* nsl_system::get_proc(const int mindex)
{
	return (nsl_function*) proc_list->get_by_index(mindex);
}

// i/o files

int nsl_system::add_file_type(nsl_file* sfile)
{
	sfile->set_index(++file_type_total);
	file_type_list->append(sfile);
	sfile->set_m_parent(this);

	return file_type_total;
}
nsl_file* nsl_system::get_file_type(const char* tname) // any dir
{
	const char* str;
	file_type_list->wind_up();
	nsl_file* sfile;
	while (sfile = (nsl_file*)file_type_list->next())
	{
		str = sfile->get_filename();	// w/o file ending
		if (strcmp(tname,str) == 0)
			return sfile;
		str = sfile->get_name(); 	// w/ file ending
		if (strcmp(tname,str) == 0)
			return sfile;
	}
	return (nsl_file*) 0;
}
nsl_file* nsl_system::get_file_type(const int tindex)
{
	return (nsl_file*) file_type_list->get_by_index(tindex);
}

// print

int nsl_system::print_system_status(ostream& out) const
{
//	print_base_status(out);
	
	out << "\n# model_total:\t\t" << model_total;
	out << "\n# diff_method_total:\t" << diff_method_total;
	out << "\n# thresh_lib_total:\t" << thresh_lib_total;
	out << "\n# file_type_total:\t" << file_type_total;
	out << "\n# nsl_dir:\t" << nsl_dir << "\n";
 	out.flush();

	return 1;
}
int nsl_system::print_status(ostream& out)  const // virtual
{
	print_system_status(out);
	return 1;
}
int nsl_system::print_system(ostream& out) const
{
//	print_base(out);

//	print_system_status(out);
	
	return 1;
}
int nsl_system::print(ostream& out) const // virtual
{
	print_system(out);
	return 1;
}

// print all

int nsl_system::print_system_all_status(ostream& out) const
{
	print_system_status(out);
//	print_base_all_status(out);
	return 1;
}
int nsl_system::print_all_status(ostream& out)  const // virtual
{
	print_system_all_status(out);
	return 1;
}
int nsl_system::print_system_all(ostream& out) const
{
	print_system(out);
//	print_base_all(out);
	return 1;
}
int nsl_system::print_all(ostream& out) const // virtual
{
	print_system_all(out);
	return 1;
}

int nsl_system::write_model(fstream* file,nsl_model* model)
{
//	if (TRACE_FG == 1)
//		return 1; // do not print the final values if trace is on

	if (model != NULL || (model = NSL_SYSTEM->get_model()) != NULL)
	{
	   	print_layers(file,model);
	   	print_models(file,model);
	}
	else
		cmd_out("nsl_nsl_file::write_nsl_file: Null Model");

	return 1;
}

void nsl_system::print_layers(fstream* file,nsl_model* model)
{
	nsl_list *list;
	num_type t = 0;
	nsl_string str0;
	nsl_string str1;
	nsl_string str2;

	if (file != NULL && model != NULL &&
		(list = model->get_data_list()) != NULL)
	{
       list->wind_up();
       nsl_layer* layer;

/*AW99	   if ((t = model->getSimTime()) == 0)
 	   		*file << "\ninit\n";
	   else
	        *file << "\nstep\n";
*/
		if (model->getSimFg() == 0) {
			sprintf(str0,"\n# Sim Epoch: %d",getSimEpochStep());
			sprintf(str1,"\n# Sim Time: %f",getSimTime());
			sprintf(str2,"\n# Accummulated Sim Time: %f",getSimAccumTime());
		} else {
			sprintf(str0,"\n# Train Epoch: %d",getTrainEpochStep());
			sprintf(str1,"\n# Train Time: %f",getTrainTime());
			sprintf(str2,"\n# Accummulated Train Time: %f",getTrainAccumTime());
		}

		*file << "\n\n#-----------------------";
		*file << "\n# module: " << model->get_name();
		*file << str0;
		*file << str1;
		*file << str2;
		*file << "\n";

/*	   Nsloutput("\n// t=",*file);
	   Nsloutput(t,*file);
	   Nsloutput("\n",*file);
*/
//     *file << "\n// t=" << t << endl;

       while (layer = (nsl_layer*) list->next())
	   {
	   	if (layer->get_file_able_fg() == 0)
			continue;

	   		layer->print(*file);
	   }
	}
	else
		cmd_out("Null model layer list write");
}
void nsl_system::print_models(fstream* file,nsl_model* model)
{
	nsl_list *list;
	num_type t = 0;

	if (file != NULL && model != NULL &&
		(list = model->get_model_list()) != NULL)
	{
	   	list->wind_up();
	   	nsl_model* model;
	   	while (model = (nsl_model*) list->next())
		{
			print_layers(file,model);
	   		print_models(file,model);
		}
	}
	else
		cmd_out("Null model layer list write");
}

// read, write

int nsl_system::write_system(nsl_buffer&)
{
	return 1;
}
int nsl_system::write(nsl_buffer& buf)
{
	write_system(buf);
	return 1;
}
int nsl_system::read_system(nsl_buffer&)
{
	return 1;
}
int nsl_system::read(nsl_buffer& buf)
{
	read_system(buf);
	return 1;
}

// read, write

int nsl_system::write_system(nsl_char_buf&)
{
	return 1;
}
int nsl_system::write(nsl_char_buf& buf)
{
	write_system(buf);
	return 1;
}
int nsl_system::read_system(nsl_char_buf&)
{
	return 1;
}
int nsl_system::read(nsl_char_buf& buf)
{
	read_system(buf);
	return 1;
}
void nsl_system::print_layers_variables(nsl_model* model)
{	nsl_list *list;
	num_type t = 0;
//	nsl_string str0;
//	nsl_string str1;
//	nsl_string str2;

	if (model != NULL && (list = model->get_data_list()) != NULL)
	{	list->wind_up();
		nsl_layer* layer;
		while (layer = (nsl_layer*) list->next())
		{	if (layer->get_file_able_fg() == 0)
				continue;
			layer->show_variables(layer);
		}
	}
	else
		cmd_out("Null model layer list write");
}
void nsl_system::print_models_variables(nsl_model* model)
{	nsl_list *list;
	num_type t = 0;
	if (model != NULL && (list = model->get_model_list()) != NULL)
	{  	list->wind_up();
	   	nsl_model* model;
	   	while (model = (nsl_model*) list->next())
		{	print_layers_variables(model);
	   		print_models_variables(model);
		}
	}
	else
		cmd_out("Null model layer list write");
}
