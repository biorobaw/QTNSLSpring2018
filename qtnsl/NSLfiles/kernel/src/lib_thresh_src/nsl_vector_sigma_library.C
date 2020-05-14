/* SCCS  @(#)nsl_vector_sigma_library.C	1.1---95/08/13--20:48:24 */
//
//	nsl_vector_sigma_library.C
//

#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"
#include "nsl_vector_math.h"

//typedef nsl_num_2 nsl_num_2;
////typedef nsl_num_0 nsl_num_0;
////typedef nsl_num_1 nsl_num_1;

nsl_num_1 NSLsigma(const nsl_num_1& a)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
	   if (a[i] > 1.0)
		c[i] = 1.0;
	   else if (a[i] > 0)
		c[i] = a[i]*a[i]*(3.0-2.0*a[i]);
	   else
		c[i] = 0;
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const nsl_num_1& x1,
	const nsl_num_1& x2)
{
 	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1[i])/(x2[i]-x1[i]);
	    if (a[i] > x2[i])
		    c[i] = 1.0;
	    else if (a[i] > x1[i])
		    c[i] = sigma*sigma*(3.0-2.0*sigma);
	    else
		    c[i] = 0;
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const num_type x1,const num_type x2)
{
 	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1)/(x2-x1);
	    if (a[i] > x2)
		    c[i] = 1.0;
	    else if (a[i] > x1)
		    c[i] = sigma*sigma*(3.0-2.0*sigma);
	    else
		    c[i] = 0;
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const nsl_num_0& x1,const nsl_num_0& x2)
{
 	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1.get_data())/(x2.get_data()-x1.get_data());
	    if (a[i] > x2)
		    c[i] = 1.0;
	    else if (a[i] > x1)
		    c[i] = sigma*sigma*(3.0-2.0*sigma);
	    else
		    c[i] = 0;
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const nsl_num_1& x1,
	const nsl_num_1& x2,const nsl_num_1& y1,const nsl_num_1& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1[i])/(x2[i]-x1[i]);
	    if (a[i] > x2[i])
		    c[i] = y2[i];
	    else if (a[i] > x1[i])
		    c[i] = (y2[i]-y1[i])*sigma*sigma*(3.0-2.0*sigma)
			 + y1[i];
	    else
		    c[i] = y1[i];
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const nsl_num_1& x1,
	const nsl_num_1& x2,const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1[i])/(x2[i]-x1[i]);
	    if (a[i] > x2[i])
		    c[i] = y2;
	    else if (a[i] > x1[i])
		    c[i] = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	    else
		    c[i] = y1;
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const nsl_num_1& x1,
	const nsl_num_1& x2,const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1[i])/(x2[i]-x1[i]);
	    if (a[i] > x2[i])
		    c[i] = y2.get_data();
	    else if (a[i] > x1[i])
		    c[i] = (y2.get_data()-y1.get_data())*sigma*sigma*(3.0-2.0*sigma) + y1.get_data();
	    else
		    c[i] = y1.get_data();
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1)/(x2-x1);
	    if (a[i] > x2)
		    c[i] = y2;
	    else if (a[i] > x1)
		    c[i] = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	    else
		    c[i] = y1;
	}
	return c;
}
nsl_num_1 NSLsigma(const nsl_num_1& a,const nsl_num_0& x1,const nsl_num_0& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);
	num_type sigma;

	for (int i = 0; i < s1; i++)
	{
            sigma = (a[i]-x1.get_data())/(x2.get_data()-x1.get_data());
	    if (a[i] > x2)
		    c[i] = y2.get_data();
	    else if (a[i] > x1)
		    c[i] = (y2.get_data()-y1.get_data())*sigma*sigma*(3.0-2.0*sigma) + y1.get_data();
	    else
		    c[i] = y1.get_data();
	}
	return c;
}
