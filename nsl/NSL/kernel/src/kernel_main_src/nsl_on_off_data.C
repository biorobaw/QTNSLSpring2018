/* SCCS  %W%---%E%--%U% */
//
//	nsl_on_off_data.C
//
#include "nsl_kernel.h"
#include "nsl_on_off_data.h"
#include "nsl_buffer.h"
#include "nsl_stream.h"

nsl_on_off_data::nsl_on_off_data(int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_on_off_data();
}
nsl_on_off_data::nsl_on_off_data(const char* str,nsl_model* m,int sfg,int fg,
	int rfg) : nsl_data_layer("on_off_data",str,m,sfg,fg,rfg)
{
	init_on_off_data();
}
nsl_on_off_data::nsl_on_off_data(const char* str,const on_off_enum val,
	nsl_model* m,int sfg,int fg,int rfg) : 
	nsl_data_layer("on_off_data",str,m,sfg,fg,rfg)
{
	init_on_off_data();
	sval = val;
}

nsl_on_off_data::nsl_on_off_data(const nsl_on_off_data& a,int sfg,int fg,
	int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_on_off_data();
	sval = a.get_value();
}

// nsl_on_off_data destructors

nsl_on_off_data::~nsl_on_off_data()
{
}

// init

int nsl_on_off_data::init_on_off_data()
{
	sval = NSL_ON;
	return 1;
}

// nsl_on_off_data set values

on_off_enum nsl_on_off_data::set_value(const on_off_enum val)
{
	sval = val;
	return sval;
}

// nsl_on_off_data assignment

on_off_enum nsl_on_off_data::operator=(const nsl_on_off_data& a)
{
	sval = a.get_value();
	return sval;
}
on_off_enum nsl_on_off_data::operator=(const on_off_enum val)
{
	sval = val;
	return sval;
}

// print

int nsl_on_off_data::print_on_off_data_status(std::ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_on_off_data::print_status(std::ostream& out) const
{
	print_on_off_data_status(out);
	return 1;
}
int nsl_on_off_data::print_on_off_data(std::ostream& out) const
{
	print_data_layer(out);
	out <<  sval << "\n";
	out.flush();
	return 1;
}
int nsl_on_off_data::print(std::ostream& out) const
{
	print_on_off_data(out);
	return 1;
}

int nsl_on_off_data::reset_on_off_data(nsl_buffer* buf)
{
	if (buf == NULL)
		sval = NSL_ON;
//	else
//		*buf >> sval;

	return 1;
}
int nsl_on_off_data::reset(nsl_buffer* buf)
{
	reset_on_off_data(buf);
	return 1;
}

int nsl_on_off_data::write_on_off_data(nsl_buffer& buf)
{
	buf << sval;
	return 1;
}
int nsl_on_off_data::write(nsl_buffer& buf)
{
	write_on_off_data(buf);
	return 1;
}
int nsl_on_off_data::read_on_off_data(nsl_buffer& buf)
{
	nsl_string str;
	buf >> str;

	if (strcmp(str,"NSL_ON") == 0)
		sval = NSL_ON;
	else if (strcmp(str,"NSL_OFF") == 0)
		sval = NSL_OFF;
	else
		cmd_error("on_off_data:read: BAD string: ",str);

	return 1;
}
int nsl_on_off_data::read(nsl_buffer& buf)
{
	read_on_off_data(buf);
	return 1;
}


