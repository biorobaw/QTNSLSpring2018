/* SCCS  @(#)nsl_matrix_div_library.C	1.1---95/08/13--20:48:15 */
//
//	nsl_matrix_div_library.C
//

#include "nsl_data_math.h"
#include "nsl.h"
#include "nsl_num.h"
#include "nsl_num_library.h"
#include <fstream>


extern void cmd_error(const char *);

// matrix pointwise division

nsl_num_2 operator/(const nsl_num_2& a,const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator/\n";
        cout << "// (matrix) " << a.get_name() << " / (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("*** nsl_num_2::operator/ ***");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
	   {
		if (b[i][j] == 0)
		{
			cmd_error("*** nsl_num_2::operator/ ***");
			b.print_status(std::cerr);
			b.print(std::cerr);
			cmd_error("Division by zero");
			return c;
		}
		c[i][j] = a[i][j] / b[i][j];
	   }

	return c;
}
nsl_num_2 operator/(const nsl_num_2& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator/\n";
        cout << "// (matrix) " << a.get_name() << " / (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	if (b == 0)
	{
		cmd_error("*** nsl_num_2::operator/ ***");
		cmd_error("b: ",b);
		cmd_error("Division by zero");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] / b;

	return c;
}
nsl_num_2 operator/(const num_type a,const  nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator/\n";
        cout << "// (num_type) " << a << " / (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
	   {
		if (b[i][j] == 0)
		{
			cmd_error("*** nsl_num_2::operator/ ***");
			cmd_error("Exit with the following status");
			b.print_status(std::cerr);
			b.print(std::cerr);
			cmd_error("Division by zero");
			return c;
		}
		c[i][j] = a / b[i][j];
	   }

	return c;
}
nsl_num_2 operator/(const nsl_num_2& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator/\n";
        cout << "// (matrix) " << a.get_name() << " / (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	num_type   Vb = b.get_data();

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	if (b == 0.f)
	{
		cmd_error("*** nsl_num_2::operator/ ***");
		b.print_status(std::cerr);
		b.print(std::cerr);
		cmd_error("Division by zero");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] / b.get_data();

	return c;
}
nsl_num_2 operator/(const nsl_num_0& a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator/\n";
        cout << "// (data) " << a.get_name() << " / (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
	   {
		if (b[i][j] == 0)
		{
			cmd_error("*** nsl_num_2::operator/ ***");
			b.print_status(std::cerr);
			b.print(std::cerr);
			cmd_error("Division by zero");
			return c;
		}
		c[i][j] = a.get_data() / b[i][j];
	   }

	return c;
}


// matrix pointwise division

nsl_num_2 NSLdiv(const nsl_num_2& a,const nsl_num_2& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("*** nsl_num_2::NSLdiv ***");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		if (b[i][j] != 0)
			c[i][j] = a[i][j] / b[i][j];
		else
		{
			cmd_error("*** nsl_num_2::NSLdiv ***");
			b.print_status(std::cerr);
			b.print(std::cerr);			
			cmd_error("DIVISION by 0");
			return c;
		}

	return c;
}
nsl_num_2 NSLdiv(const nsl_num_2& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	if (b == 0)
	{
		cmd_error("*** nsl_num_2::NSLdiv ***");	
		cmd_error("DIVISION by 0");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] / b;

	return c;
}
nsl_num_2 NSLdiv(const num_type a, const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		if (b[i][j] != 0)
			c[i][j] = a / b[i][j];
		else
		{
			cmd_error("*** nsl_num_2::NSLdiv ***");
			b.print_status(std::cerr);
			b.print(std::cerr);			
			cmd_error("DIVISION by 0");
			return c;
		}

	return c;
}
nsl_num_2 NSLdiv(const nsl_num_2& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	if (b == 0.f)
	{
		cmd_error("*** nsl_num_2::NSLdiv ***");
		b.print_status(std::cerr);
		b.print(std::cerr);			
		cmd_error("DIVISION by 0");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] / b.get_data();

	return c;
}
nsl_num_2 NSLdiv(const nsl_num_0& a, const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		if (b[i][j] != 0)
			c[i][j] = a.get_data() / b[i][j];
		else
		{
			cmd_error("*** nsl_num_2::NSLdiv ***");
			b.print_status(std::cerr);
			b.print(std::cerr);			
			cmd_error("DIVISION by 0");
			return c;
		}

	return c;
}

