/* SCCS  %W%---%E%--%U% */
//
//	nsl_din_num_0.h
//
#ifndef _NSL_DIN_NUM_0_H
#define _NSL_DIN_NUM_0_H
#include "nsl_public.h"
#include "nsl_num_0.h"
extern void cmd_out(const char *, int);
template<class NslNumType, int NslTypeId>
class nsl_din_num_0 : public nsl_num_0
{ 
public:
	nsl_din_num_0(const NslNumType val = 0,int=0,int=1,int = 1); // 0,1
	nsl_din_num_0(const char*, nsl_public* = 0,int=0,int=1,int=1);
	nsl_din_num_0(const char*, const NslNumType, nsl_public* = 0,
		int=0,int=1,int=1);
	nsl_din_num_0(const nsl_din_num_0<NslNumType,NslTypeId>&,int=0,int=1,int=1); // 0,1
	~nsl_din_num_0(void);

	void initialize(const char*, nsl_public* = 0,int=0,int=1,int=1);

// assignment
//	NslNumType 	operator=(const NslFloat0&);
//	NslNumType 	operator=(const NslFloat0&);
//	NslNumType 	operator=(const NslFloat0&);
//	NslNumType 	operator=(const nsl_din_num_0<NslNumType,NslTypeId>&);
//	NslNumType 	operator=(const nsl_dout_num_0<NslNumType,NslTypeId>&);
	NslNumType 	operator=(const float);
	NslNumType 	operator=(const double);
	NslNumType 	operator=(const int);
	
	NslNumType operator=(const nsl_din_num_0<NslNumType,NslTypeId>& a);
	NslNumType operator=(const nsl_dout_num_0<NslNumType,NslTypeId>& a);
	NslNumType operator=(const NslNumType a);

	void send();
	void receive();
	void copy(nsl_layer*);
};

template<class NslNumType, int NslTypeId>
nsl_din_num_0<NslNumType,NslTypeId>::nsl_din_num_0(const NslNumType val,int sfg,int fg,int rfg) : nsl_num_0(val,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_0<NslNumType,NslTypeId>::nsl_din_num_0(const char* str,
	nsl_public* m,int sfg,int fg,int rfg) : nsl_num_0(str,m,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_0<NslNumType,NslTypeId>::nsl_din_num_0(const char* str,
	const NslNumType val,nsl_public* m,int sfg,int fg,int rfg) : nsl_num_0(str,m,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_0<NslNumType,NslTypeId>::nsl_din_num_0(const nsl_din_num_0<NslNumType,NslTypeId>& a,
	int sfg,int fg,int rfg) : nsl_num_0(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}

template<class NslNumType, int NslTypeId>
nsl_din_num_0<NslNumType,NslTypeId>::~nsl_din_num_0(void)
{
}

// initialize

template<class NslNumType, int NslTypeId>
void nsl_din_num_0<NslNumType,NslTypeId>::initialize(const char* str,
	nsl_public* m,int sfg,int fg,int rfg)
{
	nsl_num_0::initialize(str,m,sfg,fg,rfg);
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}

/*
template<class NslNumType, int NslTypeId>
NslNumType nsl_din_num_0<NslNumType,NslTypeId>::operator=(const nsl_din_num_0<NslNumType,NslTypeId>& a)
{
	v = (NslNumType) a.get_value();

	return v;
}
template<class NslNumType, int NslTypeId>
NslNumType nsl_din_num_0<NslNumType,NslTypeId>::operator=(const nsl_dout_num_0<NslNumType,NslTypeId>& a)
{
	v = (NslNumType) a.get_value();

	return v;
}
*/
template<class NslNumType, int NslTypeId>
NslNumType nsl_din_num_0<NslNumType,NslTypeId>::operator=(const float a)
{
	v = (NslNumType) a;

/*	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}
*/
	return v;
}
template<class NslNumType, int NslTypeId>
NslNumType nsl_din_num_0<NslNumType,NslTypeId>::operator=(const double a)
{
	v = (NslNumType) a;

/*	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}
*/
	return v;
}
template<class NslNumType, int NslTypeId>
NslNumType nsl_din_num_0<NslNumType,NslTypeId>::operator=(const int a)
{
	v = (NslNumType) a;

/*	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}
*/
	return v;
}
template<class NslNumType, int NslTypeId>
void nsl_din_num_0<NslNumType,NslTypeId>::send()
{
	*((AslInOutPort<NslNumType>*) _port) << *this;
}

template<class NslNumType, int NslTypeId>
void nsl_din_num_0<NslNumType,NslTypeId>::receive()
{
	*((AslInOutPort<NslNumType>*) _port) >> *this;
}
template<class NslNumType, int NslTypeId>
void nsl_din_num_0<NslNumType,NslTypeId>::copy(nsl_layer* var)
{
	int id = var->get_type_id();
	if (id == 0)
		*this = *((NslFloat0*) var);
	else if (id == 1)
		*this = *((NslFloat0*) var);
	else if (id == 2)
		*this = *((NslFloat0*) var);
	else
		cmd_out("Bad Type ID: ",id);
}
#endif
