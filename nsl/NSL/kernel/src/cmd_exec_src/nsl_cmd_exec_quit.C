/* SCCS  @(#)nsl_cmd_exec_quit.C	1.1---95/10/13--16:35:14 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_quit.C                      */
/*                                                            */
/**************************************************************/

//# include "../../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_cmd_exec_quit.h"
#include "nsl_kernel.h"
nsl_cmd_exec_quit::nsl_cmd_exec_quit() : nsl_cmd_exec("quit")
{
// macro: exit
}

nsl_cmd_exec_quit::~nsl_cmd_exec_quit()
{
}
int nsl_cmd_exec_quit::exec(nsl_interpreter&)
{
	delete SYSTEM;

	return 0;
}
int nsl_cmd_exec_quit::help(const char*)
{
	return 1;
}

