/* SCCS  @(#)nsl_diff_interpolation_matrix.C	1.1---95/10/13--16:37:22 */
//	
//  nsl_diff_interpolation_matrix.C
//

#include "nsl_diff_interpolation_matrix.h"
#include "nsl_matrix_math.h"
#include "nsl_layer.h"
#include "nsl_num.h"

nsl_diff_interpolation_matrix::nsl_diff_interpolation_matrix()
{
	init_diff_interpolation_matrix();
}
nsl_diff_interpolation_matrix::~nsl_diff_interpolation_matrix()
{
}

int nsl_diff_interpolation_matrix::init_diff_interpolation_matrix()
{
	set_type("interpolation_matrix"); // num_matrix
 
	return 1;
}

int nsl_diff_interpolation_matrix::exec(const num_type a)
{    
	*((NslFloat2*) layer) = *((NslFloat2*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_matrix::exec(const NslFloat0& a)
{    
	*((NslFloat2*) layer) = *((NslFloat2*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_matrix::exec(const NslFloat1&)
{
 	cmd_error("nsl_diff_euler_data: Bad vector to matrix conversion");

	return 1;
}
int nsl_diff_interpolation_matrix::exec(const NslFloat2& a)
{
	*((NslFloat2*) layer) = *((NslFloat2*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_matrix::exec(const NslFloat3&)
{
 	cmd_error("nsl_diff_euler_data: Bad num_3 to matrix conversion");

	return 1;
}
int nsl_diff_interpolation_matrix::exec(const NslFloat4&)
{    
 	cmd_error("nsl_diff_euler_data: Bad num_4 to matrix conversion");

	return 1;
}

int nsl_diff_interpolation_matrix::run(nsl_layer* out,nsl_layer* in)
{
	return 1;
}

nsl_diff_method* nsl_diff_interpolation_matrix::make_copy()
{
	return new nsl_diff_interpolation_matrix;
}
