/* SCCS  @(#)nsl_cmd_exec_delay.h	1.1---95/10/30--15:56:20 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_delay.h                     */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_EXEC_DELAY_H
#define _NSL_CMD_EXEC_DELAY_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_delay : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_delay();
		~nsl_cmd_exec_delay();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
