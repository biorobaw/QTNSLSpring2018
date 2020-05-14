/* SCCS  @(#)nsl_cmd_exec_run.h	1.1---95/10/30--15:56:29 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_run.h                       */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_RUN_H
#define _NSL_CMD_EXEC_RUN_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_run : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_run();
		~nsl_cmd_exec_run();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
