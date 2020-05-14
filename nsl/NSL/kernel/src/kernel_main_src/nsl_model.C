/* SCCS  @(#)nsl_model.C	1.1---95/10/13--16:37:11 */
//
//	nsl_model.C
//
#include <stddef.h>
#include "nsl_kernel.h"
#include "nsl_stream.h"
#include "nsl_module.h"
#include "nsl_char_buf_stream_library.h"
#include "nsl_num_library.h"
#include "nsl_data_math.h"
#include "nsl_diff_manager.h"
#include "nsl_function.h"

extern void cmd_out(const char *);
extern void cmd_out(const char *, const char *);
//extern void cmd_out(const char *, int);
//extern void cmd_error(const char *, int);

extern int nsl_rint(num_type s);

nsl_model::nsl_model() : nsl_public("nsl_model"),
	simDelta("simDelta",this,1), simEndTime("simEndTime",this,1),
	trainDelta("trainDelta",this,1), trainEndTime("trainEndTime",this,1),
	simSysTime("simSysTime",this,1), trainSysTime("trainSysTime",this,1),
	simCurrentTime("simCurrentTime",this,1),
	trainCurrentTime("trainCurrentTime",this,1),
	trainAccumCurrentTime("trainAccumCurrentTime",this,1),
	simEpochStep("simEpochStep",this,1), simEpochSteps("simEpochSteps",this,1),
	trainEpochStep("trainEpochStep",this,1), trainEpochSteps("trainEpochSteps",this,1)
{
	init_model("");

}
nsl_model::nsl_model(const char* str,nsl_model* parent,int fg) : nsl_public("nsl_model"),
	simDelta("simDelta",this,1), simEndTime("simEndTime",this,1),
	trainDelta("trainDelta",this,1), trainEndTime("trainEndTime",this,1),
	simSysTime("simSysTime",this,1), trainSysTime("trainSysTime",this,1),
	simCurrentTime("simCurrentTime",this,1),
	trainCurrentTime("trainCurrentTime",this,1),
	trainAccumCurrentTime("trainAccumCurrentTime",this,1),
	simEpochStep("simEpochStep",this,1), simEpochSteps("simEpochSteps",this,1),
	trainEpochStep("trainEpochStep",this,1), trainEpochSteps("trainEpochSteps",this,1)
{
	init_model(str,parent,fg);
}
nsl_model::~nsl_model()
{
}
int nsl_model::init_model(const char* lname,nsl_model* parent,int fg)
{
	set_name(lname);
	set_type("model");
	set_base_type("model");

	DIFFM = new nsl_diff_manager("diff_manager",this); // initialize local diff manager

	data_list = new nsl_list("data"); // layer_list
	function_list = new nsl_list("function");
	model_list = new nsl_list("model"); 

	function_total = 0;
	model_total = 0;

	m_children_list->append(data_list); // layer_list
	m_children_list->append(function_list);
	m_children_list->append(model_list);
   	m_children_list->append(DIFFM);

	sim_fg = 0; // initial state

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
	setSimEndTime((float)1.0);
	setTrainEndTime((float)1.0);

	if (SYSTEM == NULL)
	{
		SYSTEM = new nsl_system;
		NSL_SYSTEM = SYSTEM;
//		cmd_out("nsl_model:Initializing SYSTEM...");
	}

	if (INTERPRETER == NULL)
	{
		INTERPRETER = new nsl_interpreter;
		NSL_INTERPRETER = INTERPRETER;
//		cmd_out("nsl_model:Initializing NSL_INTERPRETER...");
	}
/*
	if (NSL_DIFF == NULL)
	{
		NSL_DIFF = new nsl_diff;
		cmd_out("nsl_model:Initializing NSL_DIFF...");
 	}
*/
	if (fg == -1)
	{
		SYSTEM->addApplicationModel(this);
	}
	else if (parent == 0) // fg == 1)
	{
		SYSTEM->add_model(this);
	}
	else
	{
		parent->add_model(this); // add this model to parent
	}

 	return 1;
}

// simulation

void nsl_model::setSimTimeStep(int i)
{
	simCurrentTimeStep = i;
	simCurrentTime = simCurrentTimeStep*simDelta;
}
void nsl_model::setSimTime(int i) // called from 'run'
{
	simCurrentTimeStep = i;
	simCurrentTime = simCurrentTimeStep*simDelta;
}
void nsl_model::setSimTime(float i)
{
	simCurrentTime = i;
	simCurrentTimeStep = (int) nsl_rint(simCurrentTime.get_value()/simDelta.get_value());
}
void nsl_model::setSimEndTimeStep(int i)
{
	simEndTimeStep = i;
	simEndTime = simEndTimeStep*simDelta;
}
void nsl_model::setSimEndTime(float i)
{
	simEndTime = i;
	simEndTimeStep = (int) nsl_rint(simEndTime.get_value()/simDelta.get_value());
}

