/**************************************************************/
/*                                                            */
/*                nsl_cmd_block_stim_matrix.C                 */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_block_stim_matrix.h"
#include "nsl_input.h"
nsl_cmd_block_stim_matrix::nsl_cmd_block_stim_matrix()
{
	set_type("input_matrix");
	set_name("block_stim");
}

nsl_cmd_block_stim_matrix::~nsl_cmd_block_stim_matrix()
{
}
int nsl_cmd_block_stim_matrix::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_block_stim_matrix::cmd_create(nsl_interpreter& nsl)
{
	nsl_stim* stim;
  	nsl_layer* layer;
 	nsl_cmd_type* cmd_type;

	nsl_input_matrix* mpstim; 

 	if  ((m_parent != NULL) && 
             ((mpstim = (nsl_input_matrix*) m_parent->get_ptr()) != NULL) &&
             ((stim = new nsl_block_stim_matrix((nsl_input_matrix*)mpstim)) != NULL))
	{
 		nsl_string str;
 		get_obj_name(nsl, str, NSL_NAME_SIZE);
	    stim->set_name(str);
	    nsl_cmd_stim_matrix::update_data(stim);
	    if ((cmd_type = ((nsl_cmd_buf*) nsl.get_shell_list()->get_top())->
		    get_type_cmd("stim")) != NULL)
		cmd_type->set_ptr(stim);
	    else
		cmd_error("stim: NULL OBJ");
	    update_data(stim);
	    if ((cmd_type = ((nsl_cmd_buf*) nsl.get_shell_list()->get_top())->
		get_type_cmd("input_layer")) != NULL &&
		(layer = (nsl_layer*) cmd_type->get_ptr()) != NULL)
	    {
		const char* btype = layer->get_type();
		if (strcmp(btype,"input_matrix") == 0)
		  ((nsl_input_matrix*) layer)->get_input_layer()->add_stim(stim);
		else
		    cmd_error("cmd_stim: Bad input layer type: ",btype);
	    }
	    else
		cmd_error("NULL parent OBJ");
	}
	else
		cmd_error("cmd_stim: Unable to create new stim");

	return 1;
}
int nsl_cmd_block_stim_matrix::cmd_reset(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_block_stim_matrix::cmd_update(nsl_interpreter&)
{
 	update_data(OBJ);

	return 1;
}
int nsl_cmd_block_stim_matrix::init_data(nsl_base* stim)
{
	float fval;
	nsl_base* pbase;
	nsl_list* list = 0;
 	nsl_cmd_type* data;

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("stim");
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && stim != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("val")) != NULL)
	    {
		fval = ((nsl_block_stim_matrix*) stim)->get_val();
		((nsl_num_data*) data)->set_value(fval);
	    }
 	    else
		cmd_error("cmd_block_stim_matrix: NULL 'name' obj");
	}
	else
	    cmd_error("NULL OBJ");

	return 1;
}
int nsl_cmd_block_stim_matrix::update_data(nsl_base* stim,
	int,int,int,int,int,int,int,int,int,int)
{
	float fval;
 	nsl_base* pbase;
	nsl_list* list = 0;
 	nsl_cmd_type* data;

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("stim");
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && stim != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("val")) != NULL)
	    {
		fval = ((nsl_num_data*) data)->get_value();
		((nsl_block_stim_matrix*) stim)->set_val(fval);
	    }
 	    else
		cmd_error("cmd_block_stim_matrix: NULL 'name' obj");
  	}
	else
	    cmd_error("NULL OBJ");

	return 1;
}

