/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_matrix.C
//

#include "nsl_num_matrix.h"
#include "nsl_num_vector.h"
#include "nsl_kernel.h"
#include "nsl_stream.h"

extern void cmd_out(float);
extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

nsl_num_matrix::nsl_num_matrix(const int s1,const int s2,int rfg) :
	nsl_matrix_layer(false, s1,s2,rfg)
{
	init_num_matrix(s1,s2);
}
nsl_num_matrix::nsl_num_matrix(const char* str,const int s1,const int s2,
	int fg,int rfg) : nsl_matrix_layer("num_matrix",str,s1,s2,fg,rfg)
{
	init_num_matrix(s1,s2);
}
nsl_num_matrix::nsl_num_matrix(const nsl_num_matrix& a,int rfg) :
	nsl_matrix_layer(false, a.get_imax(),a.get_jmax(),rfg)
{
        int s1 = a.get_imax();
        int s2 = a.get_jmax();

        v = new num_type*[s1];

        for (int i = 0; i < s1; i++)
                v[i] = new num_type[s2];

        for (int i = 0; i < s1; i++)
           for (int j = 0; j < s2; j++)
                v[i][j] = a.v[i][j];
}

// nsl_num_matrix destructors

nsl_num_matrix::~nsl_num_matrix()
{
	for (int i = 0; i < get_imax(); i++)
		delete v[i];

	delete v;
}

// init

int nsl_num_matrix::init_num_matrix(const int s1,const int s2)
{
	if (s1 < 0 || s2 < 0)
	{
		cmd_error("ERROR: init_num_matrix");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("Cannot create matrix");
		return 0;
	}
	else if (s1 == 0 || s2 == 0)
	{
		v = (num_type**) 0;
	}
	else
	{
		v = new num_type*[s1];

		for (int i = 0; i < s1; i++)
			v[i] = new num_type[s2];

		for (int i = 0; i < s1; i++)
		   for (int j = 0; j < s2; j++)
			v[i][j] = 0;
	}

	return 1;
}
int nsl_num_matrix::alloc_mem(const int s1,const int s2)
{
	init_matrix_layer(s1,s2);
	init_num_matrix(s1,s2);
	return 1;
}

// matrix object element

num_type& nsl_num_matrix::elem(const int i,const int j)
{
	if ((i < 0 || imax <= i) || (j < 0 || jmax <= j))
	{
		cmd_error("ERROR: nsl_num_2::elem");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("j: ",j);
		cmd_error("Matrix index out of range");
		return (num_type&) v[0][0];
	}

	return (num_type&) v[i][j];
}
num_type nsl_num_matrix::set_value(const int i,const int j,const int val)
{
	return v[i][j] = (num_type) val;
}
num_type nsl_num_matrix::set_value(const int i,const int j,const float val)
{
	return v[i][j] = (num_type) val;
}
num_type nsl_num_matrix::set_value(const int i,const int j,const double val)
{
	return v[i][j] = (num_type) val;
}

// matrix assignment

num_type** nsl_num_matrix::operator=(const nsl_num_matrix& a)
{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = a.v[i][j];

	return v;
}
num_type** nsl_num_matrix::operator=(const nsl_num_data& a)
{
	int timax = get_imax();  
	int tjmax = get_jmax();

	num_type val = a.get_value();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = val;

	return v;
}

num_type** nsl_num_matrix::operator=(const double a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = (num_type) a;

	return v;
}
num_type** nsl_num_matrix::operator=(const float a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = (num_type) a;

	return v;
}
num_type** nsl_num_matrix::operator=(const int a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = (num_type) a;

	return v;
}

num_type nsl_num_matrix::max()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	num_type c = v[0][0];

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] > c)
			c = v[i][j];

	return c;
}
num_type nsl_num_matrix::min()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	num_type c = v[0][0];

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] < c)
			c = v[i][j];

	return c;
}
num_type nsl_num_matrix::max(int* im,int* jm)
{
	int simax = get_imax();
	int sjmax = get_jmax();

	num_type c = v[0][0];
	*im = *jm = 0;

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] > c)
		{
			*im = i;
			*jm = j;
			c = v[i][j];
		}

	return c;
}
num_type nsl_num_matrix::min(int* im,int* jm)
{
	int simax = get_imax();
	int sjmax = get_jmax();

	num_type c = v[0][0];
	*im = *jm = 0;

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] < c)
		{
			*im = i;
			*jm = j;
			c = v[i][j];
		}

	return c;
}

// element sum

num_type nsl_num_matrix::sum()
{
	num_type c = 0;

	for (int i = 0; i < imax; i++)
	    for (int j = 0; j < jmax; j++)
		c = v[i][j] + c;

	return c;
}

// vector transformations

nsl_num_vector nsl_num_matrix::reduce_col()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	nsl_num_vector c(simax);
	num_type* cv = c.get_vector();

	for (int j = 0; j < sjmax; j++)
	    for (int i = 0; i < simax; i++)
		cv[i] = v[i][j] + cv[i];

	return c;
}
nsl_num_vector nsl_num_matrix::reduce_row()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	nsl_num_vector c(sjmax);
	num_type* cv = c.get_vector();

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		cv[j] = v[i][j] + cv[j];

	return c;
}

// matrix sector

