/* SCCS  @(#)nsl_data_div_library.C	1.1---95/08/13--20:48:13 */
//
//	nsl_data_div_library.C
//

#include "nsl_num_data.h"
#include "nsl_num_0.h"

nsl_num_0 operator/(const nsl_num_0& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator/\n";
	cout << "// (data) " << a.get_name() << " / (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	num_type d;
	if ((d = b.get_data()) != 0)
		c = a.get_data() / d;
	else
		cmd_error("DIVISION by 0");
	return c;
}
nsl_num_0 operator/(const nsl_num_0& a,const num_type b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator/\n";
	cout << "// (data) " << a.get_name() << " / (num_type) ";
	cout << b << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	if (b != 0)
		c = a.get_data() / b;
	else
		cmd_error("DIVISION by 0");
	return c;
}
nsl_num_0 operator/(const num_type a, const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator/\n";
	cout << "// (num_type) " << a << " / (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	num_type d;
	if ((d = b.get_data()) != 0)
		c = a / d;
	else
		cmd_error("DIVISION by 0");
	return c;
}

