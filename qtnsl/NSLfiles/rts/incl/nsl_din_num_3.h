/* SCCS  %W%---%E%--%U% */
//
//	nsl_din_num_3.h
//
/*
template<class NslNumType, int NslTypeId>
class nsl_din_num_3 : public nsl_num_3<NslNumType,NslTypeId>
{
public:
		nsl_din_num_3(const int = 0,const int = 0,
			const int = 0,int=0,int=0,int=1);
		nsl_din_num_3(const char*,nsl_public* = 0,
			const int = 0,const int = 0,const int = 0,
			int=0,int=1,int=1);
		nsl_din_num_3(const nsl_din_num_3<NslNumType,NslTypeId>&,int=0,int=0,int=1);

		~nsl_din_num_3();

	void initialize(const char*,nsl_public* = 0,
			const int = 0,const int = 0,const int = 0,
			int=0,int=1,int=1);

// assignment
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const NslFloat3&);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const NslDouble3&);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const NslInt3&);
//	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const nsl_din_num_3<NslNumType,NslTypeId>&);
//	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const nsl_dout_num_3<NslNumType,NslTypeId>&);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const NslFloat0&);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const NslFloat0&);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const NslFloat0&);
//	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const nsl_din_num_0<NslNumType,NslTypeId>&);
//	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const nsl_dout_num_0<NslNumType,NslTypeId>&);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const float);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const double);
	nsl_num_3<NslNumType,NslTypeId>& 	operator=(const int);
	
		void send();
		void receive();
		void copy(nsl_layer*);
};

template<class NslNumType, int NslTypeId>
nsl_din_num_3<NslNumType,NslTypeId>::nsl_din_num_3(const int s1,const int s2,
	const int s3,int sfg,int fg,int rfg) : nsl_num_3<NslNumType,NslTypeId>(s1,s2,s3,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_3<NslNumType,NslTypeId>::nsl_din_num_3(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,int sfg,int fg,int rfg) : 
	nsl_num_3<NslNumType,NslTypeId>(str,m,s1,s2,s3,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}
template<class NslNumType, int NslTypeId>
nsl_din_num_3<NslNumType,NslTypeId>::nsl_din_num_3(const nsl_din_num_3<NslNumType,NslTypeId>& a,
	int sfg,int fg,int rfg) : nsl_num_3<NslNumType,NslTypeId>(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}

template<class NslNumType, int NslTypeId>
nsl_din_num_3<NslNumType,NslTypeId>::~nsl_din_num_3()
{

}

// initialize

template<class NslNumType, int NslTypeId>
void nsl_din_num_3<NslNumType,NslTypeId>::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,int sfg,int fg,int rfg)
{
	nsl_num_3<NslNumType,NslTypeId>::initialize(str,m,s1,s2,s3,sfg,fg,rfg);
	_port = new AslInOutPort<NslNumType>(str,m,this,ASL_DATA_INPUT);
}

// assignment

template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const NslFloat3& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax)
	{
		cmd_error("ERROR: nsl_num_3::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a[i][j][k];

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const NslDouble3& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax)
	{
		cmd_error("ERROR: nsl_num_3::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a[i][j][k];

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const NslInt3& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax)
	{
		cmd_error("ERROR: nsl_num_3::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a[i][j][k];

	return *this;
}
/*
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(
	const nsl_din_num_3<NslNumType,NslTypeId>& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax)
	{
		cmd_error("ERROR: nsl_num_3::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a[i][j][k];

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(
	const nsl_dout_num_3<NslNumType,NslTypeId>& a)
{
	if (a.get_imax() != imax || a.get_jmax() != jmax || 
		a.get_kmax() != kmax)
	{
		cmd_error("ERROR: nsl_num_3::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a[i][j][k];

	return *this;
}
*//*
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const NslFloat0& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

	return *this;
}
/*
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(
	const nsl_din_num_0<NslNumType,NslTypeId>& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(
	const nsl_dout_num_0<NslNumType,NslTypeId>& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

	return *this;
}
*//*
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const float a)
{
       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a;

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const double a)
{
       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a;

	return *this;
}
template<class NslNumType, int NslTypeId>
nsl_num_3<NslNumType,NslTypeId>& nsl_din_num_3<NslNumType,NslTypeId>::operator=(const int a)
{
       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a;

	return *this;
}
template<class NslNumType, int NslTypeId>
void nsl_din_num_3<NslNumType,NslTypeId>::send()
{
	*((AslInOutPort<NslNumType>*) _port) << *this;
}

template<class NslNumType, int NslTypeId>
void nsl_din_num_3<NslNumType,NslTypeId>::receive()
{
	*((AslInOutPort<NslNumType>*) _port) >> *this;
}
template<class NslNumType, int NslTypeId>
void nsl_din_num_3<NslNumType,NslTypeId>::copy(nsl_layer* var)
{
	int id = var->get_type_id();
	if (id == 0)
		*this = *((NslFloat3*) var);
	else if (id == 1)
		*this = *((NslDouble3*) var);
	else if (id == 2)
		*this = *((NslInt3*) var);
	else
		cmd_out("Bad Type ID: ",id);
}*/
