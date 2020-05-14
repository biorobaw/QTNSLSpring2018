/* SCCS  @(#)nsl_matrix_sigma_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_matrix_sigma_library.C
//

#include "nsl.h"
#include "nsl_num.h"
#include "nsl_data_math.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;
nsl_num_2 NSLsigma(const nsl_num_2& a)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	   	if (a[i][j] > 1.0)
		   c[i][j] = 1.0;
	   	else if (a[i][j] > 0)
		   c[i][j] = a[i][j]*a[i][j]*(3.0-2.0*a[i][j]);
	  	else
		   c[i][j] = 0;
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const nsl_num_2& x1,
	const nsl_num_2& x2)
{
 	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
            	num_type sigma = (a[i][j]-x1[i][j])/(x2[i][j]-x1[i][j]);
	    	if (a[i][j] > x2[i][j])
		    c[i][j] = 1.0;
	    	else if (a[i][j] > x1[i][j])
		    c[i][j] = sigma*sigma*(3.0-2.0*sigma);
	    	else
		    c[i][j] = 0;
	    }
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const num_type x1,const num_type x2)
{
 	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
            	num_type sigma = (a[i][j]-x1)/(x2-x1);
	    	if (a[i][j] > x2)
		    c[i][j] = 1.0;
	    	else if (a[i][j] > x1)
		    c[i][j] = sigma*sigma*(3.0-2.0*sigma);
	    	else
		    c[i][j] = 0;
	    }
	return c;
}


nsl_num_2 NSLsigma(const nsl_num_2& a,const nsl_num_0& x1,const nsl_num_0& x2)
{
 	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
            	num_type sigma = (a[i][j] 
			-x1.get_data())/(x2.get_data()-x1.get_data());
	    	if (a[i][j] > x2)
		    c[i][j] = 1.0;
	    	else if (a[i][j] > x1)
		    c[i][j] = sigma*sigma*(3.0-2.0*sigma);
	    	else
		    c[i][j] = 0;
	    }
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const nsl_num_2& x1,
	const nsl_num_2& x2,const nsl_num_2& y1,const nsl_num_2& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
            	num_type sigma = (a[i][j]-x1[i][j])/(x2[i][j]-x1[i][j]);
	    	if (a[i][j] > x2[i][j])
		    c[i][j] = y2[i][j];
	    	else if (a[i][j] > x1[i][j])
		    c[i][j] = (y2[i][j]-y1[i][j])*sigma*sigma*
			(3.0-2.0*sigma) + y1[i][j];
	    	else
		    c[i][j] = y1[i][j];
	    }
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const nsl_num_2& x1,
	const nsl_num_2& x2,const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
            	num_type sigma = (a[i][j]-x1[i][j])/(x2[i][j]-x1[i][j]);
	    	if (a[i][j] > x2[i][j])
		    c[i][j] = y2;
	    	else if (a[i][j] > x1[i][j])
		    c[i][j] = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	    	else
		    c[i][j] = y1;
	    }
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const nsl_num_2& x1,
	const nsl_num_2& x2,const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
                num_type sigma = (a[i][j]-x1[i][j])/(x2[i][j]-x1[i][j]);
	    	if (a[i][j] > x2[i][j])
		    c[i][j] = y2.get_data();
	    	else if (a[i][j] > x1[i][j])
		    c[i][j] = (y2.get_data() 
		-y1.get_data())*sigma*sigma*(3.0-2.0*sigma) + y1.get_data();
	    	else
		    c[i][j] = y1.get_data();
	    }
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
                num_type sigma = (a[i][j]-x1)/(x2-x1);
	    	if (a[i][j] > x2)
		    c[i][j] = y2;
	    	else if (a[i][j] > x1)
		    c[i][j] = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	    	else
		    c[i][j] = y1;
	    }
	return c;
}
nsl_num_2 NSLsigma(const nsl_num_2& a,const nsl_num_0& x1,const nsl_num_0& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
                num_type sigma = 
		(a[i][j]-x1.get_data())/(x2.get_data()-x1.get_data());
	    	if (a[i][j] > x2)
		    c[i][j] = y2.get_data();
	    	else if (a[i][j] > x1)
		    c[i][j] = (y2.get_data()- 
		y1.get_data())*sigma*sigma*(3.0-2.0*sigma) + y1.get_data();
	    	else
		    c[i][j] = y1.get_data();
	    }
	return c;
}
