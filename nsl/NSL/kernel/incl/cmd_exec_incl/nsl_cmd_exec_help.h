/* SCCS  @(#)nsl_cmd_exec_help.h	1.1---95/10/30--15:56:26 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_help.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_HELP_H
#define _NSL_CMD_EXEC_HELP_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_help : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_help();
		~nsl_cmd_exec_help();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
