//
//	nsl_step_library.C
//

#include "nsl_kernel.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_num.h"
#include "nsl_step_library.h"
#include "nsl_ptr_vector.h"

extern void cmd_error(const char *);
extern void cmd_error(const char *, int);
// data

nsl_step_library::nsl_step_library(const char* ltype,int fg) : 
	nsl_thresh_library(ltype,3,fg)
{
}

nsl_step_library::~nsl_step_library()
{
}

nsl_step_data_library::nsl_step_data_library(nsl_layer* l,int fg) : 
	nsl_step_library("step_data",fg)
{
	set_abstract_type("data");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
}

nsl_step_data_library::~nsl_step_data_library()
{
}

nsl_library* nsl_step_data_library::make_copy(nsl_layer* l)
{
	return new nsl_step_data_library(l);
}
nsl_layer* nsl_step_data_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	     nsl_layer* n_par = new nsl_num_data(*((nsl_num_data*)(*par)[i]));
	     n_par->set_name((*par)[i]->get_name());
	     return n_par;
	}
	else
	{
	     cmd_error("step_data_library::make_par_copy: BAD par: ",i);
	     return 0;
	}
}

int nsl_step_data_library::run(nsl_layer* c,nsl_layer* a) 
{
	if (*((nsl_num_data*) a) > *((nsl_num_data*) (*par)[0]))
		*((nsl_num_data*) c) = *((nsl_num_data*) (*par)[2]);
	else
		*((nsl_num_data*) c) = *((nsl_num_data*) (*par)[1]);

	return 1;
}

// vector

nsl_step_vector_library::nsl_step_vector_library(nsl_layer* l,int fg) : 
	nsl_step_library("step_vector",fg)
{
	set_abstract_type("vector");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
}

nsl_step_vector_library::~nsl_step_vector_library()
{
}

