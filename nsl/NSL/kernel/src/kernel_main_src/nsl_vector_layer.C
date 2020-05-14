/* SCCS  @(#)nsl_vector_layer.C	1.2---95/08/13--18:20:54 */
//
//	nsl_vector_layer.C
//
#include "nsl_kernel.h"
#include "nsl_vector_layer.h"
#include "nsl_model.h"

extern int NSLoutput(const char *);
extern int NSLoutput(const char *, int);

// creation without allocation
nsl_vector_layer::nsl_vector_layer(int sfg,int fg,int rfg) :
	nsl_layer(sfg,fg,rfg)
{
	init_vector_layer();
}

nsl_vector_layer::nsl_vector_layer(bool, int sfg,int fg,int rfg) :
	nsl_layer(sfg,fg,rfg)
{
	init_vector_layer();
}

nsl_vector_layer::nsl_vector_layer(const char* lname,nsl_public* m,
	int sfg,int fg,int rfg) : nsl_layer("vector_layer",lname,m,sfg,fg,rfg)
{
	init_vector_layer();
}
nsl_vector_layer::nsl_vector_layer(const char* ltype,const char* lname,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_vector_layer();
}
// creation with allocation
nsl_vector_layer::nsl_vector_layer(const int s,int sfg,int fg,int rfg) : 
	nsl_layer(sfg,fg,rfg)
{
	init_vector_layer(s);
}
nsl_vector_layer::nsl_vector_layer(const char* ltype,const char* lname,
	nsl_public* m,const int s,row_col_enum v,int sfg,int fg,int rfg) :
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_vector_layer(s);
	vec_type = v;   // horizontal/vertical
}

// nsl_num_1 destructors

nsl_vector_layer::~nsl_vector_layer()
{
}

void nsl_vector_layer::initialize(const char* ltype,const char* lname,
	nsl_public* m,const int s,row_col_enum v,int sfg,int fg,int rfg)
{
	nsl_layer::initialize(ltype,lname,m,sfg,fg,rfg);
	init_vector_layer(s);
	vec_type = v;   // horizontal/vertical
}

int nsl_vector_layer::init_vector_layer()
{
	set_abstract_type("vector");

	i0 = 0;
	i1 = 0;
	imax = 0;
	vec_type = NSL_ROW; // horizontal/vertical 

	return 1;
}
int nsl_vector_layer::init_vector_layer(const int s)
{
	set_abstract_type("vector");

	if (s <= 0)
	{
		init_vector_layer();
/*		cmd_error("ERROR: init_vector_layer");
		cmd_error("name: ",get_name());
		cmd_error("s: ",s);
		cmd_error("Bad Vector Size");
		return 1;
*/	}
	else
	{
		i0 = 0; i1 = s-1;
		imax = s;
	}

	return 1;
}

// print

int nsl_vector_layer::nslPrint() const
{
	print_vector_layer();
	return 1;
}
int nsl_vector_layer::print_vector_layer() const
{
	print_layer();
	NSLoutput("\n");

	return 1;
}
int nsl_vector_layer::nslStatus() const
{
	print_vector_layer_status();
	return 1;
}
int nsl_vector_layer::print_vector_layer_status() const
{
	print_layer_status();
	NSLoutput("\n# imax: ",imax);
	NSLoutput("\n# i0: ",i0);
	NSLoutput("\n# i1: ",i1);

	return 1;
}

// ostream

int nsl_vector_layer::print(ostream& out) const
{
	print_vector_layer(out);
	return 1;
}
int nsl_vector_layer::print_vector_layer(ostream& out) const
{
	print_layer(out);
	return 1;
}
int nsl_vector_layer::print_status(ostream& out) const
{
	print_vector_layer_status(out);
	return 1;
}
int nsl_vector_layer::print_vector_layer_status(ostream& out) const
{
	print_layer_status(out);
	out << "# imax: " << imax << "\n";
	out << "# i0: " << i0 << "\n";
	out << "# i1: " << i1 << "\n";
	out.flush();
	return 1;
}

int nsl_vector_layer::reset_vector_layer(nsl_buffer*)
{
	return 1;
}
int nsl_vector_layer::reset(nsl_buffer* buf)
{
	reset_vector_layer(buf);
	return 1;
}

int nsl_vector_layer::write_vector_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_vector_layer::write(nsl_buffer& buf)
{
	write_vector_layer(buf);
	return 1;
}
int nsl_vector_layer::read_vector_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_vector_layer::read(nsl_buffer& buf)
{
	read_vector_layer(buf);
	return 1;
}

