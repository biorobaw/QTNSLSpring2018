/* SCCS  @(#)nsl_3_layer.C	1.2---95/08/13--18:20:33 */
//
//	nsl_3_layer.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_3_layer.h"
#include "nsl_buffer.h"

extern int NSLoutput(const char *, int);

// creation without allocation
nsl_3_layer::nsl_3_layer(int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg)
{
	init_3_layer();
}
nsl_3_layer::nsl_3_layer(const char* lname,nsl_public* m,int sfg,
	int fg,int rfg) : nsl_layer("3_layer",lname,m,sfg,fg,rfg)
{
	init_3_layer();
}
nsl_3_layer::nsl_3_layer(const char* ltype,const char* lname,nsl_public* m,
	int sfg,int fg,int rfg) : nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_3_layer();
}
// creation with allocation
nsl_3_layer::nsl_3_layer(const int s1,const int s2,
	const int s3,int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg)
{
	init_3_layer(s1,s2,s3);
}
nsl_3_layer::nsl_3_layer(const char* ltype,const char* lname,nsl_public* m,
	const int s1,const int s2,const int s3,int sfg,int fg,int rfg) : 
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_3_layer(s1,s2,s3);
}

// nsl_3 destructors

nsl_3_layer::~nsl_3_layer()
{
}

void nsl_3_layer::initialize(const char* ltype,const char* lname,nsl_public* m,
	const int s1,const int s2,const int s3,int sfg,int fg,int rfg)
{
	nsl_layer::initialize(ltype,lname,m,sfg,fg,rfg);
	init_3_layer(s1,s2,s3);
}

int nsl_3_layer::init_3_layer()
{
	set_abstract_type("3");

	i0 = 0;
	i1 = 0;
	j0 = 0;
	j1 = 0;
	k0 = 0;
	k1 = 0;
	imax = 0;
	jmax = 0;
	kmax = 0;

	return 1;
}
int nsl_3_layer::init_3_layer(const int s1,const int s2,
	const int s3)
{
	set_abstract_type("3");

	if (s1 < 0 || s2 < 0 || s3 < 0)
	{
		cmd_error("ERROR: init_3_layer");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("s3: ",s3);
		cmd_error("Cannot create 3");
		return 0;
	}

	i0 = 0; j0 = 0; k0 = 0;
	i1 = s1-1; j1 = s2-1; k1 = s3-1;
	imax = s1; jmax = s2; kmax = s3;

	return 1;
}

// print

int nsl_3_layer::nslPrint() const
{
	print_3_layer();
	return 1;
}
int nsl_3_layer::nslStatus() const
{
	print_3_layer_status();
	return 1;
}
int nsl_3_layer::print_3_layer_status() const
{
	print_layer_status();
	NSLoutput("\n# imax: ",imax);
	NSLoutput("\n# jmax: ",jmax);
	NSLoutput("\n# kmax: ",kmax);
	NSLoutput("\n# i0: ",i0);
	NSLoutput("\n# i1: ",i1);
	NSLoutput("\n# j0: ",j0);
	NSLoutput("\n# j1: ",j1);
	NSLoutput("\n# k0: ",k0);
	NSLoutput("\n# k1: ",k1);

	return 1;
}
int nsl_3_layer::print_3_layer() const
{
	print_layer();
	return 1;
}

// ostream

int nsl_3_layer::print(ostream& out) const
{
	print_3_layer(out);
	return 1;
}
int nsl_3_layer::print_status(ostream& out) const
{
	print_3_layer_status(out);
	return 1;
}
int nsl_3_layer::print_3_layer_status(ostream& out) const
{
	print_layer_status(out);
	out << "// imax: " << imax << "\n";
	out << "// jmax: " << jmax << "\n";
	out << "// kmax: " << kmax << "\n";
	out << "// i0: " << i0 << "\n";
	out << "// i1: " << i1 << "\n";
	out << "// j0: " << j0 << "\n";
	out << "// j1: " << j1 << "\n";
	out << "// k0: " << k0 << "\n";
	out << "// k1: " << k1 << "\n";
	out.flush();
	return 1;
}
int nsl_3_layer::print_3_layer(ostream& out) const
{
	print_layer(out);
	return 1;
}

int nsl_3_layer::reset_3_layer(nsl_buffer*)
{
	return 1;
}
int nsl_3_layer::reset(nsl_buffer* buf)
{
	reset_3_layer(buf);
	return 1;
}

int nsl_3_layer::write_3_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_3_layer::write(nsl_buffer& buf)
{
	write_3_layer(buf);
	return 1;
}
int nsl_3_layer::read_3_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_3_layer::read(nsl_buffer& buf)
{
	read_3_layer(buf);
	return 1;
}

