/* SCCS  @(#)nsl_cmd_file_manager.C	1.1---95/10/13--16:36:33 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_file_manager.C                   */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_file_manager.h"

nsl_cmd_file_manager::nsl_cmd_file_manager(const char* ftype) : 
	nsl_cmd_type(ftype)
{
	set_base_type(ftype);
}

nsl_cmd_file_manager::~nsl_cmd_file_manager()
{
}

