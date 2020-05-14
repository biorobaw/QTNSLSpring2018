/* SCCS  @(#)nsl_cmd_exec_exec.C	1.1---95/10/13--16:35:11 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_exec.C                      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_exec.h"
#include "nsl_cmd_buf.h"
#include "nsl_base_list.h"
#include "nsl_kernel.h"

#ifndef _NSL_SET
typedef nsl_base_list nsl_list;
#endif

extern void cmd_error(const char *);

nsl_cmd_exec_exec::nsl_cmd_exec_exec() : nsl_cmd_exec("exec")
{
}

nsl_cmd_exec_exec::~nsl_cmd_exec_exec()
{
}
int nsl_cmd_exec_exec::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

 	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("exec");
		return 1;
	}

	nsl >> str; // exec: module,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_exec(nsl);
 	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("exec module",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_exec::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

