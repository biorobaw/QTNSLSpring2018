/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_file_manager.h                   */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_FILE_MANAGER_H
#define _NSL_CMD_FILE_MANAGER_H
#include "nsl_cmd_type.h"
class nsl_cmd_file_manager : public nsl_cmd_type 
{
public:
		nsl_cmd_file_manager(const char* = "file_manager");
		~nsl_cmd_file_manager();
};

#endif
