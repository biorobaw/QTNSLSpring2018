/* SCCS  @(#)nsl_cmd_exec_open.h	1.1---95/10/30--15:56:27 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_open.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_OPEN_H
#define _NSL_CMD_EXEC_OPEN_H
#include "nsl_cmd_exec.h"

class nsl_cmd_exec_open : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_open();
		~nsl_cmd_exec_open();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
