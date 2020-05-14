/* SCCS  @(#)nsl_sys_module.h	1.1---95/08/13--23:37:18 */
//
//	nsl_sys_module.h
//

#ifndef _NSL_SYS_MODULE_H
#define _NSL_SYS_MODULE_H
#include "nsl_module.h"
class nsl_sys_module : public nsl_module
{
public:
		nsl_sys_module();
		nsl_sys_module(char*,void (*)(),int = 0);

		~nsl_sys_module();

	int init_sys_module(char*,void (*)(),int);
};

#endif
