/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_1.h
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_num_0.h"
#include "nsl_num_1.h"
#include "nsl_num_2.h"
#include "nsl_model.h"
#include "nsl_buffer.h"
#include "nsl_stream.h"
#include "nsl_interpreter.h"
#include "nsl_num_vector.h"
#include <stddef.h>

extern int TRACE_FG;
extern fstream* NSL_FILE;

extern int NSLoutput(const float str1);
extern int NSLoutput(const char *);
extern int NSLoutput(const char *, std::ostream &);
extern int NSLoutput(const float str1,std::ostream& out);

//template<class NslNumType, int NslTypeId>
nsl_num_1::nsl_num_1(const int s,int sfg,int fg,int rfg) :
	nsl_vector_layer(s,sfg,fg,rfg)
{
	init_num_vector(s);
}
//template<class NslNumType, int NslTypeId>
nsl_num_1::nsl_num_1(const char* str,nsl_public* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg) : 
	nsl_vector_layer("num_vector",str,m,s,vtype,sfg,fg,rfg)
{
	init_num_vector(s);
}
//template<class NslNumType, int NslTypeId>
nsl_num_1::nsl_num_1(const NslFloat1& a,
	int sfg,int fg,int rfg) : nsl_vector_layer(a.get_imax(),sfg,fg,rfg)
{
    int s = a.get_imax();

	v = new NslNumType[s];

    for (int i = 0; i < s; i++)
        v[i] = a[i];
}

// nsl_num_1 destructors

//template<class NslNumType, int NslTypeId>
nsl_num_1::~nsl_num_1()
{
	delete v;
}

//template<class NslNumType, int NslTypeId>
void nsl_num_1::initialize(const char* str,nsl_public* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg)
{
	nsl_vector_layer::initialize("num_vector",str,m,s,vtype,sfg,fg,rfg);
	init_num_vector(s);
}

// init

//template<class NslNumType, int NslTypeId>
int nsl_num_1::init_num_vector(const int s)
{
	set_type_id(1);

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
		v = (NslNumType*) 0;
	}
	else
	{
	     	v = new NslNumType[s];
            	for (int i = 0; i < s; i++)
        		v[i] = 0;
	}

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::memAlloc(const int s)
{
	init_vector_layer(s);
	init_num_vector(s);
	return 1;
}

// vector object element

//template<class NslNumType, int NslTypeId>
NslNumType& nsl_num_1::operator[](const int i) const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::operator[] ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return v[0];
	}

	return v[i];
}
//template<class NslNumType, int NslTypeId>
NslNumType& nsl_num_1::elem(const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::elem ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return v[0];
	}

	return v[i];
}
//template<class NslNumType, int NslTypeId>
void nsl_num_1::set_value(const int i,const NslNumType val)
{
	v[i] = (NslNumType) val;
}

// vector assignment

