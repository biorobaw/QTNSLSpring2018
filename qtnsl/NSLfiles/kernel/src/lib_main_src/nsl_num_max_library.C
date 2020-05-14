/* SCCS  @(#)nsl_num_max_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_num_max_library.C
//

#include "nsl_base.h"

num_type NSLmax(const num_type a,const num_type b) 
{
	num_type c = (a < b) ? a : b;
	return c;
}
int NSLmax(const int a,const int b)
{
	int c = (a > b) ? a : b;
	return c;
}
