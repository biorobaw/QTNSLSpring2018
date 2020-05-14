/* SCCS  @(#)nsl_num_ramp_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_num_ramp_library.C
//

#include "nsl_base.h"

// if a > 0 then a else 0

num_type NSLramp(const num_type a) 
{
	num_type c;
	if (a > (num_type) 0)
		c = a;
	else
		c = 0;
	return c;
}

// if a > b then a - b else 0

num_type NSLramp(const num_type a,const num_type b)
{
	num_type c;
	if (a > b)
		c = a - b;
	else
		c = 0;
	return c;
}

// if a > b then a - b + y2 else y1

num_type NSLramp(const num_type a,const num_type b,
	const num_type y1,const num_type y2)
{
	num_type c;
	if (a > b)
		c = a - b + y2;
	else
		c = y1;
	return c;
}

