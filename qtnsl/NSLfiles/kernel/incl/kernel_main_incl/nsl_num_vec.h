/* SCCS  @(#)nsl_num_vec<NslNumType>.h	1.1---95/08/13--23:37:20 */
//
//	nsl_num_vec.h
//

#ifndef _NSL_NUM_VEC_H
#define _NSL_NUM_VEC_H
#include "nsl_vector_layer.h"
template<class NslNumType>
class nsl_num_vec : public nsl_vector_layer
{
	class nsl_num_mat<NslNumType>;

protected:
	NslNumType* v; 
public:
		nsl_num_vec(const int = 0,int=1);
		nsl_num_vec(const char*,nsl_model* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=1,int=1);
		nsl_num_vec(const nsl_num_vec<NslNumType>&,int=1);

		~nsl_num_vec();

	int	init_num_vector(const int = 0);
	int	alloc_mem(const int);

// get value
	NslNumType*	get_vector() const { return v; }

// element retrieval
	NslNumType&	operator[](const int);
	NslNumType&	elem(const int);

	// set value
	NslNumType	set_value(const int,const int);
	NslNumType	set_value(const int,const float);
	NslNumType	set_value(const int,const double);

// assignment
	NslNumType* 	operator=(const nsl_num_vec<float>&);
	NslNumType* 	operator=(const nsl_num_vec<double>&);
	NslNumType* 	operator=(const nsl_num_vec<int>&);
	NslNumType* 	operator=(const nsl_num_dat<float>&);
	NslNumType* 	operator=(const nsl_num_dat<double>&);
	NslNumType* 	operator=(const nsl_num_dat<int>&);
	NslNumType* 	operator=(const double);
	NslNumType* 	operator=(const float);
	NslNumType* 	operator=(const int);

        NslNumType        max();
        NslNumType        min();

        NslNumType        max(int*); // return index
        NslNumType        min(int*);

	// sum
	NslNumType	sum();

// also functions
	nsl_num_mat<NslNumType> expand_col(const int);
	nsl_num_mat<NslNumType> expand_row(const int);
	nsl_num_mat<NslNumType> expand(const int);

	nsl_num_vec<NslNumType> transpose_col();
	nsl_num_vec<NslNumType> transpose_row();
	nsl_num_vec<NslNumType> transpose();

	// sector
	nsl_num_vec<NslNumType> 	get_sector(const int,const int) const;
	nsl_num_vec<NslNumType>	set_sector(const nsl_num_vec<NslNumType>&,
					const int);
	nsl_num_vec<NslNumType> 	put_sector(const 
					nsl_num_vec<NslNumType>&,const int); 

// print

