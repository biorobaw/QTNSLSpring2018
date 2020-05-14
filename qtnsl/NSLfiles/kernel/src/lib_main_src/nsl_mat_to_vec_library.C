/* SCCS  @(#)nsl_mat_to_vec_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_mat_to_vec_library.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

nsl_num_1 NSLmat_to_vec(const nsl_num_1& ref,const nsl_num_2& a)
{
	int vec_type = ref.get_vec_type();

	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	int s = ref.get_imax();

	nsl_num_1 c(s);
	
	if (vec_type == 0) // row vector
	{
	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    c[j] = a[i][j] + c[j];
	}
	if (vec_type == 1) // col vector
	{
	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    c[i] = a[i][j] + c[i];
	}

	return c;
}

nsl_num_1 NSLmat_to_row_vec(const nsl_num_1&,const nsl_num_2& a) 
{
	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	nsl_num_1 c(sjmax);
		
	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		c[j] = a[i][j] + c[j];

	return c;
}
nsl_num_1 NSLmat_to_col_vec(const nsl_num_1&,const nsl_num_2& a) 
{
	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	nsl_num_1 c(simax);
	
	for (int j = 0; j < sjmax; j++)
	    for (int i = 0; i < simax; i++)
		c[i] = a[i][j] + c[i];

	return c;
}

nsl_num_1 NSLmat_to_row_vec(const nsl_num_2& a)
{
	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	nsl_num_1 c(sjmax);
		
	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		c[j] = a[i][j] + c[j];

	return c;
}
nsl_num_1 NSLmat_to_col_vec(const nsl_num_2& a)
{
	int simax = a.get_imax();
	int sjmax = a.get_jmax();

	nsl_num_1 c(simax);
	
	for (int j = 0; j < sjmax; j++)
	    for (int i = 0; i < simax; i++)
		c[i] = a[i][j] + c[i];

	return c;
}

