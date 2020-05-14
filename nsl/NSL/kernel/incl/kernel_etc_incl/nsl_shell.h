/* SCCS  @(#)nsl_shell.h	1.1---95/08/13--23:36:40 */
/**************************************************************/
/*                                                            */
/*                       nsl_shell.h     	              */
/*                                                            */
/**************************************************************/

#ifndef _NSL_SHELL_H
#define _NSL_SHELL_H
#include "nsl_public.h"
class nsl_shell : public nsl_public
{

public:
		nsl_shell();
		~nsl_shell();

	virtual int init();
	virtual int run(nsl_interpreter*);
};
#endif
