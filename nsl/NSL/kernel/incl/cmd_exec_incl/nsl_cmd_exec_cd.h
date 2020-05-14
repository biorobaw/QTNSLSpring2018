/* SCCS  @(#)nsl_cmd_exec_cd.h	1.1---95/10/30--15:56:20 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_cd.h                        */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXEC_CD_H
#define _NSL_CMD_EXEC_CD_H
#include "nsl_cmd_exec.h"
class nsl_interpreter;
class nsl_cmd_exec_cd : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_cd();
		~nsl_cmd_exec_cd();

	int exec(nsl_interpreter&);
	int help(const char*);
};

#endif
