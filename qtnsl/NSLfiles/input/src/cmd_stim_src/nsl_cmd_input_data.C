/**************************************************************/
/*                                                            */
/*                   nsl_cmd_input_data.C                     */
/*                                                            */
/**************************************************************/

#include "nsl_input.h"
#include "nsl_cmd_input_data.h"
#include "nsl_base.h"
#include "nsl_input_data.h"

extern void cmd_error( const char *);

nsl_cmd_input_data::nsl_cmd_input_data()
{
	set_type("input_data");
}

nsl_cmd_input_data::~nsl_cmd_input_data()
{
}

int nsl_cmd_input_data::cmd_clear(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_data::cmd_reset(nsl_interpreter&)
{
	nsl_base* pbase;
	if ((pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer")) != NULL &&
	     (OBJ = pbase->get_ptr()) != NULL)
	{
		((nsl_input_data*) OBJ)->get_input_layer()->reset(0);
	}
 
	return 1;
}
int nsl_cmd_input_data::cmd_update(nsl_interpreter&)
{
 	update_data(OBJ);

	return 1;
}
int nsl_cmd_input_data::init_data(nsl_base* layer)
{
	if (layer == NULL)
	{
		cmd_error("cmd: NULL OBJ");
		return 1;
	}

 	nsl_input_layer* in_stim = ((nsl_input_data*) layer)->get_input_layer();

 	nsl_base* pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer");
	if (pbase != NULL && in_stim != NULL)
	{
 		((nsl_cmd_layer*) pbase)->update_data(in_stim);
	}

 	return 1;
}
int nsl_cmd_input_data::update_data(nsl_base* layer,
	int,int,int,int,int,int,int,int,int,int)
{
	if (layer == NULL)
	{
		cmd_error("cmd: NULL OBJ");
		return 1;
	}

	nsl_input_layer* in_stim = ((nsl_input_data*) layer)->get_input_layer();

  	nsl_base* pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type("input_layer");
	if (pbase != NULL && in_stim != NULL)
	{
 		((nsl_cmd_layer*) pbase)->update_data(in_stim);
	}

	return 1;
}
