/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_2.h
//
/*
template<class NslNumType, int NslTypeId>
class nsl_dout_num_2 : public nsl_num_2<NslNumType,NslTypeId>
{
public:
		nsl_dout_num_2(const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_dout_num_2(const char*,nsl_public* = 0,const int = 0,
			const int = 0,int=0,int=1,int=1);
		nsl_dout_num_2(const nsl_dout_num_2<NslNumType,NslTypeId>&,int=0,int=0,int=1);

		~nsl_dout_num_2();

	void initialize(const char*,nsl_public* = 0,const int = 0,
			const int = 0,int=0,int=1,int=1);

// assignment
	nsl_num_2<NslNumType,NslTypeId>& operator=(const NslFloat2&);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const NslFloat2&);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const NslFloat2&);
//	nsl_num_2<NslNumType,NslTypeId>& operator=(const nsl_din_num_2<NslNumType,NslTypeId>&);
//	nsl_num_2<NslNumType,NslTypeId>& operator=(const nsl_dout_num_2<NslNumType,NslTypeId>&);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const NslFloat0&);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const NslFloat0&);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const NslFloat0&);
//	nsl_num_2<NslNumType,NslTypeId>& operator=(const nsl_din_num_0<NslNumType,NslTypeId>&);
//	nsl_num_2<NslNumType,NslTypeId>& operator=(const nsl_dout_num_0<NslNumType,NslTypeId>&);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const float);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const double);
	nsl_num_2<NslNumType,NslTypeId>& operator=(const int);
	
		void send();
		void receive();
		void copy(nsl_layer*);
};

template<class NslNumType, int NslTypeId>
nsl_dout_num_2<NslNumType,NslTypeId>::nsl_dout_num_2(const int s1,const int s2,
	int sfg,int fg,int rfg) : nsl_num_2<NslNumType,NslTypeId>(s1,s2,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_2<NslNumType,NslTypeId>::nsl_dout_num_2(const char* str,nsl_public* m,const int s1,
	const int s2, int sfg, int fg,int rfg) : 
	nsl_num_2<NslNumType,NslTypeId>(str,m,s1,s2,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType, int NslTypeId>
nsl_dout_num_2<NslNumType,NslTypeId>::nsl_dout_num_2(const nsl_dout_num_2<NslNumType,NslTypeId>& a,
	int sfg,int fg,int rfg) : 
	nsl_num_2<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}

// destructors

template<class NslNumType, int NslTypeId>
nsl_dout_num_2<NslNumType,NslTypeId>::~nsl_dout_num_2()
{
}

// initialize

template<class NslNumType, int NslTypeId>
void nsl_dout_num_2<NslNumType,NslTypeId>::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, int sfg, int fg,int rfg)
{
	nsl_num_2<NslNumType,NslTypeId>::initialize(str,m,s1,s2,sfg,fg,rfg);
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_OUTPUT);
}

// matrix assignment

template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const NslFloat2& a)
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

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const NslFloat2& a)
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

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const NslFloat2& a)
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

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
/*
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const 
	nsl_din_num_2<NslNumType,NslTypeId>& a)
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

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const 
	nsl_dout_num_2<NslNumType,NslTypeId>& a)
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

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
*//*
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
} */
/*
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const 
	nsl_din_num_0<NslNumType,NslTypeId>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const 
	nsl_dout_num_0<NslNumType,NslTypeId>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
*/
/*
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const float a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const double a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_2<NslNumType,NslTypeId>& nsl_dout_num_2<NslNumType,NslTypeId>::operator=(const int a)
{
	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		(*v[i])[j] = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_2<NslNumType,NslTypeId>::send()
{
	*((AslInOutPort<NslNumType>*) _port) << *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_2<NslNumType,NslTypeId>::receive()
{
	*((AslInOutPort<NslNumType>*) _port) >> *this;
}
template<class NslNumType, int NslTypeId>
void nsl_dout_num_2<NslNumType,NslTypeId>::copy(nsl_layer* var)
{
	*this = *((nsl_num_2<NslNumType,NslTypeId>*) var);
}*/
