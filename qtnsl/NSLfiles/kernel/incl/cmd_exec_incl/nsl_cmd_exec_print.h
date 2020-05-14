/* SCCS  @(#)nsl_cmd_exec_print.h	1.1---95/10/30--15:56:27 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_print.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_PRINT_H
#define _NSL_CMD_EXEC_PRINT_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_print : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_print();
		~nsl_cmd_exec_print();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