//ADDED NEW = OPERATOR -bn7
nsl_num_1& nsl_num_1::operator=(const nsl_num_vector& a)
{
	if (a.get_imax() != imax)
	{
		cmd_error("ERROR: nsl_num_1<int>::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent vector sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
	{
		v[i] = a[i];
	}

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}

//template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_1::operator=(const NslFloat1& a)
{
	if (a.get_imax() != imax)
	{
		cmd_error("ERROR: nsl_num_1<int>::operator=");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent vector sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a[i];

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}

//template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_1::operator=(const NslFloat0& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) val;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}


//template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_1::operator=(const float a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}
//template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_1::operator=(const double a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}
//template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_1::operator=(const int a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}

//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_1::max()
{
	NslNumType c = v[0];

	for (int i = 0; i < imax; i++)
		if (v[i] > c)
			c = v[i];

	return c;
}
//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_1::min()
{
	NslNumType c = v[0];

	for (int i = 0; i < imax; i++)
		if (v[i] < c)
			c = v[i];

	return c;
}

//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_1::max(int& im)
{
	NslNumType c = v[0];
	im = 0;

	for (int i = 0; i < imax; i++)
		if (v[i] > c)
		{
			c = v[i];
			im = i;
		}

	return c;
}
//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_1::min(int& im)
{
	NslNumType c = v[0];
	im = 0;

	for (int i = 0; i < imax; i++)
		if (v[i] < c)
		{
			c = v[i];
			im = i;
		}

	return c;
}

// element sum

//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_1::sum()
{
	NslNumType c = 0;

	for (int i = 0; i < imax; i++)
		c = v[i] + c;

	return c;
}

// expand

//template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_1::expand(const int n)
{
	if (vec_type == 1)
		return expand_col(n);
	else
		return expand_row(n);
}
//template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_1::expand_col(const int n)
{
	int simax = get_imax();
	int sjmax = n;

	nsl_num_2 c(simax,sjmax);
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		c[i][j] = v[i];

	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_1::expand_row(const int n)
{
	int sjmax = get_imax();
	int simax = n;

	nsl_num_2 c(simax,sjmax);
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		c[i][j] = v[j];

	return c;
}

// transpose

//template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_1::transpose()
{
	vec_type = (vec_type == NSL_ROW) ? NSL_COL : NSL_ROW;

	return *this;
}
//template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_1::transpose_row()
{
	vec_type = NSL_ROW; 

	return *this;
}
//template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_1::transpose_col()
{
	vec_type = NSL_COL; 

	return *this;
}

// vector sector

//template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_1::get_sector(const int si0,
	const int si1) const 
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

	nsl_num_1 c(simax);

	for (int i = si0; i <= si1; i++)
		c[i-si0] = v[i]; 

	return c;
}

//template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_1::set_sector(
	const nsl_num_1& a, const int si0)
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
		v[i+si0] = a[i];

	return *this;
}
//template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_1::put_sector(
	const nsl_num_1& a, const int si0)
{
	return set_sector(a,si0);
}

// print

//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_num_vector_status() const
{
	print_vector_layer_status();
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::nslStatus() const
{
	print_num_vector_status();
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_num_vector() const
{
	print_num_vector(0,get_imax()-1);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_num_vector(const int si0, const int si1) const
{
	if (sub_layer_fg == 0)
		print_vector_layer();

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
		NSLoutput(v[i]);
	NSLoutput("\n");

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::nslPrint() const
{
	print_num_vector();
/*
//	print_vector_layer(cout);
	for (int i = 0; i <= get_imax()-1; i++)
		NSLoutput(v[i]);
	NSLoutput("\n");
*/
	return 1;
}

// ostream

//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_num_vector_status(ostream& out) const
{
	print_vector_layer_status(out);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_status(ostream& out) const
{
	print_num_vector_status(out);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_num_vector(ostream& out) const
{
	print_num_vector(out,0,get_imax()-1);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_1::print_num_vector(ostream& out,const int si0,
	const int si1) const 
{
	if (sub_layer_fg == 0)
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
		NSLoutput(v[i],out); 
	NSLoutput("\n",out);

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::print(ostream& out) const
{
	print_num_vector(out);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_1::reset_num_vector(nsl_buffer* buf)
{
	NslNumType vs;

	if (buf == NULL)
		(*this) = 0;
	else
	{
		*buf >> vs;
		(*this) = vs;
	}

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::reset(nsl_buffer* buf)
{
	reset_num_vector(buf);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_1::write_num_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
		buf << v[i];
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::write(nsl_buffer& buf)
{
	write_num_vector(buf);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::read_num_vector(nsl_buffer& buf)
{
	int ti0 = i0, ti1 = i1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
	}
	if (value_fg == 1)
	{
	  NslNumType val;
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
//template<class NslNumType, int NslTypeId>
int nsl_num_1::read(nsl_buffer& buf)
{
	read_num_vector(buf);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_1::write_num_vector(nsl_char_buf& buf)
{
	for (int i = i0; i <= i1; i++)
		sprintf(buf.get_sbuf(),"%f",v[i]);

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::write(nsl_char_buf& buf)
{
	write_num_vector(buf);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::read_num_vector(nsl_char_buf&)
{
/*	int ti0 = i0, ti1 = i1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
	}
	if (value_fg == 1)
	{
	  NslNumType val;
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
*/
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_1::read(nsl_char_buf& buf)
{
	read_num_vector(buf);
	return 1;
}

