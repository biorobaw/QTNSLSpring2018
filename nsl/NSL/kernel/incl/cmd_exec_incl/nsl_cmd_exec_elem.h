/* SCCS  @(#)nsl_cmd_exec_elem.h	1.1---95/10/30--15:56:23 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_elem.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_ELEM_H
#define _NSL_CMD_EXEC_ELEM_H
#include "nsl_cmd_exec.h"

#ifndef _NSL_SET
class nsl_interpreter;
#endif

class nsl_cmd_exec_elem : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_elem();
		~nsl_cmd_exec_elem();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
