/* SCCS  @(#)nsl_cmd_exec_exec.h	1.1---95/10/30--15:56:24 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_exec.h                      */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_EXEC_EXEC_H
#define _NSL_CMD_EXEC_EXEC_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_exec : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_exec();
		~nsl_cmd_exec_exec();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif