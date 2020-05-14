/* SCCS  %W%---%E%--%U% */
//
//	nsl_int_data.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//#include "../../incl/nsl_kernel_include.h"
#include "nsl_kernel.h"
#include "nsl_int_data.h"
#include "nsl_buffer.h"
#include "nsl_stream.h"

nsl_int_data::nsl_int_data(const int val,int rfg) : nsl_data_layer(rfg)
{
	init_int_data();
	v = val;
}
nsl_int_data::nsl_int_data(const char* str,const int val,int fg,int rfg) : 
	nsl_data_layer("int_data",str,fg,rfg)
{
	init_int_data();
	v = val;
}

nsl_int_data::nsl_int_data(const nsl_int_data& a,int rfg) : nsl_data_layer(rfg)
{
	init_int_data();
	v = a.get_value();
}

// nsl_int_data destructors

nsl_int_data::~nsl_int_data()
{
}

// init

int nsl_int_data::init_int_data()
{
	v = 0;
	return 1;
}

// nsl_int_data set values

int nsl_int_data::set_value(const double val)
{
	return v = (int) val;
}
int nsl_int_data::set_value(const float val)
{
	return v = (int) val;
}
int nsl_int_data::set_value(const int val)
{
	return v = (int) val;
}

// nsl_int_data assignment

int nsl_int_data::operator=(const nsl_int_data& a)
{
	return v = (int) a.get_value();
}
int nsl_int_data::operator=(const double a)
{
	return v = (int) a;
}
int nsl_int_data::operator=(const float a)
{
	return v = (int) a;
}
int  nsl_int_data::operator=(const int a)
{
	return v = (int) a;
}

// print

int nsl_int_data::print_int_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_int_data::print_status(ostream& out) const
{
	print_int_data_status(out);
	return 1;
}
int nsl_int_data::print_int_data(ostream& out) const
{
	print_data_layer(out);
	out <<  v << "\n";
	out.flush();
	return 1;
}
int nsl_int_data::print(ostream& out) const
{
	print_int_data(out);
	return 1;
}

int nsl_int_data::reset_int_data(nsl_buffer* buf)
{
	if (buf == NULL)
		v = 0;
	else
		*buf >> v;

	return 1;
}
int nsl_int_data::reset(nsl_buffer* buf)
{
	reset_int_data(buf);
	return 1;
}

int nsl_int_data::write_int_data(nsl_buffer& buf)
{
	buf << v;
	return 1;
}
int nsl_int_data::write(nsl_buffer& buf)
{
	write_int_data(buf);
	return 1;
}
int nsl_int_data::read_int_data(nsl_buffer& buf)
{
	buf >> v;
	return 1;
}
int nsl_int_data::read(nsl_buffer& buf)
{
	read_int_data(buf);
	return 1;
}



