/* SCCS  %W%---%E%--%U% */
//
//	nsl_str_matrix.C
//



#include "nsl_kernel.h"
#include "nsl_stream.h"

extern void cmd_error(const char *);


nsl_str_matrix::nsl_str_matrix(const int s1,const int s2,
	int sfg,int fg,int rfg) : nsl_matrix_layer(s1,s2,sfg,fg,rfg)
{
	init_str_matrix(s1,s2);
}
nsl_str_matrix::nsl_str_matrix(const char* str,nsl_model* m,
	const int s1,const int s2,int sfg,int fg,int rfg) : 
	nsl_matrix_layer("str_matrix",str,m,s1,s2,sfg,fg,rfg)
{
	init_str_matrix(s1,s2);
}
nsl_str_matrix::nsl_str_matrix(const nsl_str_matrix& a,int sfg,int fg,
	int rfg) : nsl_matrix_layer(a.get_imax(),a.get_jmax(),sfg,fg,rfg)
{
	int i;

        int s1 = a.get_imax();
        int s2 = a.get_jmax();

        v = new char**[s1];

        for (i = 0; i < s1; i++)
                v[i] = new char*[s2];

        for (i = 0; i < s1; i++)
           for (int j = 0; j < s2; j++)
	   {
		v[i][j] = new char[NSL_NAME_SIZE];
                strcpy(v[i][j],a.v[i][j]);
	   }
}

// nsl_str_matrix destructors

nsl_str_matrix::~nsl_str_matrix()
{
	for (int i = 0; i < get_imax(); i++)
		delete v[i];

	delete v;
}

// init

int nsl_str_matrix::init_str_matrix(const int s1,const int s2)
{
	int i,j;

	if (s1 < 0 || s2 < 0)
	{
		cmd_error("ERROR: init_str_matrix");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("Cannot create matrix");
		return 0;
	}
	else if (s1 == 0 || s2 == 0)
	{
		v = (char***) 0;
	}
	else
	{
		v = new char**[s1];

		for (i = 0; i < s1; i++)
			v[i] = new char*[s2];
	
		for (i = 0; i < s1; i++)
		   for (j = 0; j < s2; j++)
		   {
			v[i][j] = new char[NSL_NAME_SIZE];
			strcpy(v[i][j],"");
		   }
	}

	return 1;
}
int nsl_str_matrix::alloc_mem(const int s1,const int s2)
{
	init_matrix_layer(s1,s2);
	init_str_matrix(s1,s2);
	return 1;
}

// matrix object element

char***& nsl_str_matrix::elem(const int i,const int j) 
{
	if ((i < 0 || imax <= i) || (j < 0 || jmax <= j))
	{
		cmd_error("ERROR: nsl_num_2::elem");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("j: ",j);
		cmd_error("Matrix index out of range");
		return (char***&) v[0][0];
	}

	return (char***&) v[i][j];
}
char*** nsl_str_matrix::set_value(const int i,const int j,char* val)
{
	strcpy(v[i][j],val);
	return v;
}

// matrix assignment

char*** nsl_str_matrix::operator=(const nsl_str_matrix& a)
{
	if (a.imax != imax || a.jmax != jmax)
	{
		cmd_error("ERROR: nsl_num_2::operator=");
		cmd_error("Exit with the following status");
		a.print_status(cerr);
		this->print_status(cerr);
		cmd_error("Inconsistent matrix sizes");
		return 0;
	}

	for (int i = 0; i < imax; i++)
	   for (int j = 0; j < jmax; j++)
		strcpy(v[i][j],a.v[i][j]);

	return v;
}
char*** nsl_str_matrix::operator=(const nsl_str_data& a)
{
	int timax = get_imax();  
	int tjmax = get_jmax();

	const char* val = a.get_value();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		strcpy(v[i][j],val);

	return v;
}

char*** nsl_str_matrix::operator=(const char* a)
{
	int timax = get_imax();
	int tjmax = get_jmax();

	for (int i = 0; i < timax; i++)
	   for (int j = 0; j < tjmax; j++)
		strcpy(v[i][j],a);

	return v;
}

// matrix sector

