/* SCCS  %W%---%E%--%U% */
//
//	nsl_row_col_data.C
//

#include "nsl_row_col_data.h"
#include "nsl_stream.h"

nsl_row_col_data::nsl_row_col_data(int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_row_col_data();
}
nsl_row_col_data::nsl_row_col_data(const char* str,nsl_model* m,int sfg,
	int fg,int rfg) : nsl_data_layer("row_col_data",str,(nsl_public*)m,sfg,fg,rfg)
{
	init_row_col_data();
}
nsl_row_col_data::nsl_row_col_data(const char* str,
	const row_col_enum val,nsl_model* m,int sfg,int fg,int rfg) : 
	nsl_data_layer("row_col_data",str,(nsl_public*)m,sfg,fg,rfg)
{
	init_row_col_data();
	sval = val;
}

nsl_row_col_data::nsl_row_col_data(const nsl_row_col_data& a,int sfg,int fg,
	int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_row_col_data();
	sval = a.get_value();
}

// nsl_row_col_data destructors

nsl_row_col_data::~nsl_row_col_data()
{
}

// init

int nsl_row_col_data::init_row_col_data()
{
	sval = NSL_ROW;
	return 1;
}

// nsl_row_col_data set values

row_col_enum nsl_row_col_data::set_value(const row_col_enum val)
{
	sval = val;
	return sval;
}

// nsl_row_col_data assignment

row_col_enum nsl_row_col_data::operator=(const nsl_row_col_data& a)
{
	sval = a.get_value();
	return sval;
}
row_col_enum nsl_row_col_data::operator=(const row_col_enum val)
{
	sval = val;
	return sval;
}

// print

int nsl_row_col_data::print_row_col_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_row_col_data::print_status(ostream& out) const
{
	print_row_col_data_status(out);
	return 1;
}
int nsl_row_col_data::print_row_col_data(ostream& out) const
{
	print_data_layer(out);
	out <<  sval << "\n";
	out.flush();
	return 1;
}
int nsl_row_col_data::print(ostream& out) const
{
	print_row_col_data(out);
	return 1;
}

int nsl_row_col_data::reset_row_col_data(nsl_buffer* buf)
{
	if (buf == NULL)
		sval = NSL_ROW;
//	else
//		*buf >> sval;

	return 1;
}
int nsl_row_col_data::reset(nsl_buffer* buf)
{
	reset_row_col_data(buf);
	return 1;
}

int nsl_row_col_data::write_row_col_data(nsl_buffer& buf)
{
	buf << sval;
	return 1;
}
int nsl_row_col_data::write(nsl_buffer& buf)
{
	write_row_col_data(buf);
	return 1;
}
int nsl_row_col_data::read_row_col_data(nsl_buffer& buf)
{
	nsl_string str;
	buf >> str;

	if (strcmp(str,"NSL_ROW") == 0)
		sval = NSL_ROW;
	else if (strcmp(str,"NSL_COL") == 0)
		sval = NSL_COL;
	else
		cmd_error("row_col_data:read: BAD string: ",str);

	return 1;
}
int nsl_row_col_data::read(nsl_buffer& buf)
{
	read_row_col_data(buf);
	return 1;
}


