/* SCCS  %W%---%E%--%U% */
//
//	nsl_din_num_4.h
//
/*
template<class NslNumType, int NslTypeId>
class nsl_din_num_4 : public nsl_num_4<NslNumType,NslTypeId>
{
public:
		nsl_din_num_4(const int = 0,const int = 0,
			const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_din_num_4(const char*,nsl_public* = 0,const int = 0,
			const int = 0,const int = 0,const int = 0,
			int = 0,int=1,int=1);
		nsl_din_num_4(const nsl_din_num_4<NslNumType,NslTypeId>&,int = 0,int=0,int=1);

		~nsl_din_num_4();

	void initialize(const char*,nsl_public* = 0,const int = 0,
			const int = 0,const int = 0,const int = 0,
			int = 0,int=1,int=1);

// assignment
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const NslFloat4&);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const NslDouble4&);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const NslInt4&);
//	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const nsl_din_num_4<NslNumType,NslTypeId>&);
//	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const nsl_dout_num_4<NslNumType,NslTypeId>&);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const NslFloat0&);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const NslFloat0&);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const NslFloat0&);
//	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const nsl_din_num_0<NslNumType,NslTypeId>&);
//	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const nsl_dout_num_0<NslNumType,NslTypeId>&);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const float);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const double);
	nsl_num_4<NslNumType,NslTypeId>& 	operator=(const int);

		void send();
		void receive();
		void copy(nsl_layer*);
};

template<class NslNumType, int NslTypeId>
nsl_din_num_4<NslNumType,NslTypeId>::nsl_din_num_4(const int s1,const int s2,
	const int s3,const int s4,int sfg,int fg,int rfg) : 
	nsl_num_4<NslNumType,NslTypeId>(s1,s2,s3,s4,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_4<NslNumType,NslTypeId>::nsl_din_num_4(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,const int s4, int sfg, int fg,int rfg) : 
	nsl_num_4<NslNumType,NslTypeId>(str,m,s1,s2,s3,s4,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_4<NslNumType,NslTypeId>::nsl_din_num_4(const nsl_din_num_4<NslNumType,NslTypeId>& a,
	int sfg,int fg,int rfg) : 
	nsl_num_4<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}

template<class NslNumType, int NslTypeId>
nsl_din_num_4<NslNumType,NslTypeId>::~nsl_din_num_4()
{

}

// initialize

template<class NslNumType, int NslTypeId>
void nsl_din_num_4<NslNumType,NslTypeId>::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,const int s4, int sfg, int fg,int rfg) 
{
	nsl_num_4<NslNumType,NslTypeId>::initialize(str,m,s1,s2,s3,s4,sfg,fg,rfg);
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}

// assignment

template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const NslFloat4& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax || a.get_lmax() != lmax)
	{
		cmd_error("ERROR: nsl_num_4::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const NslDouble4& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax || a.get_lmax() != lmax)
	{
		cmd_error("ERROR: nsl_num_4::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const NslInt4& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax || a.get_lmax() != lmax)
	{
		cmd_error("ERROR: nsl_num_4::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}
/*
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(
	const nsl_din_num_4<NslNumType,NslTypeId>& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax || a.get_lmax() != lmax)
	{
		cmd_error("ERROR: nsl_num_4::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(
	const nsl_dout_num_4<NslNumType,NslTypeId>& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax || a.get_lmax() != lmax)
	{
		cmd_error("ERROR: nsl_num_4::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}
*//*
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;


	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;


	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;


	return *this;
}
/*
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(
	const nsl_din_num_0<NslNumType,NslTypeId>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;


	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(
	const nsl_dout_num_0<NslNumType,NslTypeId>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;


	return *this;
}
*//*
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const float a)
{
	int timax = get_imax();  

	for (int i = 0; i < timax; i++)
		*v[i] = (NslNumType) a;

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const double a)
{
	int timax = get_imax();  

	for (int i = 0; i < timax; i++)
		*v[i] = (NslNumType) a;

	return *this;
}template<class NslNumType, int NslTypeId>
nsl_num_4<NslNumType,NslTypeId>& nsl_din_num_4<NslNumType,NslTypeId>::operator=(const int a)
{
	int timax = get_imax();  

	for (int i = 0; i < timax; i++)
		*v[i] = (NslNumType) a;

	return *this;
}
template<class NslNumType, int NslTypeId>
void nsl_din_num_4<NslNumType,NslTypeId>::send()
{
	*((AslInOutPort<NslNumType>*) _port) << *this;
}

template<class NslNumType, int NslTypeId>
void nsl_din_num_4<NslNumType,NslTypeId>::receive()
{
	*((AslInOutPort<NslNumType>*) _port) >> *this;
}
template<class NslNumType, int NslTypeId>
void nsl_din_num_4<NslNumType,NslTypeId>::copy(nsl_layer* var)
{
	int id = var->get_type_id();
	if (id == 0)
		*this = *((NslFloat4*) var);
	else if (id == 1)
		*this = *((NslDouble4*) var);
	else if (id == 2)
		*this = *((NslInt4*) var);
	else
		cmd_out("Bad Type ID: ",id);
}
*/
