/* SCCS  @(#)nsl_num_min_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_num_min_library.C
//

#include "nsl_base.h"

num_type val_NSLmin(const num_type a,const num_type b)
{
	num_type c = (a < b) ? a : b;
	return c;
}
int NSLmin(const int a,const int b)
{
	int c = (a < b) ? a : b;
	return c;
}

