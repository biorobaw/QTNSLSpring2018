/* SCCS  @(#)nsl_4_layer.C	1.2---95/08/13--18:20:33 */
//
//	nsl_4_layer.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_4_layer.h"
#include "nsl_model.h"
#include "nsl_buffer.h"

extern int NSLoutput(const char *, int);

// creation without allocation
nsl_4_layer::nsl_4_layer(int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg)
{
	init_4_layer();
}
nsl_4_layer::nsl_4_layer(const char* lname,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_layer("4_layer",lname,m,sfg,fg,rfg)
{
	init_4_layer();
}
nsl_4_layer::nsl_4_layer(const char* ltype,const char* lname,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_4_layer();
}
// creation with allocation
nsl_4_layer::nsl_4_layer(const int s1,const int s2,const int s3,const int s4,
	int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg)
{
	init_4_layer(s1,s2,s3,s4);
}
nsl_4_layer::nsl_4_layer(const char* ltype,const char* lname,nsl_public* m,
	const int s1,const int s2,const int s3,const int s4,
	int sfg,int fg,int rfg) : nsl_layer(ltype,lname,m,sfg,fg,rfg) 
{
	init_4_layer(s1,s2,s3,s4);
}

// nsl_4 destructors

nsl_4_layer::~nsl_4_layer()
{
}

// initialize

void nsl_4_layer::initialize(const char* ltype,const char* lname,nsl_public* m,
	const int s1,const int s2,const int s3,const int s4,
	int sfg,int fg,int rfg)
{
	nsl_layer::initialize(ltype,lname,m,sfg,fg,rfg);
	init_4_layer(s1,s2,s3,s4);
}

int nsl_4_layer::init_4_layer()
{
	set_abstract_type("4");

	i0 = 0;
	i1 = 0;
	j0 = 0;
	j1 = 0;
	k0 = 0;
	k1 = 0;
	l0 = 0;
	l1 = 0;
	imax = 0;
	jmax = 0;
	kmax = 0;
	lmax = 0;

	return 1;
}
int nsl_4_layer::init_4_layer(const int s1,const int s2,
	const int s3,const int s4)
{
	set_abstract_type("4");

	if (s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0)
	{
		cmd_error("ERROR: init_4_layer");
		cmd_error("name: ",get_name());
		cmd_error("s1: ",s1);
		cmd_error("s2: ",s2);
		cmd_error("s3: ",s3);
		cmd_error("s4: ",s4);
		cmd_error("Cannot create 4");
		return 0;
	}

	i0 = 0; j0 = 0; k0 = 0; l0 = 0;
	i1 = s1-1; j1 = s2-1; k1 = s3-1; l1 = s4-1;
	imax = s1; jmax = s2; kmax = s3; lmax = s4;

	return 1;
}

// print

int nsl_4_layer::nslPrint() const
{
	print_4_layer();
	return 1;
}
int nsl_4_layer::nslStatus() const
{
	print_4_layer_status();
	return 1;
}
int nsl_4_layer::print_4_layer_status() const
{
	print_layer_status();
	NSLoutput("\n# imax: ",imax);
	NSLoutput("\n# jmax: ",jmax);
	NSLoutput("\n# kmax: ",kmax);
	NSLoutput("\n# lmax: ",lmax);
	NSLoutput("\n# i0: ",i0);
	NSLoutput("\n# i1: ",i1);
	NSLoutput("\n# j0: ",j0);
	NSLoutput("\n# j1: ",j1);
	NSLoutput("\n# k0: ",k0);
	NSLoutput("\n# k1: ",k1);
	NSLoutput("\n# l0: ",l0);
	NSLoutput("\n# l1: ",l1);

	return 1;
}
int nsl_4_layer::print_4_layer() const
{
	print_layer();
	return 1;
}

// ostream

int nsl_4_layer::print(ostream& out) const
{
	print_4_layer(out);
	return 1;
}
int nsl_4_layer::print_status(ostream& out) const
{
	print_4_layer_status(out);
	return 1;
}
int nsl_4_layer::print_4_layer_status(ostream& out) const
{
	print_layer_status(out);
	out << "// imax: " << imax << "\n";
	out << "// jmax: " << jmax << "\n";
	out << "// kmax: " << kmax << "\n";
	out << "// lmax: " << lmax << "\n";
	out << "// i0: " << i0 << "\n";
	out << "// i1: " << i1 << "\n";
	out << "// j0: " << j0 << "\n";
	out << "// j1: " << j1 << "\n";
	out << "// k0: " << k0 << "\n";
	out << "// k1: " << k1 << "\n";
	out << "// l0: " << l0 << "\n";
	out << "// l1: " << l1 << "\n";
	out.flush();
	return 1;
}
int nsl_4_layer::print_4_layer(ostream& out) const
{
	print_layer(out);
	return 1;
}

int nsl_4_layer::reset_4_layer(nsl_buffer*)
{
	return 1;
}
int nsl_4_layer::reset(nsl_buffer* buf)
{
	reset_4_layer(buf);
	return 1;
}

int nsl_4_layer::write_4_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_4_layer::write(nsl_buffer& buf)
{
	write_4_layer(buf);
	return 1;
}
int nsl_4_layer::read_4_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_4_layer::read(nsl_buffer& buf)
{
	read_4_layer(buf);
	return 1;
}


