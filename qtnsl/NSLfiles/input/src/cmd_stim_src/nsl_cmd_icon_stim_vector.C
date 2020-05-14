/**************************************************************/
/*                                                            */
/*                nsl_cmd_icon_stim_vector.C                  */
/*                                                            */
/**************************************************************/


#include "nsl_input.h"
#include "nsl_num_vector.h"

nsl_cmd_icon_stim_vector::nsl_cmd_icon_stim_vector()
{
	set_type("input_vector");
	set_name("icon_stim");
}

nsl_cmd_icon_stim_vector::~nsl_cmd_icon_stim_vector()
{
}
int nsl_cmd_icon_stim_vector::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_icon_stim_vector::cmd_create(nsl_interpreter& nsl)
{
	nsl_stim* stim;
  	nsl_layer* layer;
  	nsl_cmd_type* cmd_type;

	nsl_input_vector* mpstim; 

 	if  ((m_parent != NULL) && 
             ((mpstim = (nsl_input_vector*) m_parent->get_ptr()) != NULL) &&
             ((stim = new nsl_block_stim_vector((nsl_input_vector*)mpstim)) != NULL))
	{
 		nsl_string str;
 		get_obj_name(nsl, str, NSL_NAME_SIZE);
	    stim->set_name(str);
	    nsl_cmd_stim_vector::update_data(stim);
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
		if (strcmp(btype,"input_vector") == 0)
		  ((nsl_input_vector*) layer)->get_input_layer()->add_stim(stim);
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
int nsl_cmd_icon_stim_vector::cmd_reset(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_icon_stim_vector::cmd_update(nsl_interpreter&)
{
  	update_data(OBJ);

	return 1;
}
int nsl_cmd_icon_stim_vector::init_data(nsl_base* stim)
{
	nsl_num_1* vec;
 	nsl_list* list = 0;
 	nsl_cmd_type* data;
	nsl_base* pbase;

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("stim");
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && OBJ != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("icon")) != NULL)
	    {
		vec = ((nsl_icon_stim_vector*) stim)->get_icon();
	    }
 	    else
		cmd_error("cmd_icon_stim_vector: NULL 'name' obj");
	}
	else
	    cmd_error("NULL OBJ");

 	return 1;
}
int nsl_cmd_icon_stim_vector::update_data(nsl_base* stim,
	int,int,int,int,int,int,int,int,int,int)
{
	nsl_num_1* vec;
 	nsl_list* list = 0;
 	nsl_cmd_type* data;
	nsl_base* pbase;

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("stim");
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && OBJ != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("icon")) != NULL)
	    {
//		vec = (nsl_num_vector*) data->get_lobj();
//		*((nsl_icon_stim_vector*) stim)->get_icon() = *vec;
	    }
 	    else
		cmd_error("cmd_icon_stim_vector: NULL 'name' obj");
	}
	else
	    cmd_error("NULL OBJ");

 	return 1;
}

