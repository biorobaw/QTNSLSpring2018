/* SCCS  @(#)nsl_diff_euler.C	1.1---95/10/13--16:37:19 */
//
// nsl_diff_euler.C
//

#include "nsl_diff_euler.h"
#include "nsl_num_vector.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_vector_math.h"
#include "nsl_matrix_math.h"
#include "nsl_num.h"
#include "nsl_num_3.h"
#include "nsl_num_4.h"
#include "nsl_num_library.h"
#include "nsl_num_3_library.h"
#include "nsl_num_4_library.h"

extern void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
		 num_type& b);

extern void cmd_error(const char *);


nsl_diff_euler::nsl_diff_euler()
{
	init_diff_euler();
}
nsl_diff_euler::~nsl_diff_euler()
{
}
int nsl_diff_euler::init()
{
	if (tm == 0.0)
		cmd_error("nsl_diff_euler: Division by 0");
	else
		p = dt/tm;

	return 1;
}
int nsl_diff_euler::init_diff_euler()
{
	set_name("EULER");
	set_type("euler");
	p = 0.0;
 
	return 1;
}

int nsl_diff_euler::exec(const num_type)
{
	cmd_error("nsl_diff_euler: virtual num_type exec");

	return 1;
}
int nsl_diff_euler::exec(const NslFloat0&)
{
	cmd_error("nsl_diff_euler: virtual nsl_num_0 exec");

	return 1;
}
int nsl_diff_euler::exec(const NslFloat1&)
{
	cmd_error("nsl_diff_euler: virtual nsl_num_1 exec");

	return 1;
}
int nsl_diff_euler::exec(const NslFloat2&)
{
	cmd_error("nsl_diff_euler: virtual nsl_num_2 exec");

	return 1;
}
int nsl_diff_euler::exec(const NslFloat3&)
{
	cmd_error("nsl_diff_euler: virtual nsl_num_3 exec");

	return 1;
}
int nsl_diff_euler::exec(const NslFloat4&)
{
	cmd_error("nsl_diff_euler: virtual nsl_num_4 exec");

	return 1;
}


int nsl_diff_euler::execute(num_type m, num_type tm0, num_type dt0,
	const num_type a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0;

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat0& m, num_type tm0, num_type dt0,
	const NslFloat0& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0;

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat0& m, NslFloat0& tm0, num_type dt0,
	const NslFloat0& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0.elem();

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat1& m, num_type tm0, num_type dt0,
	const NslFloat1& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	float p0 = dt0/tm0;

	m = ((nsl_num_1&)m) + (a*p0);

	return 1;
}
int nsl_diff_euler::execute(NslFloat1& m, NslFloat0& tm0, num_type dt0,
	const NslFloat1& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0.elem();

	m = ((nsl_num_1&)m) + (a*p0);

	return 1;
}

int nsl_diff_euler::execute(NslFloat2& m, num_type tm0, num_type dt0,
	const NslFloat2& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0;

	NSLmult_plus((nsl_num_2&)m,(nsl_num_2&)a,p0);	//	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat2& m, NslFloat0& tm0, num_type dt0,
	const NslFloat2& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0.elem();

	NSLmult_plus((nsl_num_2&)m,(nsl_num_2&)a,p0);	//	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat3& m, num_type tm0, num_type dt0,
	const NslFloat3& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0;

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat3& m, NslFloat0& tm0, num_type dt0,
	const NslFloat3& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0.elem();

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat4& m, num_type tm0, num_type dt0,
	const NslFloat4& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0;

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::execute(NslFloat4& m, NslFloat0& tm0, num_type dt0,
	const NslFloat4& a)
{
	if (tm0 == 0) {
		cmd_error("nsl_diff_euler: Division by 0");
		return 0;
	}

	num_type p0 = dt0/tm0.elem();

	m = m + a*p0;

	return 1;
}
int nsl_diff_euler::run(nsl_layer*,nsl_layer*) {
	cmd_error("nsl_diff_euler::run");
	return 0;
}

nsl_diff_method* nsl_diff_euler::make_copy() {
	return new nsl_diff_euler;
}

