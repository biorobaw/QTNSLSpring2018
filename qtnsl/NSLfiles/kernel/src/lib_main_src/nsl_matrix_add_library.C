/* SCCS  @(#)nsl_matrix_add_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_matrix_add_library.C
//

#include "nsl_num.h"

extern void cmd_error(const char *);
//extern void cmd_error(const char *, const char *);
//extern void cmd_out(const char *);

// matrix addition

nsl_num_2 operator+(const nsl_num_2& a)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (matrix) "<< " = + (matrix) ";
        cout << a.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j];

	return c;
}
nsl_num_2 operator+(const nsl_num_2& a,const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (matrix) " << a.get_name() << " + (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("*** nsl_num_2::operator+ ***");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return a;
	}

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + b[i][j];

	return c;
}
nsl_num_2 operator+(const nsl_num_2& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (matrix) " << a.get_name() << " + (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + b;

	return c;
}
nsl_num_2 operator+(const num_type a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (num_type) " << a << " + (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a + b[i][j];

	return c;
}
nsl_num_2 operator+(const nsl_num_2& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (matrix) " << a.get_name() << " + (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + b.get_data();

	return c;
}
nsl_num_2 operator+(const nsl_num_0& a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (data) " << a.get_name() << " + (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a.get_data() + b[i][j];

	return c;
}

// matrix addition

nsl_num_2 NSLadd(const nsl_num_2& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j];

	return c;
}
nsl_num_2 NSLadd(const nsl_num_2& a,const nsl_num_2& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("*** nsl_num_2::,NSLadd ***");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		b.print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return a;
	}

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + b[i][j];

	return c;
}
nsl_num_2 NSLadd(const nsl_num_2& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + b;

	return c;
}
nsl_num_2 NSLadd(const num_type a, const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a + b[i][j];

	return c;
}
nsl_num_2 NSLadd(const nsl_num_2& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + b.get_data();

	return c;
}
nsl_num_2 NSLadd(const nsl_num_0& a, const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a.get_data() + b[i][j];

	return c;
}

//template<class NslNumType, int NslTypeId>
nsl_num_2 operator+(const nsl_num_2& a,const double b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (matrix) " << a.get_name() << " + (double) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + (float) b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_2 operator+(const nsl_num_2& a,const int b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (matrix) " << a.get_name() << " + (int) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] + (float) b;

	return c;
}

//template<class NslNumType, int NslTypeId>
nsl_num_2 operator+(const double a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (double) " << a << " + (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a + b[i][j];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_2 operator+(const int a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator+\n";
        cout << "// (int) " << a << " + (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a + b[i][j];

	return c;
}
// add_equal

//template<class NslNumType, int NslTypeId>
void NSLadd_equal(nsl_num_2& out,const nsl_num_2& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_equal: Inconsistent matrix sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = a[i][j];
}

// vec_to_mat

//template<class NslNumType, int NslTypeId>
void NSLadd_equal(nsl_num_2& out,const nsl_num_1& a)
{
	int vec_type = a.get_vec_type();

	int simax = out.get_imax();
	int sjmax = out.get_jmax();

	int s = a.get_imax();

//	out = 0;

	if (vec_type == 0) // row vector
	{
	    if (s != sjmax)
	    {
		cmd_error("*** NSLvec_to_mat ***");
		cmd_error("vector jmax: ",s);
		cmd_error("matrix jmax: ",sjmax);
		cmd_error("Bad vector size");
		return;
	    }

	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    out[i][j] = a[j];
	}
	if (vec_type == 1) // col vector
	{
	    if (s != simax)
	    {
		cmd_error("*** NSLvec_to_mat ***");
		cmd_error("vector imax: ",s);
		cmd_error("matrix imax: ",simax);
		cmd_error("Bad vector size");
		return;
	    }

	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    out[i][j] = a[i];
	}
}

//template<class NslNumType, int NslTypeId>
void NSLadd_col_equal(nsl_num_2& out,const nsl_num_1& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();

	if (aimax != outimax)
	{
		cmd_error("NSLadd_col_equal: Inconsistent matrix/vector sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
	    for (int j = 0; j < outjmax; j++)
			out[i][j] = a[i];
}
//template<class NslNumType, int NslTypeId>
void NSLadd_row_equal(nsl_num_2& out,const nsl_num_1& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int ajmax = a.get_imax();

	if (ajmax != outjmax)
	{
		cmd_error("NSLadd_row_equal: Inconsistent matrix/vector sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
	    for (int j = 0; j < outjmax; j++)
			out[i][j] = a[j];
}

//template<class NslNumType, int NslTypeId>
void NSLadd_equal(nsl_num_2& out,const nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data();
}

// add_plus

//template<class NslNumType, int NslTypeId>
void NSLadd_plus(nsl_num_2& out,const nsl_num_2& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_plus: Inconsistent matrix sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = out[i][j] + a[i][j];
}
//template<class NslNumType, int NslTypeId>
void NSLadd_plus(nsl_num_2& out,const nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data();
}

// add_minus

//template<class NslNumType, int NslTypeId>
void NSLadd_minus(nsl_num_2& out,const nsl_num_2& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_minus: Inconsistent matrix sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = out[i][j] - a[i][j];
}
//template<class NslNumType, int NslTypeId>
void NSLadd_minus(nsl_num_2& out,const nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data();
}

/////////////////////////////////////////////////////
