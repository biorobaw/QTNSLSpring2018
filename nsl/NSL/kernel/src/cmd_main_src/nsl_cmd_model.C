/* SCCS  @(#)nsl_cmd_model.C	1.3---95/10/30--15:37:24 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_model.C                          */
/*                                                            */
/**************************************************************/


#include "nsl_kernel.h"
#include "nsl_num_data.h"
#include "nsl_cmd_model.h"
#include "nsl_cmd_system.h"
#include "nsl_file.h"
#include <stddef.h>
typedef nsl_list nsl_base_list;

extern int TRAIN_FG;
extern int BREAKFG;
extern int INTERRUPTFG;
extern int ASLsys();
extern int ASLrun(int time_step);
extern int ASLtrain(int time_step);
extern void cmd_error(const char *);

int nsl_cmd_model::model_run(nsl_model *model, num_type t0, num_type t1)
{
	int fg;
	num_type t,dt;
	nsl_file* file = NSL.get_output_file();
	on_off_enum io_fg = NSL.get_output_able_fg();

	TRAIN_FG = 0;

	if ((dt = NSL_SYSTEM->getSimDelta()) <= 0.0)
	{
		cmd_error("Bad time step: ",dt);
		return 1;
	}

	if (t1 < 0.0)
		t1 = -1;

	for (t = t0; t1 == -1 || t <= t1; t = t + dt)
	{
	    if (BREAKFG == 1)
	    {
		BREAKFG = 0;
		INTERRUPTFG = 1;
		cmd_error("Simulation Interrupt");
		return 1;
	    }

	    num_type endTime = NSL_SYSTEM->getSimEndTime();
	    int epochStep = NSL_SYSTEM->getSimEpochStep();
	    num_type currentTime = t;
	    num_type accumCurrentTime = t+epochStep*endTime;
	    NSL_SYSTEM->setSimTime(currentTime);
	    NSL_SYSTEM->setSimAccumTime(accumCurrentTime);

	    fg = ASLrun(NSL_SYSTEM->getSimTimeStep()); // all modules

 	    if (SYS_INTERFACE != NULL)
	    {
//	    	if (t0 == 0.0)
//		    SYS_INTERFACE->clear();
	    	SYS_INTERFACE->display();
	    }

	    if (io_fg == NSL_ON && file != NULL)
		file->write(model);

	    if (fg != 1)
	    	break;
	}
//	if (fg == -1)
	   fg = ASLrun(-1); // call endRun

 	if (SYS_INTERFACE != NULL)
	    	SYS_INTERFACE->display();

	return fg;
}

int nsl_cmd_model::model_train(nsl_model *model, num_type t0, num_type t1)
{
	int fg;
	num_type t,dt;
	nsl_file* file = NSL.get_output_file();
	on_off_enum io_fg = NSL.get_output_able_fg();

	TRAIN_FG = 1;

	if ((dt = NSL_SYSTEM->getTrainDelta()) <= 0.0)
	{
		cmd_error("Bad time step: ",dt);
		return 1;
	}

	if (t1 < 0.0)
		t1 = -1;

	for (t = t0; t1 == -1 || t <= t1; t = t + dt)
	{
	    if (BREAKFG == 1)
	    {
		BREAKFG = 0;
		INTERRUPTFG = 1;
		cmd_error("Simulation Interrupt");
		return 1;
	    }

	    num_type endTime = NSL_SYSTEM->getTrainEndTime();
	    int epochStep = NSL_SYSTEM->getTrainEpochStep();
	    num_type currentTime = t;
	    num_type accumCurrentTime = t+epochStep*endTime;
	    NSL_SYSTEM->setTrainTime(currentTime);
	    NSL_SYSTEM->setTrainAccumTime(accumCurrentTime);

	    fg = ASLtrain(t); // NSL_SYSTEM->getTrainTimeStep()); // all modules

 	    if (SYS_INTERFACE != NULL)
	    {
//	    	if (t0 == 0.0)
//		    SYS_INTERFACE->clear();
	    	SYS_INTERFACE->display();
	    }

	    if (io_fg == NSL_ON && file != NULL)
			file->write(model);

	    if (fg != 1)
	    	break;
	}

//	if (fg == -1)
  		fg = ASLtrain(-1); // call all endTrain

 	if (SYS_INTERFACE != NULL)
	    	SYS_INTERFACE->display();

	return fg;
}

nsl_cmd_model::nsl_cmd_model() : nsl_cmd_type("model")
{
	init_cmd_model();
}

nsl_cmd_model::~nsl_cmd_model()
{
	init_cmd_model();
}

int nsl_cmd_model::init_cmd_model()
{
	return set_cmd_model();
}
int nsl_cmd_model::set_cmd_model()
{
	set_base_type("model");

	if (SYSTEM == NULL)
		SYSTEM = new nsl_system;

	nsl_model* model = SYSTEM->get_model(1);

	OBJ = model;
		
	return 1;
}

// data

int nsl_cmd_model::init_data(nsl_base*)
{
	return 1;
}
int nsl_cmd_model::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	// Check for data and update model object

        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
	num_type t;

	if (OBJ == NULL)
	{
		cmd_error("cmd_model: NULL LOBJ");
		return 0;
	}

        pbase = SYSTEM->get_cmd_system()->
             get_m_children_list()->get_mi_by_type(get_base_type());
        if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
        else
                cmd_error("cmd_model: NULL parent type");

        if (list != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("delta")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		((nsl_model*) OBJ)->setSimDelta(t);
	  }
//          else
//                cmd_error("cmd_model: NULL 'delta' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("current_time")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		((nsl_model*) OBJ)->setSimCurrentTime(t);
	  }
