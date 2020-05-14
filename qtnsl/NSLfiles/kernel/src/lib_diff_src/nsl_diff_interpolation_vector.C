/* SCCS  @(#)nsl_diff_interpolation_vector.C	1.1---95/10/13--16:37:22 */
//	
//  nsl_diff_interpolation_vector.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_diff_interpolation_vector.h"
#include "nsl_num_vector.h"
#include "../../incl/nsl.h"
#include "nsl_num.h"
#include "nsl_vector_math.h"

extern void cmd_error(const char *);

/* SCCS  @(#)nsl_diff_interpolation_vector.C	1.1---95/10/13--16:37:22 */
//
//  nsl_diff_interpolation_vector.C
//

# include "nsl_all_kernel_include.h"

nsl_diff_interpolation_vector::nsl_diff_interpolation_vector()
{
	init_diff_interpolation_vector();
}
nsl_diff_interpolation_vector::~nsl_diff_interpolation_vector()
{
}

int nsl_diff_interpolation_vector::init_diff_interpolation_vector()
{
	set_type("interpolation_vector"); // num_vector
 
	return 1;
}

int nsl_diff_interpolation_vector::exec(const num_type a)
{    
	*((NslFloat1*) layer) = *((NslFloat1*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_vector::exec(const NslFloat0& a)
{    
	*((NslFloat1*) layer) = *((NslFloat1*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_vector::exec(const NslFloat1& a)
{
 	*((NslFloat1*) layer) = *((NslFloat1*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_vector::exec(const NslFloat2&)
{
 	cmd_error("nsl_diff_euler_data: Bad matrix to data conversion");

	return 1;
}
int nsl_diff_interpolation_vector::exec(const NslFloat3&)
{
 	cmd_error("nsl_diff_euler_data: Bad matrix to data conversion");

	return 1;
}
int nsl_diff_interpolation_vector::exec(const NslFloat4&)
{
 	cmd_error("nsl_diff_euler_data: Bad matrix to data conversion");

	return 1;
}

int nsl_diff_interpolation_vector::run(nsl_layer* out,nsl_layer* in)
{
	return 1;
}

nsl_diff_method* nsl_diff_interpolation_vector::make_copy()
{
	return new nsl_diff_interpolation_vector;
}
