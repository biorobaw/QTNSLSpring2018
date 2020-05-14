#include "nsl_kernel.h"
#include "nsl_num.h"
#include "nsl_num_3_library.h"


nsl_num_3 operator*(const nsl_num_3& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator*\n";
        cout << "// (matrix) " << a.get_name() << " * (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				c[i][j][k] = a[i][j][k] * b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator*(const num_type a, const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator*\n";
        cout << "// (num_type) " << a << " * (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
		for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a * b[i][j][k];

	return c;
}

nsl_num_3 operator-(const nsl_num_3& a)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator-\n";
        cout << "// (num_3) " << " = - (num_3) ";
        cout << a.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
		for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = -a[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_3& a,const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator-\n";
        cout << "// (num_3) " << a.get_name() << " - (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax)
	{
		cmd_error("*** nsl_num_3::operator- ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_3 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] - b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_3& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator-\n";
        cout << "// (num_3) " << a.get_name() << " - (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] - b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const num_type a, const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator-\n";
        cout << "// (num_type) " << a << " - (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a - b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_3& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator-\n";
        cout << "// (num_3) " << a.get_name() << " - (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] - b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator-(const nsl_num_0& a, const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator-\n";
        cout << "// (data) " << a.get_name() << " - (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a.get_data() - b[i][j][k];

	return c;
}

// num_3 subtraction
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = -a[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a,const nsl_num_3& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax)
	{
		cmd_error("*** nsl_num_3::NSLsub ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_3 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] - b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] - b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const num_type a, const nsl_num_3& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a - b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_3& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] - b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLsub(const nsl_num_0& a,const  nsl_num_3& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a.get_data() - b[i][j][k];

	return c;
}

nsl_num_3 operator+(const nsl_num_3& a)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator+\n";
        cout << "// (num_3) " << " = + (num_3) ";
        cout << a.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
		for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = +a[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_3& a,const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator+\n";
        cout << "// (num_3) " << a.get_name() << " + (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax)
	{
		cmd_error("*** nsl_num_3::operator+ ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_3 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] + b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_3& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator+\n";
        cout << "// (num_3) " << a.get_name() << " + (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] + b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const num_type a, const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator+\n";
        cout << "// (num_type) " << a << " + (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a + b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_3& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator+\n";
        cout << "// (num_3) " << a.get_name() << " + (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] + b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 operator+(const nsl_num_0& a, const nsl_num_3& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_3 operator+\n";
        cout << "// (data) " << a.get_name() << " + (num_3) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a.get_data() + b[i][j][k];

	return c;
}

// num_3 addtraction
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = +a[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a,const nsl_num_3& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax)
	{
		cmd_error("*** nsl_num_3::NSLadd ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_3 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] + b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] + b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const num_type a, const nsl_num_3& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a + b[i][j][k];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_3& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	nsl_num_3 c(aimax,ajmax,akmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
					c[i][j][k] = a[i][j][k] + b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_3 NSLadd(const nsl_num_0& a,const  nsl_num_3& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();

	nsl_num_3 c(bimax,bjmax,bkmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
					c[i][j][k] = a.get_data() + b[i][j][k];

	return c;
}

void NSLmult_equal(nsl_num_3& out,const nsl_num_3& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int outkmax = out.get_kmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	if (aimax != outimax || ajmax != outjmax || akmax != outkmax)
	{
		cmd_error("NSLmult_equal: Inconsistent num_3 sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
		for (int j = 0; j < outjmax; j++)
			for (int k = 0; k < outkmax; k++)
				out[i][j][k] = a[i][j][k] * b;
}
//template<class NslNumType, int NslTypeId>
void NSLmult_plus(nsl_num_3& out,const nsl_num_3& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int outkmax = out.get_kmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();

	if (aimax != outimax || ajmax != outjmax || akmax != outkmax)
	{
		cmd_error("NSLmult_plus: Inconsistent num_3 sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
		for (int j = 0; j < outjmax; j++)
			for (int k = 0; k < outkmax; k++)
				out[i][j][k] = out[i][j][k] + a[i][j][k] * b;
}
