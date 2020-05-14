/* SCCS  @(#)nsl_dump_data.C	1.2---97/02/25--19:15:30 */
//
//	nsl_dump_data.C
//
#include "nsl_dump_data.h"
#include "nsl_model.h"
#include "nsl_buffer.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"

/* SCCS  @(#)nsl_dump_data.C	1.2---97/02/25--19:15:30 */
//
//	nsl_dump_data.C
//

# include "nsl_all_kernel_include.h"

nsl_dump_data::nsl_dump_data(int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_dump_data();
}
nsl_dump_data::nsl_dump_data(const char* str,nsl_public* m,
	int sfg,int fg,int rfg) : nsl_data_layer("dump_data",str,m,sfg,fg,rfg)
{
	init_dump_data();
}
nsl_dump_data::nsl_dump_data(const char* str,const dump_enum val,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_data_layer("dump_data",str,m,sfg,fg,rfg)
{
	init_dump_data();
	sval = val;
}

nsl_dump_data::nsl_dump_data(const nsl_dump_data& a,int sfg,int fg,int rfg) : 
	nsl_data_layer(sfg,fg,rfg)
{
	init_dump_data();
	sval = a.get_value();
}

// nsl_dump_data destructors

nsl_dump_data::~nsl_dump_data()
{
}

// init

int nsl_dump_data::init_dump_data()
{
	sval = NSL_COUT;
	return 1;
}

// nsl_dump_data set values

dump_enum nsl_dump_data::set_value(const dump_enum val)
{
	sval = val;
	return sval;
}

// nsl_dump_data assignment

dump_enum nsl_dump_data::operator=(const nsl_dump_data& a)
{
	sval = a.get_value();
	return sval;
}
dump_enum nsl_dump_data::operator=(const dump_enum val)
{
	sval = val;
	return sval;
}

// print

int nsl_dump_data::print_dump_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
int nsl_dump_data::print_status(ostream& out) const
{
	print_dump_data_status(out);
	return 1;
}
int nsl_dump_data::print_dump_data(ostream& out) const
{
	print_data_layer(out);
	out <<  sval << "\n";
	out.flush();
	return 1;
}
int nsl_dump_data::print(ostream& out) const
{
	print_dump_data(out);
	return 1;
}

int nsl_dump_data::reset_dump_data(nsl_buffer* buf)
{
	if (buf == NULL)
		sval = NSL_COUT;
//	else
//		*buf >> sval;

	return 1;
}
int nsl_dump_data::reset(nsl_buffer* buf)
{
	reset_dump_data(buf);
	return 1;
}

int nsl_dump_data::write_dump_data(nsl_buffer& buf)
{
	buf << sval;
	return 1;
}
int nsl_dump_data::write(nsl_buffer& buf)
{
	write_dump_data(buf);
	return 1;
}
int nsl_dump_data::read_dump_data(nsl_buffer& buf)
{
	nsl_string str;
	buf >> str;

	if (strcmp(str,"NSL_LP") == 0)
		sval = NSL_LP;
	else if (strcmp(str,"NSL_COUT") == 0)
		sval = NSL_COUT;
	else if (strcmp(str,"NSL_FOUT") == 0)
		sval = NSL_FOUT;
	else
		cmd_error("dump_data:read: BAD string: ",str);

	return 1;
}
int nsl_dump_data::read(nsl_buffer& buf)
{
	read_dump_data(buf);
	return 1;
}





