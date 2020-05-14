/* SCCS  @(#)nsl_int_vector.C	1.2---95/08/13--18:20:29 */
//
//	nsl_int_vector.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../../../MAIN/src/sys_main_src/nsl.h"

//# include "../../incl/kernel_main_incl/nsl_vector_layer.h"
//# include "../../incl/kernel_main_incl/nsl_int_vector.h"
#include "nsl_kernel.h"
#include "nsl_int_vector.h"
#include "nsl_int_data.h"
#include "nsl_int_matrix.h"
#include "nsl_buffer.h"
#include "nsl_interpreter.h"

extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

nsl_int_vector::nsl_int_vector(const int s,int rfg) : nsl_vector_layer(false, s,rfg)
{
	init_int_vector(s);
}
nsl_int_vector::nsl_int_vector(const char* str,const int s,
	row_col_enum vtype,int fg,int rfg) :
	nsl_vector_layer("int_vector",str,NULL,s,vtype,fg,rfg) //TODO: added NULL because no constructor has these arguments
{
	init_int_vector(s);
}
nsl_int_vector::nsl_int_vector(const nsl_int_vector& a,int rfg) : 
	nsl_vector_layer(false, a.get_imax(),rfg)
{
        const int s = a.get_imax();

	init_int_vector(s);

	if (s > 0)
	{
	    int* va = a.get_vector();

            for (int i = 0; i < s; i++)
                v[i] = va[i];
	}
}

// nsl_int_vector destructors

nsl_int_vector::~nsl_int_vector()
{
	delete v;
}

// init

int nsl_int_vector::init_int_vector(const int s)
{
	if (s < 0)
	{
		cmd_error("ERROR: init_int_vector");
		cmd_error("name: ",get_name());
		cmd_error("s: ",s);
		cmd_error("Bad Vector Size");
		return 1;
	}
	else if (s == 0)
	{
		v = (int*) 0;
	}
	else
	{
		v = new int[s];

		for (int i = 0; i < s; i++)
			v[i] = 0;
	}

	return 1;
}
int nsl_int_vector::alloc_mem(const int s)
{
	init_vector_layer(s);
	init_int_vector(s);
	return 1;
}

// vector object element

int& nsl_int_vector::operator[](const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_int_vector::operator[]");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (int&) v[0];
	}

	return (int&) v[i];
}
int& nsl_int_vector::elem(const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_int_vector::elem");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (int&) v[0];
	}

	return (int&) v[i];
}
int nsl_int_vector::set_value(const int i,const int val)
{
	return v[i] = (int) val;
}
int nsl_int_vector::set_value(const int i,const float val)
{
	return v[i] = (int) val;
}
int nsl_int_vector::set_value(const int i,const double val)
{
	return v[i] = (int) val;
}

// vector assignment

int* nsl_int_vector::operator=(const nsl_int_vector& a) 
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_int_vector::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		v[i] = a.v[i];

	return v;
}
int* nsl_int_vector::operator=(const nsl_int_data& a)
{
	int timax = get_imax();  

	int val = a.get_value();

	for (int i = 0; i < timax; i++)
		v[i] = val;

	return v;
}

int* nsl_int_vector::operator=(const double a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (int) a;

	return v;
}
int* nsl_int_vector::operator=(const float a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (int) a;

	return v;
}
int* nsl_int_vector::operator=(const int a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (int) a;

	return v;
}

int nsl_int_vector::max()
{
	int simax = get_imax();

	int c = v[0];

	for (int i = 0; i < simax; i++)
		if (v[i] > c)
			c = v[i];

	return c;
}
int nsl_int_vector::min()
{
	int simax = get_imax();

	int c = v[0];

	for (int i = 0; i < simax; i++)
		if (v[i] < c)
			c = v[i];

	return c;
}

