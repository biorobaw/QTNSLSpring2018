//
//	nsl_num_library.C
//

#include "nsl_num.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_data_math.h"
#include "nsl_matrix_math.h"
#include "nsl_vector_math.h"
#include "nsl_num_library.h"

//qual
nsl_num_data operator-(nsl_num_data &a, num_type b)
{
	return nsl_num_data(a.get_data() - b);
}

nsl_num_data operator+(nsl_num_data &a, nsl_num_data b)
{
	return nsl_num_data(a.get_data() + b.get_data());
}

nsl_num_data operator+(nsl_num_data &a, num_type b)
{
	return nsl_num_data(a.get_data() + b);
}

nsl_num_data operator*(nsl_num_data &a, num_type b)
{
	return nsl_num_data(a.get_data()*b);
}

nsl_num_data operator*(num_type &a, nsl_num_data b)
{
	return nsl_num_data(b.get_data()*a);
}
// data
//!!! changed any class from nsl_num_0,matrix,vector to typedef if they have [] operator CALLED
bool operator>(float a, const nsl_num_0& b)
{
	return a > b.get_data();
}

bool operator>(const nsl_num_0& b, float a)
{
	return b.get_data() > a;
}

bool operator>(const nsl_num_0 &a, const nsl_num_0 &b)
{
	return a.get_data() > b.get_data();
}

bool operator<(float a, const nsl_num_0 &b)
{
	return a < b.get_data();
}

bool operator<(const nsl_num_0 &a, const nsl_num_0 &b)
{
	return a.get_data() < b.get_data();
}

bool operator==(const nsl_num_0 &a, float b)
{
	return a.get_data() == b;
}
/*
nsl_num_0 operator*(float b, const nsl_num_0 &a)
{
	return nsl_num_0(b - a.get_data() );
}

nsl_num_0 operator*(const nsl_num_0 &a, float b)
{
	return nsl_num_0(a.get_data() - b);
}

nsl_num_0 operator*(const nsl_num_0 &a, const nsl_num_0 &b)
{
	return nsl_num_0(a.get_data() - b.get_data());
}

nsl_num_0 operator/(const nsl_num_0 &a, float b)
{
	return nsl_num_0(a.get_data()/b);
}

nsl_num_0 operator/(const nsl_num_0 &a, const nsl_num_0 & b)
{
	return nsl_num_0(a.get_data()/b.get_data());
}


nsl_num_0 operator-(const nsl_num_0 &a, float b)
{
return nsl_num_0(a.get_data() - b);
}

nsl_num_0 operator-(float b, const nsl_num_0 &a)
{
return nsl_num_0(b - a.get_data());
}

nsl_num_0 operator-(const nsl_num_0 &a, const nsl_num_0 &b)
{
return nsl_num_0(a.get_data() - b.get_data());
} */
//!!!----------------

void NSLmult_equal(nsl_num_0& out,const nsl_num_0& a,const num_type& b)
{
	out.elem() = a.get_data() * b;
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_1& a,
	const nsl_num_0& b)
{
	int amax = a.get_imax();

	out = 0;
	for (int i = 0; i < amax; i++)
		out = out + a[i] * b;
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_1& a,
	const nsl_num_1& b)
{
	int amax = a.get_imax();

	out = 0;
	for (int i = 0; i < amax; i++)
		out = out + a[i] * b[i];
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_2& a,
	const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out + a[i][j] * b;
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_2& a,
	const nsl_num_2& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out + a[i][j] * b[i][j];
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	out.elem() = a.get_data() * b.get_data();
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_1& b)
{
	int bmax = b.get_imax();

	out = 0;
	for (int i = 0; i < bmax; i++)
		out = out + a * b[i];
}

void NSLmult_equal(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	out = 0;
	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		out = out + a * b[i][j];
}

//fx temp!! -bn7
void NSLmult_equal_FX(nsl_num_1& out,const nsl_num_1& a,
	const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b;
}
//

// vector


