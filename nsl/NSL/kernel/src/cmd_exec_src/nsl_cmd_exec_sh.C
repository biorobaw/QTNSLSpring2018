/* SCCS  @(#)nsl_cmd_exec_sh.C	1.1---95/10/13--16:35:16 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_sh.C                        */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_sh.h"
#include "nsl_kernel.h"
nsl_cmd_exec_sh::nsl_cmd_exec_sh() : nsl_cmd_exec("sh")
{
}

nsl_cmd_exec_sh::~nsl_cmd_exec_sh()
{
}
int nsl_cmd_exec_sh::exec(nsl_interpreter& nsl)
{
	nsl_string str,cmd;
	int fg = 2;

	if (nsl.get_str_cnt() > 0)
	{
		nsl >> str;
		strcpy(cmd,str);
		
		while (nsl.get_str_cnt() > 0)
		{
			nsl >> str;
			strcat(cmd," ");
			strcat(cmd,str);
		}
		if (str[0] != 0)
			system(str);
	}

	return fg;
}
int nsl_cmd_exec_sh::help(const char*)
{
	return 2;
}

