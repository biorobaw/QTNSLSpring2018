/* SCCS  @(#)nsl_cmd_exec_file_enable.h	1.1---95/10/30--15:56:25 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_file_enable.h               */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_FILE_ENABLE_H
#define _NSL_CMD_EXEC_FILE_ENABLE_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_file_enable : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_file_enable();
		~nsl_cmd_exec_file_enable();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
