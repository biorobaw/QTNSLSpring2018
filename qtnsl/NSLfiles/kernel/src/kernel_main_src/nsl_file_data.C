/* SCCS  @(#)nsl_file_data.C	1.2---97/02/25--19:15:31 */
//
//	nsl_file_data.C
//
#include "nsl_kernel.h"
#include "nsl_file_data.h"
#include "nsl_model.h"
#include "nsl_stream.h"

nsl_file_data::nsl_file_data(int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_file_data();
}
nsl_file_data::nsl_file_data(const char* str,nsl_public* m,int sfg,int fg,
	int rfg) : nsl_data_layer("file_data",str,m,sfg,fg,rfg)
{
	init_file_data();
}
nsl_file_data::nsl_file_data(const char* str,const file_enum val,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_data_layer("file_data",str,m,sfg,fg,rfg)
{
	init_file_data();
	sval = val;
}

nsl_file_data::nsl_file_data(const nsl_file_data& a,int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_file_data();
	sval = a.get_value();
}

// nsl_file_data destructors

nsl_file_data::~nsl_file_data()
{
}

// init

int nsl_file_data::init_file_data()
{
	sval = NSL_CIN;
	return 1;
}

// nsl_file_data set values

file_enum nsl_file_data::set_value(const file_enum val)
{
	sval = val;
	return sval;
}

// nsl_file_data assignment

file_enum nsl_file_data::operator=(const nsl_file_data& a)
{
	sval = a.get_value();
	return sval;
}
file_enum nsl_file_data::operator=(const file_enum val)
{
	sval = val;
	return sval;
}

// print

int nsl_file_data::print_file_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_file_data::print_status(ostream& out) const
{
	print_file_data_status(out);
	return 1;
}
int nsl_file_data::print_file_data(ostream& out) const
{
	print_data_layer(out);
	out <<  sval << "\n";
	out.flush();
	return 1;
}
int nsl_file_data::print(ostream& out) const
{
	print_file_data(out);
	return 1;
}

int nsl_file_data::reset_file_data(nsl_buffer* buf)
{
	if (buf == NULL)
		sval = NSL_CIN;
//	else
//		*buf >> sval;

	return 1;
}
int nsl_file_data::reset(nsl_buffer* buf)
{
	reset_file_data(buf);
	return 1;
}

int nsl_file_data::write_file_data(nsl_buffer& buf)
{
	buf << sval;
	return 1;
}
int nsl_file_data::write(nsl_buffer& buf)
{
	write_file_data(buf);
	return 1;
}
int nsl_file_data::read_file_data(nsl_buffer& buf)
{
	nsl_string str;
	buf >> str;

	if (strcmp(str,"NSL_CIN") == 0)
		sval = NSL_CIN;
	else if (strcmp(str,"NSL_FIN") == 0)
		sval = NSL_FIN;
	else
		cmd_error("file_data:read: BAD string: ",str);

	return 1;
}
int nsl_file_data::read(nsl_buffer& buf)
{
	read_file_data(buf);
	return 1;
}


