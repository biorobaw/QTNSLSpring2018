/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_dat.h
//

#ifndef _NSL_NUM_DAT_H
#define _NSL_NUM_DAT_H
#include "nsl_data_layer.h"
template<class NslNumType>
class nsl_num_dat : public nsl_data_layer
{
protected:
	NslNumType v; 
public:
	nsl_num_dat(const NslNumType val = 0,int = 1);
	nsl_num_dat(const char*, nsl_model* = 0,int=1,int=1);
	nsl_num_dat(const char*, const NslNumType, nsl_model* = 0,
		int=1,int=1);
	nsl_num_dat(const nsl_num_dat<NslNumType>&,int=1); 
	~nsl_num_dat(void);

	int	init_num_data();
	NslNumType get_data() 	const { return v; }
	NslNumType get_value() 	const { return v; }
	NslNumType& elem() { return v; } 	

	NslNumType	set_value(const int);
	NslNumType	set_value(const float);
	NslNumType	set_value(const double);

// add
	nsl_num_dat<NslNumType> operator+();
	nsl_num_dat<NslNumType> operator+(const nsl_num_dat<NslNumType>&);
	nsl_num_dat<NslNumType> operator+(const NslNumType);

// assignment
	NslNumType 	operator=(const nsl_num_dat<float>&);
	NslNumType 	operator=(const nsl_num_dat<double>&);
	NslNumType 	operator=(const nsl_num_dat<int>&);
	NslNumType 	operator=(const double);
	NslNumType 	operator=(const float);
	NslNumType 	operator=(const int a);

// print

	virtual int	print(ostream&) const;
	int	print_num_data(ostream&) const;
	virtual int	print_status(ostream&) const;
	int	print_num_data_status(ostream&) const;
	int 	reset_num_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

template<class NslNumType>
nsl_num_dat<NslNumType>::nsl_num_dat(const NslNumType val,int rfg) : 
	nsl_data_layer(rfg)
{
	init_num_data();
	v = val;
}
template<class NslNumType>
nsl_num_dat<NslNumType>::nsl_num_dat(const char* str,
	nsl_model* m,int fg,int rfg) : 
	nsl_data_layer("num_data",str,m,fg,rfg)
{
	init_num_data();
	v = 0;
}
template<class NslNumType>
nsl_num_dat<NslNumType>::nsl_num_dat(const char* str,
	const NslNumType val,nsl_model* m,int fg,int rfg) : 
	nsl_data_layer("num_data",str,m,fg,rfg)
{
	init_num_data();
	v = val;
}
template<class NslNumType>
nsl_num_dat<NslNumType>::nsl_num_dat(const nsl_num_dat<NslNumType>& a,
	int rfg) : nsl_data_layer(rfg)
{
	init_num_data();
	v = a.get_value();
}

template<class NslNumType>
nsl_num_dat<NslNumType>::~nsl_num_dat(void)
{
}

// init

template<class NslNumType>
int nsl_num_dat<NslNumType>::init_num_data()
{
	v = 0;
	return 1;
}

// nsl_num_dat set values

template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::set_value(const double val)
{
	return v = (NslNumType) val;
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::set_value(const float val)
{
	return v = (NslNumType) val;
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::set_value(const int val)
{
	return v = (NslNumType) val;
}

// nsl_num_dat<NslNumType> addition

template<class NslNumType>
nsl_num_dat<NslNumType> nsl_num_dat<NslNumType>::operator+()
{
	nsl_num_dat<NslNumType> c;
	c = get_data();
	return c;
}
template<class NslNumType>
nsl_num_dat<NslNumType> nsl_num_dat<NslNumType>::operator+(const nsl_num_dat<NslNumType>& b)
{
	nsl_num_dat<NslNumType> c;
	c = get_data() + b.get_data();
	return c;
}
template<class NslNumType>
nsl_num_dat<NslNumType> nsl_num_dat<NslNumType>::operator+(const NslNumType b)
{
	nsl_num_dat<NslNumType> c;
	c = get_data() + b;
	return c;
}

// nsl_num_dat<NslNumType> assignment

template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::operator=(const nsl_num_dat<float>& a)
{
	return v = (NslNumType) a.get_value();
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::operator=(const nsl_num_dat<double>& a)
{
	return v = (NslNumType) a.get_value();
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::operator=(const nsl_num_dat<int>& a)
{
	return v = (NslNumType) a.get_value();
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::operator=(const double a)
{
	return v = (NslNumType) a;
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::operator=(const float a)
{
	return v = (NslNumType) a;
}
template<class NslNumType>
NslNumType nsl_num_dat<NslNumType>::operator=(const int a)
{
	return v = (NslNumType) a;
}

// print

template<class NslNumType>
int nsl_num_dat<NslNumType>::print_num_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::print_status(ostream& out) const
{
	print_num_data_status(out);
	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::print_num_data(ostream& out) const
{
	print_data_layer(out);
	out <<  v << "\n";
	out.flush();
	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::print(ostream& out) const
{
	print_num_data(out);
	return 1;
}

template<class NslNumType>
int nsl_num_dat<NslNumType>::reset_num_data(nsl_buffer* buf)
{
	if (buf == NULL)
		v = 0;
	else
		*buf >> v;

	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::reset(nsl_buffer* buf)
{
	reset_num_data(buf);
	return 1;
}

template<class NslNumType>
int nsl_num_dat<NslNumType>::write_num_data(nsl_buffer& buf)
{
	buf << v;
	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::write(nsl_buffer& buf)
{
	write_num_data(buf);
	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::read_num_data(nsl_buffer& buf)
{
	buf >> v;
	return 1;
}
template<class NslNumType>
int nsl_num_dat<NslNumType>::read(nsl_buffer& buf)
{
	read_num_data(buf);
	return 1;
}

#endif