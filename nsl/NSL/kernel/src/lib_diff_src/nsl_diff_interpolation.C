/* SCCS  @(#)nsl_diff_interpolation.C	1.1---95/10/13--16:37:21 */
//	
//  nsl_diff_interpolation.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_num.h"
#include "nsl_diff_interpolation.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_data_math.h"
#include "nsl_matrix_math.h"
#include "nsl_vector_math.h"
#include "nsl_num_library.h"
#include "nsl_num_3_library.h"
#include "nsl_num_4_library.h"
#include "nsl_num_3.h"
#include "nsl_num_4.h"
#include <cmath>

/* SCCS  @(#)nsl_diff_interpolation.C	1.1---95/10/13--16:37:21 */
//
//  nsl_diff_interpolation.C
//

# include "nsl_all_kernel_include.h"

nsl_diff_interpolation::nsl_diff_interpolation()
{
	init_diff_interpolation();
}
nsl_diff_interpolation::~nsl_diff_interpolation()
{
}
int nsl_diff_interpolation::init()
{
	if (tm == 0.0)
		cmd_error("nsl_diff_interpolation: Division by 0");
	else
 		p = exp((num_type)-dt/tm);
	
	return 1;
}
int nsl_diff_interpolation::init_diff_interpolation()
{
	set_name("INTERPOLATION");
	set_type("interpolation");
	p = 0.0;

 	return 1;
}

int nsl_diff_interpolation::exec(const num_type)
{
 	cmd_error("nsl_diff_interpolation: virtual num_type exec");

	return 1;
}
int nsl_diff_interpolation::exec(const NslFloat0&)
{
 	cmd_error("nsl_diff_interpolation: virtual nsl_num_0 exec");

	return 1;
}
int nsl_diff_interpolation::exec(const NslFloat1&)
{
 	cmd_error("nsl_diff_interpolation: virtual nsl_num_1 exec");

	return 1;
}
int nsl_diff_interpolation::exec(const NslFloat2&)
{
 	cmd_error("nsl_diff_interpolation: virtual nsl_num_2 exec");

	return 1;
}
int nsl_diff_interpolation::exec(const NslFloat3&)
{
 	cmd_error("nsl_diff_interpolation: virtual nsl_num_3 exec");

	return 1;
}
int nsl_diff_interpolation::exec(const NslFloat4&)
{
 	cmd_error("nsl_diff_interpolation: virtual nsl_num_4 exec");

	return 1;
}
int nsl_diff_interpolation::execute(num_type m, num_type tm0, 
	num_type dt0, const num_type a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0);
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat0& m, num_type tm0,
	num_type dt0, const NslFloat0& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0);

	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat0& m, NslFloat0& tm0,
	num_type dt0, const NslFloat0& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0.elem());

	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat1& m, num_type tm0,
	num_type dt0, const NslFloat1& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0);

	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat1& m, NslFloat0& tm0,
	num_type dt0, const NslFloat1& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0.elem());

	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat2& m, num_type tm0,
	num_type dt0, const NslFloat2& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0);
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat2& m, NslFloat0& tm0,
	num_type dt0, const NslFloat2& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0.elem());
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat3& m, num_type tm0,
	num_type dt0, const NslFloat3& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0);
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat3& m, NslFloat0& tm0,
	num_type dt0, const NslFloat3& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0.elem());
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat4& m, num_type tm0,
	num_type dt0, const NslFloat4& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0);
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::execute(NslFloat4& m, NslFloat0& tm0,
	num_type dt0, const NslFloat4& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_interpolation: Division by 0");
		return 0;
	}

 	num_type p0 = exp((num_type)-dt0/tm0.elem());
	
	m = m + a*(1-p0);

	return 1;
}
int nsl_diff_interpolation::run(nsl_layer*,nsl_layer*) {
	cmd_error("nsl_diff_interpolation::run");
	return 0;
}

nsl_diff_method* nsl_diff_interpolation::make_copy() {
	return new nsl_diff_interpolation;
}
