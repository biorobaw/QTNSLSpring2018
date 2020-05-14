/* SCCS  %W%---%E%--%U% */
//
//	nsl_str_data.C
//
#include "nsl_str_data.h"
#include "nsl_kernel.h"
#include "nsl_stream.h"

nsl_str_data::nsl_str_data(int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg) 
{
	init_str_data();
}
nsl_str_data::nsl_str_data(const char* str,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_data_layer("str_data",str,m,sfg,fg,rfg)
{
	init_str_data();
}
nsl_str_data::nsl_str_data(const char* str,
	const char* val,nsl_public* m,int sfg,int fg,int rfg) :
	nsl_data_layer("str_data",str,m,sfg,fg,rfg)
{
	init_str_data();
	if (val != NULL)
		strcpy(sval,val);
}

nsl_str_data::nsl_str_data(const nsl_str_data& a,int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_str_data();
	strcpy(sval,a.get_value());
}

nsl_str_data::nsl_str_data(const char* a,int sfg,int fg,int rfg) :
	nsl_data_layer(sfg,fg,rfg)
{
	init_str_data();
	strcpy(sval,a);
}

// nsl_str_data destructors

nsl_str_data::~nsl_str_data()
{
}

// init

int nsl_str_data::init_str_data()
{
	strcpy(sval,"");
	return 1;
}

void nsl_str_data::initialize(const char* str,
	nsl_public* m,int sfg,int fg,int rfg)
{
	nsl_data_layer::initialize("str_data",str,m,sfg,fg,rfg);
	init_str_data();
}

// nsl_str_data set values

char* nsl_str_data::set_value(const char* val)
{
	strcpy(sval,val);
	return sval;
}

char nsl_str_data::operator[](const int i)
{
	if (i <= strlen(sval))
		return sval[i];
	else
		return 0;
}


// nsl_str_data assignment

char* nsl_str_data::operator=(const nsl_str_data& a)
{
	strcpy(sval,a.get_value());
	return sval;
}
char* nsl_str_data::operator=(const char* val)
{
	strcpy(sval,val);
	return sval;
}

// print

int nsl_str_data::print_str_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_str_data::print_status(ostream& out) const
{
	print_str_data_status(out);
	return 1;
}
int nsl_str_data::print_str_data(ostream& out) const
{
	print_data_layer(out);
	out <<  sval << "\n";
	out.flush();
	return 1;
}
int nsl_str_data::print(ostream& out) const
{
	print_str_data(out);
	return 1;
}

int nsl_str_data::reset_str_data(nsl_buffer* buf)
{
	if (buf == NULL)
		strcpy(sval,"");
	else
		*buf >> sval;

	return 1;
}
int nsl_str_data::reset(nsl_buffer* buf)
{
	reset_str_data(buf);
	return 1;
}

int nsl_str_data::write_str_data(nsl_buffer& buf)
{
	buf << sval;
	return 1;
}
int nsl_str_data::write(nsl_buffer& buf)
{
	write_str_data(buf);
	return 1;
}
int nsl_str_data::read_str_data(nsl_buffer& buf)
{
	buf >> sval;
	return 1;
}
int nsl_str_data::read(nsl_buffer& buf)
{
	read_str_data(buf);
	return 1;
}


