/* SCCS  @(#)nsl_cmd_exec_stop.h	1.1---95/10/30--15:56:31 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_stop.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_STOP_H
#define _NSL_CMD_EXEC_STOP_H
#include "nsl_cmd_exec.h"
class nsl_interpreter;
class nsl_cmd_exec_stop : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_stop();
		~nsl_cmd_exec_stop();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
