/* SCCS  @(#)nsl_cmd_exec_cd.C	1.1---95/10/13--16:35:07 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_cd.C                        */
/*                                                            */
/**************************************************************/

//# include "../../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_cmd_exec_cd.h"
#include "nsl_interpreter.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"
nsl_cmd_exec_cd::nsl_cmd_exec_cd() : nsl_cmd_exec("cd")
{
}

nsl_cmd_exec_cd::~nsl_cmd_exec_cd()
{
}

extern "C" int chdir(char*);

int nsl_cmd_exec_cd::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;

	if (nsl.get_str_cnt() != 0) 
	{
	   	nsl >> str;
		chdir(str);
	}
	else
		chdir(getenv("HOME"));

	return fg;
}
int nsl_cmd_exec_cd::help(const char*)
{
	return 1;
}

