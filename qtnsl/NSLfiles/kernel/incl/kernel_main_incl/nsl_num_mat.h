/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_mat.h
//

template<class NslNumType>
class nsl_num_mat : public nsl_matrix_layer
{
protected:
	NslNumType** v; 
public:
		nsl_num_mat(const int = 0,const int = 0,int=1);
		nsl_num_mat(const char*,nsl_model* = 0,const int = 0,
			const int = 0,int=1,int=1);
		nsl_num_mat(const nsl_num_mat<NslNumType>&,int=1);

		~nsl_num_mat();

	int	init_num_matrix(const int = 0,const int = 0);
	int	alloc_mem(const int,const int);

// get value
	NslNumType**	get_matrix() const { return v; }

// element retrieval
	NslNumType&	elem(const int,const int);
	nsl_num_vec<NslNumType>&	operator[](const int);

	// set value
	NslNumType	set_value(const int,const int,const int);
	NslNumType	set_value(const int,const int,const float);
	NslNumType	set_value(const int,const int,const double);

// assignment
	NslNumType** 	operator=(const nsl_num_mat<float>&);
	NslNumType** 	operator=(const nsl_num_mat<double>&);
	NslNumType** 	operator=(const nsl_num_mat<int>&);
	NslNumType** 	operator=(const nsl_num_dat<float>&);
	NslNumType** 	operator=(const nsl_num_dat<double>&);
	NslNumType** 	operator=(const nsl_num_dat<int>&);
	NslNumType** 	operator=(const double);
	NslNumType** 	operator=(const float);
	NslNumType** 	operator=(const int);

        NslNumType        max();
        NslNumType        min();

        NslNumType        max(int*,int*); // return index
        NslNumType        min(int*,int*);


	// sum
	NslNumType	sum();

// also functions
	nsl_num_vec<NslNumType> reduce_row();
	nsl_num_vec<NslNumType> reduce_col();

	nsl_num_mat<NslNumType> get_sector(const int,const int,const int,
		const int) const;
	nsl_num_mat<NslNumType> set_sector(const nsl_num_mat<NslNumType>&,
		const int,const int);
	nsl_num_mat<NslNumType> put_sector(const nsl_num_mat<NslNumType>&,
		const int,const int);

	nsl_num_vec<NslNumType>	get_row(const int) const;
	nsl_num_vec<NslNumType>	get_col(const int) const;
	nsl_num_mat<NslNumType>	set_row(const nsl_num_vec<NslNumType>&,const int);
	nsl_num_mat<NslNumType>	set_col(const nsl_num_vec<NslNumType>&,const int);

// print

	virtual int	print(ostream&) const;
	int	print_num_matrix(ostream&) const;
	int	print_num_matrix(ostream&,const int,const int,const int,
		const int) const;
	virtual int	print_status(ostream&) const;
	int	print_num_matrix_status(ostream&) const;

