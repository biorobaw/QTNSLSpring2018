/* SCCS  @(#)nsl_cmd_exec_csh.h	1.1---95/10/30--15:56:22 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_csh.h                       */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_CSH_H
#define _NSL_CMD_EXEC_CSH_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_csh : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_csh();
		~nsl_cmd_exec_csh();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
