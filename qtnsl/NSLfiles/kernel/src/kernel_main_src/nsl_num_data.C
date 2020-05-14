/* SCCS  @(#)nsl_num_data.C	1.2---95/08/13--18:20:40 */
//
//	nsl_num_data.C
//
#include "nsl_kernel.h"
#include "nsl_num_data.h"
#include "nsl_stream.h"

extern void cmd_out(float);

nsl_num_data::nsl_num_data(const num_type val,int rfg) : nsl_data_layer(rfg)
{
	init_num_data();
	v = val;
}
nsl_num_data::nsl_num_data(const char* str,const num_type val,int fg,int rfg) : 
	nsl_data_layer("num_data",str,fg,rfg)
{
	init_num_data();
	v = val;
}
nsl_num_data::nsl_num_data(const nsl_num_data& a,int rfg) : nsl_data_layer(rfg)
{
	init_num_data();
	v = a.get_value();
}


// nsl_num_data destructors

nsl_num_data::~nsl_num_data()
{
}

// init

int nsl_num_data::init_num_data()
{
	v = 0;
	return 1;
}

// nsl_num_data set values

num_type nsl_num_data::set_value(const double val)
{
	return v = (num_type) val;
}
num_type nsl_num_data::set_value(const float val)
{
	return v = (num_type) val;
}
num_type nsl_num_data::set_value(const int val)
{
	return v = (num_type) val;
}

// nsl_num_data assignment

num_type nsl_num_data::operator=(const nsl_num_data& a)
{
	return v = (num_type) a.get_value();
}
num_type nsl_num_data::operator=(const double a)
{
	return v = (num_type) a;
}
num_type nsl_num_data::operator=(const float a)
{
	return v = (num_type) a;
}
num_type nsl_num_data::operator=(const int a)
{
	return v = (num_type) a;
}

// print

int nsl_num_data::print_num_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_num_data::print_status(ostream& out) const
{
	print_num_data_status(out);
	return 1;
}
int nsl_num_data::print_num_data(ostream& out) const
{
	print_data_layer(out);
	cmd_out(v); 
	cmd_out("\n");
	return 1;
}
int nsl_num_data::print(ostream& out) const
{
	print_num_data(out);
	return 1;
}

int nsl_num_data::reset_num_data(nsl_buffer* buf)
{
	if (buf == NULL)
		v = 0;
	else
		*buf >> v;

	return 1;
}
int nsl_num_data::reset(nsl_buffer* buf)
{
	reset_num_data(buf);
	return 1;
}

int nsl_num_data::write_num_data(nsl_buffer& buf)
{
	buf << v;
	return 1;
}
int nsl_num_data::write(nsl_buffer& buf)
{
	write_num_data(buf);
	return 1;
}
int nsl_num_data::read_num_data(nsl_buffer& buf)
{
	buf >> v;
	return 1;
}
int nsl_num_data::read(nsl_buffer& buf)
{
	read_num_data(buf);
	return 1;
}



