/* SCCS  @(#)nsl_cmd_exec_help.C	1.1---95/10/13--16:35:12 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_help.C                      */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_exec_help.h"
#include "nsl_interpreter.h"


nsl_cmd_exec_help::nsl_cmd_exec_help() : nsl_cmd_exec("help")
{
}

nsl_cmd_exec_help::~nsl_cmd_exec_help()
{
}
int nsl_cmd_exec_help::exec(nsl_interpreter& nsl)
{
 	nsl_string str;
	int fg = 2;

	if (nsl.get_str_cnt() > 0)
	{
 		nsl >> str; // help 'command'
		fg = help(str);
	}
	else
		fg = help("help");
 
 	return 1;
}
int nsl_cmd_exec_help::help(const char* str)
{
	return help_file(str);
}

