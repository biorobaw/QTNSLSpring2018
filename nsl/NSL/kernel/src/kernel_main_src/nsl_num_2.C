/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_2.h
//

#include "nsl.h"
#include "nsl_kernel.h"
#include "nsl_num.h"
#include "nsl_num_library.h"
#include "nsl_buffer.h"
#include "nsl_stream.h"
#include "nsl_interpreter.h"
#include <stddef.h>

extern int TRACE_FG;
extern fstream* NSL_FILE;

extern int NSLoutput(const float str1);
extern int NSLoutput(const char *);
extern int NSLoutput(const char *, std::ostream&);
extern int NSLoutput(int, std::ostream&);

extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

////template<class NslNumType, int NslTypeId>
nsl_num_2::nsl_num_2(const int s1,const int s2,
	int sfg,int fg,int rfg) : nsl_matrix_layer(s1,s2,sfg,fg,rfg)
{
	init_num_matrix(s1,s2);
}
////template<class NslNumType, int NslTypeId>
nsl_num_2::nsl_num_2(const char* str,nsl_public* m,const int s1,
	const int s2, int sfg, int fg,int rfg) : 
	nsl_matrix_layer("num_matrix",str,m,s1,s2,sfg,fg,rfg)
{
	init_num_matrix(s1,s2);
}
////template<class NslNumType, int NslTypeId>
nsl_num_2::nsl_num_2(const NslFloat2& a,
	int sfg,int fg,int rfg) :
	nsl_matrix_layer(a.get_imax(),a.get_jmax(),sfg,fg,rfg)
{
	int i=0;

        int s1 = a.get_imax();
        int s2 = a.get_jmax();

	v = new nsl_num_1*[s1];

	for (i = 0; i < s1; i++)
		v[i] = new nsl_num_1(s2,1);

        for (i = 0; i < s1; i++)
        	*v[i] = a[i];
}

// destructors

////template<class NslNumType, int NslTypeId>
nsl_num_2::~nsl_num_2()
{
	for (int i = 0; i < get_imax(); i++)
		delete v[i];

	delete v;
}

// initialize

////template<class NslNumType, int NslTypeId>
void nsl_num_2::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, int sfg, int fg,int rfg)
{
	nsl_matrix_layer::initialize("num_matrix",str,m,s1,s2,sfg,fg,rfg);
	init_num_matrix(s1,s2);
}

// init

////template<class NslNumType, int NslTypeId>
int nsl_num_2::init_num_matrix(const int s1,const int s2)
{
	set_type_id(0);

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
		v = (nsl_num_1**) 0;
	}
	else
	{
		v = new nsl_num_1*[s1];

		for (int i = 0; i < s1; i++)
			v[i] = new nsl_num_1(s2,1);
	}

	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::memAlloc(const int s1,const int s2)
{
	init_matrix_layer(s1,s2);
	init_num_matrix(s1,s2);
	return 1;
}

// matrix object element

////template<class NslNumType, int NslTypeId>
NslNumType& nsl_num_2::elem(const int i,const int j)
{
	if ((i < 0 || imax <= i) || (j < 0 || jmax <= j))
	{
		cmd_error("ERROR: nsl_num_2::elem");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("j: ",j);
		cmd_error("Matrix index out of range");
		return (*v[0])[0];
	}

	return (*v[i])[j];
}
////template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_2::operator[](const int i)const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_2::operator[]");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("index out of range");
		return *v[0];
	}

	return *v[i];
}
////template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_num_2::get_vector(const int i) const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_2::get_vector");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("index out of range");
		return *v[0];
	}

	return *v[i];
}

////template<class NslNumType, int NslTypeId>
void nsl_num_2::set_value(const int i,const int j,
	const NslNumType val)
{
	(*v[i])[j] = (NslNumType) val;
}

// matrix assignment

////template<class NslNumType, int NslTypeId>
nsl_num_2& nsl_num_2::operator=(const NslFloat2& a)
{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}

