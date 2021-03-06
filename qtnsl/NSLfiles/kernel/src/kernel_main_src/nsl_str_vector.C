/* SCCS  @(#)nsl_str_vector.C	1.2---95/08/13--18:20:35 */
//
//	nsl_str_vector.C
//

#include "nsl_str_vector.h"
#include "nsl_str_data.h"
#include "nsl_buffer.h"
#include "nsl_str_matrix.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);

nsl_str_vector::nsl_str_vector(const int s,int sfg,int fg,int rfg) : 
	nsl_vector_layer(s,sfg,fg,rfg)
{
	init_str_vector(s);
}
nsl_str_vector::nsl_str_vector(const char* str,nsl_model* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg) : 
	nsl_vector_layer("str_vector",str,m,s,vtype,sfg,fg,rfg)
{
	init_str_vector(s);
}
nsl_str_vector::nsl_str_vector(const nsl_str_vector& a,
	int sfg,int fg,int rfg) : nsl_vector_layer(a.get_imax(),sfg,fg,rfg)
{
        int s = a.get_imax();

	init_str_vector(s);

	if (s > 0)
	{
//	    char** va = a.get_vector();

            for (int i = 0; i < s; i++)
                strcpy(v[i],a.v[i]);
	}
}

// nsl_str_vector destructors

nsl_str_vector::~nsl_str_vector()
{
	delete v;
}

// init

int nsl_str_vector::init_str_vector(const int s)
{
	if (s < 0)
	{
		cmd_error("ERROR: init_str_vector");
		cmd_error("name: ",get_name());
		cmd_error("s: ",s);
		cmd_error("Bad Vector Size");
		return 1;
	}
	else if (s == 0)
	{
		v = (char**) 0;
	}
	else
	{
		v = new char*[s];

		for (int i = 0; i < s; i++)
		{
			v[i] = new char[NSL_NAME_SIZE];
			strcpy(v[i],"");
		}
	}

	return 1;
}
int nsl_str_vector::alloc_mem(const int s)
{
	init_vector_layer(s);
	init_str_vector(s);
	return 1;
}

// vector object element

char*& nsl_str_vector::operator[](const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::operator[] ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (char*&) v[0];
	}

	return (char*&) v[i];
}
char*& nsl_str_vector::elem(const int i) 
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::elem ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (char*&) v[0];
	}

	return (char*&) v[i];
}
char* nsl_str_vector::set_value(const int i,char* val)
{
	return v[i] = (char*) val;
}

// vector assignment

char** nsl_str_vector::operator=(const nsl_str_vector& a)
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_str_vector::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		strcpy(v[i],a.v[i]);

	return v;
}
char** nsl_str_vector::operator=(const nsl_str_data& a)
{
	int timax = get_imax();  

	const char* val = a.get_value();

	for (int i = 0; i < timax; i++)
		strcpy(v[i],val);

	return v;
}
char** nsl_str_vector::operator=(const char* val)
{
	int timax = get_imax();  

 	for (int i = 0; i < timax; i++)
		strcpy(v[i],val);

	return v;
}

// expand

nsl_str_matrix nsl_str_vector::expand(const int n)
{
	if (vec_type == 1)
		return expand_col(n);
	else
		return expand_row(n);
}
nsl_str_matrix nsl_str_vector::expand_col(const int n)
{
	int simax = get_imax();
	int sjmax = n;

	nsl_str_matrix c(simax,sjmax);
	char*** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		strcpy(cv[i][j],v[i]);

	return c;
}
nsl_str_matrix nsl_str_vector::expand_row(const int n)
{
	int sjmax = get_imax();
	int simax = n;

	nsl_str_matrix c(simax,sjmax);
	char*** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		strcpy(cv[i][j],v[j]);

	return c;
}

// transpose

nsl_str_vector nsl_str_vector::transpose()
{
	vec_type = (vec_type == NSL_ROW) ? NSL_COL : NSL_ROW;

	return *this;
}
nsl_str_vector nsl_str_vector::transpose_row()
{
	vec_type = NSL_ROW; 

	return *this;
}
nsl_str_vector nsl_str_vector::transpose_col()
{
	vec_type = NSL_COL; 

	return *this;
}

// vector sector

nsl_str_vector nsl_str_vector::get_sector(const int si0,const int si1) const 
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

	nsl_str_vector c(simax);

	for (int i = si0; i <= si1; i++)
		strcpy(c.v[i-si0],v[i]); 

	return c;
}
nsl_str_vector nsl_str_vector::set_sector(const nsl_str_vector& a, 
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
		strcpy(v[i+si0],a.v[i]);

	return (*this);
}
nsl_str_vector nsl_str_vector::put_sector(const nsl_str_vector& a, 
	const int si0) 
{
	return set_sector(a,si0);
}

// print

int nsl_str_vector::print_str_vector_status(ostream& out) const 
{
	print_vector_layer_status(out);
	return 1;
}
int nsl_str_vector::print_status(ostream& out) const 
{
	print_str_vector_status(out);
	return 1;
}
int nsl_str_vector::print_str_vector(ostream& out) const 
{
	print_str_vector(out,0,get_imax()-1);
	return 1;
}
int nsl_str_vector::print_str_vector(ostream& out,const int si0, 
	const int si1) const 
{
	print_vector_layer(out);
	if (si0 > si1 || si0 < 0 || si1 > get_imax()-1)
	{
		cmd_error("ERROR: print_str_vector");
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
int nsl_str_vector::print(ostream& out) const 
{
	print_str_vector(out);
	return 1;
}

int nsl_str_vector::reset_str_vector(nsl_buffer* buf)
{
	nsl_string vs;

	if (buf == NULL)
	{
		for (int i = i0; i <= i1; i++)
			strcpy(v[i],"");
	}
	else
	{
		*buf >> vs;
		for (int i = i0; i <= i1; i++)
			strcpy(v[i],vs);
	}

	return 1;
}
int nsl_str_vector::reset(nsl_buffer* buf)
{
	reset_str_vector(buf);
	return 1;
}

int nsl_str_vector::write_str_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
		buf << v[i];
	return 1;
}
int nsl_str_vector::write(nsl_buffer& buf)
{
	write_str_vector(buf);
	return 1;
}
int nsl_str_vector::read_str_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	{	
	    if (buf.get_str_cnt() == 0)
		((nsl_interpreter*) buf.get_m_parent())->init_input();
	    buf >> v[i];
	}
	return 1;
}
int nsl_str_vector::read(nsl_buffer& buf)
{
	read_str_vector(buf);
	return 1;
}
