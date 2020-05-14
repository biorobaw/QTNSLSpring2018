/* SCCS  @(#)nsl_vec_to_mat_library.C	1.1---95/08/13--20:48:17 */
//
//	nsl_vec_to_mat_library.C
//

#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;
#include "nsl_vector_math.h"
#include "nsl_matrix_math.h"
#include "nsl.h"

extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

nsl_num_2 NSLvec_to_mat(const nsl_num_2& ref,const nsl_num_1& a)
{
	int vec_type = a.get_vec_type();

	int simax = ref.get_imax();
	int sjmax = ref.get_jmax();

	int s = a.get_imax();

	nsl_num_2 c(simax,sjmax);
	
	if (vec_type == 0) // row vector
	{
	    if (s != sjmax)
	    {
		cmd_error("*** NSLvec_to_mat ***");
		cmd_error("vector jmax: ",s);
		cmd_error("matrix jmax: ",sjmax);
		cmd_error("Bad vector size");
		return c;
	    }

	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    c[i][j] = a[j];
	}
	if (vec_type == 1) // col vector
	{
	    if (s != simax)
	    {
		cmd_error("*** NSLvec_to_mat ***");
		cmd_error("vector imax: ",s);
		cmd_error("matrix imax: ",simax);
		cmd_error("Bad vector size");
		return c;
	    }

	    for (int i = 0; i < simax; i++)
	    	for (int j = 0; j < sjmax; j++)
		    c[i][j] = a[i];
	}

	return c;
}

nsl_num_2 NSLrow_vec_to_mat(const nsl_num_2& ref,const nsl_num_1& a)
{
	int simax = ref.get_imax();
	int sjmax = ref.get_jmax();

	int s = a.get_imax();

	nsl_num_2 c(simax,sjmax);

	if (s != sjmax)
	{
		cmd_error("*** NSLrow_vec_to_mat ***");
		cmd_error("vector jmax: ",s);
		cmd_error("matrix jmax: ",sjmax);
		cmd_error("Bad vector size");
		return c;
	}

	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		c[i][j] = a[j];

	return c;
}

nsl_num_2 NSLcol_vec_to_mat(const nsl_num_2& ref,const nsl_num_1& a)
{ 
	int simax = ref.get_imax();
	int sjmax = ref.get_jmax();

	int s = a.get_imax();

	nsl_num_2 c(simax,sjmax);

	if (s != simax)
	{
		cmd_error("*** NSLcol_vec_to_mat ***");
		cmd_error("vector imax: ",s);
		cmd_error("matrix imax: ",simax);
		cmd_error("Bad vector size");
		return c;
	}

	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		c[i][j] = a[i];

	return c; 
}

nsl_num_2 NSLrow_vec_to_mat(const nsl_num_1& a,const int simax)
{
	int sjmax = a.get_imax();

	nsl_num_2 c(simax,sjmax);

	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		c[i][j] = a[j];

	return c;
}

nsl_num_2 NSLcol_vec_to_mat(const nsl_num_1& a,const int sjmax)
{
	int simax = a.get_imax();

	nsl_num_2 c(simax,sjmax);
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		c[i][j] = a[i];

	return c;
}
