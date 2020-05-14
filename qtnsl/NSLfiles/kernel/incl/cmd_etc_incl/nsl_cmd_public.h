/* SCCS  @(#)nsl_cmd_public.h	1.1---95/08/13--23:36:35 */
//
//	nsl_cmd_public.h
//

#ifndef _NSL_CMD_PUBLIC
#define _NSL_CMD_PUBLIC
#include "nsl_base.h"
class nsl_cmd_public : public nsl_base
{
protected:
	nsl_cmd_public(const char*,int = 0);
	nsl_cmd_public(int = 0);
	virtual ~nsl_cmd_public();
	
	void 	init_cmd_public(int = 0);
public:
};
#endif
