/* SCCS  @(#)nsl_vector_gauss_library.C	1.1---95/08/13--20:48:24 */
//
//	nsl_vector_gauss_library.C
//

#include "nsl_vector_math.h"
#include "nsl_num.h"
#include <cmath>


nsl_num_1 NSLgauss(const nsl_num_0& sig,const int xn)
{
	nsl_num_1 c(xn);
	float m = xn/2;

	for (int i=0; i < xn; i++)
	    c.elem(i) = (float) exp(-(i-m)*(i-m)/
			(2*sig.get_data()*sig.get_data()));

	return c;
}

