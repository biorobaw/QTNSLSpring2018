/* SCCS  @(#)nsl_cmd_exec_close.h	1.1---95/10/30--15:56:20 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_close.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_CLOSE_H
#define _NSL_CMD_EXEC_CLOSE_H
#include "nsl_cmd_exec.h"

class nsl_cmd_exec_close : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_close();
		~nsl_cmd_exec_close();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
