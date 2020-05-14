/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_4.C
//

#include "nsl_num_4.h"
#include "nsl_num_3.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"
#include "nsl_kernel.h"


extern void cmd_error(const char *);
extern void cmd_error(const char *, int);

//template<class NslNumType>
nsl_num_4/*NslNumType*/::nsl_num_4(const int s1,const int s2,
	const int s3,const int s4,int sfg,int fg,int rfg) : 
	nsl_4_layer(s1,s2,s3,s4,sfg,fg,rfg)
{
	init_num_4(s1,s2,s3,s4);
}
//template<class NslNumType>
nsl_num_4/*NslNumType*/::nsl_num_4(const char* str,nsl_model* m,const int s1,
	const int s2, const int s3,const int s4, int sfg, int fg,int rfg) : 
	nsl_4_layer("num_4",str,m,s1,s2,s3,s4,sfg,fg,rfg)
{
	init_num_4(s1,s2,s3,s4);
}
//template<class NslNumType>
nsl_num_4/*NslNumType*/::nsl_num_4(const nsl_num_4/*NslNumType*/& a,
	int sfg,int fg,int rfg) : 
	nsl_4_layer(a.get_imax(),a.get_jmax(),a.get_kmax(),a.get_lmax(),
	sfg,fg,rfg)
{
        int s1 = a.get_imax();
        int s2 = a.get_jmax();
        int s3 = a.get_kmax();
        int s4 = a.get_lmax();

	v = new nsl_num_3/*NslNumType*/*[s1];

	for (int i = 0; i < s1; i++) 
		v[i] = new nsl_num_3/*NslNumType*/(s2,s3,s4,1);
	
        for (int i = 0; i < s1; i++)
        	*v[i] = a[i];
}

// nsl_num_4/*NslNumType*/ destructors

//template<class NslNumType>
nsl_num_4/*NslNumType*/::~nsl_num_4()
{
//	for (int i = 0; i < get_imax(); i++)
//		delete v[i];

	delete v;
}

// init

//template<class NslNumType>
int nsl_num_4/*NslNumType*/::init_num_4(const int s1,const int s2,
	const int s3,const int s4)
{
	if (s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0)
	{
		cmd_error("ERROR: init_num_4");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("s3: ",s3);
		cmd_error("s4: ",s4);
		cmd_error("Cannot create matrix");
		return 0;
	}
	else if (s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0)
	{
		v = (nsl_num_3/*NslNumType*/**) 0;
	}
	else
	{
		v = new nsl_num_3/*NslNumType*/*[s1];

		for (int i = 0; i < s1; i++) 
			v[i] = new nsl_num_3/*NslNumType*/(s2,s3,s4,1);
	}

	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::alloc_mem(const int s1,const int s2,
	const int s3,const int s4)
{
	init_4_layer(s1,s2,s3,s4);
	init_num_4(s1,s2,s3,s4);
	return 1;
}

// matrix object element

//template<class NslNumType>
NslNumType& nsl_num_4/*NslNumType*/::elem(const int i,const int j,
	const int k,const int l)
{
	if ((i < 0 || imax <= i) || (j < 0 || jmax <= j) || 
		(k < 0 || kmax <= k) || (l < 0 || lmax <= l))
	{
		cmd_error("ERROR: nsl_4::elem");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("j: ",j);
		cmd_error("k: ",k);
		cmd_error("l: ",l);
		cmd_error("Matrix index out of range");
		return (*v[0])[0][0][0];
	}

	return (*v[i])[j][k][l];
}
//template<class NslNumType>
nsl_num_3/*NslNumType*/& nsl_num_4/*NslNumType*/::operator[](const int i) const
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_4::operator[]");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix index out of range");
		return  *v[0];
	}

	return *v[i];
}
//template<class NslNumType>
nsl_num_2/*NslNumType*/& nsl_num_4/*NslNumType*/::get_matrix(const int i,
	const int j) const
{
	if ((i < 0 || imax <= i) || (j < 0 || jmax <= j))
	{
		cmd_error("ERROR: nsl_num_4::get_matrix");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("j: ",j);
		cmd_error("Matrix index out of range");
		return  (*v[0])[0];
	}

	return (*v[i])[j];
}
//template<class NslNumType>
void nsl_num_4/*NslNumType*/::set_value(const int i,const int j,
	const int k,const int l,const NslNumType val)
{
	(*v[i])[j][k][l] = val;
}

// assignment

//template<class NslNumType>
nsl_num_4/*NslNumType*/& nsl_num_4/*NslNumType*/::operator=(
	const nsl_num_4/*NslNumType*/& a)
{
	if (a.imax != imax || a.jmax != jmax || 
		a.kmax != kmax || a.lmax != lmax)
	{
		cmd_error("ERROR: nsl_num_4::operator=");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent sizes");
		return *this;
	}

	for (int i = 0; i < imax; i++)
		*v[i] = a[i];

	return *this;
}
//template<class NslNumType>
nsl_num_4/*NslNumType*/& nsl_num_4/*NslNumType*/::operator=(
	const nsl_num_0/*NslNumType*/& a)
{
	int timax = get_imax();  

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
		*v[i] = val;


	return *this;
}

