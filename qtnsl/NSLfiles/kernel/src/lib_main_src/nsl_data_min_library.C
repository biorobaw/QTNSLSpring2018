/* SCCS  @(#)nsl_data_min_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_data_min_library.C
//

#include "nsl_num.h"
#include "nsl_data_math.h"


// if a < b then a else 0

nsl_num_0 NSLmin(const nsl_num_0& a,const nsl_num_0& b)
{
	nsl_num_0 c;
	if (a.get_data() < b.get_data())
	    c = a;
	else
	    c = b;
	return c;
}
nsl_num_0 NSLmin(const nsl_num_0& a,const num_type b)
{
	nsl_num_0 c;
	if (a.get_data() < b)
	    c = a;
	else
	    c = b;
	return c;
}

