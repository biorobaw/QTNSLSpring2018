/* SCCS  @(#)nsl_cmd_diff_manager.C	1.1---95/10/13--16:36:32 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_diff_manager.C                   */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_diff_manager.h"
#include "nsl_base.h"

nsl_cmd_diff_manager::nsl_cmd_diff_manager(const char* dtype) : 	
	nsl_cmd_type(dtype)
{
	set_base_type(dtype);
}

nsl_cmd_diff_manager::~nsl_cmd_diff_manager()
{
}

