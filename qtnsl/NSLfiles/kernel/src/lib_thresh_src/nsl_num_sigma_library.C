/* SCCS  @(#)nsl_num_sigma_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_num_sigma_library.C
//

#include "nsl.h"

num_type NSLsigma(const num_type a)
{
	num_type c;
	if (a > 1.0)
		c = 1.0;
	else if (a > 0)
		c = (num_type) a*a*(3.0-2.0*a);
	else
		c = 0;
	return c;
}
num_type NSLsigma(const num_type a,const num_type x1,const num_type x2)
{
	num_type c;
    num_type sigma = (a-x1)/(x2-x1);
	if (a > x2)
		c = 1.0;
	else if (a > x1)
		c = (num_type) sigma*sigma*(3.0-2.0*sigma);
	else
		c = 0.0;
	return c;
}
num_type NSLsigma(const num_type a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	num_type c;
        num_type sigma = (a-x1)/(x2-x1);
	if (a > x2)
		c = y2;
	else if (a > x1)
		c = (num_type) (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	else
		c = y1;
	return c;
}
