/* SCCS  @(#)nsl_cmd_exec_disable.h	1.1---95/10/30--15:56:23 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_disable.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_DISABLE_H
#define _NSL_CMD_EXEC_DISABLE_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_disable : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_disable();
		~nsl_cmd_exec_disable();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