nsl_num_matrix nsl_num_matrix::get_sector(const int si0, const int si1,
	const int sj0, const int sj1) const
{
	if (si0 > si1 || sj0 > sj0 || si0 < 0 || sj0 < 0 ||
	    si1 > get_imax() || sj1 > get_jmax())
	    {
		cmd_error("ERROR: nsl_num_matrix::get_sector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("Bad matrix sector");
		return 0;
	    }

	int simax = si1 - si0 + 1;
	int sjmax = sj1 - sj0 + 1;

	nsl_num_matrix c(simax,sjmax);

	for (int i = si0; i <= si1; i++)
	    for (int j = sj0; j <= sj1; j++)
		c.v[i-si0][j-sj0] = v[i][j];

	return c;
}
nsl_num_matrix nsl_num_matrix::set_sector(const nsl_num_matrix& a,
	const int si0, const int sj0)
{
	if (si0 < 0 || sj0 < 0)
	{
		cmd_error("ERROR: nsl_num_matrix::set_sector");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("i0: ",si0);
		cmd_error("j0: ",sj0);
		cmd_error("Bad matrix sector");
		return 0;
	}

	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
	int simax = get_imax();
	int sjmax = get_jmax();

	int scimax = (saimax < simax) ? saimax : simax;
	int scjmax = (sajmax < sjmax) ? sajmax : sjmax;

	for (int i = 0; i < scimax; i++)
	    for (int j = 0; j < scjmax; j++)
		v[i+si0][j+sj0] = a.v[i][j];

	return (*this);
}
nsl_num_matrix nsl_num_matrix::put_sector(const nsl_num_matrix& a,
	const int si0, const int sj0)
{
	return set_sector(a,si0,sj0);
}
nsl_num_vector nsl_num_matrix::get_row(const int i) const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_matrix::get_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_vector a(jmax);

	for (int j = 0; j < jmax; j++)
		a.elem(j) = v[i][j];

	return a;
}
nsl_num_vector nsl_num_matrix::get_col(const  int j) const
{
	if (j < 0 || jmax <= j)
	{
		cmd_error("ERROR: nsl_num_matrix::get_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix col index out of range");
		return 0;
	}

	nsl_num_vector a(imax);

	for (int i = 0; i < imax; i++)
		a.elem(i) = v[i][j];

	return a;
}
nsl_num_matrix nsl_num_matrix::set_row(const nsl_num_vector& a,const int i)
{
	if (i < 0 || imax <= i || a.get_imax() != jmax)
	{
		cmd_error("ERROR: nsl_num_matrix::set_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_matrix c(imax,jmax);

	c = (*this);
	num_type* av = a.get_vector();

	for (int j = 0; j < jmax; j++)
		c.v[i][j] = av[j];

	return c;
}
nsl_num_matrix nsl_num_matrix::set_col(const nsl_num_vector& a,const int j)
{
	if (j < 0 || jmax <= j || a.get_imax() != imax)
	{
		cmd_error("ERROR: nsl_num_matrix::set_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_matrix c(imax,jmax);

	c = (*this);
	num_type* av = a.get_vector();

	for (int i = 0; i < imax; i++)
		c.v[i][j] = av[i];

	return c;
}

// print

int nsl_num_matrix::print_num_matrix_status(ostream& out) const
{
	print_matrix_layer_status(out);
	return 1;
}
int nsl_num_matrix::print_status(ostream& out) const
{
	print_num_matrix_status(out);
	return 1;
}
int nsl_num_matrix::print_num_matrix(ostream& out) const
{
	print_num_matrix(out,0,imax-1,0,jmax-1);
	return 1;
}
int nsl_num_matrix::print_num_matrix(ostream& out,
	const int si0, const int si1, const int sj0,const  int sj1) const
{
	print_matrix_layer(out);
	if (si0 > si1 || sj0 > sj1 || si0 < 0 || sj0 < 0 ||
	    si1 > get_imax()-1 || sj1 > get_jmax()-1)
	    {
		cmd_error("ERROR: nsl_num_2::print");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("i0: ",i0);
		cmd_error("j0: ",j0);
		cmd_error("i1: ",i1);
		cmd_error("j1: ",j1);
		cmd_error("Bad matrix sector");
		return 0;
	    }

	for (int i = si0; i <= si1; i++)
	{
	    for (int j = sj0; j <= sj1; j++)
		cmd_out(v[i][j]);
	    cmd_out("\n");
	}

	return 1;
}
int nsl_num_matrix::print(ostream& out) const
{
	print_num_matrix(out);
	return 1;
}

int nsl_num_matrix::reset_num_matrix(nsl_buffer* buf)
{
	num_type vs;

 	if (buf == NULL)
		(*this) = 0;
	else
	{
		*buf >> vs;
 		(*this) = vs;
	}

	return 1;
}
int nsl_num_matrix::reset(nsl_buffer* buf)
{
	reset_num_matrix(buf);
	return 1;
}

int nsl_num_matrix::write_num_matrix(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		buf << v[i][j];
	return 1;
}
int nsl_num_matrix::write(nsl_buffer& buf)
{
	write_num_matrix(buf);
	return 1;
}
int nsl_num_matrix::read_num_matrix(nsl_buffer& buf)
{
	int ti0 = i0, ti1 = i1, tj0 = j0, tj1 = j1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
		buf >> j0;
		buf >> j1;
	}
	if (value_fg == 1)
	{
	  num_type val;
	  buf >> val; 
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		v[i][j] = val;
	}
	else
	{
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
	    {
	        if (buf.get_str_cnt() == 0)
		    ((nsl_interpreter*) buf.get_m_parent())->init_input();
		buf >> v[i][j];
	    }
	}

	i0 = ti0; i1 = ti1; j0 = tj0; j1 = tj1;

	return 1;
}
int nsl_num_matrix::read(nsl_buffer& buf)
{
	read_num_matrix(buf);
	return 1;
}

