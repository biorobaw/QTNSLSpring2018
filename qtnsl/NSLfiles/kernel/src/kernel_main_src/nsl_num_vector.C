/* SCCS  @(#)nsl_num_vector.C	1.1---95/10/13--16:37:12 */
//
//	nsl_num_vector.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_stream.h"
#include "nsl_buffer.h"
#include "nsl_kernel.h"

#include "nsl_num_1.h"

extern void cmd_error(const char *, const char *);
extern void cmd_error(const char *);
extern void cmd_out(const char *);
extern void cmd_out(float);

nsl_num_vector::nsl_num_vector(const int s,int rfg) : nsl_vector_layer(false, s,rfg)
{
	init_num_vector(s);
}
nsl_num_vector::nsl_num_vector(const char* str,const int s,row_col_enum vtype,
	int fg,int rfg) : nsl_vector_layer("num_vector",str,NULL,s,vtype,fg,rfg)
{
	init_num_vector(s);
}
nsl_num_vector::nsl_num_vector(const nsl_num_vector& a,int rfg) : 
	nsl_vector_layer(false, a.get_imax(),rfg)
{
        int s = a.get_imax();

	init_num_vector(s);

	if (s > 0)
	{
//	    num_type* va = a.get_vector();

            for (int i = 0; i < s; i++)
                v[i] = a.v[i];
	}
}

//NEW CONSTRUCTOR -bn7
//nsl_num_vector(nsl_num_1&a);
nsl_num_vector::nsl_num_vector(const nsl_num_1& a) :
	nsl_vector_layer(false, a.get_imax(),1)
{
        int s = a.get_imax();

	init_num_vector(s);

	if (s > 0)
	{
//	    num_type* va = a.get_vector();

            for (int i = 0; i < s; i++)
                v[i] = a[i];
	}
}
/////
// nsl_num_vector destructors

nsl_num_vector::~nsl_num_vector()
{
	delete v;
}

// init

int nsl_num_vector::init_num_vector(const int s)
{
	if (s < 0)
	{
		cmd_error("ERROR: init_num_vector");
		cmd_error("name: ",get_name());
		cmd_error("s: ",s);
		cmd_error("Bad Vector Size");
		return 1;
	}
	else if (s == 0)
	{
		v = (num_type*) 0;
	}
	else
	{
		v = new num_type[s];

		for (int i = 0; i < s; i++)
			v[i] = 0;
	}

	return 1;
}
int nsl_num_vector::alloc_mem(const int s)
{
	init_vector_layer(s);
	init_num_vector(s);
	return 1;
}

// vector object element

num_type& nsl_num_vector::operator[](const int i) const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::operator[] ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (num_type&) v[0];
	}

	return (num_type&) v[i];
}
num_type& nsl_num_vector::elem(const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::elem ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (num_type&) v[0];
	}

	return (num_type&) v[i];
}
num_type nsl_num_vector::set_value(const int i,const int val)
{
	return v[i] = (num_type) val;
}
num_type nsl_num_vector::set_value(const int i,const float val)
{
	return v[i] = (num_type) val;
}
num_type nsl_num_vector::set_value(const int i,const double val)
{
	return v[i] = (num_type) val;
}

// vector assignment

num_type* nsl_num_vector::operator=(const nsl_num_vector& a)
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_num_vector::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		v[i] = a.v[i];

	return v;
}
num_type* nsl_num_vector::operator=(const nsl_num_data& a)
{
	int timax = get_imax();  

	num_type val = a.get_value();

	for (int i = 0; i < timax; i++)
		v[i] = val;

	return v;
}

num_type* nsl_num_vector::operator=(const double a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (num_type) a;

	return v;
}
num_type* nsl_num_vector::operator=(const float a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (num_type) a;

	return v;
}
num_type* nsl_num_vector::operator=(const int a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (num_type) a;

	return v;
}

num_type nsl_num_vector::max()
{
	int simax = get_imax();

	num_type c = v[0];

	for (int i = 0; i < simax; i++)
		if (v[i] > c)
			c = v[i];

	return c;
}
num_type nsl_num_vector::min()
{
	int simax = get_imax();

	num_type c = v[0];

	for (int i = 0; i < simax; i++)
		if (v[i] < c)
			c = v[i];

	return c;
}

