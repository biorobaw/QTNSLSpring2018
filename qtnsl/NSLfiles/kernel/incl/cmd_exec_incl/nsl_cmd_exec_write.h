/* SCCS  @(#)nsl_cmd_exec_write.h	1.1---95/10/30--15:56:32 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_write.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_H
#define _NSL_CMD_EXEC_H
#include "nsl_cmd_exec.h"
class nsl_interpreter;

class nsl_cmd_exec_write : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_write();
		~nsl_cmd_exec_write();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
