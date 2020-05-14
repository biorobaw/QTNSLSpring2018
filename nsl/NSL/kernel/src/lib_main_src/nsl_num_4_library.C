#include "nsl_kernel.h"
#include "nsl_num.h"
#include "nsl_num_4_library.h"
#include "nsl_num_3_library.h"

nsl_num_4 operator+(const nsl_num_4& a)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator+\n";
        cout << "// (num_4) " << " = + (num_4) ";
        cout << a.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
		for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = +a[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_4& a,const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator+\n";
        cout << "// (num_4) " << a.get_name() << " + (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax || almax != blmax)
	{
		cmd_error("*** nsl_num_4::operator+ ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_4 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] + b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_4& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator+\n";
        cout << "// (num_4) " << a.get_name() << " + (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] + b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const num_type a, const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator+\n";
        cout << "// (num_type) " << a << " + (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a + b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_4& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator+\n";
        cout << "// (num_4) " << a.get_name() << " + (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] + b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator+(const nsl_num_0& a, const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator+\n";
        cout << "// (data) " << a.get_name() << " + (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a.get_data() + b[i][j][k][l];

	return c;
}

// num_4 addtraction
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = +a[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a,const nsl_num_4& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax || almax != blmax)
	{
		cmd_error("*** nsl_num_4::NSLadd ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_4 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] + b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] + b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const num_type a, const nsl_num_4& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a + b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_4& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] + b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLadd(const nsl_num_0& a,const  nsl_num_4& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a.get_data() + b[i][j][k][l];

	return c;
}

//template<class NslNumType, int NslTypeId>
void NSLadd_plus(const nsl_num_4& a,const nsl_num_4& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax || almax != blmax)
	{
		cmd_error("*** nsl_num_4::NSLadd ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_4 sizes");
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					a[i][j][k][l] = a[i][j][k][l] + b[i][j][k][l];
}

nsl_num_4 operator*(const nsl_num_4& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator*\n";
        cout << "// (matrix) " << a.get_name() << " * (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] * b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator*(const num_type a, const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator*\n";
        cout << "// (num_type) " << a << " * (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
		for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a * b[i][j][k][l];

	return c;
}

void NSLmult_equal(nsl_num_4& out,const nsl_num_4& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int outkmax = out.get_kmax();
	int outlmax = out.get_lmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	if (aimax != outimax || ajmax != outjmax || akmax != outkmax || almax != outlmax)
	{
		cmd_error("NSLmult_equal: Inconsistent num_4 sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
		for (int j = 0; j < outjmax; j++)
			for (int k = 0; k < outkmax; k++)
				for (int l = 0; l < outlmax; l++)
					out[i][j][k][l] = a[i][j][k][l] * b;
}
//template<class NslNumType, int NslTypeId>
void NSLmult_equal(nsl_num_4& out,const num_type& b,
	const nsl_num_4& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int outkmax = out.get_kmax();
	int outlmax = out.get_lmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	if (aimax != outimax || ajmax != outjmax || akmax != outkmax || almax != outlmax)
	{
		cmd_error("NSLmult_equal: Inconsistent num_4 sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
		for (int j = 0; j < outjmax; j++)
			for (int k = 0; k < outkmax; k++)
				for (int l = 0; l < outlmax; l++)
					out[i][j][k][l] = a[i][j][k][l] * b;
}
//template<class NslNumType, int NslTypeId>
void NSLmult_plus(nsl_num_4& out,const nsl_num_4& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int outkmax = out.get_kmax();
	int outlmax = out.get_lmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	if (aimax != outimax || ajmax != outjmax || akmax != outkmax || almax != outlmax)
	{
		cmd_error("NSLmult_plus: Inconsistent num_4 sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
		for (int j = 0; j < outjmax; j++)
			for (int k = 0; k < outkmax; k++)
				for (int l = 0; l < outlmax; l++)
					out[i][j][k][l] = out[i][j][k][l] + a[i][j][k][l] * b;
}
//template<class NslNumType, int NslTypeId>
void NSLmult_plus(nsl_num_4& out,const num_type& b,
	const nsl_num_4& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int outkmax = out.get_kmax();
	int outlmax = out.get_lmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	if (aimax != outimax || ajmax != outjmax || akmax != outkmax || almax != outlmax)
	{
		cmd_error("NSLmult_plus: Inconsistent num_4 sizes");
		out.print_status(cerr);
		a.print_status(cerr);
	}

	for (int i = 0; i < outimax; i++)
		for (int j = 0; j < outjmax; j++)
			for (int k = 0; k < outkmax; k++)
				for (int l = 0; l < outlmax; l++)
					out[i][j][k][l] = out[i][j][k][l] + a[i][j][k][l] * b;
}

nsl_num_4 operator-(const nsl_num_4& a)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator-\n";
        cout << "// (num_4) " << " = - (num_4) ";
        cout << a.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
		for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = -a[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator-(const nsl_num_4& a,const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator-\n";
        cout << "// (num_4) " << a.get_name() << " - (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax || almax != blmax)
	{
		cmd_error("*** nsl_num_4::operator- ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_4 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] - b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator-(const nsl_num_4& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator-\n";
        cout << "// (num_4) " << a.get_name() << " - (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] - b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator-(const num_type a, const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator-\n";
        cout << "// (num_type) " << a << " - (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a - b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator-(const nsl_num_4& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator-\n";
        cout << "// (num_4) " << a.get_name() << " - (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] - b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 operator-(const nsl_num_0& a, const nsl_num_4& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_4 operator-\n";
        cout << "// (data) " << a.get_name() << " - (num_4) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a.get_data() - b[i][j][k][l];

	return c;
}

// num_4 subtraction
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLsub(const nsl_num_4& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = -a[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLsub(const nsl_num_4& a,const nsl_num_4& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	if (aimax != bimax || ajmax != bjmax || akmax != bkmax || almax != blmax)
	{
		cmd_error("*** nsl_num_4::NSLsub ***");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		b.print_status(cerr);
		cmd_error("Inconsistent num_4 sizes");
		return c;
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] - b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLsub(const nsl_num_4& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] - b;

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLsub(const num_type a, const nsl_num_4& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a - b[i][j][k][l];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLsub(const nsl_num_4& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int akmax = a.get_kmax();
	int almax = a.get_lmax();

	nsl_num_4 c(aimax,ajmax,akmax,almax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
			for (int k = 0; k < akmax; k++)
				for (int l = 0; l < almax; l++)
					c[i][j][k][l] = a[i][j][k][l] - b.get_data();

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_4 NSLsub(const nsl_num_0& a,const  nsl_num_4& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();
	int bkmax = b.get_kmax();
	int blmax = b.get_lmax();

	nsl_num_4 c(bimax,bjmax,bkmax,blmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
			for (int k = 0; k < bkmax; k++)
				for (int l = 0; l < blmax; l++)
					c[i][j][k][l] = a.get_data() - b[i][j][k][l];

	return c;
}
