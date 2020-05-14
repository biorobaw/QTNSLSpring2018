/**************************************************************/
/*                                                            */
/*                   nsl_cmd_input_layer.C                    */
/*                                                            */
/**************************************************************/
#include "nsl_input.h"
#include "nsl_cmd_input_layer.h"

extern void cmd_error(const char *);

nsl_cmd_input_layer::nsl_cmd_input_layer() : nsl_cmd_layer("input_layer")
{
	set_base_type("layer");

	nsl_layer* l;

	nsl_model* model = SYSTEM->get_model();
	if (model == NULL)
	{
//		cmd_error("CMD INPUT LAYER: Null Model");
		return;
	}
	
	for (int i=1; (l = (nsl_layer*) model->get_data(i)) != NULL &&
	     l->get_layer_type() != 1; i++);

	if (l != NULL)
		OBJ = l;
//	else
//		cmd_error("CMD INPUT LAYER: Null Input Layer");

}

nsl_cmd_input_layer::~nsl_cmd_input_layer()
{
}

int nsl_cmd_input_layer::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_input_layer::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_layer::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_layer::cmd_update(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_input_layer::init_data(nsl_base* layer)
{
  	on_off_enum val;
  	nsl_cmd_type* data;
 	nsl_list* list = 0;
	nsl_base* pbase;

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer");
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && layer != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("overlap")) != NULL)
	    {
		val = ((nsl_input_layer*) layer)->get_overlapfg();
		((nsl_on_off_data*) data)->set_value(val);
	    }
	    else
		cmd_error("nsl_cmd_input_layer: NULL 'overlap' obj");
  	}
	else
		cmd_error("NULL OBJ");

	return 1;
}
int nsl_cmd_input_layer::update_data(nsl_base* layer,
	int,int,int,int,int,int,int,int,int,int)
{
  	on_off_enum val;
  	nsl_cmd_type* data;
 	nsl_list* list = 0;
	nsl_base* pbase;

 	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer");
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd_stim: NULL stim parent type");
	if (list != NULL && layer != NULL)
	{
	    if ((data = (nsl_cmd_type*) list->get_by_name("overlap")) != NULL)
	    {
		val = ((nsl_on_off_data*) data)->get_value();
		((nsl_input_layer*) layer)->set_overlapfg(val);
 	    }
	    else
		cmd_error("nsl_cmd_input_layer: NULL 'overlap' obj");
  	}
	else
		cmd_error("NULL OBJ");

	return 1;
}
