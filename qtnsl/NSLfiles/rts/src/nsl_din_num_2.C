/* SCCS  %W%---%E%--%U% */
//
//	nsl_din_num_2.C
//
/*
# include "nsl_all_kernel_include.h"
# include "asl_all_rts_include.h"

template<class NslNumType>
nsl_din_num_2<NslNumType>::nsl_din_num_2(const int s1,const int s2,
	int sfg,int fg,int rfg) : nsl_num_2(s1,s2,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDinFloat2>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType>
nsl_din_num_2<NslNumType>::nsl_din_num_2(const char* str,nsl_public* m,const int s1,
	const int s2, int sfg, int fg,int rfg) : 
	nsl_num_2(str,m,s1,s2,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslDinFloat2>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType>
nsl_din_num_2<NslNumType>::nsl_din_num_2(const nsl_din_num_2<NslNumType>& a,
	int sfg,int fg,int rfg) : 
	nsl_num_2(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDinFloat2>(str,m,this,ASL_DATA_INPUT);
}

// destructors

template<class NslNumType>
nsl_din_num_2<NslNumType>::~nsl_din_num_2()
{
}

// initialize

template<class NslNumType>
void nsl_din_num_2<NslNumType>::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, int sfg, int fg,int rfg)
{
	nsl_num_2::initialize(str,m,s1,s2,sfg,fg,rfg);
	_port = new AslInOutPort<NslDinFloat2>(str,m,this,ASL_DATA_INPUT);
}

// matrix assignment

template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const 
	nsl_num_2<NslNumType>& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = a[i][j];

	return *this;
}
template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const 
	nsl_din_num_2<NslNumType>& a)
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
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = a[i][j];

	return *this;
}
template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const 
	nsl_dout_num_2<NslNumType>& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = a[i][j];

	return *this;
}
template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const 
	nsl_num_0<NslNumType>& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) val;

	return *this;
}
template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const 
	nsl_din_num_0<NslNumType>& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) val;

	return *this;
}
template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const 
	nsl_dout_num_0<NslNumType>& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) val;

	return *this;
}
template<class NslNumType>
nsl_num_2<NslNumType>& nsl_din_num_2<NslNumType>::operator=(const NslNumType a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	return *this;
}
template<class NslNumType>
void nsl_din_num_2<NslNumType>::send()
{
	*((AslInOutPort<NslDinFloat2>*) _port) << *this;
}

template<class NslNumType>
void nsl_din_num_2<NslNumType>::receive()
{
	*((AslInOutPort<NslDinFloat2>*) _port) >> *this;
}
*/