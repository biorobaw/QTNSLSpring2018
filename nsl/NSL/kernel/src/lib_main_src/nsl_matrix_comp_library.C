/* SCCS  @(#)nsl_matrix_comp_library.C	1.1---95/08/13--20:48:14 */
//
//	nsl_matrix_comp_library.C
//

#include "nsl_num.h"

// comparator

int operator>(const nsl_num_2& a, const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] > b)
			return 1;
	return 0;
}

int operator<(const nsl_num_2& a, const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] < b)
			return 1;
	return 0;
}
int operator>(const num_type a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a > b[i][j])
			return 1;
	return 0;
}

int operator<(const num_type a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a < b[i][j])
			return 1;
	return 0;
}
int operator>(const nsl_num_2& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] > b)
			return 1;
	return 0;
}

int operator<(const nsl_num_2& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] < b)
			return 1;
	return 0;
}
int operator>(const nsl_num_0& a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a > b[i][j])
			return 1;
	return 0;
}

int operator<(const nsl_num_0& a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a.get_data() < b[i][j])
			return 1;
	return 0;
}

// >=,<=

int operator>=(const nsl_num_2& a, const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] >= b)
			return 1;
	return 0;
}

int operator<=(const nsl_num_2& a, const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] <= b)
			return 1;
	return 0;
}
int operator>=(const num_type a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a >= b[i][j])
			return 1;
	return 0;
}

int operator<=(const num_type a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a <= b[i][j])
			return 1;
	return 0;
}
int operator>=(const nsl_num_2& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] >= b)
			return 1;
	return 0;
}

int operator<=(const nsl_num_2& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] <= b)
			return 1;
	return 0;
}
int operator>=(const nsl_num_0& a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a >= b[i][j])
			return 1;
	return 0;
}

int operator<=(const nsl_num_0& a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a <= b[i][j])
			return 1;
	return 0;
}

// ==, !=

int operator==(const nsl_num_2& a, const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] == b)
			return 1;
	return 0;
}

int operator!=(const nsl_num_2& a, const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] != b)
			return 1;
	return 0;
}
int operator==(const num_type a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a == b[i][j])
			return 1;
	return 0;
}

int operator!=(const num_type a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a != b[i][j])
			return 1;
	return 0;
}
int operator==(const nsl_num_2& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] == b)
			return 1;
	return 0;
}

int operator!=(const nsl_num_2& a, const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a[i][j] != b)
			return 1;
	return 0;
}
int operator==(const nsl_num_0& a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a == b[i][j])
			return 1;
	return 0;
}

int operator!=(const nsl_num_0& a, const nsl_num_2& b)
{
	int aimax = b.get_imax();
	int ajmax = b.get_jmax();

	for(int i = 0; i < aimax; i++)
	    for(int j = 0; j < ajmax; j++)
		if(a != b[i][j])
			return 1;
	return 0;
}
