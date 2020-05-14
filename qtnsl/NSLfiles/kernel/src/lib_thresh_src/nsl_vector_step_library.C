/* SCCS  @(#)nsl_vector_step_library.C	1.1---95/08/13--20:48:24 */
//
//	nsl_vector_step_library.C
//

#include "nsl.h"
#include "nsl_num.h"
#include "nsl_data_math.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;
extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

// if a > 0 then 1 else 0

nsl_num_1 NSLstep(const nsl_num_1& a)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > (num_type) 0)
			c[i] = (num_type) 1;
		else
			c[i] = 0;
	return c;
}

// if a > b then 1 else 0

nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_1& b)
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
			c[i] = (num_type) 1;
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLstep(const nsl_num_1& a,const num_type b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = (num_type) 1;
		else
			c[i] = 0;
	return c;
}
nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = (num_type) 1;
		else
			c[i] = 0;
	return c;
}

// if a > b then y2 else y1

nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_1& b,
	const nsl_num_1& y1,const nsl_num_1& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLstep ***");
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
			c[i] = y2[i];
		else
			c[i] = y1[i];
	return c;
}
nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_1& b,
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
			c[i] = y2;
		else
			c[i] = y1;
	return c;
}
nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_1& b,
	const nsl_num_0& y1,const nsl_num_0& y2)
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
			c[i] = y2.get_data();
		else
			c[i] = y1.get_data();
	return c;
}
nsl_num_1 NSLstep(const nsl_num_1& a,const num_type b,
	const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = y2;
		else
			c[i] = y1;
	return c;
}
nsl_num_1 NSLstep(const nsl_num_1& a,const nsl_num_0& b,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = y2.get_data();
		else
			c[i] = y1.get_data();
	return c;
}