void nsl_model::resetSimTime()
{
	simCurrentTimeStep = 0;
	simCurrentTime = 0.0;
}

void nsl_model::incrSimTime()
{
	++simCurrentTimeStep;
	simCurrentTime = simCurrentTimeStep*simDelta;
}

// train

void nsl_model::setTrainTimeStep(int i)
{
	trainCurrentTimeStep = i;
	trainCurrentTime = trainCurrentTimeStep*trainDelta;
}
void nsl_model::setTrainTime(int i) // called from 'run'
{
	trainCurrentTimeStep = i;
	trainCurrentTime = trainCurrentTimeStep*trainDelta;
}
void nsl_model::setTrainTime(float i)
{
	trainCurrentTime = i;
	trainCurrentTimeStep = (int) nsl_rint(trainCurrentTime.get_value()/trainDelta.get_value());
}
void nsl_model::setTrainEndTimeStep(int i)
{
	trainEndTimeStep = i;
	trainEndTime = trainEndTimeStep*trainDelta;
}
void nsl_model::setTrainEndTime(float i)
{
	trainEndTime = i;
	trainEndTimeStep = (int) nsl_rint(trainEndTime.get_value()/trainDelta.get_value());
}
void nsl_model::setTrainAccumTime(float f) // called from 'run'
{
	trainAccumCurrentTime = f;
	trainAccumCurrentTimeStep = (int) nsl_rint(trainAccumCurrentTime.get_value()/trainDelta.get_value());
}

void nsl_model::resetTrainTime()
{
	trainCurrentTimeStep = 0;
	trainCurrentTime = 0.0;

	trainAccumCurrentTimeStep = 0;
	trainAccumCurrentTime = 0.0;
}

void nsl_model::incrTrainTime()
{
	++trainCurrentTimeStep;
	trainCurrentTime = trainCurrentTimeStep*trainDelta;
	if (trainCurrentTime.get_data() >= trainEndTime.get_data()) {
		trainCurrentTimeStep = 0;
		trainCurrentTime = 0.0;
	}

	++trainAccumCurrentTimeStep;
	trainAccumCurrentTime = trainAccumCurrentTimeStep*trainDelta;
}

// add function
 
int nsl_model::add_function(nsl_function* function)
{
	function->set_index(++function_total);
	function_list->append(function);
	function->set_m_parent(this);

	return function_total;
}

// get function

nsl_function* nsl_model::get_function()
{
	if (function_list != NULL)
	{
	   function_list->wind_up();
	   nsl_function* function;
	      function = (nsl_function*)function_list->next(); // return first function
		return function;
	}
	else
	   cmd_out("NULL function_list");

	return (nsl_function*) 0;
}
nsl_function* nsl_model::get_function(const char* lname)
{
	if (function_list != NULL)
	{
	   function_list->wind_up();
	   const char* str;
	   nsl_function* function;
	   while (function = (nsl_function*)function_list->next())
	   {
		str = function->get_name();
		if (strcmp(lname,str) == 0)
			return (nsl_function*) function;
	   }
	}
	else
	   cmd_out("NULL 'nsl_function_list'");

	return (nsl_function*) 0;
}
nsl_function* nsl_model::get_function(const int lindex)
{
	if (function_list != NULL)
	{
	   function_list->wind_up();
	   nsl_function* function;
	   while (function = (nsl_function*)function_list->next())
	   {
		if (lindex == function->get_index())
			return (nsl_function*) function;
	   }
	}
	else
	   cmd_out("NULL 'nsl_function_list'");

	return (nsl_function*) 0;
}

// add model
 
int nsl_model::add_model(nsl_model* model)
{
	model->set_index(++model_total);
	model_list->append(model);
	model->set_m_parent(this);

	return model_total;
}

// get model

nsl_model* nsl_model::get_model()
{
	if (model_list != NULL)
	{
	   model_list->wind_up(); 
	   nsl_model* model;
	      model = (nsl_model*)model_list->next(); // return first model
		return model;
	}
	else
	   cmd_out("NULL model_list");

	return (nsl_model*) 0;
}

nsl_model* nsl_model::get_model(const char* fullstr)
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
		model = model->get_model(pname);

//	cmd_out("nsl_model::get_model");

	return model; // this
}

