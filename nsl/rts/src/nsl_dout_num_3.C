/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_3.C
//
/*
# include "nsl_all_kernel_include.h"
# include "asl_all_rts_include.h"

template<class NslNumType>
nsl_dout_num_3<NslNumType>::nsl_dout_num_3(const int s1,const int s2,
	const int s3,int sfg,int fg,int rfg) : nsl_num_3(s1,s2,s3,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat3>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_3<NslNumType>::nsl_dout_num_3(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,int sfg,int fg,int rfg) : 
	nsl_num_3(str,m,s1,s2,s3,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslDoutFloat3>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_3<NslNumType>::nsl_dout_num_3(const nsl_dout_num_3<NslNumType>& a,
	int sfg,int fg,int rfg) : nsl_num_3(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat3>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType>
nsl_dout_num_3<NslNumType>::~nsl_dout_num_3()
{

}

// initialize

template<class NslNumType>
void nsl_dout_num_3<NslNumType>::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,int sfg,int fg,int rfg)
{
	nsl_num_3::initialize(str,m,s1,s2,s3,sfg,fg,rfg);
	_port = new AslInOutPort<NslDoutFloat3>(str,m,this,ASL_DATA_OUTPUT);
}

// assignment

template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(
	const nsl_num_3<NslNumType>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(
	const nsl_din_num_3<NslNumType>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(
	const nsl_dout_num_3<NslNumType>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(
	const nsl_num_0<NslNumType>& a)
{
	NslNumType val = a.get_value();

        for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(
	const nsl_din_num_0<NslNumType>& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(
	const nsl_dout_num_0<NslNumType>& a)
{
	NslNumType val = a.get_value();

       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = val;

//	send(); // send out implicitely when modified
	
	return *this;
}

template<class NslNumType>
nsl_num_3<NslNumType>& nsl_dout_num_3<NslNumType>::operator=(const NslNumType a)
{
       for (int i = 0; i < imax; i++)
           for (int j = 0; j < jmax; j++)
        	for (int k = 0; k < kmax; k++)
        		(*v[i])[j][k] = a;

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
void nsl_dout_num_3<NslNumType>::send()
{
	*((AslInOutPort<NslDoutFloat3>*) _port) << *this;
}
template<class NslNumType>
void nsl_dout_num_3<NslNumType>::receive()
{
	*((AslInOutPort<NslDoutFloat3>*) _port) >> *this;
}
*/