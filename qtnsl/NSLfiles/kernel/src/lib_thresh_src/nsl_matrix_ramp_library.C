/* SCCS  @(#)nsl_matrix_ramp_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_matrix_ramp_library.C
//

#include "nsl.h"
#include "nsl_matrix_math.h"
#include "nsl_data_math.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;
// if a > 0 then a else 0

nsl_num_2 NSLramp(const nsl_num_2& a) 
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > (num_type) 0)
			c[i][j] = a[i][j];
		else
			c[i][j] = 0;
	return c;
}

// if a > b then a - b else 0

nsl_num_2 NSLramp(const nsl_num_2& a,const nsl_num_2& b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("jmax2: ",b.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b[i][j])
			c[i][j] = a[i][j] - b[i][j];
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLramp(const nsl_num_2& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = a[i][j] - b.get_data();
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLramp(const nsl_num_2& a,const num_type b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = a[i][j] - b;
		else
			c[i][j] = 0;
	return c;
}

// if a > b then a - b + y2 else y1

nsl_num_2 NSLramp(const nsl_num_2& a,const nsl_num_2& b,const nsl_num_2& y1,
	const nsl_num_2& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax() ||
	    a.get_imax() != y1.get_imax() || a.get_jmax() != y1.get_jmax() ||
	    a.get_imax() != y2.get_imax() || a.get_jmax() != y2.get_jmax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("jmax2: ",b.get_jmax());
		cmd_error("imax3: ",y1.get_imax());
		cmd_error("jmax3: ",y1.get_jmax());
		cmd_error("imax4: ",y2.get_imax());
		cmd_error("jmax4: ",y2.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b[i][j])
			c[i][j] = a[i][j] - b[i][j] + y2[i][j];
		else
			c[i][j] = y1[i][j];
	return c;
}
nsl_num_2 NSLramp(const nsl_num_2& a,const nsl_num_2& b,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("jmax2: ",b.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b[i][j])
			c[i][j] = a[i][j] - b[i][j] + y2;
		else
			c[i][j] = y1;
	return c;
}
nsl_num_2 NSLramp(const nsl_num_2& a,const nsl_num_2& b,const nsl_num_0& y1,
	const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("jmax2: ",b.get_jmax());
		cmd_error("bad matrix sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b[i][j])
			c[i][j] = a[i][j] - b[i][j] + y2.get_data();
		else
			c[i][j] = y1.get_data();
	return c;
}
nsl_num_2 NSLramp(const nsl_num_2& a,const num_type b,const num_type y1,
	const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = a[i][j] - b + y2;
		else
			c[i][j] = y1;
	return c;
}
nsl_num_2 NSLramp(const nsl_num_2& a,const nsl_num_0& b,const nsl_num_0& y1,
	const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = a[i][j] - b.get_data() + y2.get_data();
		else
			c[i][j] = y1.get_data();
	return c;
}
