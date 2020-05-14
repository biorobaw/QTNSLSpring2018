/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_1.h
//
#ifndef _NSL_DOUT_NUM_1_H
#define _NSL_DOUT_NUM_1_H
#include "nsl_public.h"
#include "nsl_num_1.h"
class nsl_num_0;
extern fstream* NSL_FILE;
extern int TRACE_FG;
template<class NslNumType, int NslTypeId>
class nsl_dout_num_1 : public nsl_num_1
{
public:
		nsl_dout_num_1(const int = 0,int = 0,int=0,int=1);
		nsl_dout_num_1(const char*,nsl_model* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=1,int=1);
		nsl_dout_num_1(const nsl_dout_num_1<NslNumType,NslTypeId>&,int=0,int=0,int=1);

		~nsl_dout_num_1();

	void initialize(const char*,nsl_public* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=1,int=1);

// assignment is not inherited in C++
	nsl_num_1& 	operator=(const NslFloat1&);
//	nsl_num_1& 	operator=(const nsl_din_num_1<NslNumType,NslTypeId>&);
//	nsl_num_1& 	operator=(const nsl_dout_num_1<NslNumType,NslTypeId>&);
	nsl_num_1& 	operator=(const nsl_num_0&);
//	nsl_num_1& 	operator=(const nsl_din_num_0<NslNumType,NslTypeId>&);
//	nsl_num_1& 	operator=(const nsl_dout_num_0<NslNumType,NslTypeId>&);
	nsl_num_1& 	operator=(const float);
	nsl_num_1& 	operator=(const double);
	nsl_num_1& 	operator=(const int);
		
		void send();
		void receive();
		void copy(nsl_layer*);
};

template<class NslNumType, int NslTypeId>
nsl_dout_num_1<NslNumType,NslTypeId>::nsl_dout_num_1(const int s,int sfg,int fg,int rfg) : 
	nsl_num_1(s,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_1<NslNumType,NslTypeId>::nsl_dout_num_1(const char* str,nsl_model* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg) : 
	nsl_num_1(str,m,s,vtype,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_1<NslNumType,NslTypeId>::nsl_dout_num_1(const nsl_dout_num_1<NslNumType,NslTypeId>& a,
	int sfg,int fg,int rfg) : nsl_num_1(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType, int NslTypeId>
nsl_dout_num_1<NslNumType,NslTypeId>::~nsl_dout_num_1()
{

}

// initialize

template<class NslNumType, int NslTypeId>
void nsl_dout_num_1<NslNumType,NslTypeId>::initialize(const char* str,nsl_public* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg)
{
	nsl_num_1::initialize(str,m,s,vtype,sfg,fg,rfg);
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}

// vector assignment

template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const NslFloat1& a)
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
		v[i] = a[i];
		
	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}

/*
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const
	nsl_din_num_1<NslNumType,NslTypeId>& a)
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
		v[i] = a[i];

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const
	nsl_dout_num_1<NslNumType,NslTypeId>& a)
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
		v[i] = a[i];

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
*/
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) val;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}

/*
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const
	nsl_din_num_0<NslNumType,NslTypeId>& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) val;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const
	nsl_dout_num_0<NslNumType,NslTypeId>& a)
{
	NslNumType val = a.get_value();

	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) val;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
*/
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const float a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const double a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_1& nsl_dout_num_1<NslNumType,NslTypeId>::operator=(const int a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_1<NslNumType,NslTypeId>::send()
{
	*((AslInOutPort<NslNumType>*) _port) << *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_1<NslNumType,NslTypeId>::receive()
{
	*((AslInOutPort<NslNumType>*) _port) >> *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_1<NslNumType,NslTypeId>::copy(nsl_layer* var)
{
	*this = *((nsl_num_1*) var);
}
#endif
