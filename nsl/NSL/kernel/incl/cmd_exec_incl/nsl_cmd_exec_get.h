/* SCCS  @(#)nsl_cmd_exec_set.h	1.1---95/10/30--15:56:29 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_set.h                       */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_GET_H
#define _NSL_CMD_EXEC_GET_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_get : public nsl_cmd_exec
{
protected:
	nsl_list* macro_list; // macros
	int macro_total;
public:
		nsl_cmd_exec_get();
		~nsl_cmd_exec_get();

	int exec(nsl_interpreter&);
	int help(const char*);
// macro list:
	int add_macro(nsl_cmd_macro*);
};
#endif
