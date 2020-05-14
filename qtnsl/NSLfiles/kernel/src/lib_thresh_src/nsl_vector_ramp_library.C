/* SCCS  @(#)nsl_vector_ramp_library.C	1.1---95/08/13--20:48:24 */
//
//	nsl_vector_ramp_library.C
//

#include "nsl_num.h"
#include "nsl_num_data.h"
#include "nsl_data_math.h"


extern void cmd_error(const char *);
extern void cmd_error(const char *, int);
// if a > 0 then a else 0

nsl_num_1 NSLramp(const nsl_num_1& a) 
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > (num_type) 0)
			c[i] = a[i];
		else
			c[i] = 0;
	return c;
}

// if a > b then a - b else 0

nsl_num_1 NSLramp(const nsl_num_1& a,const nsl_num_1& b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b[i])
			c[i] = a[i] - b[i];
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLramp(const nsl_num_1& a,const num_type b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i] - b;
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLramp(const nsl_num_1& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i] - b.get_data();
		else
			c[i] = 0;
	return c;
}

// if a > b then a - b + y2 else y1

nsl_num_1 NSLramp(const nsl_num_1& a,const nsl_num_1& b,
	const nsl_num_1& y1,const nsl_num_1& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("imax3: ",y1.get_imax());
		cmd_error("imax4: ",y2.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b[i])
			c[i] = a[i] - b[i] + y2[i];
		else
			c[i] = y1[i];
	return c;
}
nsl_num_1 NSLramp(const nsl_num_1& a,const nsl_num_1& b,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLstep ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b[i])
			c[i] = a[i] - b[i] + y2;
		else
			c[i] = y1;
	return c;
}
nsl_num_1 NSLramp(const nsl_num_1& a,const nsl_num_1& b,const nsl_num_0& y1,
	const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLstep ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b[i])
			c[i] = a[i] - b[i] + y2.get_data();
		else
			c[i] = y1.get_data();
	return c;
}
nsl_num_1 NSLramp(const nsl_num_1& a,const num_type b,const num_type y1,
	const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i] - b + y2;
		else
			c[i] = y1;
	return c;
}
nsl_num_1 NSLramp(const nsl_num_1& a,const nsl_num_0& b,const nsl_num_0& y1,
	const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i] - b.get_data() + y2.get_data();
		else
			c[i] = y1.get_data();
	return c;
}