//template<class NslNumType>
nsl_num_4/*NslNumType*/& nsl_num_4/*NslNumType*/::operator=(const NslNumType a)
{
	int timax = get_imax();  

	for (int i = 0; i < timax; i++)
		*v[i] = (NslNumType) a;

	return *this;
}

//template<class NslNumType>
NslNumType nsl_num_4/*NslNumType*/::max()
{
	NslNumType c = (*v[0])[0][0][0];

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		for (int k = 0; k < kmax; k++)
		     for (int l = 0; l < lmax; l++) 
			if ((*v[i])[j][k][l] > c)
				c = (*v[i])[j][k][l];


	return c;
}
//template<class NslNumType>
NslNumType nsl_num_4/*NslNumType*/::min()
{
	NslNumType c = (*v[0])[0][0][0];

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		for (int k = 0; k < kmax; k++)
		     for (int l = 0; l < lmax; l++) 
			if ((*v[i])[j][k][l] < c)
				c = (*v[i])[j][k][l];

	return c;
}
//template<class NslNumType>
NslNumType nsl_num_4/*NslNumType*/::max(int* im,int* jm,int* km,int* lm)
{
	NslNumType c = (*v[0])[0][0][0];
	*im = *jm = *km = *lm = 0;

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		for (int k = 0; k < kmax; k++)
		     for (int l = 0; l < lmax; l++) 
			if ((*v[i])[j][k][l] > c)
			{
				*im = i;
				*jm = j;
				*km = k;
				*lm = l;
				c = (*v[i])[j][k][l];
			}

	return c;
}
//template<class NslNumType>
NslNumType nsl_num_4/*NslNumType*/::min(int* im,int* jm,int* km,int* lm)
{
	NslNumType c = (*v[0])[0][0][0];
	*im = *jm = *km = *lm = 0;

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		for (int k = 0; k < kmax; k++)
		     for (int l = 0; l < lmax; l++) 
			if ((*v[i])[j][k][l] < c)
			{
				*im = i;
				*jm = j;
				*km = k;
				*lm = l;
				c = (*v[i])[j][k][l];
			}

	return c;
}

// element sum

//template<class NslNumType>
NslNumType nsl_num_4/*NslNumType*/::sum()
{
	NslNumType c = 0;

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		for (int k = 0; k < kmax; k++)
		     for (int l = 0; l < lmax; l++) 
			if ((*v[i])[j][k][l] < c)
				c = (*v[i])[j][k][l] + c;

	return c;
}

// sector

