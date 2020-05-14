/* SCCS  @(#)nsl_num_step_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_num_step_library.C
//

#include "nsl_base.h"

// if a > 0 then 1 else 0

num_type NSLstep(const num_type a)
{
	num_type c;
	if (a > (num_type) 0)
		c = (num_type) 1;
	else
		c = 0;
	return c;
}

// if a > b then 1 else 0

num_type NSLstep(const num_type a,const num_type b)
{
	num_type c;
	if (a > b)
		c = (num_type) 1;
	else
		c = 0;
	return c;
}

// if a > b then y2 else y1

num_type NSLstep(const num_type a,const num_type b,
	const num_type y1,const num_type y2)
{
	num_type c;
	if (a > b)
		c = y2;
	else
		c = y1;
	return c;
}
