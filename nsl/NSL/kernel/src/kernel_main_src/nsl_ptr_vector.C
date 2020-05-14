/* SCCS  %W%---%E%--%U% */
//
//	nsl_ptr_vector.C
//

#include <stddef.h>
#include "nsl_ptr_vector.h"
#include "nsl_ptr_matrix.h"
#include "nsl_ptr_data.h"
#include "nsl_base.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);
extern void cmd_error(const char *, const char *);
extern void cmd_error(const char *, int);

nsl_ptr_vector::nsl_ptr_vector(const int s,int sfg,int fg,int rfg) : 
	nsl_vector_layer(s,sfg,fg,rfg)
{
	init_ptr_vector(s);
}
nsl_ptr_vector::nsl_ptr_vector(const char* str,nsl_model* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg) : 
	nsl_vector_layer("ptr_vector",str,m,s,vtype,sfg,fg,rfg)
{
	init_ptr_vector(s);
}
nsl_ptr_vector::nsl_ptr_vector(const nsl_ptr_vector& a,int sfg,int fg,
	int rfg) : nsl_vector_layer(a.get_imax(),sfg,fg,rfg)
{
        int s = a.get_imax();

	init_ptr_vector(s);

	if (s > 0)
	{
//	    nsl_base** va = a.get_vector();

            for (int i = 0; i < s; i++)
                v[i] = a.v[i];
	}
}

// nsl_ptr_vector destructors

nsl_ptr_vector::~nsl_ptr_vector()
{
	delete v;
}

// init

int nsl_ptr_vector::init_ptr_vector(const int s)
{
	if (s < 0)
	{
		cmd_error("ERROR: init_ptr_vector");
		cmd_error("name: ",get_name());
		cmd_error("s: ",s);
		cmd_error("Bad Vector Size");
		return 1;
	}
	else if (s == 0)
	{
		v = (nsl_base**) 0;
	}
	else
	{
		v = new nsl_base*[s];

		for (int i = 0; i < s; i++)
			v[i] = 0;
	}

	return 1;
}
int nsl_ptr_vector::alloc_mem(const int s)
{
	init_vector_layer(s);
	init_ptr_vector(s);
	return 1;
}

// vector object element

nsl_base*& nsl_ptr_vector::operator[](const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::operator[] ***");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (nsl_base*&) v[0];
	}

	return (nsl_base*&) v[i];
}
nsl_base*& nsl_ptr_vector::elem(const int i) 
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::elem ***");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (nsl_base*&) v[0];
	}

	return (nsl_base*&) v[i];
}
nsl_base* nsl_ptr_vector::set_value(const int i,nsl_base* val)
{
	return v[i] = (nsl_base*) val;
}

// vector assignment

nsl_base** nsl_ptr_vector::operator=(const nsl_ptr_vector& a)
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_ptr_vector::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		v[i] = a.v[i];

	return v;
}
nsl_base** nsl_ptr_vector::operator=(const nsl_ptr_data& a)
{
	int timax = get_imax();  

	nsl_base* val = a.get_value();

	for (int i = 0; i < timax; i++)
		v[i] = val;

	return v;
}

// expand

nsl_ptr_matrix nsl_ptr_vector::expand(const int n)
{
	if (vec_type == 1)
		return expand_col(n);
	else
		return expand_row(n);
}
nsl_ptr_matrix nsl_ptr_vector::expand_col(const int n)
{
	int simax = get_imax();
	int sjmax = n;

	nsl_ptr_matrix c(simax,sjmax);
	nsl_base*** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[i];

	return c;
}
nsl_ptr_matrix nsl_ptr_vector::expand_row(const int n)
{
	int sjmax = get_imax();
	int simax = n;

	nsl_ptr_matrix c(simax,sjmax);
	nsl_base*** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[j];

	return c;
}

// transpose

