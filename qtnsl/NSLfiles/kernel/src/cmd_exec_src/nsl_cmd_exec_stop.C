/* SCCS  @(#)nsl_cmd_exec_stop.C	1.1---95/10/13--16:35:17 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_stop.C                      */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_cmd_exec_stop.h"
#include "nsl_cmd_buf.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
#include <stdlib.h>
#include <string.h>

nsl_cmd_exec_stop::nsl_cmd_exec_stop() : nsl_cmd_exec("stop")
{
}

nsl_cmd_exec_stop::~nsl_cmd_exec_stop()
{
}
int nsl_cmd_exec_stop::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
 	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"file");
	}
	else
		nsl >> str; // stop: file,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_stop(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("stop file",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_stop::help(const char*)
{
	return 1;
}

