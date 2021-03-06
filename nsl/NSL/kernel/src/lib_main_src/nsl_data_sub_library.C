/* SCCS  @(#)nsl_data_sub_library.C	1.1---95/08/13--20:48:13 */
//
//	nsl_data_sub_library.C
//

#include "nsl_num_data.h"
#include "nsl_num_0.h"

using namespace std;

// nsl_num_0 subtruction

nsl_num_0 operator-(const nsl_num_0& a)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator-\n";
	cout << "// (data) "<< " = - (data) ";
	cout << a.get_name() << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	c = -a.get_data();
	return c;
}
nsl_num_0 operator-(const nsl_num_0& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator-\n";
	cout << "// (data) " << a.get_name() << " - (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	c = a.get_data() - b.get_data();
	return c;
}
nsl_num_0 operator-(const nsl_num_0& a,const num_type b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator-\n";
	cout << "// (data) " << a.get_name() << " - (num_type) ";
	cout << b << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	c = a.get_data() - b;
	return c;
}
nsl_num_0 operator-(const num_type a, const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_0  operator-\n";
	cout << "// (num_type) " << a << " - (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	nsl_num_0 c;
	c = a - b.get_data();
	return c;
}

