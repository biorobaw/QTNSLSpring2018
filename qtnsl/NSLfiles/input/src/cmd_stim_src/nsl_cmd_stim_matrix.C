/**************************************************************/
/*                                                            */
/*                   nsl_cmd_stim_matrix.C             	      */
/*                                                            */
/**************************************************************/

///# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_input_include.h"
#include "nsl_input.h"
#include "nsl_cmd_stim_matrix.h"
#include "nsl_num_data.h"
#include "nsl_cmd_spec_type.h"
#include "nsl_stim_matrix.h"
#include "nsl_base_list.h"
#include "nsl_cmd_system.h"
extern void cmd_error(const char *);

nsl_cmd_stim_matrix::nsl_cmd_stim_matrix()
{
	set_type("stim_matrix");
}

nsl_cmd_stim_matrix::~nsl_cmd_stim_matrix()
{
}
int nsl_cmd_stim_matrix::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_stim_matrix::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_matrix::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_matrix::cmd_update(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_stim_matrix::init_data(nsl_base* stim)
{
	num_type fval = 0;
	spec_type_enum spec_type = NSL_CORNER;
	stim_type_enum stim_type = NSL_BLOCK;
 	nsl_cmd_type* data;
 	nsl_base* pbase;
	nsl_list* list = 0;

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
		spec_type = ((nsl_stim_matrix*) stim)->get_spec_type();
		((nsl_cmd_spec_type*) data)->set_spec_type(spec_type);
 	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'stim_type' obj");
	  if (spec_type == NSL_CORNER)
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("x0")) != NULL)
	    {
		fval = ((nsl_stim_matrix*) stim)->get_x0();
		((nsl_num_data*) data)->set_value(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'x0' obj");
	    if ((data = (nsl_cmd_type*) list->get_by_name("y0")) != NULL)
	    {
		fval = ((nsl_stim_matrix*) stim)->get_y0();
		((nsl_num_data*) data)->set_value(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'y0' obj");
	  }
	  else
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("xc")) != NULL)
	    {
		fval = ((nsl_stim_matrix*) stim)->get_xc();
		((nsl_num_data*) data)->set_value(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'xc' obj");
	    if ((data = (nsl_cmd_type*) list->get_by_name("yc")) != NULL)
	    {
		fval = ((nsl_stim_matrix*) stim)->get_yc();
		((nsl_num_data*) data)->set_value(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'yc' obj");
	  }
	  if ((data = (nsl_cmd_type*) list->get_by_name("dx")) != NULL)
	  {
		fval = ((nsl_stim_matrix*) stim)->get_dx();
		((nsl_num_data*) data)->set_value(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'dx' obj");
	  if ((data = (nsl_cmd_type*) list->get_by_name("dy")) != NULL)
	  {
		fval = ((nsl_stim_matrix*) stim)->get_dy();
		((nsl_num_data*) data)->set_value(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'dy' obj");
	  if ((data = (nsl_cmd_type*) list->get_by_name("vx")) != NULL)
	  {
		fval = ((nsl_stim_matrix*) stim)->get_vx();
		((nsl_num_data*) data)->set_value(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'vx' obj");
	  if ((data = (nsl_cmd_type*) list->get_by_name("vy")) != NULL)
	  {
		fval = ((nsl_stim_matrix*) stim)->get_vy();
		((nsl_num_data*) data)->set_value(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'vy' obj");
	}

	return 1;
}

int nsl_cmd_stim_matrix::update_data(nsl_base* stim,
	int,int,int,int,int,int,int,int,int,int)
{
	num_type fval = 0;
	spec_type_enum spec_type = NSL_CORNER;
	stim_type_enum stim_type = NSL_BLOCK;
 	nsl_cmd_type* data;
	nsl_base* pbase;
	nsl_list* list = 0;

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
		((nsl_stim_matrix*) stim)->set_spec_type(spec_type);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'stim_type' obj");
	  if (spec_type == NSL_CORNER)
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("x0")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_stim_matrix*) stim)->set_x0(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'x0' obj");
	    if ((data = (nsl_cmd_type*) list->get_by_name("y0")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_stim_matrix*) stim)->set_y0(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'y0' obj");
	  }
	  else
	  {
	    if ((data = (nsl_cmd_type*) list->get_by_name("xc")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_stim_matrix*) stim)->set_xc(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'xc' obj");
	    if ((data = (nsl_cmd_type*) list->get_by_name("yc")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_stim_matrix*) stim)->set_yc(fval);
	    }
	    else
		cmd_error("nsl_cmd_stim_matrix: NULL 'yc' obj");
	  }
	  if ((data = (nsl_cmd_type*) list->get_by_name("dx")) != NULL)
	  {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_stim_matrix*) stim)->set_dx(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'dx' obj");
	  if ((data = (nsl_cmd_type*) list->get_by_name("dy")) != NULL)
	  {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_stim_matrix*) stim)->set_dy(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'dy' obj");
	  if ((data = (nsl_cmd_type*) list->get_by_name("vx")) != NULL)
	  {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_stim_matrix*) stim)->set_vx(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'vx' obj");
	  if ((data = (nsl_cmd_type*) list->get_by_name("vy")) != NULL)
	  {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_stim_matrix*) stim)->set_vy(fval);
	  }
	  else
		cmd_error("nsl_cmd_stim_matrix: NULL 'vy' obj");
	}

	return 1;
}