void NSLmult_equal(nsl_num_1& out,const nsl_num_1& a,
	const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b;
}

void NSLmult_equal(nsl_num_1& out,const nsl_num_1& a,
	const nsl_num_0& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b.get_data();
}

void NSLmult_equal(nsl_num_1& out,const nsl_num_1& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();
	int amax = a.get_imax();
	int bmax = b.get_imax();

	if (amax != bmax || bmax != outmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b[i];
}

// mat to vec

void NSLmult_equal(nsl_num_1& out,const nsl_num_2& b,
	const nsl_num_0& a)
{
	int simax = out.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	out = 0;

	if (out.get_vec_type() == 0) // ROW
	{
		if (simax != sbjmax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
			out[j] = out[j] + a.get_data()*b[i][j];
	}
	else // COL
	{
		if (simax != sbimax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < sbimax; i++)
		    for (int j = 0; j < sbjmax; j++)
			out[i] = out[i] + a.get_data()*b[i][j];
	}
}
void NSLmult_equal(nsl_num_1& out,const nsl_num_2& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bmax = b.get_imax();

	if (aimax != bmax || bmax != outmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i] = a[i][j] * b[i];
}

void NSLmult_equal(nsl_num_1& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data() * b.get_data();
}

void NSLmult_equal(nsl_num_1& out,const nsl_num_0& a,
	const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data() * b;
}

void NSLmult_equal(nsl_num_1& out,const nsl_num_0& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data() * b[i];
}

// matrix
void NSLmult_equal(nsl_num_2& out,const nsl_num_2& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * b;
}

void NSLmult_equal(nsl_num_2& out,const nsl_num_2& a,
	const nsl_num_0& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * b.get_data();
}

void NSLmult_equal(nsl_num_2& out,const nsl_num_2& a,
	const nsl_num_2& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != outimax || ajmax != outjmax || 
		aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * b[i][j];
}

// matrix conv
// fix for no allocation/deallocation of d

void NSLmult_equal(nsl_num_2& out,const nsl_num_2& b,
	const nsl_num_1& a)
{
	int saimax = a.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int vec_type;
	int simax;
	int m;
	num_type val;

	val = 0;
	out = 0; // needed

	if ((vec_type = a.get_vec_type()) == 0)
	{
		simax = saimax + sbjmax - 1;
		nsl_num_2 d(sbimax,simax);

		d.put_sector(b,0,saimax/2); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;	
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i][j+m];
			out[i][j] = val;
		   }
	}
	else
	{
		simax = saimax + sbimax - 1;
		nsl_num_2 d(simax,sbjmax);

		d.put_sector(b,saimax/2,0); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i+m][j];
			out[i][j] = val;
		   }
	}
}

// vec to mat

void NSLmult_equal(nsl_num_2& out,const nsl_num_1& b,
	const nsl_num_0& a)
{
	int sbimax = b.get_imax();
	int simax = out.get_imax();
	int sjmax = out.get_jmax();

	if (b.get_vec_type() == 0) // ROW
	{
		if (sbimax != sjmax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < simax; i++)
		   for (int j = 0; j < sjmax; j++)
			out[i][j] = a.get_data()*b[j];
	}
	else // COL
	{
		if (sbimax != simax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < simax; i++)
		    for (int j = 0; j < sjmax; j++)
			out[i][j] = a.get_data()*b[i];
	}
}

void NSLmult_equal(nsl_num_2& out,const nsl_num_0& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data() * b;
}

void NSLmult_equal(nsl_num_2& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data() * b.get_data();
}

