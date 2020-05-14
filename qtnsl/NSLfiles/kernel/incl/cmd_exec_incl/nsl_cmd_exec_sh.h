/* SCCS  @(#)nsl_cmd_exec_sh.h	1.1---95/10/30--15:56:30 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_sh.h                        */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_SH_H
#define _NSL_CMD_EXEC_SH_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_sh : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_sh();
		~nsl_cmd_exec_sh();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif