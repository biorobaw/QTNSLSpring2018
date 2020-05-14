/* SCCS  @(#)nsl_cmd_exec_cont.h	1.1---95/10/30--15:56:21 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_cont.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_CONT_H
#define _NSL_CMD_EXEC_CONT_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_cont : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_cont();
		~nsl_cmd_exec_cont();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