//////template<class NslNumType, int NslTypeId>
//nsl_num_2& nsl_num_2::operator=(const
//	nsl_din_num_2& a)
/*{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}*/
//////template<class NslNumType, int NslTypeId>
//nsl_num_2& nsl_num_2::operator=(const
//	nsl_dout_num_2& a)
/*{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}*/
////template<class NslNumType, int NslTypeId>
nsl_num_2& nsl_num_2::operator=(const NslFloat0& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) val;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}
//////template<class NslNumType, int NslTypeId>
//nsl_num_2& nsl_num_2::operator=(const
//	nsl_din_num_0& a)
/*{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) val;

	return *this;
}*/
//////template<class NslNumType, int NslTypeId>
//nsl_num_2& nsl_num_2::operator=(const
//	nsl_dout_num_0& a)
/*{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) val;

	return *this;
}*/
////template<class NslNumType, int NslTypeId>
nsl_num_2& nsl_num_2::operator=(const float a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}
////template<class NslNumType, int NslTypeId>
nsl_num_2& nsl_num_2::operator=(const double a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}////template<class NslNumType, int NslTypeId>
nsl_num_2& nsl_num_2::operator=(const int a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return *this;
}
////template<class NslNumType, int NslTypeId>
NslNumType nsl_num_2::max()
{
	NslNumType c = (*v[0])[0];

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		if ((*v[i])[j] > c)
			c = (*v[i])[j];

	return c;
}
////template<class NslNumType, int NslTypeId>
NslNumType nsl_num_2::min()
{
	NslNumType c = (*v[0])[0];

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		if ((*v[i])[j] < c)
			c = (*v[i])[j];

	return c;
}
////template<class NslNumType, int NslTypeId>
NslNumType nsl_num_2::max(int& im,int& jm)
{
	int i=0,j=0;

	NslNumType c = (*v[0])[0];
	im = jm = 0;

	for (i = 0; i < imax; i++)
	   for (j = 0; j < jmax; j++)
		if ((*v[i])[j] > c)
		{
			im = i;
			jm = j;
			c = (*v[i])[j];
		}

	return c;
}
////template<class NslNumType, int NslTypeId>
NslNumType nsl_num_2::min(int& im,int& jm)
{
	NslNumType c = (*v[0])[0];
	im = jm = 0;

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		if ((*v[i])[j] < c)
		{
			im = i;
			jm = j;
			c = (*v[i])[j];
		}

	return c;
}

// element sum

////template<class NslNumType, int NslTypeId>
NslNumType nsl_num_2::sum()
{
	NslNumType c = 0;

	for (int i = 0; i < imax; i++)
	    for (int j = 0; j < jmax; j++)
		c = (*v[i])[j] + c;

	return c;
}

// vector transfor2ions

////template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_2::reduce_col()
{
	nsl_num_1 c(imax);
	
	for (int j = 0; j < jmax; j++)
	    for (int i = 0; i < imax; i++)
		c[i] = (*v[i])[j] + c[i];

	return c;
}
////template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_2::reduce_row()
{
	nsl_num_1 c(jmax);
		
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		c[j] = (*v[i])[j] + c[j];

	return c;
}

// matrix sector

////template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_2::get_sector(const int si0,
	const int si1, const int sj0, const int sj1) const 
{
	if (si0 > si1 || sj0 > sj0 || si0 < 0 || sj0 < 0 || 
	    si1 > get_imax() || sj1 > get_jmax())
	    {
		cmd_error("ERROR: nsl_num_2::get_sector");
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

	nsl_num_2 c(simax,sjmax);

	for (int i = si0; i <= si1; i++)
	    for (int j = sj0; j <= sj1; j++)
		c[i-si0][j-sj0] = (*v[i])[j];

	return c;
}

////template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_2::set_sector(
	const nsl_num_2& a, const int si0, const int sj0)
{
	if (si0 < 0 || sj0 < 0)
	{
		cmd_error("ERROR: nsl_num_2::set_sector");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("i0: ",si0);
		cmd_error("j0: ",sj0);
		cmd_error("Bad matrix sector");
		return *this;
	}

	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
	int simax = get_imax();
	int sjmax = get_jmax();

	int scimax = (saimax < simax) ? saimax : simax;
	int scjmax = (sajmax < sjmax) ? sajmax : sjmax;

	for (int i = 0; i < scimax; i++)
	    for (int j = 0; j < scjmax; j++)
		(*v[i+si0])[j+sj0] = a[i][j];

	return *this;
}

////template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_2::put_sector(
	const nsl_num_2& a, const int si0, const int sj0)
{
	return set_sector(a,si0,sj0);
}

