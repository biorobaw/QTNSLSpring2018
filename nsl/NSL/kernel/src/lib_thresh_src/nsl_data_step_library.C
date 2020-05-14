/* SCCS  @(#)nsl_data_step_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_data_step_library.C
//

#include "nsl_data_math.h"
#include "nsl_num.h"

// NSLstep

// if a > 0 then 1 else 0

nsl_num_0 NSLstep(const nsl_num_0& a)
{
	nsl_num_0 c;
 
	if (a > 0)
		c = 1.0;
	else
		c = 0;
	return c;
}

// if a > b then 1 else 0

nsl_num_0 NSLstep(const nsl_num_0& a,const num_type b)
{
	nsl_num_0 c;
	if (a > b)
		c = 1.0;
	else
		c = 0;
	return c;
}
nsl_num_0 NSLstep(const nsl_num_0& i,const nsl_num_0& k)
{
	nsl_num_0 &b = const_cast<nsl_num_0&>(k);
	nsl_num_0 &a = const_cast<nsl_num_0&>(i);

	nsl_num_0 c;
	if (a > b)
		c = 1.0;
	else
		c = 0;
	return c;
}
nsl_num_0 NSLstep(const nsl_num_0& a,const num_type b,
	const num_type y1,const num_type y2)
{
	nsl_num_0 c;
	if (a > b)
		c = y2;
	else
		c = y1;
	return c;
}
nsl_num_0 NSLstep(const nsl_num_0& i,const nsl_num_0& k,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	nsl_num_0 &b = const_cast<nsl_num_0&>(k);
	nsl_num_0 &a = const_cast<nsl_num_0&>(i);

	nsl_num_0 c;
	if (a > b)
		c = y2;
	else
		c = y1;
	return c;
}
