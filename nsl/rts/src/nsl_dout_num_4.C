/* SCCS  %W%---%E%--%U% */
//
//	nsl_dout_num_4.C
//
/*
# include "nsl_all_kernel_include.h"
# include "asl_all_rts_include.h"

template<class NslNumType>
nsl_dout_num_4<NslNumType>::nsl_dout_num_4(const int s1,const int s2,
	const int s3,const int s4,int sfg,int fg,int rfg) : 
	nsl_num_4(s1,s2,s3,s4,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat4>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_4<NslNumType>::nsl_dout_num_4(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,const int s4, int sfg, int fg,int rfg) : 
	nsl_num_4(str,m,s1,s2,s3,s4,sfg,fg,rfg)
{
	_port = new AslInOutPort<NslDoutFloat4>(str,m,this,ASL_DATA_OUTPUT);
}
template<class NslNumType>
nsl_dout_num_4<NslNumType>::nsl_dout_num_4(const nsl_dout_num_4<NslNumType>& a,
	int sfg,int fg,int rfg) : 
	nsl_num_4(a,sfg,fg,rfg)
{
//	_port = new AslInOutPort<NslDoutFloat4>(str,m,this,ASL_DATA_OUTPUT);
}

template<class NslNumType>
nsl_dout_num_4<NslNumType>::~nsl_dout_num_4()
{

}

// initialize

template<class NslNumType>
void nsl_dout_num_4<NslNumType>::initialize(const char* str,nsl_public* m,const int s1,
	const int s2, const int s3,const int s4, int sfg, int fg,int rfg)  
{
	nsl_num_4::initialize(str,m,s1,s2,s3,s4,sfg,fg,rfg);
	_port = new AslInOutPort<NslDoutFloat4>(str,m,this,ASL_DATA_OUTPUT);
}

// assignment

template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(
	const nsl_num_4<NslNumType>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(
	const nsl_din_num_4<NslNumType>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(
	const nsl_dout_num_4<NslNumType>& a)
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

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(
	const nsl_num_0<NslNumType>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;
		
//	send(); // send out implicitely when modified

	return *this;
}
template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(
	const nsl_din_num_0<NslNumType>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(
	const nsl_dout_num_0<NslNumType>& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;

//	send(); // send out implicitely when modified
	
	return *this;
}

template<class NslNumType>
nsl_num_4<NslNumType>& nsl_dout_num_4<NslNumType>::operator=(const NslNumType a)
{
	int timax = get_imax();  

	for (int i = 0; i < timax; i++)
		*v[i] = (NslNumType) a;

//	send(); // send out implicitely when modified
	
	return *this;
}
template<class NslNumType>
void nsl_dout_num_4<NslNumType>::send()
{
	*((AslInOutPort<NslDoutFloat4>*) _port) << *this;
}
template<class NslNumType>
void nsl_dout_num_4<NslNumType>::receive()
{
	*((AslInOutPort<NslDoutFloat4>*) _port) >> *this;
}
*/