nsl_ptr_vector nsl_ptr_vector::transpose()
{
	vec_type = (vec_type == NSL_ROW) ? NSL_COL : NSL_ROW;

	return *this;
}
nsl_ptr_vector nsl_ptr_vector::transpose_row()
{
	vec_type = NSL_ROW;  // row 

	return *this;
}
nsl_ptr_vector nsl_ptr_vector::transpose_col()
{
	vec_type = NSL_COL;  // col 

	return *this;
}

// vector sector

nsl_ptr_vector nsl_ptr_vector::get_sector(const int si0, const int si1) const 
{
	if (si0 > si1 || si0 < 0 || si1 > get_imax())
	{
		cmd_error("ERROR: nsl_num_1::get_sector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("Bad vector sector");
		return 0;
	}

	int simax = si1 - si0 + 1;

	nsl_ptr_vector c(simax);

	for (int i = si0; i <= si1; i++)
		c.v[i-si0] = v[i]; 

	return c;
}
nsl_ptr_vector nsl_ptr_vector::set_sector(const nsl_ptr_vector& a, 
	const int si0) 
{
	if (si0 < 0)
	{
		cmd_error("ERROR: nsl_num_1::get_sector");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("i0: ",si0);
		cmd_error("Bad vector sector");
		return 0;
	}

	int saimax = a.get_imax();
	int simax = get_imax();

	int smax = (saimax < simax) ? saimax : simax;

	for (int i = 0; i < smax; i++)
		v[i+si0] = a.v[i];

	return (*this);
}
nsl_ptr_vector nsl_ptr_vector::put_sector(const nsl_ptr_vector& a, 
	const int si0) 
{
	return set_sector(a,si0);
}

// print

int nsl_ptr_vector::print_ptr_vector_status(ostream& out) const
{
	print_vector_layer_status(out);
	return 1;
}
int nsl_ptr_vector::print_status(ostream& out) const
{
	print_ptr_vector_status(out);
	return 1;
}
int nsl_ptr_vector::print_ptr_vector(ostream& out) const
{
	print_ptr_vector(out,0,get_imax()-1);
	return 1;
}
int nsl_ptr_vector::print_ptr_vector(ostream& out,const int si0,
	const int si1) const 
{
	print_vector_layer(out);
	if (si0 > si1 || si0 < 0 || si1 > get_imax()-1)
	{
		cmd_error("ERROR: print_ptr_vector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("i0: ",i0);
		cmd_error("i1: ",i1);
		cmd_error("Bad vector sector");
		return 0;
	}

	for (int i = si0; i <= si1; i++)
	{
		v[i]->print(out);
		out << " "; 
	}
	out << "\n";
	out.flush();

	return 1;
}
int nsl_ptr_vector::print(ostream& out) const
{
	print_ptr_vector(out);
	return 1;
}

int nsl_ptr_vector::reset_ptr_vector(nsl_buffer* buf)
{
 	if (buf == NULL)
	{
		for (int i = 0; i < imax; i++)
 			v[i] = 0;
	}
	else
 		cmd_error("ptr_vector: Cannot reset from buffer");
 
	return 1;
}
int nsl_ptr_vector::reset(nsl_buffer* buf)
{
	reset_ptr_vector(buf);
	return 1;
}

int nsl_ptr_vector::write_ptr_vector(nsl_buffer& buf) 
{
	for (int i = 0; i < imax; i++)
	{
	   if (v[i] != NULL)
		v[i]->write(buf);
	   else
		cmd_error("ptr_vector: NULL ptr write element: ",i);
	}

	return 1;
}
int nsl_ptr_vector::write(nsl_buffer& buf)
{
	write_ptr_vector(buf);
	return 1;
}
int nsl_ptr_vector::read_ptr_vector(nsl_buffer& buf)
{
	for (int i = 0; i < imax; i++)
	{
	   if (v[i] != NULL)
		v[i]->read(buf);
	   else
		cmd_error("ptr_vector: NULL ptr read element: ",i);
	}

	return 1;
}
int nsl_ptr_vector::read(nsl_buffer& buf)
{
	read_ptr_vector(buf);
	return 1;
}

