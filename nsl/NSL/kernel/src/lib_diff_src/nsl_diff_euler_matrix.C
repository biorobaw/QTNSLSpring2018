/* SCCS  @(#)nsl_diff_euler_matrix.C	1.1---95/10/13--16:37:20 */
//
// nsl_diff_euler_matrix.C
//

#include "nsl_diff_euler_matrix.h"
#include "nsl_kernel.h"
#include "nsl_matrix_math.h"
#include "nsl_num.h"
#include "nsl_num_library.h"

/* SCCS  @(#)nsl_diff_euler_matrix.C	1.1---95/10/13--16:37:20 */
//
// nsl_diff_euler_matrix.C
//

# include "nsl_all_kernel_include.h"

nsl_diff_euler_matrix::nsl_diff_euler_matrix()
{
	init_diff_euler_matrix();
}
nsl_diff_euler_matrix::~nsl_diff_euler_matrix()
{
}

int nsl_diff_euler_matrix::init_diff_euler_matrix()
{
	set_type("euler_matrix"); // num_matrix
 
	return 1;
}

int nsl_diff_euler_matrix::exec(const num_type a)
{
	*((NslFloat2*) layer) = *((NslFloat2*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_matrix::exec(const NslFloat0& a)
{
	*((NslFloat2*) layer) = *((NslFloat2*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_matrix::exec(const NslFloat1&)
{
	cmd_error("nsl_diff_euler_vector: Bad vector to matrix conversion");

	return 1;
}
int nsl_diff_euler_matrix::exec(const NslFloat2& a)
{
	*((NslFloat2*) layer) = *((NslFloat2*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_matrix::exec(const NslFloat3&)
{
	cmd_error("nsl_diff_euler_vector: Bad 3 to matrix conversion");

	return 1;
}
int nsl_diff_euler_matrix::exec(const NslFloat4& a)
{
	cmd_error("nsl_diff_euler_vector: Bad 4 to matrix conversion");

	return 1;
}

int nsl_diff_euler_matrix::run(nsl_layer* out,nsl_layer* in)
{
	num_type p0 = dt/tm;
	num_type p1 = 1.0 - dt/tm;
	
	// m(t+dt) = (1-dt/tm)*m(t) + (dt/tm)*Sm
    	NSLmult_equal(*((nsl_num_2*) out), *((nsl_num_2*) out), p1);
	NSLmult_plus(*((nsl_num_2*) out), *((nsl_num_2*) in), p0);

	return 1;
}

nsl_diff_method* nsl_diff_euler_matrix::make_copy()
{
	return new nsl_diff_euler_matrix;
}
