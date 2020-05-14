/* SCCS  @(#)nsl_matrix_prod_library.C	1.1---95/08/13--20:48:16 */
//
//	nsl_matrix_prod_library.C
//

#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;
// product

nsl_num_0 NSLprod(const nsl_num_1& w,const nsl_num_1& x)
{
	int size = w.get_imax();

	nsl_num_0 c;

	if (size != x.get_imax())
	{
                cmd_error("*** NSLprod ***");
                cmd_error("Exit with the following status");
                w.print_status(std::cerr);
                x.print_status(std::cerr);
		cmd_error("Bad dimensions in NSLprod");
		return c;
	}
	
	for (int i = 0; i < size; i++)
		c = c + w[i]*x[i];

	return c;
}
nsl_num_1 NSLprod(const nsl_num_1& w,const nsl_num_2& x)
{
	int size = x.get_imax();
	int vsize = x.get_jmax();

	nsl_num_1 c(vsize);

	if (size != w.get_imax())
	{
                cmd_error("*** NSLprod ***");
                cmd_error("Exit with the following status");
                w.print_status(std::cerr);
                x.print_status(std::cerr);
		cmd_error("Bad dimensions in NSLprod");
		return c;
	}
	
	for (int j = 0; j < vsize; j++)
	{
	    c[j] = 0;
	    for (int i = 0; i < size; i++)
		c[j] = c[j] + w[i]*x[i][j];
	}

	return c;
}
nsl_num_1 NSLprod(const nsl_num_2& w,const nsl_num_1& x)
{
	int size = w.get_jmax();
	int vsize = w.get_imax();

	nsl_num_1 c(vsize);

	if (size != x.get_imax())
	{
                cmd_error("*** NSLprod ***");
                cmd_error("Exit with the following status");
                w.print_status(std::cerr);
                x.print_status(std::cerr);
		cmd_error("Bad dimensions in NSLprod");
		return c;
	}
		
	for (int i = 0; i < vsize; i++)
	{
	    c[i] = 0;
	    for (int j = 0; j < size; j++)
		c[i] = c[i] + w[i][j]*x[j];
	}

	return c;
}

nsl_num_2 NSLprod(const nsl_num_2& w,const nsl_num_2& x)
{
	int isize = w.get_imax();
	int jsize = x.get_jmax();

	int size = w.get_jmax();

	nsl_num_2 c(isize,jsize);

	if (size != x.get_imax())
	{
                cmd_error("*** NSLprod ***");
                cmd_error("Exit with the following status");
                w.print_status(std::cerr);
                x.print_status(std::cerr);
		cmd_error("Bad dimensions in NSLprod");
		return c;
	}
		
	for (int i = 0; i < isize; i++)
	    for (int j = 0; j < jsize; j++)
	    {
	    	c[i][j] = 0;
	    	for (int k = 0; k < size; k++)
		   c[i][j] = c[i][j] + w[i][k]*x[k][j];
	    }

	return c;
}
