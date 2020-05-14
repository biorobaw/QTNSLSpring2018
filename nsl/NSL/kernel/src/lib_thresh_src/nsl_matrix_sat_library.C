/* SCCS  @(#)nsl_matrix_sat_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_matrix_sat_library.C
//

#include "nsl_num.h"
#include "nsl_num_library.h"
#include "nsl_data_math.h"

extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

nsl_num_2 NSLsat(const nsl_num_2& a)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > (num_type) 1)
			c[i][j] = (num_type) 1;
		else if (a[i][j] > 0)
			c[i][j] = a[i][j];
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const nsl_num_2& x1,const nsl_num_2& x2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != x1.get_imax() || a.get_jmax() != x1.get_jmax()||
	    a.get_imax() != x2.get_imax() || a.get_jmax() != x2.get_jmax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("jmax2: ",x1.get_jmax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("jmax3: ",x2.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2[i][j])
		    c[i][j] = 1.0;
		else if (a[i][j] > x1[i][j])
		    c[i][j] = (a[i][j]-x1[i][j])/(x2[i][j]-x1[i][j]);
		else
		    c[i][j] = 0;
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const num_type x1,const num_type x2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2)
			c[i][j] = 1.0;
		else if (a[i][j] > x1)
			c[i][j] = (a[i][j]-x1)/(x2-x1);
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const nsl_num_0& x1,const nsl_num_0& x2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2)
			c[i][j] = 1.0;
		else if (a[i][j] > x1)
		   c[i][j] = 
			(a[i][j]-x1.get_data())/(x2.get_data()-x1.get_data());
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const nsl_num_2& x1,const nsl_num_2& x2,
	const nsl_num_2& y1,const nsl_num_2& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != x1.get_imax() || a.get_jmax() != x1.get_jmax() ||
	    a.get_imax() != x2.get_imax() || a.get_jmax() != x2.get_jmax() ||
	    a.get_imax() != y1.get_imax() || a.get_jmax() != y1.get_jmax() ||
	    a.get_imax() != y2.get_imax() || a.get_jmax() != y2.get_jmax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("jmax2: ",x1.get_jmax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("jmax3: ",x2.get_jmax());
		cmd_error("imax4: ",y1.get_imax());
		cmd_error("jmax4: ",y1.get_jmax());
		cmd_error("imax5: ",y2.get_imax());
		cmd_error("jmax5: ",y2.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2[i][j])
		    c[i][j] = y2[i][j];
		else if (a[i][j] > x1[i][j])
		    c[i][j] = (y2[i][j]-y1[i][j])*(a[i][j]-x1[i][j])/
				(x2[i][j]-x1[i][j]) + y1[i][j];
		else
		    c[i][j] = y1[i][j];
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const nsl_num_2& x1,const nsl_num_2& x2,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != x1.get_imax() || a.get_jmax() != x1.get_jmax() ||
	    a.get_imax() != x2.get_imax() || a.get_jmax() != x2.get_jmax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("jmax2: ",x1.get_jmax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("jmax3: ",x2.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2[i][j])
		    c[i][j] = y2;
		else if (a[i][j] > x1[i][j])
		    c[i][j] = (y2-y1)*(a[i][j]-x1[i][j])/
				(x2[i][j]-x1[i][j]) + y1;
		else
		    c[i][j] = y1;
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const nsl_num_2& x1,const nsl_num_2& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != x1.get_imax() || a.get_jmax() != x1.get_jmax() ||
	    a.get_imax() != x2.get_imax() || a.get_jmax() != x2.get_jmax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",x1.get_imax());
		cmd_error("jmax2: ",x1.get_jmax());
		cmd_error("imax3: ",x2.get_imax());
		cmd_error("jmax3: ",x2.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2[i][j])
		    c[i][j] = y2.get_data();
		else if (a[i][j] > x1[i][j])
		    c[i][j] = (y2.get_data()-y1.get_data())*(a[i][j]-x1[i][j])/
				(x2[i][j]-x1[i][j]) + y1.get_data();
		else
		    c[i][j] = y1.get_data();
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const num_type x1,const num_type x2,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2)
		    c[i][j] = y2;
		else if (a[i][j] > x1)
		    c[i][j] = (y2-y1)*(a[i][j]-x1)/(x2-x1) + y1;
		else
		    c[i][j] = y1;
	return c;
}
nsl_num_2 NSLsat(const nsl_num_2& a,const nsl_num_0& x1,const nsl_num_0& x2,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > x2)
		    c[i][j] = y2.get_data();
		else if (a[i][j] > x1)
		    c[i][j] = (y2.get_data()-y1.get_data()) *(a[i][j]- 
		x1.get_data())/(x2.get_data() - x1.get_data()) + y1.get_data();
		else
		    c[i][j] = y1.get_data();
	return c;
}
