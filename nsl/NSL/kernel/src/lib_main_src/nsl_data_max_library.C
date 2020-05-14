/* SCCS  @(#)nsl_data_max_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_data_max_library.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_num_data.h"
#include "nsl_num.h"
#include "nsl_data_math.h"
// if a > b then a else 0

nsl_num_0 NSLmax(const nsl_num_0& i,const nsl_num_0& k)
{
	nsl_num_0 &b = const_cast<nsl_num_0&>(k);
	nsl_num_0 &a = const_cast<nsl_num_0&>(i);

	nsl_num_0 c;
	if (a > b)
	    c = a;
	else
	    c = b;
	return c;
}
nsl_num_0 NSLmax(const nsl_num_0& a,const num_type b)
{
	nsl_num_0 c;
	if (a > b)
	    c = a;
	else
	    c = b;
	return c;
}