int nsl_int_vector::max(int* im)
{
	int simax = get_imax();

	int c = v[0];
	*im = 0;

	for (int i = 0; i < simax; i++)
		if (v[i] > c)
		{
			c = v[i];
			*im = i;
		}

	return c;
}
int nsl_int_vector::min(int* im)
{
	int simax = get_imax();

	int c = v[0];
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

int nsl_int_vector::sum()
{
	int c = 0;

	for (int i = 0; i < imax; i++)
		c = v[i] + c;
	return c;
}

// expand

nsl_int_matrix nsl_int_vector::expand(const int n)
{
	if (vec_type == 1)
		return expand_col(n);
	else
		return expand_row(n);
}
nsl_int_matrix nsl_int_vector::expand_col(const int n)
{
	int simax = get_imax();
	int sjmax = n;

	nsl_int_matrix c(simax,sjmax);
	int** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[i];

	return c;
}
nsl_int_matrix nsl_int_vector::expand_row(const int n)
{
	int sjmax = get_imax();
	int simax = n;

	nsl_int_matrix c(simax,sjmax);
	int** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[j];

	return c;
}

// transpose

nsl_int_vector nsl_int_vector::transpose()
{
	vec_type = (vec_type == NSL_COL) ? NSL_ROW : NSL_COL;

	return *this;
}
nsl_int_vector nsl_int_vector::transpose_row()
{
	vec_type = NSL_ROW;  

	return *this;
}
nsl_int_vector nsl_int_vector::transpose_col()
{
	vec_type = NSL_COL;  

	return *this;
}

// vector sector

nsl_int_vector nsl_int_vector::get_sector(const int si0,const int si1) const
{
	if (si0 > si1 || si0 < 0 || si1 > get_imax())
	{
		cmd_error("ERROR: nsl_int_vector::get_sector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("Bad vector sector");
		return 0;
	}

	int simax = si1 - si0 + 1;

	nsl_int_vector c(simax);

	for (int i = si0; i <= si1; i++)
		c.v[i-si0] = v[i]; 

	return c;
}
nsl_int_vector nsl_int_vector::set_sector(const nsl_int_vector& a,
	const int si0) 
{
	if (si0 < 0)
	{
		cmd_error("ERROR: nsl_int_vector::get_sector");
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
nsl_int_vector nsl_int_vector::put_sector(const nsl_int_vector& a,
	const int si0)
{
	return set_sector(a,si0);
}

// print

int nsl_int_vector::print_int_vector_status(ostream& out) const
{
	print_vector_layer_status(out);
	return 1;
}
int nsl_int_vector::print_status(ostream& out) const
{
	print_int_vector_status(out);
	return 1;
}
int nsl_int_vector::print_int_vector(ostream& out) const
{
	print_int_vector(out,0,get_imax()-1);
	return 1;
}
int nsl_int_vector::print_int_vector(ostream& out,
	const int si0,const int si1) const 
{
	print_vector_layer(out);
	if (si0 > si1 || si0 < 0 || si1 > get_imax()-1)
	{
		cmd_error("ERROR: print_int_vector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("i0: ",i0);
		cmd_error("i1: ",i1);
		cmd_error("Bad vector sector");
		return 0;
	}

	for (int i = si0; i <= si1; i++)
		out << v[i] << " "; 
	out << "\n";
	out.flush();

	return 1;
}
int nsl_int_vector::print(ostream& out) const
{
	print_int_vector(out);
	return 1;
}

int nsl_int_vector::reset_int_vector(nsl_buffer* buf)
{
	int vs;

	if (buf == NULL)
		(*this) = 0;
	else
	{
		*buf >> vs;
		(*this) = vs;
	}

	return 1;
}
int nsl_int_vector::reset(nsl_buffer* buf)
{
	reset_int_vector(buf);
	return 1;
}

int nsl_int_vector::write_int_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
		buf << v[i];
	return 1;
}
int nsl_int_vector::write(nsl_buffer& buf)
{
	write_int_vector(buf);
	return 1;
}
int nsl_int_vector::read_int_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	{	
	    if (buf.get_str_cnt() == 0)
		((nsl_interpreter*) buf.get_m_parent())->init_input();
	    buf >> v[i];
	}
	return 1;
}
int nsl_int_vector::read(nsl_buffer& buf)
{
	read_int_vector(buf);
	return 1;
}



