/* SCCS  @(#)nsl_vector_comp_library.C	1.1---95/08/13--20:48:18 */

//
//	nsl_vector_comp_library.C

#include "nsl_num.h"
#include "nsl_vector_math.h"

// vector convolution

// comparator

int operator>(const nsl_num_1& a, const num_type b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] > b)
			return 1;
	return 0;
}

int operator<(const nsl_num_1& a, const num_type b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] < b)
			return 1;
	return 0;
}
int operator>(const num_type a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a > b[i])
			return 1;
	return 0;
}

int operator<(const num_type a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a < b[i])
			return 1;
	return 0;
}
int operator>(const nsl_num_1& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] > b)
			return 1;
	return 0;
}

int operator<(const nsl_num_1& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] < b)
			return 1;
	return 0;
}
int operator>(const nsl_num_0& a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a > b[i])
			return 1;
	return 0;
}

int operator<(const nsl_num_0& a,const  nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
	{
		float bx = b[i];

		if (a.get_data() < bx)
			return 1;
	}

	return 0;
}
/*
bool operator>(float a, const nsl_num_0 &b)
{
	return (a > b.get_data());
} */
// >=, <=

int operator>=(const nsl_num_1& a, const num_type b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] >= b)
			return 1;
	return 0;
}

int operator<=(const nsl_num_1& a, const num_type b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] <= b)
			return 1;
	return 0;
}
int operator>=(const num_type a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a >= b[i])
			return 1;
	return 0;
}

int operator<=(const num_type a,const  nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a <= b[i])
			return 1;
	return 0;
}
int operator>=(const nsl_num_1& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] >= b)
			return 1;
	return 0;
}

int operator<=(const nsl_num_1& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] <= b)
			return 1;
	return 0;
}
int operator>=(const nsl_num_0& a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a >= b[i])
			return 1;
	return 0;
}

int operator<=(const nsl_num_0& a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a <= b[i])
			return 1;
	return 0;
}

// ==, !=

int operator==(const nsl_num_1& a, const num_type b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] == b)
			return 1;
	return 0;
}

int operator!=(const nsl_num_1& a,const  num_type b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] != b)
			return 1;
	return 0;
}
int operator==(const num_type a,const  nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a == b[i])
			return 1;
	return 0;
}

int operator!=(const num_type a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a != b[i])
			return 1;
	return 0;
}
int operator==(const nsl_num_1& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] == b)
			return 1;
	return 0;
}

int operator!=(const nsl_num_1& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a[i] != b)
			return 1;
	return 0;
}
int operator==(const nsl_num_0& a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a == b[i])
			return 1;
	return 0;
}

int operator!=(const nsl_num_0& a, const nsl_num_1& b)
{
	int aimax = b.get_imax();

	for(int i = 0; i < aimax; i++)
		if(a != b[i])
			return 1;
	return 0;
}
