/* SCCS  @(#)nsl_cmd_exec_status.h	1.1---95/10/30--15:56:30 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_status.h                    */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_STATUS_H
#define _NSL_CMD_EXEC_STATUS_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_status : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_status();
		~nsl_cmd_exec_status();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
