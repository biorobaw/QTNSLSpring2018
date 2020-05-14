/* SCCS  @(#)nsl_diff_euler_3.C	1.1---95/10/13--16:37:20 */
//
// nsl_diff_euler_3.C
//

# include "nsl_diff_euler_3.h"
#include "nsl_num.h"
#include "nsl_num_3_library.h"
#include "nsl_num_3.h"

extern void NSLmult_equal(nsl_num_3& out,const nsl_num_3& a,
		const num_type& b);

nsl_diff_euler_3::nsl_diff_euler_3()
{
	init_diff_euler_3();
}
nsl_diff_euler_3::~nsl_diff_euler_3()
{
}

int nsl_diff_euler_3::init_diff_euler_3()
{
	set_type("euler_3"); // num_3

	return 1;
}

int nsl_diff_euler_3::exec(const num_type a)
{
	*((NslFloat3*) layer) = *((NslFloat3*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_3::exec(const NslFloat0& a)
{
	*((NslFloat3*) layer) = *((NslFloat3*) layer) + (p*a.get_data());

	return 1;
}
int nsl_diff_euler_3::exec(const NslFloat1&)
{
	cmd_error("nsl_diff_euler_3: Bad vector to 3 conversion");

	return 1;
}
int nsl_diff_euler_3::exec(const NslFloat2& a)
{
	cmd_error("nsl_diff_euler_3: Bad matrix to 3 conversion");

	return 1;
}
int nsl_diff_euler_3::exec(const NslFloat3& a)
{
	*((NslFloat3*) layer) = *((NslFloat3*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_3::exec(const NslFloat4& a)
{
	cmd_error("nsl_diff_euler_3: Bad 4 to 3 conversion");

	return 1;
}

int nsl_diff_euler_3::run(nsl_layer* out,nsl_layer* in)
{
	num_type p0 = dt/tm;
	num_type p1 = 1.0 - dt/tm;

	// m(t+dt) = (1-dt/tm)*m(t) + (dt/tm)*Sm
    NSLmult_equal(*((NslFloat3*) out), *((NslFloat3*) out), p1);
	NSLmult_plus(*((NslFloat3*) out), *((NslFloat3*) in), p0);

	return 1;
}

nsl_diff_method* nsl_diff_euler_3::make_copy()
{
	return new nsl_diff_euler_3;
}
