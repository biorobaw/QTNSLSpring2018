/**************************************************************/
/*                                                            */
/*                nsl_cmd_time_interval.C                     */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_time_interval.h"
#include "nsl_stim.h"
#include "nsl_cmd_buf.h"
#include "nsl_input.h"

extern void cmd_error(const char *);

nsl_cmd_time_interval::nsl_cmd_time_interval() : nsl_cmd_type("time_interval")
{
}

nsl_cmd_time_interval::~nsl_cmd_time_interval()
{
}
int nsl_cmd_time_interval::cmd_clear(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_time_interval::cmd_create(nsl_interpreter& nsl)
{
	nsl_stim* stim;
	nsl_time_interval* tobj;
 	nsl_cmd_type* cmd_type;

	if ((cmd_type = ((nsl_cmd_buf*) nsl.get_shell_list()->get_top())->
		get_type_cmd("stim")) != NULL && 
		(stim = (nsl_stim*) cmd_type->get_ptr()) != NULL &&
		(tobj = new nsl_time_interval) != NULL)
	{
		stim->add_time_interval(tobj);
  		update_data(tobj);
   	}
	else
		cmd_error("time_interval: NULL OBJ");

	return 1;
}
int nsl_cmd_time_interval::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_time_interval::cmd_update(nsl_interpreter&)
{
 	update_data(OBJ);

	return 1;
}
int nsl_cmd_time_interval::init_data(nsl_base* tobj)
{
 	num_type fval;
  	nsl_cmd_type* data;

	nsl_stim* stim = (nsl_stim*) tobj->get_m_parent();
 	if (data_list != NULL && stim != NULL && tobj != NULL)
	{
	    if ((data = (nsl_cmd_type*) data_list->get_by_name("t0")) != NULL)
	    {
 		fval = ((nsl_time_interval*) tobj)->get_t0();
		((nsl_num_data*) data)->set_value(fval);
	    }
 	    else
		cmd_error("nsl_cmd_time: NULL 't0' obj");
 	    if ((data = (nsl_cmd_type*) data_list->get_by_name("t1")) != NULL)
	    {
 		fval = ((nsl_time_interval*) tobj)->get_t1();
		((nsl_num_data*) data)->set_value(fval);
	    }
 	    else
		cmd_error("nsl_cmd_time: NULL 't1' obj");
	}
 	else
		cmd_error("nsl_cmd_time: NULL OBJ");

	return 1;
}
int nsl_cmd_time_interval::update_data(nsl_base* tobj,
	int,int,int,int,int,int,int,int,int,int)
{
 	num_type t0=0.0,t1=1.0;
  	nsl_cmd_type* data;

	nsl_stim* stim = (nsl_stim*) tobj->get_m_parent();
 	if (data_list != NULL && stim != NULL && tobj != NULL)
	{
	    if ((data = (nsl_cmd_type*) data_list->get_by_name("t0")) != NULL)
 		t0 = ((nsl_num_data*) data)->get_value();
 	    else
		cmd_error("nsl_cmd_time: NULL 't0' obj");
	    if ((data = (nsl_cmd_type*) data_list->get_by_name("t1")) != NULL)
 		t1 = ((nsl_num_data*) data)->get_value();
 	    else
		cmd_error("nsl_cmd_time: NULL 't1' obj");

 	    stim->set_mode(1); // use time interval specifications
	    ((nsl_time_interval*) tobj)->set_t0(t0);
	    ((nsl_time_interval*) tobj)->set_t1(t1);
 	}
 	else
		cmd_error("nsl_cmd_time: NULL OBJ");

	return 1;
}
 
