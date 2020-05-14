/* SCCS  @(#)nsl_cmd_exec_file_disable.h	1.1---95/10/30--15:56:25 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_file_disable.h              */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_FILE_DISABLE_H
#define _NSL_CMD_EXEC_FILE_DISABLE_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_file_disable : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_file_disable();
		~nsl_cmd_exec_file_disable();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif