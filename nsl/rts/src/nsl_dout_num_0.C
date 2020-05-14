/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_0.C
//
/*
# include "nsl_all_kernel_include.h"
# include "asl_all_rts_include.h"

template<class NslNumType>
nsl_dout_num_0<NslNumType>::nsl_dout_num_0(const NslNumType val,int sfg,int fg,int rfg) : 
	nsl_num_0(val,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat0>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_0<NslNumType>::nsl_dout_num_0(const char* str,
	nsl_public* m,int sfg,int fg,int rfg) : 
	nsl_num_0(str,m,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslDoutFloat0>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_0<NslNumType>::nsl_dout_num_0(const char* str,
	const NslNumType val,nsl_public* m,int sfg,int fg,int rfg) : 
	nsl_num_0(str,m,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslDoutFloat0>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_0<NslNumType>::nsl_dout_num_0(const nsl_dout_num_0<NslNumType>& a,
	int sfg,int fg,int rfg) : nsl_num_0(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat0>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType>
nsl_dout_num_0<NslNumType>::~nsl_dout_num_0(void)
{
}

// initialize

template<class NslNumType>
void nsl_dout_num_0<NslNumType>::initialize(const char* str,
	nsl_public* m,int sfg,int fg,int rfg)
{
	nsl_num_0::initialize(str,m,sfg,fg,rfg);
	_port = new AslInOutPort<NslDoutFloat0>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType>
NslNumType nsl_dout_num_0<NslNumType>::operator=(const nsl_num_0<NslNumType>& a)
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
template<class NslNumType>
NslNumType nsl_dout_num_0<NslNumType>::operator=(const nsl_din_num_0<NslNumType>& a)
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
template<class NslNumType>
NslNumType nsl_dout_num_0<NslNumType>::operator=(const nsl_dout_num_0<NslNumType>& a)
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
template<class NslNumType>
NslNumType nsl_dout_num_0<NslNumType>::operator=(const NslNumType a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return v;
}

template<class NslNumType>
void nsl_dout_num_0<NslNumType>::send()
{
	*((AslInOutPort<NslDoutFloat0>*) _port) << *this;
}
template<class NslNumType>
void nsl_dout_num_0<NslNumType>::receive()
{
	*((AslInOutPort<NslDoutFloat0>*) _port) >> *this;
}
*/