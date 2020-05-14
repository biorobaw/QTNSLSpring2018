/* SCCS  @(#)nsl_cmd_exec_assign.h	1.1---95/10/30--15:56:20 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_assign.h                    */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_ASSIGN_H
#define _NSL_CMD_EXEC_ASSIGN_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_assign : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_assign();
		~nsl_cmd_exec_assign();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif