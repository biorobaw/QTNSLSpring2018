/* SCCS  @(#)nsl_data_ramp_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_data_ramp_library.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include "nsl_num.h"
#include "nsl_data_math.h"

// if a > 0 then a else 0

nsl_num_0 NSLramp(const nsl_num_0& a) 
{
	nsl_num_0 c;
	if (a > (num_type) 0)
		c = a;
	else
		c = 0;
	return c;
}

// if a > b then a - b else 0

nsl_num_0 NSLramp(const nsl_num_0& a,const num_type b)
{
	nsl_num_0 c;
	if (a > b)
		c = a - b;
	else
		c = 0;
	return c;
}
nsl_num_0 NSLramp(const nsl_num_0& i,const nsl_num_0& k)
{
	nsl_num_0 &b = const_cast<nsl_num_0&>(k);
	nsl_num_0 &a = const_cast<nsl_num_0&>(i);

	nsl_num_0 c;
	if (a > b)
		c = a.get_data() - b.get_data();
	else
		c = 0;
	return c;
}
nsl_num_0 NSLramp(const nsl_num_0& a,const num_type b,
	const num_type y1,const num_type y2)
{
	nsl_num_0 c;
	if (a > b)
		c = a - b + y2;
	else
		c = y1;
	return c;
}
nsl_num_0 NSLramp(const nsl_num_0& i,const nsl_num_0& k,
	const nsl_num_0& y1,const nsl_num_0& y2)
{
	nsl_num_0 c;

	nsl_num_0 &b = const_cast<nsl_num_0&>(k);
	nsl_num_0 &a = const_cast<nsl_num_0&>(i);

	if (a > b)
		c = a.get_data() - b.get_data() + y2.get_data();
	else
		c = y1;
	return c;
}

