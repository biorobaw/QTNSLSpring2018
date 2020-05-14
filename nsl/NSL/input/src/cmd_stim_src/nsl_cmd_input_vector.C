/**************************************************************/
/*                                                            */
/*                   nsl_cmd_input_vector.C                   */
/*                                                            */
/**************************************************************/

#include "nsl_input.h"
#include "nsl_cmd_input_vector.h"

extern void cmd_error(const char *);

nsl_cmd_input_vector::nsl_cmd_input_vector()
{
	set_type("input_vector");
}

nsl_cmd_input_vector::~nsl_cmd_input_vector()
{
}

int nsl_cmd_input_vector::cmd_clear(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_vector::cmd_reset(nsl_interpreter&)
{
	nsl_base* pbase;
	if ((pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer")) != NULL &&
	     (OBJ = pbase->get_ptr()) != NULL)
	{
		((nsl_input_vector*) OBJ)->get_input_layer()->reset(0);
	}
 
	return 1;
}
int nsl_cmd_input_vector::cmd_update(nsl_interpreter&)
{
 	update_data(OBJ);

	return 1;
}
int nsl_cmd_input_vector::init_data(nsl_base* layer)
{
 	int ival = 0;
	num_type fval = 0.0;
 	nsl_cmd_type* data;
 	nsl_list* list = 0;
	nsl_base* pbase;

	if (layer == NULL)
	{
		cmd_error("cmd: NULL OBJ");
		return 1;
	}

	nsl_input_layer* in_stim = ((nsl_input_vector*) layer)->get_input_layer();

   	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer");
	if (pbase != NULL && in_stim != NULL)
	{
		list = ((nsl_cmd_type*) pbase)->get_data_list();
		((nsl_cmd_layer*) pbase)->update_data(in_stim);
	}
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && layer != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("xz")) != NULL)
	    {
		ival = ((nsl_input_vector*) layer)->get_xz();
		((nsl_int_data*) data)->set_value(ival);
	    }
	    else
		cmd_error("nsl_cmd_input_vector: NULL 'xz' obj");
 	    if ((data = (nsl_cmd_type*) list->get_by_name("dx")) != NULL)
	    {
		fval = ((nsl_input_vector*) layer)->get_dx();
		((nsl_num_data*) data)->set_value(fval);
	    }
	    else
		cmd_error("nsl_cmd_input_vector: NULL 'dx' obj");
 	}
	else
		cmd_error("NULL OBJ");

	return 1;
}
int nsl_cmd_input_vector::update_data(nsl_base* layer,
	int,int,int,int,int,int,int,int,int,int)
{
 	int ival = 0;
	num_type fval = 0.0;
 	nsl_cmd_type* data;
 	nsl_list* list = 0;
	nsl_base* pbase;

	if (layer == NULL)
	{
		cmd_error("cmd: NULL OBJ");
		return 1;
	}

	nsl_input_layer* in_stim = ((nsl_input_vector*) layer)->get_input_layer();

   	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer");
	if (pbase != NULL && in_stim != NULL)
	{
		list = ((nsl_cmd_type*) pbase)->get_data_list();
		((nsl_cmd_layer*) pbase)->update_data(in_stim);
	}
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && layer != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("xz")) != NULL)
	    {
		ival = ((nsl_int_data*) data)->get_value();
		((nsl_input_vector*) layer)->set_xz(ival);
	    }
	    else
		cmd_error("nsl_cmd_input_vector: NULL 'xz' obj");
 	    if ((data = (nsl_cmd_type*) list->get_by_name("dx")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
	   	((nsl_input_vector*) layer)->set_dx(fval);
	    }
	    else
		cmd_error("nsl_cmd_input_vector: NULL 'dx' obj");
 	}
	else
		cmd_error("NULL OBJ");

	return 1;
}
