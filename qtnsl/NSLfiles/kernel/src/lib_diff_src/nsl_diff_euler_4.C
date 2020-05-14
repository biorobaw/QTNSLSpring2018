/* SCCS  @(#)nsl_diff_euler_4.C	1.1---95/10/13--16:37:20 */
//
// nsl_diff_euler_4.C
//

# include "nsl_diff_euler_4.h"
#include "nsl_num_4_library.h"
#include "nsl_num_4.h"
#include "nsl_num.h"

nsl_diff_euler_4::nsl_diff_euler_4()
{
	init_diff_euler_4();
}
nsl_diff_euler_4::~nsl_diff_euler_4()
{
}

int nsl_diff_euler_4::init_diff_euler_4()
{
	set_type("euler_4"); // num_matrix

	return 1;
}

int nsl_diff_euler_4::exec(const num_type a)
{
	*((NslFloat4*) layer) = *((NslFloat4*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_4::exec(const NslFloat0& a)
{
	*((NslFloat4*) layer) = *((NslFloat4*) layer) + (p*a.get_value());

	return 1;
}
int nsl_diff_euler_4::exec(const NslFloat1&)
{
	cmd_error("nsl_diff_euler_4: Bad vector to 4 conversion");

	return 1;
}
int nsl_diff_euler_4::exec(const NslFloat2& a)
{
	cmd_error("nsl_diff_euler_4: Bad matrix to 4 conversion");

	return 1;
}
int nsl_diff_euler_4::exec(const NslFloat3& a)
{
	cmd_error("nsl_diff_euler_4: Bad 3 to 4 conversion");

	return 1;
}
int nsl_diff_euler_4::exec(const NslFloat4& a)
{
	*((NslFloat4*) layer) = *((NslFloat4*) layer) + p*a;

	return 1;
}

int nsl_diff_euler_4::run(nsl_layer* out,nsl_layer* in)
{
	num_type p0 = dt/tm;
	num_type p1 = 1.0 - dt/tm;

	// m(t+dt) = (1-dt/tm)*m(t) + (dt/tm)*Sm
    NSLmult_equal(*((NslFloat4*) out), *((NslFloat4*) out), p1);
	NSLmult_plus(*((NslFloat4*) out), *((NslFloat4*) in), p0);

	return 1;
}

nsl_diff_method* nsl_diff_euler_4::make_copy()
{
	return new nsl_diff_euler_4;
}