void NSLmult_equal(nsl_num_2& out,const nsl_num_0& a,
	const nsl_num_2& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (bimax != outimax || bjmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data() * b[i][j];
}

// mult_plus

// data

void NSLmult_plus(nsl_num_0& out,const nsl_num_0& a,const num_type& b)
{
	out.elem() += a.get_data() * b;
}

void NSLmult_plus(nsl_num_0& out,const nsl_num_1& a,
	const nsl_num_0& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out + a[i] * b.get_data();
}

void NSLmult_plus(nsl_num_0& out,const nsl_num_1& a,
	const nsl_num_1& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out + a[i] * b[i];
}

void NSLmult_plus(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	out.elem() += a.get_data() * b.get_data();
}

void NSLmult_plus(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_1& b)
{
	int bmax = b.get_imax();

	for (int i = 0; i < bmax; i++)
		out = out + a.get_data() * b[i];
}

// vector
//!!fx temp//-bn7
void NSLmult_plus_FX(nsl_num_1& out,const nsl_num_1& a,const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b;
}
///

void NSLmult_plus(nsl_num_1& out,const nsl_num_1& a,const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b;
}

void NSLmult_plus(nsl_num_1& out,const nsl_num_1& a,
	const nsl_num_0& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b.get_data();
}

void NSLmult_plus(nsl_num_1& out,const nsl_num_1& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b[i];
}

void NSLmult_plus(nsl_num_1& out,const nsl_num_0& a,
	const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data() * b;
}

void NSLmult_plus(nsl_num_1& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data() * b.get_data();
}

void NSLmult_plus(nsl_num_1& out,const nsl_num_0& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data() * b[i];
}

// matrix

void NSLmult_plus(nsl_num_2& out,const nsl_num_2& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b;
}

void NSLmult_plus(nsl_num_2& out,const nsl_num_2& a,
	const nsl_num_0& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b.get_data();
}

void NSLmult_plus(nsl_num_2& out,const nsl_num_2& a,
	const nsl_num_2& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != outimax || ajmax != outjmax || 
		aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b[i][j];
}

void NSLmult_plus(nsl_num_2& out,const nsl_num_0& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data() * b;
}

void NSLmult_plus(nsl_num_2& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data() * b.get_data();
}

void NSLmult_plus(nsl_num_2& out,const nsl_num_0& a,
	const nsl_num_2& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (bimax != outimax || bjmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data() * b[i][j];
}

// mult_minus

// data

void NSLmult_minus(nsl_num_0& out,const nsl_num_0& a,const num_type& b)
{
	out.elem() -= a.get_data() * b;
}

void NSLmult_minus(nsl_num_0& out,const nsl_num_1& a,
	const nsl_num_0& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out - a[i] * b.get_data();
}

void NSLmult_minus(nsl_num_0& out,const nsl_num_1& a,
	const nsl_num_1& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out - a[i] * b[i];
}

void NSLmult_minus(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	out.elem() -= a.get_data() * b.get_data();
}

void NSLmult_minus(nsl_num_0& out,const nsl_num_0& a,
	const nsl_num_1& b)
{
	int bmax = b.get_imax();

	for (int i = 0; i < bmax; i++)
		out = out - a.get_data() * b[i];
}

// vector

void NSLmult_minus(nsl_num_1& out,const nsl_num_1& a,
	const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i] * b;
}

void NSLmult_minus(nsl_num_1& out,const nsl_num_1& a,
	const nsl_num_0& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i] * b.get_data();
}

void NSLmult_minus(nsl_num_1& out,const nsl_num_1& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i] * b[i];
}

void NSLmult_minus(nsl_num_1& out,const nsl_num_0& a,
	const num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data() * b;
}

void NSLmult_minus(nsl_num_1& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data() * b.get_data();
}

void NSLmult_minus(nsl_num_1& out,const nsl_num_0& a,
	const nsl_num_1& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data() * b[i];
}

// matrix

void NSLmult_minus(nsl_num_2& out,const nsl_num_2& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a[i][j] * b;
}

void NSLmult_minus(nsl_num_2& out,const nsl_num_2& a,
	const nsl_num_0& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a[i][j] * b.get_data();
}

void NSLmult_minus(nsl_num_2& out,const nsl_num_2& a,
	const nsl_num_2& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != outimax || ajmax != outjmax || 
		aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a[i][j] * b[i][j];
}

