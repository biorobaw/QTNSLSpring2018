/* SCCS  @(#)nsl_cmd_exec_quit.h	1.1---95/10/30--15:56:28 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_quit.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_QUIT_H
#define _NSL_CMD_EXEC_QUIT_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_quit : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_quit();
		~nsl_cmd_exec_quit();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
