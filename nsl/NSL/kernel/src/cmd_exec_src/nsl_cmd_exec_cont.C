/* SCCS  @(#)nsl_cmd_exec_cont.C	1.1---95/10/13--16:35:08 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_cont.C                      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_cont.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
nsl_cmd_exec_cont::nsl_cmd_exec_cont() : nsl_cmd_exec("cont")
{
}

nsl_cmd_exec_cont::~nsl_cmd_exec_cont()
{
}
int nsl_cmd_exec_cont::exec(nsl_interpreter& nsl)
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
		nsl >> str; // cont: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_cont(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("cont model",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_cont::help(const char*)
{
	return 1;
}