	int 	reset_num_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

template<class NslNumType>
nsl_num_mat<NslNumType>::nsl_num_mat(const int s1,const int s2,
	int rfg) : nsl_matrix_layer(s1,s2,rfg)
{
	init_num_matrix(s1,s2);
}
template<class NslNumType>
nsl_num_mat<NslNumType>::nsl_num_mat(const char* str,nsl_model* m,const int s1,
	const int s2, int fg,int rfg) : 
	nsl_matrix_layer("num_matrix",str,m,s1,s2,fg,rfg)
{
	init_num_matrix(s1,s2);
}
template<class NslNumType>
nsl_num_mat<NslNumType>::nsl_num_mat(const nsl_num_mat<NslNumType>& a,
	int rfg) : nsl_matrix_layer(a.get_imax(),a.get_jmax(),rfg)
{
        int s1 = a.get_imax();
        int s2 = a.get_jmax();

        v = new NslNumType*[s1];

        for (int i = 0; i < s1; i++)
                v[i] = new NslNumType[s2];

        for (i = 0; i < s1; i++)
           for (int j = 0; j < s2; j++)
                v[i][j] = a.v[i][j];
}

// nsl_num_mat<NslNumType> destructors

template<class NslNumType>
nsl_num_mat<NslNumType>::~nsl_num_mat()
{
	for (int i = 0; i < get_imax(); i++)
		delete v[i];

	delete v;
}

// init

template<class NslNumType>
int nsl_num_mat<NslNumType>::init_num_matrix(const int s1,const int s2)
{
	if (s1 < 0 || s2 < 0)
	{
		cmd_error("ERROR: init_num_matrix");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("Cannot create matrix");
		return 0;
	}
	else if (s1 == 0 || s2 == 0)
	{
		v = (NslNumType**) 0;
	}
	else
	{
		v = new NslNumType*[s1];

		for (int i = 0; i < s1; i++)
			v[i] = new NslNumType[s2];
	
		for (i = 0; i < s1; i++)
		   for (int j = 0; j < s2; j++)
			v[i][j] = 0;
	}

	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::alloc_mem(const int s1,const int s2)
{
	init_matrix_layer(s1,s2);
	init_num_matrix(s1,s2);
	return 1;
}

// matrix object element

template<class NslNumType>
NslNumType& nsl_num_mat<NslNumType>::elem(const int i,const int j)
{
	if ((i < 0 || imax <= i) || (j < 0 || jmax <= j))
	{
		cmd_error("ERROR: nsl_num_2::elem");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("j: ",j);
		cmd_error("Matrix index out of range");
		return (NslNumType&) v[0][0];
	}

	return (NslNumType&) v[i][j];
}
template<class NslNumType>
nsl_num_vec<NslNumType>& nsl_num_mat<NslNumType>::operator[](const int i)
{
/*AW98	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_3::operator[]");
		cmd_error("name: ",get_name());
		cmd_error("index out of range");
		return *v[0];
	}
*/
//AW98 temporary
	static nsl_num_vec<NslNumType> tmp(jmax);
	tmp = get_row(i);
	return tmp; // (*v)[i];
}
template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::set_value(const int i,const int j,const int val)
{
	return v[i][j] = (NslNumType) val;
}
template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::set_value(const int i,const int j,
	const float val)
{
	return v[i][j] = (NslNumType) val;
}
template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::set_value(const int i,const int j,
	const double val)
{
	return v[i][j] = (NslNumType) val;
}

// matrix assignment

template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const nsl_num_mat<float>& a)
{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = a.v[i][j];

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const nsl_num_mat<double>& a)
{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = a.v[i][j];

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const nsl_num_mat<int>& a)
{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("Inconsistent matrix sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = a.v[i][j];

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const nsl_num_dat<float>& a)
{
	int timax = get_imax();  
	int tjmax = get_jmax();

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = val;

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const nsl_num_dat<double>& a)
{
	int timax = get_imax();  
	int tjmax = get_jmax();

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = val;

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const nsl_num_dat<int>& a)
{
	int timax = get_imax();  
	int tjmax = get_jmax();

	NslNumType val = a.get_value();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = val;

	return v;
}

template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const double a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		v[i][j] = (NslNumType) a;

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const float a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = (NslNumType) a;

	return v;
}
template<class NslNumType>
NslNumType** nsl_num_mat<NslNumType>::operator=(const int a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		v[i][j] = (NslNumType) a;

	return v;
}

template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::max()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	NslNumType c = v[0][0];

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] > c)
			c = v[i][j];

	return c;
}
template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::min()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	NslNumType c = v[0][0];

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] < c)
			c = v[i][j];

	return c;
}
template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::max(int* im,int* jm)
{
	int simax = get_imax();
	int sjmax = get_jmax();

	NslNumType c = v[0][0];
	*im = *jm = 0;

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] > c)
		{
			*im = i;
			*jm = j;
			c = v[i][j];
		}

	return c;
}
template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::min(int* im,int* jm)
{
	int simax = get_imax();
	int sjmax = get_jmax();

	NslNumType c = v[0][0];
	*im = *jm = 0;

	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		if (v[i][j] < c)
		{
			*im = i;
			*jm = j;
			c = v[i][j];
		}

	return c;
}

