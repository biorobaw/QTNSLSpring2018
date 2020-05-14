/* SCCS  @(#)nsl_cmd_exec_init.h	1.1---95/10/30--15:56:26 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_init.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_INIT_H
#define _NSL_CMD_EXEC_INIT_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_init : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_init();
		~nsl_cmd_exec_init();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
