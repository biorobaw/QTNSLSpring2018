/* SCCS  @(#)nsl_cmd_exec_enable.C	1.1---95/10/13--16:35:10 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_enable.C                    */
/*                                                            */
/**************************************************************/
#include "nsl_cmd_exec_enable.h"
#include "nsl_cmd_buf.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
nsl_cmd_exec_enable::nsl_cmd_exec_enable() : nsl_cmd_exec("enable")
{
}

nsl_cmd_exec_enable::~nsl_cmd_exec_enable()
{
}
int nsl_cmd_exec_enable::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

 	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("enable");
		return 1;
	}

	nsl >> str; // enable: layer,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_enable(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("enable module",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_enable::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

