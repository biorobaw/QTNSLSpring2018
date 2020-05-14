/* SCCS  @(#)nsl_cmd_exec_create.h	1.1---95/10/30--15:56:22 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_create.h                    */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_CREATE_H
#define _NSL_CMD_EXEC_CREATE_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_create : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_create();
		~nsl_cmd_exec_create();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
