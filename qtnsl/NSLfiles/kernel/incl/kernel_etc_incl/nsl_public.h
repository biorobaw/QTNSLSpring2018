/* SCCS  @(#)nsl_public.h	1.1---95/08/13--23:36:35 */
//
//	nsl_public.h
//

#ifndef _NSL_PUBLIC_H
#define _NSL_PUBLIC_H
#include "nsl_base.h"

#ifndef _NSL_SET
class nsl_buffer;
class nsl_base_list;
class nsl_layer;
class nsl_interpreter;
class nsl_function;
//class nsl_num_vector;
//class nsl_num_data;
//class nsl_num_matrix;
#endif
class nsl_public : public nsl_base
{
protected:
	nsl_public(const char* str,int = 0);
	nsl_public(int = 0);
	virtual ~nsl_public();

	void 	init_public(int = 0);
public:
	virtual int display();
};
#endif
