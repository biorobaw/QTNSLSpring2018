/* SCCS  @(#)nsl_diff_euler_vector.C	1.1---95/10/13--16:37:21 */
//
// nsl_diff_euler_vector.C
//

#include "nsl_kernel.h"
#include "nsl_diff_euler_vector.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_vector_math.h"
#include "nsl_data_math.h"
#include "nsl_num.h"
#include "nsl_num_library.h"

nsl_diff_euler_vector::nsl_diff_euler_vector()
{
	init_diff_euler_vector();
}
nsl_diff_euler_vector::~nsl_diff_euler_vector()
{
}

int nsl_diff_euler_vector::init_diff_euler_vector()
{
	set_type("euler_vector"); // num_vector
 
	return 1;
}

int nsl_diff_euler_vector::exec(const num_type a)
{
	*((NslFloat1*) layer) = *((NslFloat1*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_vector::exec(const NslFloat0& a)
{
	*((NslFloat1*) layer) = *((NslFloat1*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_vector::exec(const NslFloat1& a)
{
 	*((NslFloat1*) layer) = *((NslFloat1*) layer) + p*a;
 
	return 1;
}
int nsl_diff_euler_vector::exec(const NslFloat2&)
{
	cmd_error("nsl_diff_euler_vector: Bad matrix to vector conversion");

	return 1;
}
int nsl_diff_euler_vector::exec(const NslFloat3&)
{
	cmd_error("nsl_diff_euler_vector: Bad 3 to vector conversion");

	return 1;
}
int nsl_diff_euler_vector::exec(const NslFloat4&)
{
	cmd_error("nsl_diff_euler_vector: Bad 4 to vector conversion");

	return 1;
}

extern void NSLmult_equal_FX(nsl_num_1& out,const nsl_num_1& a,
		const num_type& b);

extern void NSLmult_plus_FX(nsl_num_1& out,const nsl_num_1& a,const num_type& b);

int nsl_diff_euler_vector::run(nsl_layer* out,nsl_layer* in)
{
	const num_type p0 = dt/tm;
	num_type p1 = 1.0 - dt/tm;

	// m(t+dt) = (1-dt/tm)*m(t) + (dt/tm)*Sm
	NSLmult_equal_FX(*((nsl_num_1*) out), *((nsl_num_1*) out), p1);
	NSLmult_plus_FX(*((nsl_num_1*) out), *((nsl_num_1*) in), p0);

	return 1;
}

nsl_diff_method* nsl_diff_euler_vector::make_copy()
{
	return new nsl_diff_euler_vector;
}