nsl_str_matrix nsl_str_matrix::get_sector(const int si0, const int si1, 
	const int sj0, const int sj1) const 
{
	if (si0 > si1 || sj0 > sj0 || si0 < 0 || sj0 < 0 || 
	    si1 > get_imax() || sj1 > get_jmax())
	    {
		cmd_error("ERROR: nsl_str_matrix::get_sector");
		this->print_status(cerr);
		cmd_error("si0: ",si0);
		cmd_error("si1: ",si1);
		cmd_error("sj0: ",sj0);
		cmd_error("sj1: ",sj1);
		cmd_error("Bad matrix sector");
		return 0;
	    }

	int simax = si1 - si0 + 1;
	int sjmax = sj1 - sj0 + 1;

	nsl_str_matrix c(simax,sjmax);

	for (int i = si0; i <= si1; i++)
	    for (int j = sj0; j <= sj1; j++)
		strcpy(c.v[i-si0][j-sj0],v[i][j]); 

	return c;
}
nsl_str_matrix nsl_str_matrix::set_sector(const nsl_str_matrix& a, 
	const int si0,const  int sj0) 
{
	if (si0 < 0 || sj0 < 0)
	{
		cmd_error("ERROR: nsl_str_matrix::set_sector");
		a.print_status(cerr);
		this->print_status(cerr);
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
		strcpy(v[i+si0][j+sj0],a.v[i][j]); 

	return (*this);
}
nsl_str_matrix nsl_str_matrix::put_sector(const nsl_str_matrix& a, 
	const int si0, const int sj0) 
{
	return set_sector(a,si0,sj0);
}
nsl_str_vector nsl_str_matrix::get_row(const int i) const 
{
	if (i < 0 || imax <= i)
	{
		cmd_error("ERROR: nsl_str_matrix::get_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_str_vector a(jmax);

	for (int j = 0; j < jmax; j++)
		strcpy(a.elem(j),v[i][j]);

	return a;
}
nsl_str_vector nsl_str_matrix::get_col(const int j) const 
{
	if (j < 0 || jmax <= j)
	{
		cmd_error("ERROR: nsl_str_matrix::get_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix col index out of range");
		return 0;
	}

	nsl_str_vector a(imax);

	for (int i = 0; i < imax; i++)
		strcpy(a.elem(i),v[i][j]);

	return a;
}
nsl_str_matrix nsl_str_matrix::set_row(const nsl_str_vector& a,const int i)
{
	if (i < 0 || imax <= i || a.get_imax() != jmax)
	{
		cmd_error("ERROR: nsl_str_matrix::set_row");
		cmd_error("name: ",get_name());
		cmd_error("i: ",i);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_str_matrix c(imax,jmax);
	char** av = a.get_vector();

	c = (*this);

	for (int j = 0; j < jmax; j++)
		strcpy(c.v[i][j],av[j]);

	return c;
}
nsl_str_matrix nsl_str_matrix::set_col(const nsl_str_vector& a,const int j)
{
	if (j < 0 || jmax <= j || a.get_imax() != imax)
	{
		cmd_error("ERROR: nsl_str_matrix::set_col");
		cmd_error("name: ",get_name());
		cmd_error("j: ",j);
		cmd_error("Matrix row index out of range");
		return 0;
	}

	nsl_str_matrix c(imax,jmax);
	char** av = a.get_vector();

	c = (*this);

	for (int i = 0; i < imax; i++)
		strcpy(c.v[i][j],av[i]);

	return c;
}

// print

int nsl_str_matrix::print_str_matrix_status(ostream& out) const
{
	print_matrix_layer_status(out);
	return 1;
}
int nsl_str_matrix::print_status(ostream& out) const
{
	print_str_matrix_status(out);
	return 1;
}
int nsl_str_matrix::print_str_matrix(ostream& out) const
{
	print_str_matrix(out,0,imax-1,0,jmax-1);
	return 1;
}
int nsl_str_matrix::print_str_matrix(ostream& out,
	const int si0, const int si1, const int sj0,const  int sj1) const 
{
	if (si0 > si1 || sj0 > sj1 || si0 < 0 || sj0 < 0 || 
	    si1 > get_imax()-1 || sj1 > get_jmax()-1)
	    {
		cmd_error("ERROR: nsl_num_2::print");
		this->print_status(cerr);
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
int nsl_str_matrix::print(ostream& out) const
{
	print_str_matrix(out);
	return 1;
}

int nsl_str_matrix::reset_str_matrix(nsl_buffer* buf)
{
	nsl_string vs;

 	if (buf == NULL)
		(*this) = "";
	else
	{
		*buf >> vs;
 		(*this) = vs;
	}
 
	return 1;
}
int nsl_str_matrix::reset(nsl_buffer* buf)
{
	reset_str_matrix(buf);
	return 1;
}

int nsl_str_matrix::write_str_matrix(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
		buf << v[i][j]; 
	return 1;
}
int nsl_str_matrix::write(nsl_buffer& buf)
{
	write_str_matrix(buf);
	return 1;
}
int nsl_str_matrix::read_str_matrix(nsl_buffer& buf)
{
	for (int i = i0; i <= i1; i++)
	    for (int j = j0; j <= j1; j++)
	    {
	        if (buf.get_str_cnt() == 0)
		    ((nsl_interpreter*) buf.get_m_parent())->init_input();
		buf >> v[i][j]; 
	    }
	return 1;
}
int nsl_str_matrix::read(nsl_buffer& buf)
{
	read_str_matrix(buf);
	return 1;
}