void NSLmult_minus(nsl_num_2& out,const nsl_num_0& a,
	const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data() * b;
}

void NSLmult_minus(nsl_num_2& out,const nsl_num_0& a,
	const nsl_num_0& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data() * b.get_data();
}

void NSLmult_minus(nsl_num_2& out,const nsl_num_0& a,
	const nsl_num_2& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (bimax != outimax || bjmax != outjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data() * b[i][j];
}

// add_equal

// data

void NSLadd_equal(nsl_num_0& out,const nsl_num_2& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out + a[i][j];
}
void NSLadd_equal(nsl_num_0& out,const nsl_num_1& a)
{
	int amax = a.get_imax();

	out = 0;
	for (int i = 0; i < amax; i++)
		out = out + a[i];
}
void NSLadd_equal(nsl_num_0& out,const nsl_num_0& a)
{
	out = a.get_data();
}


void NSLadd_equal(nsl_num_data& out,const nsl_num_0& a)
{
	out = a.get_data();
}

void NSLadd_equal(nsl_num_data& out, nsl_num_0& a)
{
	out = a.get_data();
}

// vector

void NSLadd_equal(nsl_num_1& out,const nsl_num_1& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i];
}
void NSLadd_equal(nsl_num_1& out,const nsl_num_0& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data();
}

void NSLadd_equal(nsl_num_vector& out,const nsl_num_0& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data();
}

void NSLadd_equal(nsl_num_vector& out, nsl_num_0& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data();
}
// mat_to_vec

void NSLadd_equal(nsl_num_1& out,const nsl_num_2& a)
{
	int vec_type = out.get_vec_type();

	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	int s = out.get_imax();

	out = 0;

	if (vec_type == 0) // row vector
	{
	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    out[j] = out[j] + a[i][j];
	}
	if (vec_type == 1) // col vector
	{
	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    out[i] = out[i] + a[i][j];
	}
}

// matrix
/*
void NSLadd_equal(nsl_num_2& out,const nsl_num_2& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = a[i][j];
}

*/

void NSLadd_equal(nsl_num_matrix& out, nsl_num_data& a) //TODO: revise -bn7
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data();
}

// vec_to_mat
/*
void NSLadd_equal(nsl_num_2& out,const nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data();
}
 *
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
} */

// add_plus

// data

void NSLadd_plus(nsl_num_0& out,const nsl_num_2& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out + a[i][j];
}
void NSLadd_plus(nsl_num_0& out,const nsl_num_1& a)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out + a[i];
}
void NSLadd_plus(nsl_num_0& out,const nsl_num_0& a)
{
	out.elem() += a.get_data();
}

// vector

void NSLadd_plus(nsl_num_1& out,const nsl_num_1& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i];
}
void NSLadd_plus(nsl_num_1& out,const nsl_num_0& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data();
}

// matrix
/*
void NSLadd_plus(nsl_num_2& out,const nsl_num_2& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = out[i][j] + a[i][j];
}


void NSLadd_plus(nsl_num_2& out,const nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data();
}
*/
// add_minus

// data

void NSLadd_minus(nsl_num_0& out,const nsl_num_2& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out - a[i][j];
}
void NSLadd_minus(nsl_num_0& out,const nsl_num_1& a)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out - a[i];
}
void NSLadd_minus(nsl_num_0& out,const nsl_num_0& a)
{
	out.elem() -= a.get_data();
}
/*
void NSLadd_minus(nsl_num_data& out,const nsl_num_0& a)
{
	out.elem() -= a.get_data();
}*/

void NSLadd_minus(nsl_num_data& out, nsl_num_0& a)
{
	out.elem() -= a.get_data();
}
// vector

void NSLadd_minus(nsl_num_1& out,const nsl_num_1& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i];
}
void NSLadd_minus(nsl_num_1& out,const nsl_num_0& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data();
}

void NSLadd_minus(nsl_num_vector& out,const nsl_num_0& a) //TODO: verify -bn7
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data();
}

