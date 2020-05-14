/* SCCS  @(#)nsl_vector_add_library.C	1.1---95/08/13--20:48:18 */
//
//	nsl_vector_add_library.C
//
#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

nsl_num_1 operator+(const nsl_num_1& a)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator+\n";
	cout << "// (vector) " << " = (vector) ";
	cout << a.get_name() << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i];

	return c;
}
nsl_num_1 operator+(const nsl_num_1& a,const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator+\n";
	cout << "// (vector) " << a.get_name() << " + (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();
	int bimax = b.get_imax();

	nsl_num_1 c(aimax);

	if (aimax != bimax)
	{
		cmd_error("*** nsl_num_1::operator+ ***");
		cmd_error("Exit with status:");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] + b[i];

	return c;
}
nsl_num_1 operator+(const nsl_num_1& a,const num_type b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator+\n";
	cout << "// (vector) " << a.get_name() << " + (num_type) ";
	cout << b << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] + b;

	return c;
}
nsl_num_1 operator+(const num_type a, const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator+\n";
	cout << "// (num_type) " << a << " + (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a + b[i];

	return c;
}
nsl_num_1 operator+(const nsl_num_1& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator+\n";
	cout << "// (vector) " << a.get_name() << " + (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] + b.get_data();

	return c;
}
nsl_num_1 operator+(const nsl_num_0& a, const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator+\n";
	cout << "// (data) " << a.get_name() << " + (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a.get_data() + b[i];

	return c;
}

// vector addition

nsl_num_1 NSLadd(const nsl_num_1& a)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i];

	return c;
}
nsl_num_1 NSLadd(const nsl_num_1& a,const nsl_num_1& b)
{
	int aimax = a.get_imax();
	int bimax = b.get_imax();

	nsl_num_1 c(aimax);

	if (aimax != bimax)
	{
		cmd_error("*** nsl_num_1::NSLadd ***");
		cmd_error("Exit with status:");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] + b[i];

	return c;
}
nsl_num_1 NSLadd(const nsl_num_1& a,const num_type b)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] + b;

	return c;
}
nsl_num_1 NSLadd(const num_type a, const nsl_num_1& b)
{
	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a + b[i];

	return c;
}
nsl_num_1 NSLadd(const nsl_num_1& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] + b.get_data();

	return c;
}
nsl_num_1 NSLadd(const nsl_num_0& a, const nsl_num_1& b)
{
	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a.get_data() + b[i];

	return c;
}

