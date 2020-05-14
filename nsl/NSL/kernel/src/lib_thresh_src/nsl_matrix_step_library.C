/* SCCS  @(#)nsl_matrix_step_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_matrix_step_library.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_num_matrix.h"
#include "nsl_matrix_math.h"
#include "nsl_num.h"


// if a > 0 then 1 else 0
extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

nsl_num_2 NSLstep(const nsl_num_2& a,
	const num_type b,const num_type y1,const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = y2;
		else
			c[i][j] = y1;
	return c;
}

// if a > b then 1 else 0

nsl_num_2 NSLstep(const nsl_num_2& a,const nsl_num_2& b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax())
	{
		cmd_error("*** NSLstep ***");
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
			c[i][j] = (num_type) 1;
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLstep(const nsl_num_2& a,const num_type b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = (num_type) 1;
		else
			c[i][j] = 0;
	return c;
}
nsl_num_2 NSLstep(const nsl_num_2& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = (num_type) 1;
		else
			c[i][j] = 0;
	return c;
}

// if a > b then y2 else y1

nsl_num_2 NSLstep(const nsl_num_2& a,const nsl_num_2& b,const nsl_num_2& y1,
	const nsl_num_2& y2)
{
	int s1 = b.get_imax();
	int s2 = b.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax() ||
	    a.get_imax() != y1.get_imax() || a.get_jmax() != y1.get_jmax() ||
	    a.get_imax() != y2.get_imax() || a.get_jmax() != y2.get_jmax())
	{
		cmd_error("*** NSLstep ***");
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
			c[i][j] = y2[i][j];
		else
			c[i][j] = y1[i][j];
	return c;
}
nsl_num_2 NSLstep(const nsl_num_2& a,const nsl_num_2& b,const nsl_num_0& y1,
	nsl_num_0& y2)
{
	int s1 = b.get_imax();
	int s2 = b.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax())
	{
		cmd_error("*** NSLstep ***");
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
			c[i][j] = y2.get_data();
		else
			c[i][j] = y1.get_data();
	return c;
}
/*
nsl_num_2 NSLstep(const nsl_num_2& a,const num_type b,const num_type y1,
	const num_type y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = y2;
		else
			c[i][j] = y1;
	return c;
}
*/
nsl_num_2 NSLstep(const nsl_num_2& a,const nsl_num_0& b,const nsl_num_0& y1,
	const nsl_num_0& y2)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] > b)
			c[i][j] = y2.get_data();
		else
			c[i][j] = y1.get_data();
	return c;
}