void NSLadd_minus(nsl_num_vector& out,nsl_num_0& a) //TODO: verify -bn7
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data();
}

// matrix
/*
void NSLadd_minus(nsl_num_2& out,const nsl_num_2& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = out[i][j] - a[i][j];
}

void NSLadd_minus(nsl_num_2& out,const nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data();
}


void NSLadd_minus(nsl_num_matrix& out,const nsl_num_0& a) //TODO : revise -bn7
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data();
}
*/

//
//	nsl_num_library.C
//

///////////////////////////////////////////EXTENDED OVERLOADS/////////////////////////////////-bn7
//qual

// data
//!!! changed any class from nsl_num_data,matrix,vector to typedef if they have [] operator CALLED

void NSLmult_equal(nsl_num_data& out, nsl_num_data& a, num_type& b)
{
	out.elem() = a.get_data() * b;
}

void NSLmult_equal(nsl_num_0 &out, nsl_num_0 &a, num_type& b)
{
	out.elem() = a.get_data() * b;
}

/*
void NSLmult_equal(nsl_num_data& out, const nsl_num_data& a, const num_type& b)
{
	out.elem() = a.get_data() * b;
}*/

void NSLmult_equal(nsl_num_data& out, nsl_num_vector& a,
	 nsl_num_data& b)
{
	int amax = a.get_imax();

	out = 0;
	for (int i = 0; i < amax; i++)
		out = out + a[i] * b;
}

void NSLmult_equal(nsl_num_data& out, nsl_num_vector& a,
	 nsl_num_vector& b)
{
	int amax = a.get_imax();

	out = 0;
	for (int i = 0; i < amax; i++)
		out = out + a[i] * b[i];
}

void NSLmult_equal(nsl_num_data& out, nsl_num_matrix& a,
	 nsl_num_data& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out + a[i][j] * b;
}

void NSLmult_equal(nsl_num_data& out, nsl_num_matrix& a,
	 nsl_num_matrix& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out + a[i][j] * b[i][j];
}

void NSLmult_equal(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	out.elem() = a.get_data() * b.get_data();
}

void NSLmult_equal(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_vector& b)
{
	int bmax = b.get_imax();

	out = 0;
	for (int i = 0; i < bmax; i++)
		out = out + (a.get_data() * b[i]);
}

void NSLmult_equal(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_matrix& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	out = 0;
	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		out = out + a.get_data() * b[i][j];
}

// vector

void NSLmult_equal(nsl_num_vector& out, nsl_num_vector& a,
	 num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b;
}

void NSLmult_equal(nsl_num_vector& out, const nsl_num_vector& a,
	 const num_type& b)
{
	nsl_num_vector &ax = const_cast<nsl_num_vector&>(a);

	int outmax = out.get_imax();

	num_type bx = b;

	for (int i = 0; i < outmax; i++)
		out[i] = ax[i] * bx;
}

void NSLmult_equal(nsl_num_vector& out, nsl_num_vector& a,
	 nsl_num_data& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b.get_data();
}

void NSLmult_equal(nsl_num_vector& out, nsl_num_vector& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();
	int amax = a.get_imax();
	int bmax = b.get_imax();

	if (amax != bmax || bmax != outmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outmax; i++)
		out[i] = a[i] * b[i];
}

// mat to vec

void NSLmult_equal(nsl_num_vector& out, nsl_num_matrix& b,
	 nsl_num_data& a)
{
	int simax = out.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	out = 0;

	if (out.get_vec_type() == 0) // ROW
	{
		if (simax != sbjmax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
			out[j] = out[j] + a.get_data()*b[i][j];
	}
	else // COL
	{
		if (simax != sbimax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < sbimax; i++)
		    for (int j = 0; j < sbjmax; j++)
			out[i] = out[i] + a.get_data()*b[i][j];
	}
}

void NSLmult_equal(nsl_num_vector& out, nsl_num_matrix& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bmax = b.get_imax();

	if (aimax != bmax || bmax != outmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i] = a[i][j] * b[i];
}

void NSLmult_equal(nsl_num_vector& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data() * b.get_data();
}

void NSLmult_equal(nsl_num_vector& out, nsl_num_data& a,
	 num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data() * b;
}

void NSLmult_equal(nsl_num_vector& out, nsl_num_data& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data() * b[i];
}

// matrix
/*
void NSLmult_equal(nsl_num_matrix& out, const nsl_num_matrix& a,
	 const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	num_type bx = b;

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * bx;
}
*/

void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * b;
}

