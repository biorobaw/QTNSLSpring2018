/* SCCS  @(#)nsl_cmd_exec_load.h	1.1---95/10/30--15:56:26 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_load.h                      */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_EXEC_LOAD_H
#define _NSL_CMD_EXEC_LOAD_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_load : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_load();
		~nsl_cmd_exec_load();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