	virtual int	print(std::ostream&) const;
	int	print_num_vector(std::ostream&) const;
	int	print_num_vector(std::ostream&,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_num_vector_status(std::ostream&) const;

	int 	reset_num_vector(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_vector(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_vector(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

template<class NslNumType>
nsl_num_vec<NslNumType>::nsl_num_vec(const int s,int rfg) : 
	nsl_vector_layer(false, s,rfg)
{
	init_num_vector(s);
}
template<class NslNumType>
nsl_num_vec<NslNumType>::nsl_num_vec(const char* str,nsl_model* m,
	const int s,row_col_enum vtype,int fg,int rfg) : 
	nsl_vector_layer("num_vector",str,m,s,vtype,fg,rfg)
{
	init_num_vector(s);
}
template<class NslNumType>
nsl_num_vec<NslNumType>::nsl_num_vec(const nsl_num_vec<NslNumType>& a,
	int rfg) : nsl_vector_layer(a.get_imax(),rfg)
{
        int s = a.get_imax();

	init_num_vector(s);

	if (s > 0)
	{
//	    NslNumType* va = a.get_vector();

            for (int i = 0; i < s; i++)
                v[i] = a.v[i];
	}
}

// nsl_num_vec<NslNumType> destructors

template<class NslNumType>
nsl_num_vec<NslNumType>::~nsl_num_vec()
{
	delete v;
}

// init

template<class NslNumType>
int nsl_num_vec<NslNumType>::init_num_vector(const int s)
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
template<class NslNumType>
int nsl_num_vec<NslNumType>::alloc_mem(const int s)
{
	init_vector_layer(s);
	init_num_vector(s);
	return 1;
}

// vector object element

template<class NslNumType>
NslNumType& nsl_num_vec<NslNumType>::operator[](const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::operator[] ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (NslNumType&) v[0];
	}

	return (NslNumType&) v[i];
}
template<class NslNumType>
NslNumType& nsl_num_vec<NslNumType>::elem(const int i)
{
	if (i < 0 || imax <= i)
	{
		cmd_error("*** nsl_num_1::elem ***");
		cmd_error("Exit with status:");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Vector index out of range");
		return (NslNumType&) v[0];
	}

	return (NslNumType&) v[i];
}
template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::set_value(const int i,const int val)
{
	return v[i] = (NslNumType) val;
}
template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::set_value(const int i,const float val)
{
	return v[i] = (NslNumType) val;
}
template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::set_value(const int i,const double val)
{
	return v[i] = (NslNumType) val;
}

// vector assignment

template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const nsl_num_vec<float>& a)
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_num_vec<float>::operator=");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		v[i] = a.v[i];

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const nsl_num_vec<double>& a)
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_num_vec<double>::operator=");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		v[i] = a.v[i];

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const nsl_num_vec<int>& a)
{
	if (a.imax != imax)
	{
		cmd_error("ERROR: nsl_num_vec<int>::operator=");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent vector sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
		v[i] = a.v[i];

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const nsl_num_dat<float>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		v[i] = val;

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const nsl_num_dat<double>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		v[i] = val;

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const nsl_num_dat<int>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		v[i] = val;

	return v;
}

template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const double a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (NslNumType) a;

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const float a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (NslNumType) a;

	return v;
}
template<class NslNumType>
NslNumType* nsl_num_vec<NslNumType>::operator=(const int a)
{
	int timax = get_imax();

	for (int i = 0; i < timax; i++)
		v[i] = (NslNumType) a;

	return v;
}

template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::max()
{
	int simax = get_imax();

	NslNumType c = v[0];

	for (int i = 0; i < simax; i++)
		if (v[i] > c)
			c = v[i];

	return c;
}
template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::min()
{
	int simax = get_imax();

	NslNumType c = v[0];

	for (int i = 0; i < simax; i++)
		if (v[i] < c)
			c = v[i];

	return c;
}

template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::max(int* im)
{
	int simax = get_imax();

	NslNumType c = v[0];
	*im = 0;

	for (int i = 0; i < simax; i++)
		if (v[i] > c)
		{
			c = v[i];
			*im = i;
		}

	return c;
}
template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::min(int* im)
{
	int simax = get_imax();

	NslNumType c = v[0];
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

template<class NslNumType>
NslNumType nsl_num_vec<NslNumType>::sum()
{
	NslNumType c = 0;

	for (int i = 0; i < imax; i++)
		c = v[i] + c;
	return c;
}

// expand

template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_vec<NslNumType>::expand(const int n)
{
	if (vec_type == 1)
		return expand_col(n);
	else
		return expand_row(n);
}
template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_vec<NslNumType>::expand_col(const int n)
{
	int simax = get_imax();
	int sjmax = n;

	nsl_num_mat<NslNumType> c(simax,sjmax);
	NslNumType** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[i];

	return c;
}
template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_vec<NslNumType>::expand_row(const int n)
{
	int sjmax = get_imax();
	int simax = n;

	nsl_num_mat<NslNumType> c(simax,sjmax);
	NslNumType** cv = c.get_matrix();
	
	for (int i = 0; i < simax; i++)
	    for (int j = 0; j < sjmax; j++)
		cv[i][j] = v[j];

	return c;
}

// transpose

template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_vec<NslNumType>::transpose()
{
	vec_type = (vec_type == NSL_ROW) ? NSL_COL : NSL_ROW;

	return *this;
}
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_vec<NslNumType>::transpose_row()
{
	vec_type = NSL_ROW; 

	return *this;
}
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_vec<NslNumType>::transpose_col()
{
	vec_type = NSL_COL; 

	return *this;
}

// vector sector

template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_vec<NslNumType>::get_sector(const int si0, 
	const int si1) const 
{
	if (si0 > si1 || si0 < 0 || si1 > get_imax())
	{
		cmd_error("ERROR: nsl_num_vec<NslNumType>::get_sector");
		this->print_status(std::cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("Bad vector sector");
		return 0;
	}

	int simax = si1 - si0 + 1;

	nsl_num_vec<NslNumType> c(simax);

	for (int i = si0; i <= si1; i++)
		c.v[i-si0] = v[i]; 

	return c;
}
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_vec<NslNumType>::set_sector(
	const nsl_num_vec<NslNumType>& a, const int si0) 
{
	if (si0 < 0)
	{
		cmd_error("ERROR: nsl_num_vec<NslNumType>::get_sector");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
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
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_vec<NslNumType>::put_sector(
	const nsl_num_vec<NslNumType>& a, const int si0) 
{
	return set_sector(a,si0);
}

// print

template<class NslNumType>
int nsl_num_vec<NslNumType>::print_num_vector_status(std::ostream& out) const
{
	print_vector_layer_status(out);
	return 1;
}
template<class NslNumType>
int nsl_num_vec<NslNumType>::print_status(std::ostream& out) const
{
	print_num_vector_status(out);
	return 1;
}
template<class NslNumType>
int nsl_num_vec<NslNumType>::print_num_vector(std::ostream& out) const
{
	print_num_vector(out,0,get_imax()-1);
	return 1;
}
template<class NslNumType>
int nsl_num_vec<NslNumType>::print_num_vector(std::ostream& out,const int si0,
	const int si1) const 
{
	print_vector_layer(out);
	if (si0 > si1 || si0 < 0 || si1 > get_imax()-1)
	{
		cmd_error("ERROR: print_num_vector");
		this->print_status(std::cerr);
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
template<class NslNumType>
int nsl_num_vec<NslNumType>::print(std::ostream& out) const
{
	print_num_vector(out);
	return 1;
}

template<class NslNumType>
int nsl_num_vec<NslNumType>::reset_num_vector(nsl_buffer* buf)
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
template<class NslNumType>
int nsl_num_vec<NslNumType>::reset(nsl_buffer* buf)
{
	reset_num_vector(buf);
	return 1;
}

template<class NslNumType>
int nsl_num_vec<NslNumType>::write_num_vector(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
		buf << v[i];
	return 1;
}
template<class NslNumType>
int nsl_num_vec<NslNumType>::write(nsl_buffer& buf)
{
	write_num_vector(buf);
	return 1;
}
template<class NslNumType>
int nsl_num_vec<NslNumType>::read_num_vector(nsl_buffer& buf)
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
template<class NslNumType>
int nsl_num_vec<NslNumType>::read(nsl_buffer& buf)
{
	read_num_vector(buf);
	return 1;
}

#endif