//          else
//                cmd_error("cmd_model: NULL 'current_time' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("end_time")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		((nsl_model*) OBJ)->setSimEndTime(t);
	  }
//          else
//                cmd_error("cmd_model: NULL 'end_time' obj");
        }

	return 1;
}

// cmds

int nsl_cmd_model::cmd_cont(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	num_type t,t0,t1,dt,ts;
	nsl_file* file;

	nsl_model* model = SYSTEM->get_model();
	
	if (model == NULL)
	{
	    cmd_error("NULL NSL_MODEL");
	    return 0;
	}

	if ((dt = NSL_SYSTEM->getSimDelta()) <= 0.0)
	{
		cmd_error("Bad time step: ",dt);
		return 1;
	}

	ts = NSL_SYSTEM->getSimTime();

	t0 = ts + dt;

	if (nsl.get_str_cnt() == 0)
	    t1 = NSL_SYSTEM->getSimEndTime();
	else
	{
	    nsl >> str;

	    t1 = atof(str); 		// end_time
	}

	fg = model_run(model,t0,t1); 

	return fg;
}
int nsl_cmd_model::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_model::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_model::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_model::cmd_init(nsl_interpreter&)
{
	nsl_string str;
	int fg = 2;

	nsl_model* model = SYSTEM->get_model();
	
	if (model == NULL)
	{
	    cmd_error("NULL NSL_MODEL");
	    return 0;
	}

	fg = ASLsys();

	// fg = model_run(model,0,0);

	return fg;
}
int nsl_cmd_model::cmd_get(nsl_interpreter& nsl)
{
	return cmd_type_get(nsl);
}
int nsl_cmd_model::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_model::cmd_run(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	num_type t,t0,t1,dt,ts;

	nsl_model* model = SYSTEM->get_model();
	
	if (model == NULL)
	{
	    cmd_error("NULL NSL_MODEL");
	    return 0;
	}

	model->setSimFg(0); // run state

	if ((dt = NSL_SYSTEM->getSimDelta()) <= 0.0)
	{
		cmd_error("Bad time step: ",dt);
		return 1;
	}

	ts = NSL_SYSTEM->getSimTime();

	int epochs = NSL_SYSTEM->getSimEpochSteps();

	t0 = 0.0;

	if (nsl.get_str_cnt() == 0)
	    t1 = NSL_SYSTEM->getSimEndTime();
	else
	{
	    nsl >> str;

	    t1 = atof(str); 		// end_time
	}

//	fg = model_run(model,t0,t1);

		for (int st = 0; ; st++) {
		if (epochs != -1 && st >= epochs)
			break;
		NSL_SYSTEM->setSimEpochStep(st);
		fg = model_run(model,t0,t1);
		if (fg == -2)
			break;
//		ASLrun(-1);
	}

	return fg;
}
int nsl_cmd_model::cmd_set(nsl_interpreter& nsl)
{
	return cmd_type_set(nsl);
}
int nsl_cmd_model::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_model::cmd_step(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	int i;
	num_type t,t0,t1,dt,ts;
	nsl_file* file;

	nsl_model* model = SYSTEM->get_model();
	
	if (model == NULL)
	{
	    cmd_error("NULL NSL_MODEL");
	    return 0;
	}

	if ((dt = NSL_SYSTEM->getSimDelta()) <= 0.0)
	{
		cmd_error("Bad time step: ",dt);
		return 1;
	}

	ts = NSL_SYSTEM->getSimTime();

	t0 = ts + dt;

	if (nsl.get_str_cnt() == 0)
	    i = 1;		// 1 iteration
	else
	{
	    nsl >> str;

	    i = atoi(str); 	// n iterations
	}

	t1 = ts + i*dt; 	// end_time

	fg = model_run(model,t0,t1);

	return fg;
}
int nsl_cmd_model::cmd_train(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 1;
	num_type t,t0,t1,dt,ts;

	nsl_model* model = SYSTEM->get_model();

	if (model == NULL)
	{
	    cmd_error("NULL NSL_MODEL");
	    return 0;
	}

	model->setSimFg(1); // train state

	if ((dt = NSL_SYSTEM->getTrainDelta()) <= 0.0)
	{
		cmd_error("Bad time step: ",dt);
		return 1;
	}

	ts = NSL_SYSTEM->getTrainTime();

	int epochs = NSL_SYSTEM->getTrainEpochSteps();

	t0 = 0.0;

	if (nsl.get_str_cnt() == 0)
	    t1 = NSL_SYSTEM->getTrainEndTime();
	else
	{
	    nsl >> str;

	    t1 = atof(str); 		// end_time
	}

//	fg = model_train(model,t0,t0);

	for (int st = 0; ; st++) {
		if (epochs != -1 && st >= epochs)
			break;
		NSL_SYSTEM->setTrainEpochStep(st);
		fg = model_train(model,t0,t1);
		if (fg == -2)
			break;
//		ASLtrain(-1);
	}

	return fg;
}
int nsl_cmd_model::cmd_update(nsl_interpreter& nsl)
{
	int fg = 2;
        nsl_layer* data;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
	num_type t;

        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("model")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("delta")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		((nsl_model*) OBJ)->setSimDelta(t);
	  }
//          else
//                cmd_error("cmd_model: NULL 'delta' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("current_time")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		((nsl_model*) OBJ)->setSimCurrentTime(t);
	  }
//          else
//                cmd_error("cmd_model: NULL 'current_time' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("end_time")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		((nsl_model*) OBJ)->setSimEndTime(t);
	  }
//          else
//                cmd_error("cmd_model: NULL 'end_time' obj");
        }

	return fg;
}

// local print

int nsl_cmd_model::print_cmd_model(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_model::print(std::ostream& out) const // virtual
{
	print_cmd_model(out);
	return 1;
}