void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& a,
	 nsl_num_data& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * b.get_data();
}

void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& a,
	 nsl_num_matrix& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != outimax || ajmax != outjmax ||
		aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a[i][j] * b[i][j];
}

// matrix conv
// fix for no allocation/deallocation of d

void NSLmult_equal(nsl_num_matrix& out, nsl_num_matrix& b,
	 nsl_num_vector& a)
{
	int saimax = a.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int vec_type;
	int simax;
	int m;
	num_type val;

	val = 0;
	out = 0; // needed

	if ((vec_type = a.get_vec_type()) == 0)
	{
		simax = saimax + sbjmax - 1;
		nsl_num_matrix d(sbimax,simax);

		d.put_sector(b,0,saimax/2);

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i][j+m];
			out[i][j] = val;
		   }
	}
	else
	{
		simax = saimax + sbimax - 1;
		nsl_num_matrix d(simax,sbjmax);

		d.put_sector(b,saimax/2,0);

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i+m][j];
			out[i][j] = val;
		   }
	}
}

// vec to mat

void NSLmult_equal(nsl_num_matrix& out, nsl_num_vector& b,
	 nsl_num_data& a)
{
	int sbimax = b.get_imax();
	int simax = out.get_imax();
	int sjmax = out.get_jmax();

	if (b.get_vec_type() == 0) // ROW
	{
		if (sbimax != sjmax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < simax; i++)
		   for (int j = 0; j < sjmax; j++)
			out[i][j] = a.get_data()*b[j];
	}
	else // COL
	{
		if (sbimax != simax)
		{
			cmd_error("NSLmult_equal: Inconsistent matrix sizes");
			out.print_status(std::cerr);
			b.print_status(std::cerr);
		}

		for (int i = 0; i < simax; i++)
		    for (int j = 0; j < sjmax; j++)
			out[i][j] = a.get_data()*b[i];
	}
}

void NSLmult_equal(nsl_num_matrix& out, nsl_num_data& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data() * b;
}

void NSLmult_equal(nsl_num_matrix& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data() * b.get_data();
}

void NSLmult_equal(nsl_num_matrix& out, nsl_num_data& a,
	 nsl_num_matrix& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (bimax != outimax || bjmax != outjmax)
	{
		cmd_error("NSLmult_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data() * b[i][j];
}

// mult_plus

// data

void NSLmult_plus(nsl_num_data& out, nsl_num_data& a, num_type& b)
{
	out.elem() += a.get_data() * b;
}

void NSLmult_plus(nsl_num_0 &out, nsl_num_0 &a, num_type&b)
{
	out.elem() += a.get_data() * b;
}

void NSLmult_plus(nsl_num_data& out, nsl_num_vector& a,
	 nsl_num_data& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out + a[i] * b.get_data();
}

void NSLmult_plus(nsl_num_data& out, nsl_num_vector& a,
	 nsl_num_vector& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out + a[i] * b[i];
}

void NSLmult_plus(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	out.elem() += a.get_data() * b.get_data();
}

void NSLmult_plus(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_vector& b)
{
	int bmax = b.get_imax();

	for (int i = 0; i < bmax; i++)
		out = out + a.get_data() * b[i];
}

// vector

void NSLmult_plus(nsl_num_vector& out, nsl_num_vector& a, num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b;
}

void NSLmult_plus(nsl_num_vector& out, nsl_num_vector& a,
	 nsl_num_data& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b.get_data();
}

void NSLmult_plus(nsl_num_vector& out, nsl_num_vector& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i] * b[i];
}

void NSLmult_plus(nsl_num_vector& out, nsl_num_data& a,
	 num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data() * b;
}

void NSLmult_plus(nsl_num_vector& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data() * b.get_data();
}

void NSLmult_plus(nsl_num_vector& out, nsl_num_data& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data() * b[i];
}

// matrix

void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b;
}