nsl_model* nsl_model::get_model(const int lindex)
{
	if (model_list != NULL)
	{
	   model_list->wind_up();
	   nsl_model* model;
	   while (model = (nsl_model*)model_list->next())
	   {
		if (lindex == model->get_index())
			return (nsl_model*) model;
	   }
	}
	else
	   cmd_out("NULL 'nsl_model_list'");

	return (nsl_model*) 0;
}

nsl_model* nsl_model::makeInstance()
{
	cmd_out("nsl_model: makeInstance");

	return this;
}

// init function

int nsl_model::init()
{
	if (get_print_time_fg() == 1 || get_verbose_fg() == 1)
		cmd_out("// initiating model: ",get_name());

	if (function_list != NULL)
	{
	    function_list->wind_up();
	    nsl_function* m;
	    while (m = (nsl_function*) function_list->next())
		((nsl_function*) m)->proc(-1); // global
	}
//	else
//	   cmd_out("NULL 'nsl_function_list'");

	return 1;
}

// run function

int nsl_model::run()
{
//	if (get_print_time_fg() == 1 || get_verbose_fg() == 1)
//		cmd_out("// simulation time: ",get_time());

/* AW98	if (function_list != NULL)
	{
	    function_list->wind_up();
	    nsl_function* m;
	    while (m = (nsl_function*) function_list->next())
		((nsl_function*) m)->proc(CURRENT_TIME_STEP); // global
	}
	else
	   cmd_out("NULL 'nsl_function_list'");
*/
//	ASLrun(CURRENT_TIME_STEP);
	cmd_error("nsl_model::run: Not runnning from here");

	return 1;
}
int nsl_model::run(const int i0,const int i1)
{
	int i;

 	if (i1 < i0)
	{
	    cerr << "BAD time interval: " << i0 << "," << i1 << "\n";
	    cerr.flush();
	    return 0;
	}

//	cmd_out("running from  i0 (time step): ",i0);
//	cmd_out("        until i1 (time step): ",i1);

	for (i = i0; i <= i1; i++)
	{
/*	    if (BREAKFG == 1)
	    {
		BREAKFG = 0;
		INTERRUPTFG = 1;
		cmd_error("Simulation Interrupt");
		return 1;
	    }
*/
	    setSimTime(i);
//	    cmd_out("// TimeStep: ",i);

 	    run();
	}
	return 1;
}
int nsl_model::run(const float t0,const float t1)
{
//	if (SIM_FG == 1)

	if (t1 < t0)
	{
	    cerr << "BAD time interval: " << t0 << "," << t1 << "\n";
	    cerr.flush();
	    return 0;
	}

//	cmd_out("running from  t0 (time): ",t0);
//	cmd_out("        until t1 (time): ",t1);

	float delta = getSimDelta();
	int i0 = (int) nsl_rint(t0/delta);
	int i1 = (int) nsl_rint(t1/delta);

	int mstatus = run(i0,i1);

	return mstatus;
}
void nsl_model::file_header(ostream& out)
{
	if (data_list != NULL)
	{
	   out << "set delta " << simDelta.get_value() << "\n";
	   out << "set end_time " << simEndTime.get_value() << "\n";

	   out << "disable function ALL\n";
	   out << "disable layer ALL\n";

	   data_list->wind_up();
	   nsl_layer* layer;
	   while (layer = (nsl_layer*)data_list->next())
		if (layer->get_able_fg() == 1)
		    out << "enable layer " << layer->get_name() << "\n";
	}
	else
	   cmd_out("NULL 'data_list'");
}

// print

int nsl_model::print_model_status(ostream& out) const
{
	print_base_status(out);
	out << "# data_total:\t\t" << data_total << "\n";
	out << "# function_total:\t" << function_total << "\n";
	out << "\n";
  	if (get_print_time_fg() == 1)
	   out << "set model print_time\tON\n";
	else // if (get_print_time_fg() == 0)
	   out << "set model print_time\t\tOFF\n";
	out << "set model delta\t\t" << simDelta.get_value() << "\n";
	out << "set model current_time\t" << simCurrentTime.get_value() << "\n";
	out << "set model end_time\t" << simEndTime.get_value() << "\n";
	out.flush();
  	if (DIFFM != NULL)
		DIFFM->print_status(out);
	out.flush();

	return 1;
}
int nsl_model::print_status(ostream& out)  const // virtual
{
	print_model_status(out);
	return 1;
}
int nsl_model::print_model(ostream& out) const
{
	nsl_string str0;
	nsl_string str1;
	nsl_string str2;

//	print_base(out);
	if (sim_fg == 0) {
		sprintf(str0,"\n# Sim Epoch: %d",SYSTEM->getSimEpochStep());
		sprintf(str1,"\n# Sim Time: %f",SYSTEM->getSimTime());
		sprintf(str2,"\n# Accummulated Sim Time: %f",SYSTEM->getSimAccumTime());
	} else {
		sprintf(str0,"\n# Train Epoch: %d",SYSTEM->getTrainEpochStep());
		sprintf(str1,"\n# Train Time: %f",SYSTEM->getTrainTime());
		sprintf(str2,"\n# Accummulated Train Time: %f",SYSTEM->getTrainAccumTime());
	}

	out << "\n\n#-----------------------";
	out << "\n# module: " << get_name();
	out << str0;
	out << str1;
	out << str2;
	out << "\n";

	return 1;
}
int nsl_model::print(ostream& out) const // virtual
{
	print_model(out);
	return 1;
}

