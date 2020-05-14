/* SCCS  @(#)nsl_matrix_expdecay_library.C	1.1---95/08/13--20:48:15 */
//
//	nsl_matrix_expdecay_library.C
//

#include <cmath>
#include "nsl.h"
#include "nsl_num_matrix.h"
#include "nsl_num_data.h"
#include "nsl_model.h"
#include "nsl_system.h"
#include "nsl_num_2.h"
#include "nsl_num_0.h"

extern void cmd_error(const char *);

nsl_num_2 NSLexpdecay(nsl_num_2& T,nsl_num_0& kx1)
{
        int imax = T.get_imax();
        int jmax = T.get_jmax();

	nsl_num_2 Q(imax,jmax);

        int i0 = T.get_i0();
        int i1 = T.get_i1();
        int j0 = T.get_j0();
        int j1 = T.get_j1();

	nsl_model* model = NSL_SYSTEM->get_model();

	if (model == NULL)
	{
		cmd_error("NSLexxpdecay: NULL model");
		return T;
	}

        num_type dt = model->getSimDelta();	//chagned from get_delta to getSimDelta -bn7

        int i,j;
        num_type val;
        
        for (i=i0; i<=i1; i++)
            for (j=j0; j<=j1; j++)
            {
                val = exp(-dt/kx1.elem());
                Q.elem(i,j) = val*T.elem(i,j);
            }

	return Q;
}

