/* SCCS  @(#)nsl_sys_function.h	1.1---95/08/13--23:37:18 */
//
//	nsl_sys_function.h
//

#ifndef _NSL_SYS_FUNCTION_H
#define _NSL_SYS_FUNCTION_H
#include "nsl_function.h"
class nsl_sys_function : public nsl_function
{
public:
		nsl_sys_function();
		nsl_sys_function(char*,void (*)(),int = 0);

		~nsl_sys_function();

	int init_sys_function(char*,void (*)(),int);
};
#endif