////template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_2::get_row(const int i) const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_2::get_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_1 a(jmax);

	for (int j = 0; j < jmax; j++)
		a[j] = (*v[i])[j];

	return a;
}
////template<class NslNumType, int NslTypeId>
nsl_num_1 nsl_num_2::get_col(const  int j) const
{
	if (j < 0 || jmax <= j)
	{
		cmd_error("ERROR: nsl_num_2::get_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix col index out of range");
		return 0;
	}

	nsl_num_1 a(imax);

	for (int i = 0; i < imax; i++)
		a[i] = (*v[i])[j];

	return a;
}
////template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_2::set_row(
	const nsl_num_1& a,const int i)
{
	if (i < 0 || imax <= i || a.get_imax() != jmax)
	{
		cmd_error("ERROR: nsl_num_2::set_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_2 c(imax,jmax);

	c = (*this);

	for (int j = 0; j < jmax; j++)
		c[i][j] = (*v[0])[j];

	return c;
}
////template<class NslNumType, int NslTypeId>
nsl_num_2 nsl_num_2::set_col(
	const nsl_num_1& a,const int j)
{
	if (j < 0 || jmax <= j || a.get_imax() != imax)
	{
		cmd_error("ERROR: nsl_num_2::set_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_2 c(imax,jmax);

	c = (*this);

	for (int i = 0; i < imax; i++)
		c[i][j] = (*v[0])[j];

	return c;
}

// print

////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_num_matrix_status() const
{
	print_matrix_layer_status();
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::nslStatus() const
{
	print_num_matrix_status();
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_num_matrix() const
{
	print_num_matrix(0,imax-1,0,jmax-1);
	return 1;
}

////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_num_matrix(
	const int si0, const int si1, const int sj0,const  int sj1) const
{
	if (sub_layer_fg == 0)
		print_matrix_layer();

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
//		v[i]->nslPrint();
	    for (int j = sj0; j <= sj1; j++)
			NSLoutput((*v[i])[j]);
	    NSLoutput("\n");
	}

	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::nslPrint() const
{
	print_num_matrix();
	return 1;
}

// ostream

////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_num_matrix_status(ostream& out) const
{
	print_matrix_layer_status(out);
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_status(ostream& out) const
{
	print_num_matrix_status(out);
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_num_matrix(ostream& out) const
{
	print_num_matrix(out,0,imax-1,0,jmax-1);
	return 1;
}

////template<class NslNumType, int NslTypeId>
int nsl_num_2::print_num_matrix(ostream& out,
	const int si0, const int si1, const int sj0,const  int sj1) const 
{
	if (sub_layer_fg == 0)
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
		NSLoutput((*v[i])[j],out);
	    NSLoutput("\n",out);
	}

	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::print(ostream& out) const
{
	print_num_matrix(out);
	return 1;
}

////template<class NslNumType, int NslTypeId>
int nsl_num_2::reset_num_matrix(nsl_buffer* buf)
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
////template<class NslNumType, int NslTypeId>
int nsl_num_2::reset(nsl_buffer* buf)
{
	reset_num_matrix(buf);
	return 1;
}

////template<class NslNumType, int NslTypeId>
int nsl_num_2::write_num_matrix(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		buf << (*v[i])[j];
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::write(nsl_buffer& buf)
{
	write_num_matrix(buf);
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::read_num_matrix(nsl_buffer& buf)
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
	  NslNumType val;
	  buf >> val; 
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		(*v[i])[j] = val;
	}
	else 
	{
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
	    {
	        if (buf.get_str_cnt() == 0)
		    ((nsl_interpreter*) buf.get_m_parent())->init_input();
		buf >> (*v[i])[j];
	    }
	}

	i0 = ti0; i1 = ti1; j0 = tj0; j1 = tj1;

	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::read(nsl_buffer& buf)
{
	read_num_matrix(buf);
	return 1;
}

////template<class NslNumType, int NslTypeId>
int nsl_num_2::write_num_matrix(nsl_char_buf& buf)
{
	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
			sprintf(buf.get_sbuf(), "%f",(*v[i])[j]);

	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::write(nsl_char_buf& buf)
{
	write_num_matrix(buf);
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::read_num_matrix(nsl_char_buf&)
{
/*	int ti0 = i0, ti1 = i1, tj0 = j0, tj1 = j1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
		buf >> j0;
		buf >> j1;
	}
	if (value_fg == 1)
	{
	  NslNumType val;
	  buf >> val;
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		(*v[i])[j] = val;
	}
	else
	{
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
	    {
	        if (buf.get_str_cnt() == 0)
		    ((nsl_interpreter*) buf.get_m_parent())->init_input();
		buf >> (*v[i])[j];
	    }
	}

	i0 = ti0; i1 = ti1; j0 = tj0; j1 = tj1;
*/
	return 1;
}
////template<class NslNumType, int NslTypeId>
int nsl_num_2::read(nsl_char_buf& buf)
{
	read_num_matrix(buf);
	return 1;
}


//from 3.0////

