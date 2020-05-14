/* SCCS  @(#)nsl_num_sat_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_num_sat_library.C
//
#include "nsl_base.h"

num_type NSLsat(const num_type a)
{
	num_type c;
	if (a > (num_type) 0)
		c = (num_type) 1;
	else if (a > 0)
		c = a;
	else
		c = 0;
	return c;
}
num_type NSLsat(const num_type a,const num_type x1,const num_type x2)
{
	num_type c;
	if (a > x2)
		c = (num_type) 1;
	else if (a > x1)
		c = (a-x1)/(x2-x1);
	else
		c = 0;
	return c;
}
num_type NSLsat(const num_type a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	num_type c;
	if (a > x2)
		c = y2;
	else if (a > x1)
		c = (y2-y1)*(a-x1)/(x2-x1) + y1;
	else
		c = y1;
	return c;
}
