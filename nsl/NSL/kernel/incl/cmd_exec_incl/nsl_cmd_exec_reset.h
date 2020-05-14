/* SCCS  @(#)nsl_cmd_exec_reset.h	1.1---95/10/30--15:56:28 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_reset.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_RESET_H
#define _NSL_CMD_EXEC_RESET_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_reset : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_reset();
		~nsl_cmd_exec_reset();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