// print all

int nsl_model::print_model_all_status(ostream& out) const
{
	print_model_status(out);
	print_base_all_status(out);
	return 1;
}
int nsl_model::print_all_status(ostream& out)  const // virtual
{
	print_model_all_status(out);
	return 1;
}
int nsl_model::print_model_all(ostream& out) const
{
	print_model(out);
	print_base_all(out);
	return 1;
}
int nsl_model::print_all(ostream& out) const // virtual
{
	print_model_all(out);
	return 1;
}

// read, write

int nsl_model::write_model(nsl_buffer& buf)
{
	nsl_list* list;

	if ((list = get_data_list()) != NULL)
	{
        list->wind_up();
        nsl_layer* layer;
        while (layer = (nsl_layer*) list->next())
		{
			if (layer->get_file_able_fg() == 0)
				continue;

			if (sim_fg == 0) {
				buf << "# Sim Epoch: " << getSimEpochStep() << "\n";
				buf << "# Sim Time: " << getSimTime() << "\n";
			}
			else {
				buf << "# Train Epoch: " << getTrainEpochStep() << "\n";
				buf << "# Train Time: " << getTrainTime() << "\n";
			}
            buf << "assign layer " << layer->get_name() << "\n";
			layer->write(buf);
	    }
//	    buf << "step\n";
	}
	else
	{
		cmd_out("Null model layer list");
	}
	return 1;
}
int nsl_model::write(nsl_buffer& buf)
{
	write_model(buf);
	return 1;
}
int nsl_model::read_model(nsl_buffer&)
{
	nsl_list* list;

	if ((list = get_data_list()) != NULL)
	{
            list->wind_up();
            nsl_layer* layer;
            while (layer = (nsl_layer*) list->next())
	    { 
		if (layer->get_file_able_fg() == 0)
			continue;

//		layer->read(buf);
	    }
	}
	else
	{
		cmd_out("Null model layer list");
	}

	return 1;
}
int nsl_model::read(nsl_buffer& buf)
{
	read_model(buf);
	return 1;
}

// read, write

int nsl_model::write_model(nsl_char_buf& buf)
{
	nsl_list* list;

	if ((list = get_data_list()) != NULL)
	{
        list->wind_up();
        nsl_layer* layer;
        while (layer = (nsl_layer*) list->next())
		{
			if (layer->get_file_able_fg() == 0)
				continue;

			if (sim_fg == 0) {
				//buf << "# Sim Epoch: " << getSimEpochStep() << "\n";
				//buf << "# Sim Time: " << getSimTime() << "\n";
			}
			else {
				//buf << "# Train Epoch: " << getTrainEpochStep() << "\n";
				//buf << "# Train Time: " << getTrainTime() << "\n";
			}
            //buf << "assign layer " << layer->get_name() << "\n";
			layer->write(buf);
	    }
//	    buf << "step\n";
	}
	else
	{
		cmd_out("Null model layer list");
	}
	return 1;
}
int nsl_model::write(nsl_char_buf& buf)
{
	write_model(buf);
	return 1;
}
int nsl_model::read_model(nsl_char_buf&)
{
	nsl_list* list;

	if ((list = get_data_list()) != NULL)
	{
            list->wind_up();
            nsl_layer* layer;
            while (layer = (nsl_layer*) list->next())
	    {
		if (layer->get_file_able_fg() == 0)
			continue;

//		layer->read(buf);
	    }
	}
	else
	{
		cmd_out("Null model layer list");
	}

	return 1;
}
int nsl_model::read(nsl_char_buf& buf)
{
	read_model(buf);
	return 1;
}
