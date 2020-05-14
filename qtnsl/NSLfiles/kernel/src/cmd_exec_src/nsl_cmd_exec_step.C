/* SCCS  @(#)nsl_cmd_exec_step.C	1.1---95/10/13--16:35:17 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_step.C                      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_step.h"
#include "nsl_kernel.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"

nsl_cmd_exec_step::nsl_cmd_exec_step() : nsl_cmd_exec("step")
{
}

nsl_cmd_exec_step::~nsl_cmd_exec_step()
{
}
int nsl_cmd_exec_step::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
 	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"model");
	}
	else
		nsl >> str; // step: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_step(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("step model",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
	}

	return fg;
}
int nsl_cmd_exec_step::help(const char*)
{
	return 1;
}

