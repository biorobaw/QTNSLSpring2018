//
//	nsl_ramp_library.C
//

#include "nsl_ramp_library.h"
#include "nsl_layer.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_num_data.h"
#include "nsl_ptr_data.h"
#include "nsl_ptr_vector.h"
#include "nsl_ptr_matrix.h"
#include "nsl_data_math.h"
#include "nsl_num.h"
#include "nsl_kernel.h"
#include "nsl_num_library.h"


nsl_ramp_library::nsl_ramp_library(const char* ltype,int fg) : 
	nsl_thresh_library(ltype,3,fg)
{
}

nsl_ramp_library::~nsl_ramp_library()
{
}

nsl_ramp_data_library::nsl_ramp_data_library(nsl_layer* l,int fg) :
	nsl_ramp_library("ramp_data",fg)
{
	set_abstract_type("data");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
}

nsl_ramp_data_library::~nsl_ramp_data_library()
{
}

nsl_library* nsl_ramp_data_library::make_copy(nsl_layer* l)
{
	return new nsl_ramp_data_library(l);
}
nsl_layer* nsl_ramp_data_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	     nsl_layer* n_par = new nsl_num_data(*((nsl_num_data*)(*par)[i]));
	     n_par->set_name((*par)[i]->get_name());
	     return n_par;
	}
	else
	{
	     cmd_error("ramp_data_library::make_par_copy: BAD par: ",i);
	     return 0;
	}
}

// if a > b then c = a - b + y2 else c = y1


int nsl_ramp_data_library::run(nsl_layer* c,nsl_layer* a)
{
	float x = (*((nsl_num_data*) (*par)[0])).get_value();
	float y = (*((nsl_num_data*) (*par)[2])).get_value();
	if (*((nsl_num_data*) a) > *((nsl_num_data*) (*par)[0]))
	{
		nsl_num_data &rc = *((nsl_num_data*) c);
	    rc = *((nsl_num_data*) a) - (x + y);
	}
	    else
	    *((nsl_num_data*) c) = *((nsl_num_data*) (*par)[1]);

	return 1;
}

nsl_ramp_vector_library::nsl_ramp_vector_library(nsl_layer* l,int fg) :
	nsl_ramp_library("ramp_vector",fg)
{
	set_abstract_type("vector");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
}

nsl_ramp_vector_library::~nsl_ramp_vector_library()
{
}

