/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_diff_manager.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_DIFF_MANAGER_H
#define _NSL_CMD_DIFF_MANAGER_H
#include "nsl_cmd_type.h"
class nsl_cmd_diff_manager : public nsl_cmd_type 
{
public:
		nsl_cmd_diff_manager(const char* = "diff_manager");
		~nsl_cmd_diff_manager();
};

#endif
