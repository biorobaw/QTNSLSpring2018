/* SCCS  @(#)nsl_ptr_data.C	1.2---95/08/13--18:20:46 */
//
//	nsl_ptr_data.C
//

#include "nsl_ptr_data.h"
#include "nsl_base.h"
#include "nsl_buffer.h"

nsl_ptr_data::nsl_ptr_data(int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_ptr_data();
}
nsl_ptr_data::nsl_ptr_data(const char* str,
	nsl_base* val,nsl_model* m,int sfg,int fg,int rfg) :
	nsl_data_layer("ptr_data",str,(nsl_public*)m,sfg,fg,rfg)
{
	init_ptr_data();
	ptr = val;
}
nsl_ptr_data::nsl_ptr_data(const nsl_ptr_data& a,int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_ptr_data();
	ptr = a.get_value();
}

// nsl_ptr_data destructors

nsl_ptr_data::~nsl_ptr_data()
{
}

// init

int nsl_ptr_data::init_ptr_data()
{
	ptr = 0;
	return 1;
}

// nsl_ptr_data set values

nsl_base* nsl_ptr_data::set_value(nsl_base* val)
{
	return ptr = val;
}

// nsl_ptr_data assignment

nsl_base* nsl_ptr_data::operator=(const nsl_ptr_data& a)
{
	return ptr = a.get_value();
}
nsl_base* nsl_ptr_data::operator=(nsl_base* val)
{
	return ptr = val;
}

// print

int nsl_ptr_data::print_ptr_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_ptr_data::print_status(ostream& out) const
{
	print_ptr_data_status(out);
	return 1;
}
int nsl_ptr_data::print_ptr_data(ostream& out) const
{
	print_data_layer(out);
	return 1;
}
int nsl_ptr_data::print(ostream& out) const
{
	print_ptr_data(out);
	return 1;
}

int nsl_ptr_data::reset_ptr_data(nsl_buffer* buf)
{
	if (buf == NULL)
		ptr = 0;
	else
		ptr->read(*buf);

	return 1;
}
int nsl_ptr_data::reset(nsl_buffer* buf)
{
	reset_ptr_data(buf);
	return 1;
}

int nsl_ptr_data::write_ptr_data(nsl_buffer& buf)
{
	if (ptr != NULL)
		ptr->write(buf);
	else
		cmd_error("ptr_data: NULL ptr");

	return 1;
}
int nsl_ptr_data::write(nsl_buffer& buf)
{
	write_ptr_data(buf);
	return 1;
}
int nsl_ptr_data::read_ptr_data(nsl_buffer& buf)
{
	if (ptr != NULL)
		ptr->read(buf);
	else
		cmd_error("ptr_data: NULL ptr");

	return 1;
}
int nsl_ptr_data::read(nsl_buffer& buf)
{
	read_ptr_data(buf);
	return 1;
}



