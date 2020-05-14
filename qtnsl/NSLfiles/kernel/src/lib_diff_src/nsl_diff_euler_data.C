/* SCCS  @(#)nsl_diff_euler_data.C	1.1---95/10/13--16:37:20 */
//
// nsl_diff_euler_data.C
//

#include "nsl_diff_euler_data.h"
#include "nsl_layer.h"
#include "nsl_data_math.h"
#include "nsl_num.h"
#include "nsl_num_library.h"


nsl_diff_euler_data::nsl_diff_euler_data()
{
	init_diff_euler_data();
}
nsl_diff_euler_data::~nsl_diff_euler_data()
{
}

int nsl_diff_euler_data::init_diff_euler_data()
{
	set_type("euler_data"); // num_data
 
	return 1;
}

int nsl_diff_euler_data::exec(const num_type a)
{
	*((NslFloat0*) layer) = *((NslFloat0*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_data::exec(const NslFloat0& a)
{
	*((NslFloat0*) layer) = *((NslFloat0*) layer) + p*a;

	return 1;
}
int nsl_diff_euler_data::exec(const NslFloat1&)
{
	cmd_error("nsl_diff_euler_data: Bad vector to data conversion");

	return 1;
}
int nsl_diff_euler_data::exec(const NslFloat2&)
{
	cmd_error("nsl_diff_euler_data: Bad vector to data conversion");

	return 1;
}
int nsl_diff_euler_data::exec(const NslFloat3&)
{
	cmd_error("nsl_diff_euler_data: Bad vector to data conversion");

	return 1;
}
int nsl_diff_euler_data::exec(const NslFloat4&)
{
	cmd_error("nsl_diff_euler_data: Bad vector to data conversion");

	return 1;
}
int nsl_diff_euler_data::run(nsl_layer* out,nsl_layer* in)
{
	num_type p0 = dt/tm;
	num_type p1 = 1.0 - dt/tm;
	
	// m(t+dt) = (1-dt/tm)*m(t) + (dt/tm)*Sm
    	NSLmult_equal(*((NslFloat0*) out), *((NslFloat0*) out), p1);
	NSLmult_plus(*((NslFloat0*) out), *((NslFloat0*) in), p0);

	return 1;
}

nsl_diff_method* nsl_diff_euler_data::make_copy()
{
	return new nsl_diff_euler_data;
}
