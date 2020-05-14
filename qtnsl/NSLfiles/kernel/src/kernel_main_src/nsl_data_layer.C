/* SCCS  @(#)nsl_data_layer.C	1.2---95/08/13--18:20:26 */
//
//	nsl_data_layer.C
//
#include "nsl_kernel.h"
#include "nsl_data_layer.h"
#include "nsl_buffer.h"

nsl_data_layer::nsl_data_layer(int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg)
{
	init_data_layer();
}

nsl_data_layer::nsl_data_layer(const char *a, const char *b, int sfg,int fg,int rfg) : nsl_layer(sfg,fg,rfg) //TODO: char is passed in this format from int_data
{
	nsl_layer::initialize(a,b,NULL,sfg,fg,rfg);
	init_data_layer();
}

nsl_data_layer::nsl_data_layer(const char* ltype,const char* lname,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_layer(ltype,lname,m,sfg,fg,rfg)
{
	init_data_layer();
}

// nsl_data_layer destructors

nsl_data_layer::~nsl_data_layer()
{
}

void nsl_data_layer::initialize(const char* ltype,const char* lname,
	nsl_public* m,int sfg,int fg,int rfg)
{
	nsl_layer::initialize(ltype,lname,m,sfg,fg,rfg);
	init_data_layer();
}

// init

int nsl_data_layer::init_data_layer()
{
	set_abstract_type("data");

	return 1;
}

// print 

int nsl_data_layer::print_data_layer_status() const
{
	print_layer_status();
	return 1;
}
int nsl_data_layer::nslStatus() const // virtual
{
	print_data_layer_status();
	return 1;
}
int nsl_data_layer::print_data_layer() const
{
	print_layer();
	return 1;
}
int nsl_data_layer::nslPrint() const // virtual
{
	print_data_layer();
	return 1;
}

// ostream

int nsl_data_layer::print_data_layer_status(ostream& out) const
{
	print_layer_status(out);
	return 1;
}
int nsl_data_layer::print_status(ostream& out) const // virtual
{
	print_data_layer_status(out);
	return 1;
}
int nsl_data_layer::print_data_layer(ostream& out) const
{
	print_layer(out);
	return 1;
}
int nsl_data_layer::print(ostream& out) const // virtual
{
	print_data_layer(out);
	return 1;
}

int nsl_data_layer::reset_data_layer(nsl_buffer*)
{
	return 1;
}
int nsl_data_layer::reset(nsl_buffer* buf)
{
	reset_data_layer(buf);
	return 1;
}

int nsl_data_layer::write_data_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_data_layer::write(nsl_buffer& buf)
{
	write_data_layer(buf);
	return 1;
}
int nsl_data_layer::read_data_layer(nsl_buffer& buf)
{
	write_layer(buf);
	return 1;
}
int nsl_data_layer::read(nsl_buffer& buf)
{
	read_data_layer(buf);
	return 1;
}


