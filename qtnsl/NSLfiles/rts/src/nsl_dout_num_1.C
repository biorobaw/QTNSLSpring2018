/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_1.h
//
/*
# include "nsl_all_kernel_include.h"
# include "asl_all_rts_include.h"

template<class NslNumType>
nsl_dout_num_1<NslNumType>::nsl_dout_num_1(const int s,int sfg,int fg,int rfg) : 
	nsl_num_1(s,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat1>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_1<NslNumType>::nsl_dout_num_1(const char* str,nsl_public* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg) : 
	nsl_num_1(str,m,s,vtype,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslDoutFloat1>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_1<NslNumType>::nsl_dout_num_1(const nsl_dout_num_1<NslNumType>& a,
	int sfg,int fg,int rfg) : nsl_num_1(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat1>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType>
nsl_dout_num_1<NslNumType>::~nsl_dout_num_1()
{

}

// initialize

template<class NslNumType>
void nsl_dout_num_1<NslNumType>::initialize(const char* str,nsl_public* m,
	const int s,row_col_enum vtype,int sfg,int fg,int rfg)
{
	nsl_num_1::initialize(str,m,s,vtype,sfg,fg,rfg);
	_port = new AslInOutPort<NslDoutFloat1>(str,m,this,ASL_DATA_OUTPUT);
}

// vector assignment

template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const 
	nsl_num_1<NslNumType>& a)
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
template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const 
	nsl_din_num_1<NslNumType>& a)
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
template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const 
	nsl_dout_num_1<NslNumType>& a)
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
template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const 
	nsl_num_0<NslNumType>& a)
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
template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const 
	nsl_din_num_0<NslNumType>& a)
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
template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const 
	nsl_dout_num_0<NslNumType>& a)
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

template<class NslNumType>
nsl_num_1<NslNumType>& nsl_dout_num_1<NslNumType>::operator=(const NslNumType a)
{
	for (int i = 0; i < imax; i++)
		v[i] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}

template<class NslNumType>
void nsl_dout_num_1<NslNumType>::send()
{
	*((AslInOutPort<NslDoutFloat1>*) _port) << *this;
}
template<class NslNumType>
void nsl_dout_num_1<NslNumType>::receive()
{
	*((AslInOutPort<NslDoutFloat1>*) _port) >> *this;
}
*/