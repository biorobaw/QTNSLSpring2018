/* SCCS  @(#)nsl_cmd_exec_csh.C	1.1---95/10/13--16:35:09 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_csh.C                       */
/*                                                            */
/**************************************************************/

#include "nsl.h"
#include "nsl_cmd_exec_csh.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);

nsl_cmd_exec_csh::nsl_cmd_exec_csh() : nsl_cmd_exec("csh")
{
}

nsl_cmd_exec_csh::~nsl_cmd_exec_csh()
{
}
int nsl_cmd_exec_csh::exec(nsl_interpreter& nsl)
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
/*		if (str[0] != 0)
	      	    if (fork() == 0)
        	    {
			execl("/bin/csh","csh","-c",cmd,(char*) 0);
	                perror("execl");
		    }
*/	}
	else
		cmd_error("csh: Null Command");

	return fg;
}
int nsl_cmd_exec_csh::help(const char*)
{
	return 1;
}

