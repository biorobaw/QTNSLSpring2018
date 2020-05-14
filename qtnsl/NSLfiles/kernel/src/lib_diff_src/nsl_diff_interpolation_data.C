/* SCCS  @(#)nsl_diff_interpolation_data.C	1.1---95/10/13--16:37:21 */
//	
//  nsl_diff_interpolation_data.C
//

#include "nsl_diff_interpolation_data.h"
#include "nsl_num.h"
#include "nsl_data_math.h"


nsl_diff_interpolation_data::nsl_diff_interpolation_data()
{
	init_diff_interpolation_data();
}
nsl_diff_interpolation_data::~nsl_diff_interpolation_data()
{
}

int nsl_diff_interpolation_data::init_diff_interpolation_data()
{
	set_type("interpolation_data"); // num_data
 
	return 1;
}

int nsl_diff_interpolation_data::exec(const num_type a)
{
	*((NslFloat0*) layer) = *((NslFloat0*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_data::exec(const NslFloat0& a)
{
	*((NslFloat0*) layer) = *((NslFloat0*) layer) + (1-p)*a;

	return 1;
}
int nsl_diff_interpolation_data::exec(const NslFloat1&)
{
 	cmd_error("nsl_diff_euler_data: Bad vector to data conversion");

	return 1;
}
int nsl_diff_interpolation_data::exec(const NslFloat2&)
{
 	cmd_error("nsl_diff_euler_data: Bad matrix to data conversion");

	return 1;
}
int nsl_diff_interpolation_data::exec(const NslFloat3&)
{
 	cmd_error("nsl_diff_euler_data: Bad vector to data conversion");

	return 1;
}
int nsl_diff_interpolation_data::exec(const NslFloat4&)
{
 	cmd_error("nsl_diff_euler_data: Bad matrix to data conversion");

	return 1;
}

int nsl_diff_interpolation_data::run(nsl_layer* out,nsl_layer* in)
{
	return 1;
}

nsl_diff_method* nsl_diff_interpolation_data::make_copy()
{
	return new nsl_diff_interpolation_data;
}