void NSLmult_plus(nsl_num_2& out, nsl_num_2& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b;
}
/*
void NSLmult_plus(nsl_num_matrix& out, const nsl_num_matrix& a,
	 const num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	num_type bx = b;

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * bx;
}
*/

void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
	 nsl_num_data& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b.get_data();
}

void NSLmult_plus(nsl_num_matrix& out, nsl_num_matrix& a,
	 nsl_num_matrix& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != outimax || ajmax != outjmax ||
		aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a[i][j] * b[i][j];
}

void NSLmult_plus(nsl_num_matrix& out, nsl_num_data& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data() * b;
}

void NSLmult_plus(nsl_num_matrix& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data() * b.get_data();
}

void NSLmult_plus(nsl_num_matrix& out, nsl_num_data& a,
	 nsl_num_matrix& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (bimax != outimax || bjmax != outjmax)
	{
		cmd_error("NSLmult_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data() * b[i][j];
}

// mult_minus

// data

void NSLmult_minus(nsl_num_data& out, nsl_num_data& a, num_type& b)
{
	out.elem() -= a.get_data() * b;
}

void NSLmult_minus(nsl_num_data& out, nsl_num_vector& a,
	 nsl_num_data& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out - a[i] * b.get_data();
}

void NSLmult_minus(nsl_num_data& out, nsl_num_vector& a,
	 nsl_num_vector& b)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out - a[i] * b[i];
}

void NSLmult_minus(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	out.elem() -= a.get_data() * b.get_data();
}

void NSLmult_minus(nsl_num_data& out, nsl_num_data& a,
	 nsl_num_vector& b)
{
	int bmax = b.get_imax();

	for (int i = 0; i < bmax; i++)
		out = out - a.get_data() * b[i];
}

// vector

void NSLmult_minus(nsl_num_vector& out, nsl_num_vector& a,
	 num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i] * b;
}

void NSLmult_minus(nsl_num_vector& out, nsl_num_vector& a,
	 nsl_num_data& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i] * b.get_data();
}

void NSLmult_minus(nsl_num_vector& out, nsl_num_vector& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i] * b[i];
}

void NSLmult_minus(nsl_num_vector& out, nsl_num_data& a,
	 num_type& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data() * b;
}

void NSLmult_minus(nsl_num_vector& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data() * b.get_data();
}

void NSLmult_minus(nsl_num_vector& out, nsl_num_data& a,
	 nsl_num_vector& b)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data() * b[i];
}

// matrix

void NSLmult_minus(nsl_num_matrix& out, nsl_num_matrix& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a[i][j] * b;
}

void NSLmult_minus(nsl_num_matrix& out, nsl_num_matrix& a,
	 nsl_num_data& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a[i][j] * b.get_data();
}