nsl_library* nsl_step_vector_library::make_copy(nsl_layer* l)
{
	return new nsl_step_vector_library(l);
}
nsl_layer* nsl_step_vector_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_vector(*((nsl_num_vector*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("step_vector_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_step_vector_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || 
		(*par)[2] == NULL || out == NULL || in == NULL)
	{
		cmd_error("step_vector: NULL parameter");
		return -1;
	}
	nsl_num_vector a = *((nsl_num_vector*) in);
	nsl_num_vector c = *((nsl_num_vector*) out);

	num_type b = ((nsl_num_data*) (*par)[0])->elem();
	num_type y1 = ((nsl_num_data*) (*par)[1])->elem();
	num_type y2 = ((nsl_num_data*) (*par)[2])->elem();

	int s1 = a.get_imax();

	if (c.get_imax() != a.get_imax())
	{
		cmd_error("*** NSLstep ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c.get_imax());
		cmd_error("imax1: ",a.get_imax());
		cmd_error("bad vector sector");
		return 1;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = y2;
		else
			c[i] = y1;

	return 1;
}

/*

nsl_step_vector_library::nsl_step_vector_library(nsl_layer* l,int fg) : 
	nsl_step_library("step_vector",fg)
{
	set_abstract_type("vector");

	if (l == NULL)
		return;

	int n; // vector size
	if ((l->get_size_fg()) == 1 && (n = l->get_size(0)) != 0)
	{
		(*par)[0] = new nsl_num_vector("par0",n);
		(*par)[1] = new nsl_num_vector("par1",n);
		(*par)[2] = new nsl_num_vector("par2",n);
	}
	else
		cmd_error("step_vector_library: Bad Layer Size");
}

nsl_step_vector_library::~nsl_step_vector_library()
{
}

nsl_library* nsl_step_vector_library::make_copy(nsl_layer* l)
{
	return new nsl_step_vector_library(l);
}
nsl_layer* nsl_step_vector_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_vector(*((nsl_num_vector*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("step_vector_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_step_vector_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || 
		(*par)[2] == NULL || out == NULL || in == NULL)
	{
		cmd_error("step_vector: NULL parameter");
		return -1;
	}
	nsl_num_vector* a = (nsl_num_vector*) in;
	nsl_num_vector* c = (nsl_num_vector*) out;

	nsl_num_vector* b = (nsl_num_vector*) (*par)[0];
	nsl_num_vector* y1 = (nsl_num_vector*) (*par)[1];
	nsl_num_vector* y2 = (nsl_num_vector*) (*par)[2];

	int s1 = a->get_imax();

	if ((c->get_imax() != a->get_imax()) || 
		(a->get_imax() != b->get_imax()) ||
		(b->get_imax() != y1->get_imax()) ||
		(y1->get_imax() != y2->get_imax()))
	{
		cmd_error("*** NSLstep ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c->get_imax());
		cmd_error("imax1: ",a->get_imax());
		cmd_error("imax2: ",b->get_imax());
		cmd_error("imax3: ",y1->get_imax());
		cmd_error("imax4: ",y2->get_imax());
		cmd_error("bad vector sector");
		return 1;
	}

	num_type* av = a->get_vector();
	num_type* bv = b->get_vector();
	num_type* cv = c->get_vector();
	num_type* y1v = y1->get_vector();
	num_type* y2v = y2->get_vector();

	for (int i = 0; i < s1; i++)
		if (av[i] > bv[i])
			cv[i] = y2v[i];
		else
			cv[i] = y1v[i];

	return 1;
}

*/

// matrix

nsl_step_matrix_library::nsl_step_matrix_library(nsl_layer* l,int fg) : 
	nsl_step_library("step_matrix",fg)
{
	set_abstract_type("matrix");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
}

nsl_step_matrix_library::~nsl_step_matrix_library()
{
}

nsl_library* nsl_step_matrix_library::make_copy(nsl_layer* l)
{
	return new nsl_step_matrix_library(l);
}
nsl_layer* nsl_step_matrix_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_matrix(*((nsl_num_matrix*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("step_matrix_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_step_matrix_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || 
		(*par)[2] == NULL || out == NULL || in == NULL)
	{
		cmd_error("step_matrix: NULL parameter");
		return -1;
	}
	nsl_num_matrix a = *((nsl_num_matrix*) in);
	nsl_num_matrix c = *((nsl_num_matrix*) out);

	num_type b = ((nsl_num_data*) (*par)[0])->elem();
	num_type y1 = ((nsl_num_data*) (*par)[1])->elem();
	num_type y2 = ((nsl_num_data*) (*par)[2])->elem();

	int s1 = a.get_imax();
	int s2 = a.get_jmax();

	if ((c.get_imax() != a.get_imax()) || 
		(c.get_jmax() != a.get_jmax()))
	{
		cmd_error("*** NSLstep ***");
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
		if (a[i][j] > b)
			c[i][j] = y2;
		else
			c[i][j] = y1;

	return 1;
}

/*

nsl_step_matrix_library::nsl_step_matrix_library(nsl_layer* l,int fg) : 
	nsl_step_library("step_matrix",fg)
{
	set_abstract_type("matrix");

	if (l == NULL)
		return;

	int n1,n2; // vector size
	if ((l->get_size_fg()) == 1 && (n1 = l->get_size(0)) != 0 &&
		(n2 = l->get_size(1)) != 0)
	{
		(*par)[0] = new nsl_num_matrix("par0",n1,n2);
		(*par)[1] = new nsl_num_matrix("par1",n1,n2);
		(*par)[2] = new nsl_num_matrix("par2",n1,n2);
	}
	else
		cmd_error("step_matrix_library: Bad Layer Size");
}

nsl_step_matrix_library::~nsl_step_matrix_library()
{
}

nsl_library* nsl_step_matrix_library::make_copy(nsl_layer* l)
{
	return new nsl_step_matrix_library(l);
}
nsl_layer* nsl_step_matrix_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_matrix(*((nsl_num_matrix*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	    cmd_error("step_matrix_library::make_par_copy: BAD par: ",i);
	    return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_step_matrix_library::run(nsl_layer* out,nsl_layer* in)
{
	return 1;
}

*/
