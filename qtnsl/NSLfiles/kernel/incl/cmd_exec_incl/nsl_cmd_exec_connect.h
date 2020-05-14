/* SCCS  @(#)nsl_cmd_exec_connect.h	1.1---95/10/30--15:56:21 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_connect.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_CONNECT_H
#define _NSL_CMD_EXEC_CONNECT_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_connect : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_connect();
		~nsl_cmd_exec_connect();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
