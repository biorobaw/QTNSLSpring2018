/* SCCS  @(#)nsl_cmd_stim.C	1.1---95/08/13--20:52:41 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_stim.C                   	      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_stim.h"
#include "nsl_int_data.h"
#include "nsl_input.h"

extern void cmd_error(const char *);

nsl_cmd_stim::nsl_cmd_stim() : nsl_cmd_type("stim")
{
	set_base_type("stim");
}

nsl_cmd_stim::~nsl_cmd_stim()
{
}

int nsl_cmd_stim::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

 	return 1;
}
int nsl_cmd_stim::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_stim::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_stim::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}
int nsl_cmd_stim::init_data(nsl_base* stim)
{
 	int ival;
	nsl_cmd_type* data;
 	nsl_base* pbase;
	nsl_list* list = 0;

	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type(get_base_type());
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd: NULL parent type");
	if (list != NULL)
	{
	  if ((data = (nsl_cmd_type*) list->get_by_name("step")) != NULL)
	  {
		ival = ((nsl_int_data*) data)->get_value();
		((nsl_stim*) stim)->set_step(ival);
	  }
 	  else
		cmd_error("cmd_block_stim: NULL 'name' obj");
	}

	return 1;
}
int nsl_cmd_stim::update_data(nsl_base* stim,
	int,int,int,int,int,int,int,int,int,int)
{
 	int ival;
	nsl_cmd_type* data;
	nsl_base* pbase;
	nsl_list* list = 0;

	pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type(get_base_type());
	if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	else
		cmd_error("cmd: NULL parent type");
	if (list != NULL)
	{
	  if ((data = (nsl_cmd_type*) list->get_by_name("step")) != NULL)
	  {
		ival = ((nsl_int_data*) data)->get_value();
		((nsl_stim*) stim)->set_step(ival);
	  }
	  else
		cmd_error("nsl_cmd_stim: NULL 'step' obj");
	}

	return 1;
}

