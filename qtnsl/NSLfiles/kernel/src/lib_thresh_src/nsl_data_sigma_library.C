/* SCCS  @(#)nsl_data_sigma_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_data_sigma_library.C
//

#include "nsl_num.h"
#include "nsl_num_library.h"
#include "nsl_data_math.h"
#include "nsl_num_data.h"


nsl_num_0 NSLsigma(const nsl_num_0& a)
{
	nsl_num_0 c;
	if (a > 1.0)
		c = 1.0;
	else if (a > 0)
		c = a*a*(3.0-2.0*a);
	else
		c = 0;
	return c;
}
nsl_num_0 NSLsigma(const nsl_num_0& a,const num_type x1,const num_type x2)
{
	nsl_num_0 c;
        nsl_num_0 sigma = (a-x1)/(x2-x1);
	if (a > x2)
	    c = 1.0;
	else if (a > x1)
	    c = sigma*sigma*(3.0-2.0*sigma);
	else
	    c = 0;
	return c;
}
nsl_num_0 NSLsigma(const nsl_num_0& a,const nsl_num_0& x1,const nsl_num_0& x2)
{
	nsl_num_0 c;
        nsl_num_0 sigma = (a-x1)/(x2-x1);
	if (a > x2)
	    c = 1.0;
	else if (a > x1)
	    c = sigma*sigma*(3.0-2.0*sigma);
	else
	    c = 0;
	return c;
}
nsl_num_0 NSLsigma(const nsl_num_0& a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	nsl_num_0 c;
        nsl_num_0 sigma = (a-x1)/(x2-x1);
	if (a > x2)
	    c = y2;
	else if (a > x1)
	    c = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	else
	    c = y1;
	return c;
}
nsl_num_0 NSLsigma(const nsl_num_0& a,const nsl_num_0& x1,const nsl_num_0& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	nsl_num_0 c;
        nsl_num_0 sigma = (a-x1)/(x2-x1);
	if (a > x2)
	    c = y2;
	else if (a > x1)
	    c = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	else
	    c = y1;
	return c;
}