void NSLmult_minus(nsl_num_matrix& out, nsl_num_matrix& a,
	 nsl_num_matrix& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (aimax != outimax || ajmax != outjmax ||
		aimax != bimax || ajmax != bjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a[i][j] * b[i][j];
}

void NSLmult_minus(nsl_num_matrix& out, nsl_num_data& a,
	 num_type& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data() * b;
}

void NSLmult_minus(nsl_num_matrix& out, nsl_num_data& a,
	 nsl_num_data& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data() * b.get_data();
}

void NSLmult_minus(nsl_num_matrix& out, nsl_num_data& a,
	 nsl_num_matrix& b)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	if (bimax != outimax || bjmax != outjmax)
	{
		cmd_error("NSLmult_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		b.print_status(std::cerr);
	}

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data() * b[i][j];
}

// add_equal

// data

void NSLadd_equal(nsl_num_data& out, nsl_num_matrix& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out.get_value() + a[i][j];
}

void NSLadd_equal(nsl_num_data& out, nsl_num_vector& a)
{
	int amax = a.get_imax();

	out = 0;
	for (int i = 0; i < amax; i++)
		out = out.get_value() + a[i];
}


void NSLadd_equal(nsl_num_data& out, nsl_num_data& a)
{
	out = a.get_data();
}


// vector

void NSLadd_equal(nsl_num_vector& out, nsl_num_vector& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a[i];
}

/*
void NSLadd_equal(nsl_num_vector& out, nsl_num_data& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data();
}
*/

// mat_to_vec

void NSLadd_equal(nsl_num_vector& out, nsl_num_matrix& a)
{
	int vec_type = out.get_vec_type();

	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	int s = out.get_imax();

	out = 0;
	
	if (vec_type == 0) // row vector
	{
	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    out[j] = out[j] + a[i][j];
	}
	if (vec_type == 1) // col vector
	{
	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    out[i] = out[i] + a[i][j];
	}
}

// matrix

void NSLadd_equal(nsl_num_matrix& out, nsl_num_matrix& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_equal: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = a[i][j];
}

/*
void NSLadd_equal(nsl_num_matrix& out, nsl_num_0& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = a.get_data();
}
*/



// vec_to_mat

void NSLadd_equal(nsl_num_matrix& out, nsl_num_vector& a)
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

// add_plus

// data

void NSLadd_plus(nsl_num_data& out, nsl_num_matrix& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out.get_value() + a[i][j];
}
void NSLadd_plus(nsl_num_data& out, nsl_num_vector& a)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out.get_value() + a[i];
}
void NSLadd_plus(nsl_num_data& out, nsl_num_data& a)
{
	out.elem() += a.get_data();
}

// vector

void NSLadd_plus(nsl_num_vector& out, nsl_num_vector& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a[i];
}
void NSLadd_plus(nsl_num_vector& out, nsl_num_data& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] + a.get_data();
}

// matrix

void NSLadd_plus(nsl_num_matrix& out, nsl_num_matrix& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_plus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = out[i][j] + a[i][j];
}
void NSLadd_plus(nsl_num_matrix& out, nsl_num_data& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] + a.get_data();
}

// add_minus

// data

void NSLadd_minus(nsl_num_data& out, nsl_num_matrix& a)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	out = 0;
	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out = out - a[i][j];
}
void NSLadd_minus(nsl_num_data& out, nsl_num_vector& a)
{
	int amax = a.get_imax();

	for (int i = 0; i < amax; i++)
		out = out - a[i];
}
/*
void NSLadd_minus(nsl_num_data& out, nsl_num_data& a)
{
	out.elem() -= a.get_data();
}
*/
// vector

void NSLadd_minus(nsl_num_vector& out, nsl_num_vector& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a[i];
}
/*
void NSLadd_minus(nsl_num_vector& out, nsl_num_data& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = out[i] - a.get_data();
}
*/
// matrix

void NSLadd_minus(nsl_num_matrix& out, nsl_num_matrix& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	if (aimax != outimax || ajmax != outjmax)
	{
		cmd_error("NSLadd_minus: Inconsistent matrix sizes");
		out.print_status(std::cerr);
		a.print_status(std::cerr);
	}

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		out[i][j] = out[i][j] - a[i][j];
}
void NSLadd_minus(nsl_num_matrix& out, nsl_num_data& a)
{
	int outimax = out.get_imax();
	int outjmax = out.get_jmax();

	for (int i = 0; i < outimax; i++)
	   for (int j = 0; j < outjmax; j++)
		out[i][j] = out[i][j] - a.get_data();
}

/////////////////////////////////
void NSLadd_equal(nsl_num_vector& out,const nsl_num_data& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data();
}

void NSLadd_minus(nsl_num_data& out,const nsl_num_data& a)
{
	out.elem() -= a.get_data();
}
