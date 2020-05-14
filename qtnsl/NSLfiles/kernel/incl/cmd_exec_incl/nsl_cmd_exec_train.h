/* SCCS  @(#)nsl_cmd_exec_train.h	1.1---95/10/30--15:56:29 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_train.h                     */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_EXEC_TRAIN_H
#define _NSL_CMD_EXEC_TRAIN_H
#include "nsl_cmd_exec.h"
class nsl_cmd_exec_train : public nsl_cmd_exec
{
public:
		nsl_cmd_exec_train();
		~nsl_cmd_exec_train();

	int exec(nsl_interpreter&);
	int help(const char*);
};
#endif
