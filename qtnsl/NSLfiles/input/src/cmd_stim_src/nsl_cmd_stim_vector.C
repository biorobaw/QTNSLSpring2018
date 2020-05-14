/**************************************************************/
/*                                                            */
/*                   nsl_cmd_stim_vector.C             	      */
/*                                                            */
/**************************************************************/

#include "nsl_input.h"
#include "nsl_base.h"

extern void cmd_error(const char *);

nsl_cmd_stim_vector::nsl_cmd_stim_vector()
{
	set_type("stim_vector");
}

nsl_cmd_stim_vector::~nsl_cmd_stim_vector()
{
}
int nsl_cmd_stim_vector::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_stim_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_vector::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_vector::cmd_update(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_stim_vector::init_data(nsl_base* stim)
{
 	num_type fval = 0;
	nsl_cmd_type* data;
	nsl_base* pbase;
	nsl_list* list = 0;
	spec_type_enum spec_type = NSL_CORNER;
	stim_type_enum stim_type = NSL_BLOCK;

	nsl_cmd_stim::init_data(stim);

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type(get_base_type());
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd: NULL parent type");
	if (list != NULL)
	{
	  if ((data = (nsl_cmd_type*) list->get_by_name("spec_type")) != NULL)
	  {
 		spec_type = ((nsl_stim_vector*) stim)->get_spec_type();
		((nsl_cmd_spec_type*) data)->set_spec_type(spec_type);
	  }
	  else
		cmd_error("nsl_cmd_stim_vector: NULL 'spec_type' obj");
 	  if (spec_type == NSL_CORNER)
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("x0")) != NULL)
	    {
		fval = ((nsl_stim_vector*) stim)->get_x0();
		((nsl_num_data*) data)->set_value(fval);
 	    }
	    else
		cmd_error("nsl_cmd_stim_vector: NULL 'x0' obj");
 	  }
	  else
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("xc")) != NULL)
	    {
		fval = ((nsl_stim_vector*) stim)->get_xc();
		((nsl_num_data*) data)->set_value(fval);
 	    }
	    else
		cmd_error("nsl_cmd_stim_vector: NULL 'xc' obj");
 	  }
	  if ((data = (nsl_cmd_type*) list->get_by_name("dx")) != NULL)
	  {
		fval = ((nsl_stim_vector*) stim)->get_dx();
		((nsl_num_data*) data)->set_value(fval);
 	  }
	  else
		cmd_error("nsl_cmd_stim_vector: NULL 'dx' obj");
 	  if ((data = (nsl_cmd_type*) list->get_by_name("vx")) != NULL)
	  {
		fval = ((nsl_stim_vector*) stim)->get_vx();
		((nsl_num_data*) data)->set_value(fval);
 	  }
	  else
		cmd_error("nsl_cmd_stim_vector: NULL 'vx' obj");
 	}

	return 1;
}
int nsl_cmd_stim_vector::update_data(nsl_base* stim,
	int,int,int,int,int,int,int,int,int,int)
{
 	num_type fval = 0;
 	nsl_cmd_type* data;
	nsl_base* pbase;
	nsl_list* list = 0;
	spec_type_enum spec_type = NSL_CORNER;
	stim_type_enum stim_type = NSL_BLOCK;

	nsl_cmd_stim::update_data(stim);

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type(get_base_type());
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd: NULL parent type");
	if (list != NULL)
	{
	  if ((data = (nsl_cmd_type*) list->get_by_name("spec_type")) != NULL)
	  {
		spec_type = ((nsl_cmd_spec_type*) data)->get_spec_type();
		((nsl_stim_vector*) stim)->set_spec_type(spec_type);
	  }
	  else
		cmd_error("nsl_cmd_stim_vector: NULL 'spec_type' obj");
 	  if (spec_type == NSL_CORNER)
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("x0")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_stim_vector*) stim)->set_x0(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_vector: NULL 'x0' obj");
 	  }
	  else
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("xc")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_stim_vector*) stim)->set_xc(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_vector: NULL 'xc' obj");
 	  }
	  if ((data = (nsl_cmd_type*) list->get_by_name("dx")) != NULL)
	  {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_stim_vector*) stim)->set_dx(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_vector: NULL 'dx' obj");
 	  if ((data = (nsl_cmd_type*) list->get_by_name("vx")) != NULL)
	  {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_stim_vector*) stim)->set_vx(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_vector: NULL 'vx' obj");
 	}

	return 1;
}
