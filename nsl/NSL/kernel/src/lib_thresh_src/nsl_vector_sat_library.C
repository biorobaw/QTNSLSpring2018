/* SCCS  @(#)nsl_vector_sat_library.C	1.1---95/08/13--20:48:24 */
//
//	nsl_vector_sat_library.C
//

#include "nsl.h"
#include "nsl_num.h"
#include "nsl_data_math.h"
#include "nsl_vector_math.h"
#include "nsl_matrix_math.h"

extern void cmd_error(const char *, int);
extern void cmd_error(const char *);

nsl_num_1 NSLsat(const nsl_num_1& a)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > (num_type) 1)
			c[i] = (num_type) 1;
		else if (a[i] > 0)
			c[i] = a[i];
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const nsl_num_1& x1,const nsl_num_1& x2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != x1.get_imax() || a.get_imax() != x2.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > x2[i])
			c[i] = (num_type) 1;
		else if (a[i] > x1[i])
			c[i] = (a[i]-x1[i])/(x2[i]-x1[i]);
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const num_type x1,const num_type x2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > x2)
			c[i] = (num_type) 1;
		else if (a[i] > x1)
			c[i] = (a[i] - x1)/(x2 - x1);
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const nsl_num_0& x1,const nsl_num_0& x2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > x2)
			c[i] = (num_type) 1;
		else if (a[i] > x1)
			c[i] = (a[i] - x1.get_data())/(x2.get_data() - x1.get_data());
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const nsl_num_1& x1,const nsl_num_1& x2,
	const nsl_num_1& y1,const nsl_num_1& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != x1.get_imax() ||  a.get_imax() != x2.get_imax() || 
	    a.get_imax() != y1.get_imax() ||  a.get_imax() != y2.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("imax4: ",y1.get_imax());
		cmd_error("imax5: ",y2.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > x2[i])
		    c[i] = y2[i];
		else if (a[i] > x1[i])
		    c[i] = (y2[i]-y1[i])*(a[i]-x1[i])/
				(x2[i]-x1[i]) + y1[i];
		else
		    c[i] = y1[i];
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const nsl_num_1& x1,const nsl_num_1& x2,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != x1.get_imax() || a.get_imax() != x2.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > x2[i])
		    c[i] = y2;
		else if (a[i] > x1[i])
		    c[i] = (y2-y1)*(a[i]-x1[i])/
				(x2[i]-x1[i]) + y1;
		else
		    c[i] = y1;
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const nsl_num_1& x1,const nsl_num_1& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != x1.get_imax() || a.get_imax() != x2.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > x2[i])
		    c[i] = y2.get_data();
		else if (a[i] > x1[i])
		    c[i] = (y2.get_data()-y1.get_data())*(a[i]-x1[i])/
				(x2[i]-x1[i]) + y1.get_data();
		else
		    c[i] = y1.get_data();
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > x2)
		    c[i] = y2;
		else if (a[i] > x1)
		    c[i] = (y2-y1)*(a[i]-x1)/(x2-x1) + y1;
		else
		    c[i] = y1;
	return c;
}
nsl_num_1 NSLsat(const nsl_num_1& a,const nsl_num_0& x1,const nsl_num_0& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > x2)
		    c[i] = y2.get_data();
		else if (a[i] > x1)
		    c[i] = (y2.get_data()-y1.get_data())*(a[i]-x1.get_data())/(x2.get_data()-x1.get_data()) + y1.get_data();
		else
		    c[i] = y1.get_data();
	return c;
}
