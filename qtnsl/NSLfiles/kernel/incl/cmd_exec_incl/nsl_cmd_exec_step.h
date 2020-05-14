/* SCCS  @(#)nsl_cmd_exec_step.h	1.1---95/10/30--15:56:30 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_step.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_STEP_H
#define _NSL_CMD_EXEC_STEP_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_step : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_step();
		~nsl_cmd_exec_step();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
