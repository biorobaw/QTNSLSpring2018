/* SCCS  @(#)nsl_in_out_data.C	1.2---97/02/25--19:15:31 */
//
//	nsl_in_out_data.C
//
#include "nsl_kernel.h"
#include "nsl_in_out_data.h"
#include "nsl_stream.h"

//extern void cmd_error(const char *, int);

nsl_in_out_data::nsl_in_out_data(int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_in_out_data();
}
nsl_in_out_data::nsl_in_out_data(const char* str,nsl_model* m,int sfg,int fg,
	int rfg) : nsl_data_layer("in_out_data",str,m,sfg,fg,rfg)
{
	init_in_out_data();
}
nsl_in_out_data::nsl_in_out_data(const char* str,const in_out_enum val,
	nsl_model* m,int sfg,int fg,int rfg) : 
	nsl_data_layer("in_out_data",str,m,sfg,fg,rfg)
{
	init_in_out_data();
	sval = val;
}

nsl_in_out_data::nsl_in_out_data(const nsl_in_out_data& a,int sfg,int fg,
	int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_in_out_data();
	sval = a.get_value();
}

// nsl_in_out_data destructors

nsl_in_out_data::~nsl_in_out_data()
{
}

// init

int nsl_in_out_data::init_in_out_data()
{
	sval = NSL_INPUT;
	return 1;
}

// nsl_in_out_data set values

in_out_enum nsl_in_out_data::set_value(const in_out_enum val)
{
	sval = val;
	return sval;
}

// nsl_in_out_data assignment

in_out_enum nsl_in_out_data::operator=(const nsl_in_out_data& a)
{
	sval = a.get_value();
	return sval;
}
in_out_enum nsl_in_out_data::operator=(const in_out_enum val)
{
	sval = val;
	return sval;
}

// print

int nsl_in_out_data::print_in_out_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_in_out_data::print_status(ostream& out) const
{
	print_in_out_data_status(out);
	return 1;
}
int nsl_in_out_data::print_in_out_data(ostream& out) const
{
	print_data_layer(out);
	out <<  sval << "\n";
	out.flush();
	return 1;
}
int nsl_in_out_data::print(ostream& out) const
{
	print_in_out_data(out);
	return 1;
}

int nsl_in_out_data::reset_in_out_data(nsl_buffer* buf)
{
	if (buf == NULL)
		sval = NSL_INPUT;
//	else
//		*buf >> sval;

	return 1;
}
int nsl_in_out_data::reset(nsl_buffer* buf)
{
	reset_in_out_data(buf);
	return 1;
}

int nsl_in_out_data::write_in_out_data(nsl_buffer& buf)
{
	buf << sval;
	return 1;
}
int nsl_in_out_data::write(nsl_buffer& buf)
{
	write_in_out_data(buf);
	return 1;
}
int nsl_in_out_data::read_in_out_data(nsl_buffer& buf)
{
	nsl_string str;
	buf >> str;

	if (strcmp(str,"NSL_INPUT") == 0)
		sval = NSL_INPUT;
	else if (strcmp(str,"NSL_OUTPUT") == 0)
		sval = NSL_OUTPUT;
	else if (strcmp(str,"NSL_INOUT") == 0)
		sval = NSL_INOUT;
	else
		cmd_error("in_out_data:read: BAD string: ",str);

	return 1;
}
int nsl_in_out_data::read(nsl_buffer& buf)
{
	read_in_out_data(buf);
	return 1;
}


