/* SCCS  @(#)nsl_matrix_kernel_library.C	1.1---95/08/13--20:48:15 */
//
//	nsl_matrix_kernel_library.C
//

#include <cmath>
#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"
#include "nsl_matrix_math.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

nsl_num_2 NSLkernel(const int imax,const int jmax,const nsl_num_0& dia,
	const nsl_num_0& sig,const nsl_num_0& wgt)
{
        int i,j;
	num_type r,rad;

	nsl_num_2 Q(imax,jmax);

//	int imax = Q.get_imax();
//	int jmax = Q.get_jmax();
	int imax2 = imax/2;
	int jmax2 = jmax/2;
        
    	num_type rad0 = dia.get_data()/2.0;
	num_type sum = 0.0;
  	if (dia.get_data() == 0.0)
		return Q;

        for (i=0; i<imax; i++)
            for (j=0; j<jmax; j++)
	    {
		/* r is in units of 1/2 degrees, same as kernel array */
		r = (num_type) sqrt((num_type)((i-imax2)*(i-imax2)) + 
			(num_type) ((j-jmax2)*(j-jmax2)));
		/* rad is in units of degrees */
		rad = r/2.0;
		if (rad < rad0)
	  	     Q.elem(i,j) = (num_type) 
			exp(-(rad*rad)/(2.0*sig.get_data()*sig.get_data()));
		sum = sum + Q.elem(i,j);
      	    }

	if (sum == 0.0)
		Q = 0;
	else
		Q = Q/sum*wgt;

	return Q;
}

 
