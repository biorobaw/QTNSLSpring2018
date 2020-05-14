/* SCCS  @(#)nsl_matrix_mult_library.C	1.1---95/08/13--20:48:16 */
//
//	nsl_matrix_mult_library.C
//

#include "nsl_num.h"

extern void cmd_error(const char *);

// matrix pointwise multiplication

nsl_num_2 operator^(const nsl_num_2& a,const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator^\n";
        cout << "// (matrix) " << a.get_name() << " ^ (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("*** nsl_num_2::operator^ ***");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return a;
	}

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b[i][j];

	return c;
}
nsl_num_2 operator^(const nsl_num_2& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator^\n";
        cout << "// (matrix) " << a.get_name() << " ^ (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b;

	return c;
}
nsl_num_2 operator^(const num_type a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator^\n";
        cout << "// (num_type) " << a << " ^ (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a * b[i][j];

	return c;
}
nsl_num_2 operator^(const nsl_num_2& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator^\n";
        cout << "// (matrix) " << a.get_name() << " ^ (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);
	
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b.get_data();

	return c;
}
nsl_num_2 operator^(const nsl_num_0& a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator^\n";
        cout << "// (data) " << a.get_name() << " ^ (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a.get_data() * b[i][j];

	return c;
}

// matrix pointwise multiplication

nsl_num_2 NSLmult(const nsl_num_2& a,const nsl_num_2& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("*** nsl_num_2::NSLmult ***");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return a;
	}

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b[i][j];

	return c;
}
nsl_num_2 NSLmult(const nsl_num_2& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b;

	return c;
}
nsl_num_2 NSLmult(const num_type a, const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a * b[i][j];

	return c;
}
nsl_num_2 NSLmult(const nsl_num_2& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b.get_data();

	return c;
}
nsl_num_2 NSLmult(const nsl_num_0& a,const  nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a.get_data() * b[i][j];

	return c;
}

