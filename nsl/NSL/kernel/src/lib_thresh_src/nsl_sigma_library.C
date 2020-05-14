//
//	nsl_sigma_library.C
//

#include "nsl_sigma_library.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_num_library.h"
#include "nsl_layer.h"
#include "nsl_num.h"
#include "nsl_matrix_math.h"
#include "nsl_ptr_data.h"
#include "nsl_ptr_vector.h"
#include "nsl_ptr_matrix.h"

extern void cmd_error(const char *, int);
extern void cmd_error(const char *);

nsl_sigma_library::nsl_sigma_library(const char* ltype,int fg) : 
	nsl_thresh_library(ltype,4,fg)
{
}

nsl_sigma_library::~nsl_sigma_library()
{
}

// data

nsl_sigma_data_library::nsl_sigma_data_library(nsl_layer* l,int fg) : 
	nsl_sigma_library("sigma_data",fg)
{
	set_abstract_type("data");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
	(*par)[3] = new nsl_num_data("par3");
}

nsl_sigma_data_library::~nsl_sigma_data_library()
{
}

nsl_library* nsl_sigma_data_library::make_copy(nsl_layer* l)
{
	return new nsl_sigma_data_library(l);
}
nsl_layer* nsl_sigma_data_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	     nsl_layer* n_par = new nsl_num_data(*((nsl_num_data*)(*par)[i]));
	     n_par->set_name((*par)[i]->get_name());
	     return n_par;
	}
	else
	{
	     cmd_error("sigma_data_library::make_par_copy: BAD par: ",i);
	     return 0;
	}
}

int nsl_sigma_data_library::run(nsl_layer* out,nsl_layer* in) 
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || (*par)[2] == NULL ||
		(*par)[3] == NULL || out == NULL || in == NULL)
	{
		cmd_error("sigma_vector: NULL parameter");
		return -1;
	}

	nsl_num_data* a = (nsl_num_data*) in;
	nsl_num_data* c = (nsl_num_data*) out;

	num_type x1 = ((nsl_num_data*) (*par)[0])->elem();
	num_type x2 = ((nsl_num_data*) (*par)[1])->elem();
	num_type y1 = ((nsl_num_data*) (*par)[2])->elem();
	num_type y2 = ((nsl_num_data*) (*par)[3])->elem();

        num_type sigma = (a->elem()-x1)/(x2-x1);

	if (a->elem() > x2)
		c->elem() = y2;
	else if (a->elem() > x1)
		c->elem() = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
	else
		c->elem() = y1;

	return 1;
}

// vector

nsl_sigma_vector_library::nsl_sigma_vector_library(nsl_layer* l,int fg) : 
	nsl_sigma_library("sigma_vector",fg)
{
	set_abstract_type("vector");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
	(*par)[3] = new nsl_num_data("par3");
}

nsl_sigma_vector_library::~nsl_sigma_vector_library()
{
}

nsl_library* nsl_sigma_vector_library::make_copy(nsl_layer* l)
{
	return new nsl_sigma_vector_library(l);
}
nsl_layer* nsl_sigma_vector_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_vector(*((nsl_num_vector*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("sigma_vector_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > x2 then c = y2 
// else if a > x1 then c = (y2-y1)*(a-x1)/(x2-x1) + y1 
// else c = y1

int nsl_sigma_vector_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || (*par)[2] == NULL ||
		(*par)[3] == NULL || out == NULL || in == NULL)
	{
		cmd_error("sigma_vector: NULL parameter");
		return -1;
	}
	nsl_num_vector a = *((nsl_num_vector*) in);
	nsl_num_vector c = *((nsl_num_vector*) out);

	num_type x1 = ((nsl_num_data*) (*par)[0])->elem();
	num_type x2 = ((nsl_num_data*) (*par)[1])->elem();
	num_type y1 = ((nsl_num_data*) (*par)[2])->elem();
	num_type y2 = ((nsl_num_data*) (*par)[3])->elem();

	int s1 = a.get_imax();

	if (c.get_imax() != a.get_imax())
	{
		cmd_error("*** NSLsigma ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c.get_imax());
		cmd_error("imax1: ",a.get_imax());
		cmd_error("bad vector sector");
		return 1;
	}

	for (int i = 0; i < s1; i++)
	{
        	num_type sigma = (a[i]-x1)/(x2-x1);

		if (a[i] > x2)
			c[i] = y2;
		else if (a[i] > x1)
		   	c[i] = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
		else
		   	c[i] = y1;
	}

	return 1;
}

// matrix

nsl_sigma_matrix_library::nsl_sigma_matrix_library(nsl_layer* l,int fg) : 
	nsl_sigma_library("sigma_matrix",fg)
{
	set_abstract_type("matrix");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
	(*par)[3] = new nsl_num_data("par3");
}

nsl_sigma_matrix_library::~nsl_sigma_matrix_library()
{
}

nsl_library* nsl_sigma_matrix_library::make_copy(nsl_layer* l)
{
	return new nsl_sigma_matrix_library(l);
}
nsl_layer* nsl_sigma_matrix_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_matrix(*((nsl_num_matrix*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("sigma_matrix_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > x2 then c = y2 
// else if a > x1 then c = (y2-y1)*(a-x1)/(x2-x1) + y1 
// else c = y1

int nsl_sigma_matrix_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || (*par)[2] == NULL ||
		(*par)[3] == NULL || out == NULL || in == NULL)
	{
		cmd_error("sigma_matrix: NULL parameter");
		return -1;
	}
	nsl_num_matrix a = *((nsl_num_matrix*) in);
	nsl_num_matrix c = *((nsl_num_matrix*) out);

	num_type x1 = ((nsl_num_data*) (*par)[0])->elem();
	num_type x2 = ((nsl_num_data*) (*par)[1])->elem();
	num_type y1 = ((nsl_num_data*) (*par)[2])->elem();
	num_type y2 = ((nsl_num_data*) (*par)[3])->elem();

	int s1 = a.get_imax();
	int s2 = a.get_jmax();

	if ((c.get_imax() != a.get_imax()) || 
		(c.get_jmax() != a.get_jmax()))
	{
		cmd_error("*** NSLsigma ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c.get_imax());
		cmd_error("imax1: ",a.get_imax());
		cmd_error("jmax0: ",c.get_jmax());
		cmd_error("jmax1: ",a.get_jmax());
		cmd_error("bad matrix sector");
		return 1;
	}

	for (int i = 0; i < s1; i++)
	    for (int j = 0; j < s2; j++)
	    {
          	num_type sigma = (a[i][j]-x1)/(x2-x1);

		if (a[i][j] > x2)
			c[i][j] = y2;
		else if (a[i][j] > x1)
		 	 c[i][j] = (y2-y1)*sigma*sigma*(3.0-2.0*sigma) + y1;
		else
		  	c[i][j] = y1;
	    }

	return 1;
}
