/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_0.h
//
#ifndef _NSL_DOUT_NUM_0_H
#define _NSL_DOUT_NUM_0_H
#include "nsl_public.h"
#include "nsl_num_0.h"
extern fstream* NSL_FILE;
extern int TRACE_FG;
template<class NslNumType, int NslTypeId>
class nsl_dout_num_0 : public nsl_num_0
{ 
public:
	nsl_dout_num_0(const NslNumType val = 0,int=0,int=1,int = 1); // 0,1
	nsl_dout_num_0(const char*, nsl_public* = 0,int=0,int=1,int=1);
	nsl_dout_num_0(const char*, const NslNumType, nsl_public* = 0,
		int=0,int=1,int=1);
	nsl_dout_num_0(const nsl_dout_num_0<NslNumType,NslTypeId>&,int=0,int=1,int=1); // 0,1

/*	nsl_dout_num_0(const NslDoutFloat0&,int=0,int=1,int=1); // 0,1
	nsl_dout_num_0(const NslDoutDouble0&,int=0,int=1,int=1); // 0,1
	nsl_dout_num_0(const NslDoutInt0&,int=0,int=1,int=1); // 0,1
	nsl_dout_num_0(const NslFloat0&,int=0,int=1,int=1); // 0,1
	nsl_dout_num_0(const NslFloat0&,int=0,int=1,int=1); // 0,1
	nsl_dout_num_0(const NslFloat0&,int=0,int=1,int=1); // 0,1
*/
	~nsl_dout_num_0(void);

	void initialize(const char*, nsl_public* = 0,int=0,int=1,int=1);

// assignment
//	NslNumType 	operator=(const nsl_din_num_0<NslNumType,NslTypeId>&);
//	NslNumType 	operator=(const nsl_dout_num_0<NslNumType,NslTypeId>&);
	NslNumType  operator=(const NslFloat0& a);
	NslNumType 	operator=(const float);
	NslNumType 	operator=(const double);
	NslNumType 	operator=(const int);
	
	void send();
	void receive();
	void copy(nsl_layer*);
};

template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslNumType val,int sfg,int fg,int rfg) : 
	nsl_num_0(val,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const char* str,
	nsl_public* m,int sfg,int fg,int rfg) : 
	nsl_num_0(str,m,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const char* str,
	const NslNumType val,nsl_public* m,int sfg,int fg,int rfg) : 
	nsl_num_0(str,m,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const nsl_dout_num_0<NslNumType,NslTypeId>& a,
	int sfg,int fg,int rfg) : nsl_num_0(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
/*
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslDoutFloat0& a,
	int sfg,int fg,int rfg) : nsl_num_0<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslDoutDouble0& a,
	int sfg,int fg,int rfg) : nsl_num_0<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslDoutInt0& a,
	int sfg,int fg,int rfg) : nsl_num_0<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslFloat0& a,
	int sfg,int fg,int rfg) : nsl_num_0<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslFloat0& a,
	int sfg,int fg,int rfg) : nsl_num_0<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::nsl_dout_num_0(const NslFloat0& a,
	int sfg,int fg,int rfg) : nsl_num_0<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
}
*/
template<class NslNumType, int NslTypeId>
nsl_dout_num_0<NslNumType,NslTypeId>::~nsl_dout_num_0(void)
{
}

// initialize

template<class NslNumType, int NslTypeId>
void nsl_dout_num_0<NslNumType,NslTypeId>::initialize(const char* str,
	nsl_public* m,int sfg,int fg,int rfg)
{
	nsl_num_0::initialize(str,m,sfg,fg,rfg);
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType, int NslTypeId>
NslNumType nsl_dout_num_0<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	v = (NslNumType) a.get_value();

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}

/*
template<class NslNumType, int NslTypeId>
NslNumType nsl_dout_num_0<NslNumType,NslTypeId>::operator=(const nsl_din_num_0<NslNumType,NslTypeId>& a)
{
	v = (NslNumType) a.get_value();

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}
template<class NslNumType, int NslTypeId>
NslNumType nsl_dout_num_0<NslNumType,NslTypeId>::operator=(const nsl_dout_num_0<NslNumType,NslTypeId>& a)
{
	v = (NslNumType) a.get_value();

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}
*/
template<class NslNumType, int NslTypeId>
NslNumType nsl_dout_num_0<NslNumType,NslTypeId>::operator=(const float a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}
template<class NslNumType, int NslTypeId>
NslNumType nsl_dout_num_0<NslNumType,NslTypeId>::operator=(const double a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}
template<class NslNumType, int NslTypeId>
NslNumType nsl_dout_num_0<NslNumType,NslTypeId>::operator=(const int a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != (nsl_base*)SYSTEM)
	{
		m_parent->print(*NSL_FILE);
        nsl_base::print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_0<NslNumType,NslTypeId>::send()
{
	*((AslInOutPort<NslNumType>*) _port) << *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_0<NslNumType,NslTypeId>::receive()
{
	*((AslInOutPort<NslNumType>*) _port) >> *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_0<NslNumType,NslTypeId>::copy(nsl_layer* var)
{
	*this = *((nsl_num_0*)var);
}
#endif
