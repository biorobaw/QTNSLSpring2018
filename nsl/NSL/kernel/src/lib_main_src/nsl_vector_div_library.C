/* SCCS  @(#)nsl_vector_div_library.C	1.1---95/08/13--20:48:21 */
//
//	nsl_vector_div_library.C
//
#include "nsl_num.h"
#include "nsl_vector_math.h"

extern void cmd_error(const char *);
// vector pointwise division

nsl_num_1 operator/(const nsl_num_1& a,const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator/\n";
	cout << "// (vector) " << a.get_name() << " / (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();
	int bimax = b.get_imax();

	nsl_num_1 c(aimax);

	if (aimax != bimax)
	{
		cmd_error("*** nsl_num_1::operator/ ***");
		cmd_error("Exit with status:");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
		if (b[i] != 0)
			c[i] = a[i] / b[i];
		else
		{
			cmd_error("*** nsl_num_1::operator/ ***");
			a.print_status(std::cerr);
			b.print_status(std::cerr);
			return c;
		}			

	return c;
}
nsl_num_1 operator/(const nsl_num_1& a,const num_type b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator/\n";
	cout << "// (vector) " << a.get_name() << " / (num_type) ";
	cout << b << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	if (b == 0)
	{
		cmd_error("*** nsl_num_1::operator/ ***");
		a.print_status(std::cerr);
		return c;
	}

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] / b;

	return c;
}
nsl_num_1 operator/(const num_type a, const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator/\n";
	cout << "// (num_type) " << a << " / (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		if (b[i] != 0)
			c[i] = a / b[i];
		else
		{
			cmd_error("*** nsl_num_1::operator/ ***");
			b.print_status(std::cerr);
			return c;
		}			

	return c;
}
nsl_num_1 operator/(const nsl_num_1& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator/\n";
	cout << "// (vector) " << a.get_name() << " / (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	if (b == 0)
	{
		cmd_error("*** nsl_num_1::operator/ ***");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		return c;
	}

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] / b.get_data();

	return c;
}
nsl_num_1 operator/(const nsl_num_0& a, const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator/\n";
	cout << "// (data) " << a.get_name() << " / (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		if (b[i] != 0)
			c[i] = a.get_data() / b[i];
		else
		{
			cmd_error("*** nsl_num_1::operator/ ***");
			a.print_status(std::cerr);
			b.print_status(std::cerr);
			return c;
		}	

	return c;
}

// vector pointwise division

nsl_num_1 NSLdiv(const nsl_num_1& a,const nsl_num_1& b)
{
	int aimax = a.get_imax();
	int bimax = b.get_imax();

	nsl_num_1 c(aimax);

	if (aimax != bimax)
	{
		cmd_error("*** nsl_num_1::NSLdiv ***");
		cmd_error("Exit with status:");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
		if (b[i] != 0)
			c[i] = a[i] / b[i];
		else
		{
			cmd_error("*** nsl_num_1::operator/ ***");
			a.print_status(std::cerr);
			b.print_status(std::cerr);
			return c;
		}	

	return c;
}
nsl_num_1 NSLdiv(const nsl_num_1& a,const num_type b)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	if (b == 0)
	{
		cmd_error("*** nsl_num_1::operator/ ***");
		a.print_status(std::cerr);
		return c;
	}

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] / b;

	return c;
}
nsl_num_1 NSLdiv(const num_type a, const nsl_num_1& b)
{
	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		if (b[i] != 0)
			c[i] = a / b[i];
		else
		{
			cmd_error("*** nsl_num_1::operator/ ***");
			b.print_status(std::cerr);
			return c;
		}	

	return c;
}
nsl_num_1 NSLdiv(const nsl_num_1& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	if (b == 0)
	{
		cmd_error("*** nsl_num_1::operator/ ***");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		return c;
	}

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] / b.get_data();

	return c;
}
nsl_num_1 NSLdiv(const nsl_num_0& a, const nsl_num_1& b)
{
	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		if (b[i] != 0)
			c[i] = a.get_data() / b[i];
		else
		{
			cmd_error("*** nsl_num_1::operator/ ***");
			b.print_status(std::cerr);
			return c;
		}	

	return c;
}