num_type nsl_num_vector::max(int* im)
{
	int simax = get_imax();

	num_type c = v[0];
	*im = 0;

	for (int i = 0; i < simax; i++)
		if (v[i] > c)
		{
			c = v[i];
			*im = i;
		}

	return c;
}
num_type nsl_num_vector::min(int* im)
{
	int simax = get_imax();

	num_type c = v[0];
	*im = 0;

	for (int i = 0; i < simax; i++)
		if (v[i] < c)
		{
			c = v[i];
			*im = i;
		}

	return c;
}

// element sum

num_type nsl_num_vector::sum()
{
	num_type c = 0;

	for (int i = 0; i < imax; i++)
		c = v[i] + c;
	return c;
}

// expand

nsl_num_matrix nsl_num_vector::expand(const int n)
{
	if (vec_type == 1)
		return expand_col(n);
	else
		return expand_row(n);
}
nsl_num_matrix nsl_num_vector::expand_col(const int n)
{
	int simax = get_imax();
	int sjmax = n;

	nsl_num_matrix c(simax,sjmax);
	num_type** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[i];

	return c;
}
nsl_num_matrix nsl_num_vector::expand_row(const int n)
{
	int sjmax = get_imax();
	int simax = n;

	nsl_num_matrix c(simax,sjmax);
	num_type** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[j];

	return c;
}

// transpose

nsl_num_vector nsl_num_vector::transpose()
{
	vec_type = (vec_type == NSL_ROW) ? NSL_COL : NSL_ROW;

	return *this;
}
nsl_num_vector nsl_num_vector::transpose_row()
{
	vec_type = NSL_ROW; 

	return *this;
}
nsl_num_vector nsl_num_vector::transpose_col()
{
	vec_type = NSL_COL; 

	return *this;
}

// vector sector

nsl_num_vector nsl_num_vector::get_sector(const int si0, const int si1) const 
{
	if (si0 > si1 || si0 < 0 || si1 > get_imax())
	{
		cmd_error("ERROR: nsl_num_vector::get_sector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("Bad vector sector");
		return 0;
	}

	int simax = si1 - si0 + 1;

	nsl_num_vector c(simax);

	for (int i = si0; i <= si1; i++)
		c.v[i-si0] = v[i]; 

	return c;
}
nsl_num_vector nsl_num_vector::set_sector(const nsl_num_vector& a,
	const int si0) 
{
	if (si0 < 0)
	{
		cmd_error("ERROR: nsl_num_vector::get_sector");
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
nsl_num_vector nsl_num_vector::put_sector(const nsl_num_vector& a, 
	const int si0) 
{
	return set_sector(a,si0);
}

// print

int nsl_num_vector::print_num_vector_status(ostream& out) const
{
	print_vector_layer_status(out);
	return 1;
}
int nsl_num_vector::print_status(ostream& out) const
{
	print_num_vector_status(out);
	return 1;
}
int nsl_num_vector::print_num_vector(ostream& out) const
{
	print_num_vector(out,0,get_imax()-1);
	return 1;
}
int nsl_num_vector::print_num_vector(ostream& out,const int si0,
	const int si1) const 
{
	print_vector_layer(out);
	if (si0 > si1 || si0 < 0 || si1 > get_imax()-1)
	{
		cmd_error("ERROR: print_num_vector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("i0: ",i0);
		cmd_error("i1: ",i1);
		cmd_error("Bad vector sector");
		return 0;
	}

	for (int i = si0; i <= si1; i++)
		cmd_out(v[i]); 
	cmd_out("\n");

	return 1;
}
int nsl_num_vector::print(ostream& out) const
{
	print_num_vector(out);
	return 1;
}

int nsl_num_vector::reset_num_vector(nsl_buffer* buf)
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
int nsl_num_vector::reset(nsl_buffer* buf)
{
	reset_num_vector(buf);
	return 1;
}

int nsl_num_vector::write_num_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
		buf << v[i];
	return 1;
}
int nsl_num_vector::write(nsl_buffer& buf)
{
	write_num_vector(buf);
	return 1;
}
int nsl_num_vector::read_num_vector(nsl_buffer& buf)
{
	int ti0 = i0, ti1 = i1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
	}
	if (value_fg == 1)
	{
	  num_type val;
	  buf >> val; 
	  for (int i = i0; i <= i1; i++)
		v[i] = val; 
	}
	else
	{
	  for (int i = i0; i <= i1; i++)
	  {	
	    if (buf.get_str_cnt() == 0)
		((nsl_interpreter*) buf.get_m_parent())->init_input();
	    buf >> v[i];
	  }
	}

	i0 = ti0; i1 = ti1;

	return 1;
}
int nsl_num_vector::read(nsl_buffer& buf)
{
	read_num_vector(buf);
	return 1;
}