//template<class NslNumType>
nsl_num_4/*NslNumType*/ nsl_num_4/*NslNumType*/::get_sector(const int si0, 
	const int si1, const int sj0, const int sj1,
	const int sk0, const int sk1,const int sl0, const int sl1) const 
{
	if (si0 > si1 || sj0 > sj1 || sk0 > sk1 || sl0 > sl1 || si0 < 0 || 
	    sj0 < 0 || sk0 < 0 || sl0 < 0 || si1 > imax || sj1 > jmax || 
	    sk1 > kmax || sl1 > lmax)
	    {
		cmd_error("ERROR: nsl_num_4/*NslNumType*/::get_sector");
		this->print_status(std::cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("sk0: ",sk0);
		cmd_error("sk1: ",sk1);
		cmd_error("sl0: ",sl0);
		cmd_error("sl1: ",sl1);
		cmd_error("Bad 4 sector");
		return 0;
	    }

	int simax = si1 - si0 + 1;
	int sjmax = sj1 - sj0 + 1;
	int skmax = sk1 - sk0 + 1;
	int slmax = sl1 - sl0 + 1;

	nsl_num_4/*NslNumType*/ c(simax,sjmax,skmax,slmax);

	for (int i = si0; i <= si1; i++)
	    for (int j = sj0; j <= sj1; j++)
	        for (int k = sk0; j <= sk1; j++)
	            for (int l = sl0; j <= sl1; j++)
		    	c[i-si0][j-sj0][k-sk0][l-sl0] = (*v[i])[j][k][l]; 

	return c;
}
//template<class NslNumType>
nsl_num_4/*NslNumType*/ nsl_num_4/*NslNumType*/::set_sector(
	const nsl_num_4/*NslNumType*/& a, const int si0, const int sj0,
	const int sk0,const int sl0) 
{
	if (si0 < 0 || sj0 < 0 || sk0 < 0 || sl0 < 0)
	{
		cmd_error("ERROR: nsl_num_4/*NslNumType*/::set_sector");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("i0: ",si0);
		cmd_error("j0: ",sj0);
		cmd_error("k0: ",sk0);
		cmd_error("l0: ",sl0);
		cmd_error("Bad 4 sector");
		return 0;
	}

	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
	int sakmax = a.get_kmax();
	int salmax = a.get_lmax();
	int simax = get_imax();
	int sjmax = get_jmax();
	int skmax = get_kmax();
	int slmax = get_lmax();

	int scimax = (saimax < simax) ? saimax : simax;
	int scjmax = (sajmax < sjmax) ? sajmax : sjmax;
	int sckmax = (sakmax < skmax) ? sakmax : skmax;
	int sclmax = (salmax < slmax) ? salmax : slmax;

	for (int i = 0; i < scimax; i++)
	    for (int j = 0; j < scjmax; j++)
	        for (int k = 0; k < sckmax; k++)
	            for (int l = 0; l < sclmax; k++)
		    	(*v[i])[j][k][l] = a[i][j][k][l]; 

	return (*this);
}
//template<class NslNumType>
nsl_num_4/*NslNumType*/ nsl_num_4/*NslNumType*/::put_sector(
	const nsl_num_4/*NslNumType*/& a, const int si0, const int sj0,
	const int sk0,const int sl0) 
{
	return set_sector(a,si0,sj0,sk0,sl0);
}

// print

//template<class NslNumType>
int nsl_num_4/*NslNumType*/::print_num_4_status(std::ostream& out) const
{
	print_4_layer_status(out);
	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::print_status(std::ostream& out) const
{
	print_num_4_status(out);
	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::print_num_4(std::ostream& out) const
{
	print_num_4(out,0,imax-1,0,jmax-1,0,kmax-1,0,lmax-1);
	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::print_num_4(std::ostream& out,
	const int si0, const int si1, const int sj0,const  int sj1,
	const int sk0, const int sk1, const int sl0,const  int sl1) const 
{
	if (sub_layer_fg == 0)
		print_4_layer(out);

	if (si0 > si1 || sj0 > sj1 || si0 < 0 || sj0 < 0 || 
	    si1 > get_imax()-1 || sj1 > get_jmax()-1 ||
	    sk0 > sk1 || sl0 > sl1 || sk0 < 0 || sl0 < 0 || 
	    sk1 > get_kmax()-1 || sl1 > get_lmax()-1)
	    {
		cmd_error("ERROR: nsl_4::print");
		this->print_status(std::cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("sk0: ",sk0);
		cmd_error("sk1: ",sk1);
		cmd_error("sl0: ",sl0);
		cmd_error("sl1: ",sl1);
		cmd_error("i0: ",i0);
		cmd_error("j0: ",j0);
		cmd_error("i1: ",i1);
		cmd_error("j1: ",j1);
		cmd_error("k0: ",k0);
		cmd_error("l0: ",l0);
		cmd_error("k1: ",k1);
		cmd_error("l1: ",l1);
		cmd_error("Bad sector");
		return 0;
	    }

	for (int i = si0; i <= si1; i++) {
	   v[i]->print(out);
//	   out << "\n";
	}

	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::print(std::ostream& out) const
{
	print_num_4(out);
	return 1;
}

//template<class NslNumType>
int nsl_num_4/*NslNumType*/::reset_num_4(nsl_buffer* buf)
{
	NslNumType vs;

 	if (buf == NULL)
		(*this) = 0;
	else
	{
		*buf >> vs;
 		(*this) = vs;
	}
 
	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::reset(nsl_buffer* buf)
{
	reset_num_4(buf);
	return 1;
}

//template<class NslNumType>
int nsl_num_4/*NslNumType*/::write_num_4(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
		buf << *v[i]; 
	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::write(nsl_buffer& buf)
{
	write_num_4(buf);
	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::read_num_4(nsl_buffer& buf)
{
	int ti0 = i0, ti1 = i1, tj0 = j0, tj1 = j1;
	int tk0 = k0, tk1 = k1, tl0 = l0, tl1 = l1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
		buf >> j0;
		buf >> j1;
		buf >> k0;
		buf >> k1;
		buf >> l0;
		buf >> l1;
	}
	if (value_fg == 1)
	{
	  NslNumType val;
	  buf >> val; 
	  for (int i = i0; i <= i1; i++)
		*v[i] = val; 	
	}
	else 
	{
	  for (int i = i0; i <= i1; i++)
	  {
	        if (buf.get_str_cnt() == 0)
		    	((nsl_interpreter*) buf.get_m_parent())->init_input();
		buf >> *v[i]; 	 
	  }
	}

	i0 = ti0; i1 = ti1; j0 = tj0; j1 = tj1;
	k0 = tk0; k1 = tk1; l0 = tl0; l1 = tl1;

	return 1;
}
//template<class NslNumType>
int nsl_num_4/*NslNumType*/::read(nsl_buffer& buf)
{
	read_num_4(buf);
	return 1;
}