nsl_library* nsl_ramp_vector_library::make_copy(nsl_layer* l)
{
	return new nsl_ramp_vector_library(l);
}
nsl_layer* nsl_ramp_vector_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_vector(*((nsl_num_vector*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("ramp_vector_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_ramp_vector_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || 
		(*par)[2] == NULL || out == NULL || in == NULL)
	{
		cmd_error("ramp_vector: NULL parameter");
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
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c.get_imax());
		cmd_error("imax1: ",a.get_imax());
		cmd_error("bad vector sector");
		return 1;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i] - b + y2;
		else
			c[i] = y1;

	return 1;
}
/*
nsl_ramp_vector_data_library::nsl_ramp_vector_data_library(nsl_layer* l,int fg):
	nsl_ramp_vector_library("ramp_data_vector",fg)
{
	set_abstract_type("vector");

	if (l == NULL)
		return;

	(*par)[0] = new nsl_num_data("par0");
	(*par)[1] = new nsl_num_data("par1");
	(*par)[2] = new nsl_num_data("par2");
}

nsl_ramp_vector_data_library::~nsl_ramp_vector_data_library()
{
}

nsl_library* nsl_ramp_vector_data_library::make_copy(nsl_layer* l)
{
	return new nsl_ramp_vector_data_library(l);
}
nsl_layer* nsl_ramp_vector_data_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_vector(*((nsl_num_vector*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("ramp_vector_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_ramp_vector_data_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || 
		(*par)[2] == NULL || out == NULL || in == NULL)
	{
		cmd_error("ramp_vector: NULL parameter");
		return -1;
	}
	nsl_num_vector a = *((nsl_num_vector*) in);
	nsl_num_vector c = *((nsl_num_vector*) out);

	nsl_num_data b = *((nsl_num_data*) (*par)[0]);
	nsl_num_data y1 = *((nsl_num_data*) (*par)[1]);
	nsl_num_data y2 = *((nsl_num_data*) (*par)[2]);

	int s1 = a.get_imax();

	if (c.get_imax() != a.get_imax())
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c.get_imax());
		cmd_error("imax1: ",a.get_imax());
		cmd_error("bad vector sector");
		return 1;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b)
			c[i] = a[i] - b + y2;
		else
			c[i] = y1;

	return 1;
}

nsl_ramp_vector_vector_library::nsl_ramp_vector_vector_library(nsl_layer* l,
	int fg) : nsl_ramp_library("ramp_vector_vector",fg)
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
		cmd_error("ramp_vector_library: Bad Layer Size");
}

nsl_ramp_vector_vector_library::~nsl_ramp_vector_vector_library()
{
}

nsl_library* nsl_ramp_vector_vector_library::make_copy(nsl_layer* l)
{
	return new nsl_ramp_vector_vector_library(l);
}
nsl_layer* nsl_ramp_vector_vector_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_vector(*((nsl_num_vector*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("ramp_vector_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_ramp_vector_vector_library::run(nsl_layer* out,nsl_layer* in)
{
	if ((*par)[0] == NULL || (*par)[1] == NULL || 
		(*par)[2] == NULL || out == NULL || in == NULL)
	{
		cmd_error("ramp_vector: NULL parameter");
		return -1;
	}
	nsl_num_vector a = *((nsl_num_vector*) in);
	nsl_num_vector c = *((nsl_num_vector*) out);

	nsl_num_vector* b = (nsl_num_vector*) (*par)[0];
	nsl_num_vector* y1 = (nsl_num_vector*) (*par)[1];
	nsl_num_vector* y2 = (nsl_num_vector*) (*par)[2];

	int s1 = a->get_imax();

	if ((c.get_imax() != a.get_imax()) || 
		(a.get_imax() != b->get_imax()) ||
		(b->get_imax() != y1->get_imax()) ||
		(y1->get_imax() != y2->get_imax()))
	{
		cmd_error("*** NSLramp ***");
		cmd_error("Exit with the following status");
		cmd_error("imax0: ",c.get_imax());
		cmd_error("imax1: ",a.get_imax());
		cmd_error("imax2: ",b->get_imax());
		cmd_error("imax3: ",y1->get_imax());
		cmd_error("imax4: ",y2->get_imax());
		cmd_error("bad vector sector");
		return 1;
	}

	for (int i = 0; i < s1; i++)
		if (a[i] > b[i])
			c[i] = a[i] - b[i] + y2[i];
		else
			c[i] = y1[i];

	return 1;
}
*/
nsl_ramp_matrix_library::nsl_ramp_matrix_library(nsl_layer* l,int fg) :
	nsl_ramp_library("ramp_matrix",fg)
{
	set_abstract_type("matrix");

	if (l == NULL)
		return;

	int n1,n2; // vector size
	if ((l->get_size_fg()) == 1 && (n1 = l->get_size(0)) != 0 &&
		(n2 = l->get_size(1)) != 0)
	{
		(*par)[0] = new nsl_num_matrix("par0",0,n1,n2,1); //added arg '1' to remove ambiguity -bn7
		(*par)[1] = new nsl_num_matrix("par1",0,n1,n2,1);
		(*par)[2] = new nsl_num_matrix("par2",0,n1,n2,1);
	}
	else
		cmd_error("ramp_matrix_library: Bad Layer Size");
}

nsl_ramp_matrix_library::~nsl_ramp_matrix_library()
{
}

nsl_library* nsl_ramp_matrix_library::make_copy(nsl_layer* l)
{
	return new nsl_ramp_matrix_library(l);
}
nsl_layer* nsl_ramp_matrix_library::make_par_copy(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
	{
	   nsl_layer* n_par = new nsl_num_matrix(*((nsl_num_matrix*)(*par)[i]));
	   n_par->set_name((*par)[i]->get_name());
	   return n_par;
	}
	else
	{
	   cmd_error("ramp_matrix_library::make_par_copy: BAD par: ",i);
	   return 0;
	}
}

// if a > b then a - b + y2 else y1

int nsl_ramp_matrix_library::run(nsl_layer* out,nsl_layer* in)
{
	return 1;
}
