/* SCCS  @(#)nsl_cmd_exec_update.h	1.1---95/10/30--15:56:31 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_update.h                    */
/*                                                            */
/**************************************************************/


#ifndef _NSL_CMD_EXEC_UPDATE_H
#define _NSL_CMD_EXEC_UPDATE_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_update : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_update();
		~nsl_cmd_exec_update();

	int exec(nsl_interpreter&);
	int help(const char*);
};


#endif
