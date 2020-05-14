/**************************************************************/
/*                                                            */
/*                nsl_cmd_block_stim_data.C                   */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_input_include.h"

#include "nsl_input.h"
#include "nsl_cmd_block_stim_data.h"

extern void cmd_error(const char *);


nsl_cmd_block_stim_data::nsl_cmd_block_stim_data()
{
	set_type("input_data");
	set_name("block_stim");
}

nsl_cmd_block_stim_data::~nsl_cmd_block_stim_data()
{
}
int nsl_cmd_block_stim_data::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_block_stim_data::cmd_create(nsl_interpreter& nsl)
{
	nsl_stim* stim;
  	nsl_layer* layer;
	nsl_cmd_type* cmd_type;

	nsl_input_data* mpstim; 

 	if  ((m_parent != NULL) && 
             ((mpstim = (nsl_input_data*) m_parent->get_ptr()) != NULL) &&
             ((stim = new nsl_block_stim_data((nsl_input_data*)mpstim)) != NULL))
	{
 		nsl_string str;
 		get_obj_name(nsl, str, NSL_NAME_SIZE);
	    stim->set_name(str);
	    nsl_cmd_stim_data::update_data(stim);
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
		if (strcmp(btype,"input_data") == 0)
		    ((nsl_input_data*) layer)->get_input_layer()->add_stim(stim);
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
int nsl_cmd_block_stim_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_block_stim_data::cmd_update(nsl_interpreter&)
{
 	update_data(OBJ);

	return 1;
}
int nsl_cmd_block_stim_data::init_data(nsl_base* stim)
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
		fval = ((nsl_block_stim_data*) stim)->get_val();
		((nsl_num_data*) data)->set_value(fval);
 	    }
 	    else
		cmd_error("cmd_block_stim_data: NULL 'name' obj");
	}
	else
	    cmd_error("NULL OBJ");

	return 1;
}
int nsl_cmd_block_stim_data::update_data(nsl_base* stim,
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
		((nsl_block_stim_data*) stim)->set_val(fval);
	    }
 	    else
		cmd_error("cmd_block_stim_data: NULL 'name' obj");
	}
	else
	    cmd_error("NULL OBJ");

	return 1;
}
