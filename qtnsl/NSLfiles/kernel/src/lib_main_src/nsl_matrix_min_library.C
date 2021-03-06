/* SCCS  @(#)nsl_matrix_min_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_matrix_min_library.C
//

#include "nsl_num.h"
#include "nsl_matrix_math.h"
#include "nsl_data_math.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;


extern void cmd_error(const char *, int);
extern void cmd_error(const char *);

num_type NSLmin(const nsl_num_2& a) 
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();

	nsl_num_0 c;
	c = 0;

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] < c)
			c = a[i][j];
	return c.get_data();
}

// if a < b then a else b

nsl_num_2 NSLmin(const nsl_num_2& a,const nsl_num_2& b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();
	nsl_num_2 c(s1,s2);

	if (a.get_imax() != b.get_imax() || a.get_jmax() != b.get_jmax())
	{
		cmd_error("*** NSLsat ***");
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
		if (a[i][j] < b[i][j])
			c[i][j] = a[i][j];
		else
			c[i][j] = b[i][j];
	return c;
}
nsl_num_2 NSLmin(const nsl_num_2& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();

	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] < b)
			c[i][j] = a[i][j];
		else
			c[i][j] = b.get_data();
	return c;
}
nsl_num_2 NSLmin(const nsl_num_2& a,const num_type b)
{
	int s1 = a.get_imax();
	int s2 = a.get_jmax();

	nsl_num_2 c(s1,s2);

	for (int i = 0; i < s1; i++)
	   for (int j = 0; j < s2; j++)
		if (a[i][j] < b)
			c[i][j] = a[i][j];
		else
			c[i][j] = b;
	return c;
}

