/* SCCS  @(#)nsl_matrix_layer.C	1.2---95/08/13--18:20:33 */
//
//	nsl_matrix_layer.C
//
#include "nsl_kernel.h"
#include "nsl_matrix_layer.h"
#include "nsl_model.h"


extern int NSLoutput(const char* str1,const int str2);
extern int NSLoutput(const char* str1);

// creation without allocation
nsl_matrix_layer::nsl_matrix_layer(int sfg,int fg,int rfg) :
	nsl_layer(sfg,fg,rfg)
{
	init_matrix_layer();
}

nsl_matrix_layer::nsl_matrix_layer(const char*name,const char*type,
		const int s1,const int s2, int sfg,int fg,int rfg) :
	nsl_layer(name,type,NULL,sfg,fg,rfg)
{
	init_matrix_layer();
}

nsl_matrix_layer::nsl_matrix_layer(bool, int sfg,int fg,int rfg) :
	nsl_layer(sfg,fg,rfg)
{
	init_matrix_layer();
}

nsl_matrix_layer::nsl_matrix_layer(const char* lname,nsl_public* m,
	int sfg,int fg,int rfg) : nsl_layer("matrix_layer",lname,m,sfg,fg,rfg)
{
	init_matrix_layer();
}

nsl_matrix_layer::nsl_matrix_layer(const char* ltype,const char* lname,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_matrix_layer();
}
// creation with allocation
nsl_matrix_layer::nsl_matrix_layer(const int s1,const int s2,
	int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg)
{
	init_matrix_layer(s1,s2);
}
nsl_matrix_layer::nsl_matrix_layer(const char* ltype,const char* lname,
	nsl_public* m,const int s1,const int s2,int sfg,int fg,int rfg) :
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_matrix_layer(s1,s2);
}

// nsl_num_2 destructors

nsl_matrix_layer::~nsl_matrix_layer()
{
}

void nsl_matrix_layer::initialize(const char* ltype,const char* lname,
	nsl_public* m,const int s1,const int s2,int sfg,int fg,int rfg)
{
	nsl_layer::initialize(ltype,lname,m,sfg,fg,rfg);
	init_matrix_layer(s1,s2);
}

int nsl_matrix_layer::init_matrix_layer()
{
	set_abstract_type("matrix");

	i0 = 0;
	i1 = 0;
	j0 = 0;
	j1 = 0;
	imax = 0;
	jmax = 0;

	return 1;
}
int nsl_matrix_layer::init_matrix_layer(const int s1,const int s2)
{
	set_abstract_type("matrix");

	if (s1 <= 0 || s2 <= 0)
	{
		init_matrix_layer();
/*		cmd_error("ERROR: init_matrix_layer");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("Cannot create matrix");
		return 0;
*/	}
	else
	{
		i0 = 0; j0 = 0;
		i1 = s1-1; j1 = s2-1;
		imax = s1; jmax = s2;
	}

	return 1;
}

// print

int nsl_matrix_layer::nslPrint() const
{
	print_matrix_layer();
	return 1;
}
int nsl_matrix_layer::nslStatus() const
{
	print_matrix_layer_status();
	return 1;
}
int nsl_matrix_layer::print_matrix_layer_status() const
{
	print_layer_status();
	NSLoutput("\n# imax: ",imax);
	NSLoutput("\n# jmax: ",jmax);
	NSLoutput("\n# i0: ",i0);
	NSLoutput("\n# i1: ",i1);
	NSLoutput("\n# j0: ",j0);
	NSLoutput("\n# j1: ",j1);

	return 1;
}
int nsl_matrix_layer::print_matrix_layer() const
{
	print_layer();
	NSLoutput("\n");
	return 1;
}

// ostream

int nsl_matrix_layer::print(ostream& out) const
{
	print_matrix_layer(out);
	return 1;
}
int nsl_matrix_layer::print_status(ostream& out) const
{
	print_matrix_layer_status(out);
	return 1;
}
int nsl_matrix_layer::print_matrix_layer_status(ostream& out) const
{
	print_layer_status(out);
	out << "# imax: " << imax << "\n";
	out << "# jmax: " << jmax << "\n";
	out << "# i0: " << i0 << "\n";
	out << "# i1: " << i1 << "\n";
	out << "# j0: " << j0 << "\n";
	out << "# j1: " << j1 << "\n";
	out.flush();
	return 1;
}
int nsl_matrix_layer::print_matrix_layer(ostream& out) const
{
	print_layer(out);
	return 1;
}

int nsl_matrix_layer::reset_matrix_layer(nsl_buffer*)
{
	return 1;
}
int nsl_matrix_layer::reset(nsl_buffer* buf)
{
	reset_matrix_layer(buf);
	return 1;
}

int nsl_matrix_layer::write_matrix_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_matrix_layer::write(nsl_buffer& buf)
{
	write_matrix_layer(buf);
	return 1;
}
int nsl_matrix_layer::read_matrix_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_matrix_layer::read(nsl_buffer& buf)
{
	read_matrix_layer(buf);
	return 1;
}
