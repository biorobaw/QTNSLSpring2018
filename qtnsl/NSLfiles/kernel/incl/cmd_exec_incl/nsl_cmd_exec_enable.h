/* SCCS  @(#)nsl_cmd_exec_enable.h	1.1---95/10/30--15:56:24 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_enable.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_ENABLE_H
#define _NSL_CMD_EXEC_ENABLE_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_enable : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_enable();
		~nsl_cmd_exec_enable();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