// element sum

template<class NslNumType>
NslNumType nsl_num_mat<NslNumType>::sum()
{
	NslNumType c = 0;

	for (int i = 0; i < imax; i++)
	    for (int j = 0; j < jmax; j++)
		c = v[i][j] + c;

	return c;
}

// vector transformations

template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_mat<NslNumType>::reduce_col()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	nsl_num_vec<NslNumType> c(simax);
	NslNumType* cv = c.get_vector();
	
	for (int j = 0; j < sjmax; j++)
	    for (int i = 0; i < simax; i++)
		cv[i] = v[i][j] + cv[i];

	return c;
}
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_mat<NslNumType>::reduce_row()
{
	int simax = get_imax();
	int sjmax = get_jmax();

	nsl_num_vec<NslNumType> c(sjmax);
	NslNumType* cv = c.get_vector();
		
	for (int i = 0; i < simax; i++)
	   for (int j = 0; j < sjmax; j++)
		cv[j] = v[i][j] + cv[j];

	return c;
}

// matrix sector

template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_mat<NslNumType>::get_sector(const int si0, 
	const int si1, const int sj0, const int sj1) const 
{
	if (si0 > si1 || sj0 > sj0 || si0 < 0 || sj0 < 0 || 
	    si1 > get_imax() || sj1 > get_jmax())
	    {
		cmd_error("ERROR: nsl_num_mat<NslNumType>::get_sector");
		this->print_status(std::cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("Bad matrix sector");
		return 0;
	    }

	int simax = si1 - si0 + 1;
	int sjmax = sj1 - sj0 + 1;

	nsl_num_mat<NslNumType> c(simax,sjmax);

	for (int i = si0; i <= si1; i++)
	    for (int j = sj0; j <= sj1; j++)
		c.v[i-si0][j-sj0] = v[i][j]; 

	return c;
}
template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_mat<NslNumType>::set_sector(
	const nsl_num_mat<NslNumType>& a, const int si0, const int sj0) 
{
	if (si0 < 0 || sj0 < 0)
	{
		cmd_error("ERROR: nsl_num_mat<NslNumType>::set_sector");
		a.print_status(std::cerr);
		this->print_status(std::cerr);
		cmd_error("i0: ",si0);
		cmd_error("j0: ",sj0);
		cmd_error("Bad matrix sector");
		return 0;
	}

	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
	int simax = get_imax();
	int sjmax = get_jmax();

	int scimax = (saimax < simax) ? saimax : simax;
	int scjmax = (sajmax < sjmax) ? sajmax : sjmax;

	for (int i = 0; i < scimax; i++)
	    for (int j = 0; j < scjmax; j++)
		v[i+si0][j+sj0] = a.v[i][j]; 

	return (*this);
}
template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_mat<NslNumType>::put_sector(
	const nsl_num_mat<NslNumType>& a, const int si0, const int sj0) 
{
	return set_sector(a,si0,sj0);
}
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_mat<NslNumType>::get_row(const int i) const 
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_num_mat<NslNumType>::get_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_vec<NslNumType> a(jmax);

	for (int j = 0; j < jmax; j++)
		a.elem(j) = v[i][j];

	return a;
}
template<class NslNumType>
nsl_num_vec<NslNumType> nsl_num_mat<NslNumType>::get_col(const  int j) const 
{
	if (j < 0 || jmax <= j)
	{
		cmd_error("ERROR: nsl_num_mat<NslNumType>::get_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix col index out of range");
		return 0;
	}

	nsl_num_vec<NslNumType> a(imax);

	for (int i = 0; i < imax; i++)
		a.elem(i) = v[i][j];

	return a;
}
template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_mat<NslNumType>::set_row(
	const nsl_num_vec<NslNumType>& a,const int i)
{
	if (i < 0 || imax <= i || a.get_imax() != jmax)
	{
		cmd_error("ERROR: nsl_num_mat<NslNumType>::set_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_mat<NslNumType> c(imax,jmax);

	c = (*this);
	NslNumType* av = a.get_vector();

	for (int j = 0; j < jmax; j++)
		c.v[i][j] = av[j];

	return c;
}
template<class NslNumType>
nsl_num_mat<NslNumType> nsl_num_mat<NslNumType>::set_col(
	const nsl_num_vec<NslNumType>& a,const int j)
{
	if (j < 0 || jmax <= j || a.get_imax() != imax)
	{
		cmd_error("ERROR: nsl_num_mat<NslNumType>::set_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_num_mat<NslNumType> c(imax,jmax);

	c = (*this);
	NslNumType* av = a.get_vector();

	for (int i = 0; i < imax; i++)
		c.v[i][j] = av[i];

	return c;
}

// print

template<class NslNumType>
int nsl_num_mat<NslNumType>::print_num_matrix_status(ostream& out) const 
{
	print_matrix_layer_status(out);
	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::print_status(ostream& out) const 
{
	print_num_matrix_status(out);
	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::print_num_matrix(ostream& out) const 
{
	print_num_matrix(out,0,imax-1,0,jmax-1);
	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::print_num_matrix(ostream& out,
	const int si0, const int si1, const int sj0,const  int sj1) const 
{
	print_matrix_layer(out);
	if (si0 > si1 || sj0 > sj1 || si0 < 0 || sj0 < 0 || 
	    si1 > get_imax()-1 || sj1 > get_jmax()-1)
	    {
		cmd_error("ERROR: nsl_num_2::print");
		this->print_status(std::cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("i0: ",i0);
		cmd_error("j0: ",j0);
		cmd_error("i1: ",i1);
		cmd_error("j1: ",j1);
		cmd_error("Bad matrix sector");
		return 0;
	    }

	for (int i = si0; i <= si1; i++)
	{
	    for (int j = sj0; j <= sj1; j++)
		out << v[i][j] << " "; 
	    out << "\n";
	}

	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::print(ostream& out) const 
{
	print_num_matrix(out);
	return 1;
}

template<class NslNumType>
int nsl_num_mat<NslNumType>::reset_num_matrix(nsl_buffer* buf)
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
template<class NslNumType>
int nsl_num_mat<NslNumType>::reset(nsl_buffer* buf)
{
	reset_num_matrix(buf);
	return 1;
}

template<class NslNumType>
int nsl_num_mat<NslNumType>::write_num_matrix(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		buf << v[i][j]; 
	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::write(nsl_buffer& buf)
{
	write_num_matrix(buf);
	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::read_num_matrix(nsl_buffer& buf)
{
	int ti0 = i0, ti1 = i1, tj0 = j0, tj1 = j1;

	if (region_fg == 1)
	{
		buf >> i0;
		buf >> i1;
		buf >> j0;
		buf >> j1;
	}
	if (value_fg == 1)
	{
	  NslNumType val;
	  buf >> val; 
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		v[i][j] = val; 
	}
	else 
	{
	  for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
	    {
	        if (buf.get_str_cnt() == 0)
		    ((nsl_interpreter*) buf.get_m_parent())->init_input();
		buf >> v[i][j]; 
	    }
	}

	i0 = ti0; i1 = ti1; j0 = tj0; j1 = tj1;

	return 1;
}
template<class NslNumType>
int nsl_num_mat<NslNumType>::read(nsl_buffer& buf)
{
	read_num_matrix(buf);
	return 1;
}

