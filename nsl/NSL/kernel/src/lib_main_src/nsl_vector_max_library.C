/* SCCS  @(#)nsl_vector_max_library.C	1.1---95/08/13--20:48:24 */
//
//	nsl_vector_max_library.C
//

#include "nsl_num.h"
#include "nsl_num_library.h"
#include "nsl_num_vector.h"
#include "nsl_num_data.h"
#include "nsl_vector_math.h"
#include "nsl_data_math.h"

extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

num_type NSLmax(const nsl_num_1& a) 
{
	int s1 = a.get_imax();

	nsl_num_0 c;//changed nsl_num_data to nsl_num_0
	c = 0;

	for (int i = 0; i < s1; i++)
		if (a[i] > c)
			c = a[i];

	return c.get_data();
}

// if a > b then a else b

nsl_num_1 NSLmax(const nsl_num_1& a,const nsl_num_1& b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	if (a.get_imax() != b.get_imax())
	{
		cmd_error("*** NSLsat ***");
		cmd_error("Exit with the following status");
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b.get_imax());
		cmd_error("bad vector sector");
		return c;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b[i])
			c[i] = a[i];
		else
			c[i] = b[i];
	return c;
}
nsl_num_1 NSLmax(const nsl_num_1& a,const nsl_num_0& b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i];
		else
			c[i] = b.get_data();
	return c;
}
nsl_num_1 NSLmax(const nsl_num_1& a,const num_type b)
{
	int s1 = a.get_imax();
	nsl_num_1 c(s1);

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i];
		else
			c[i] = b;
	return c;
}
