/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_0.C
//

#include "nsl_num_0.h"
#include "nsl_buffer.h"
#include "nsl.h"
#include "nsl_stream.h"
#include "nsl_char_buf.h"

extern int TRACE_FG;
extern fstream* NSL_FILE;

extern int NSLoutput(const char *);
extern int NSLoutput(const char *, float);
extern int NSLoutput(int, std::ostream &);
extern int NSLoutput(const char *, std::ostream &);

nsl_num_0::nsl_num_0(const NslNumType val,int sfg,int fg,int rfg) :
	nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = val;
}
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const char* str,
	nsl_public* m,int sfg,int fg,int rfg) :
	nsl_data_layer("num_data",str,m,sfg,fg,rfg)
{
	init_num_data();
	v = 0;
}
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const char* str,
	const NslNumType val,nsl_public* m,int sfg,int fg,int rfg) :
	nsl_data_layer("num_data",str,m,sfg,fg,rfg)
{
	init_num_data();
	v = val;
}
/*
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const nsl_num_0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}
*/
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslFloat0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}

/*
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslDinFloat0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslDinDouble0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslDinInt0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}

//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslDoutFloat0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslDoutDouble0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}
//template<class NslNumType, int NslTypeId>
nsl_num_0::nsl_num_0(const NslDoutInt0& a,
	int sfg,int fg,int rfg) : nsl_data_layer(sfg,fg,rfg)
{
	init_num_data();
	v = a.get_value();
}
*/
//template<class NslNumType, int NslTypeId>
nsl_num_0::~nsl_num_0(void)
{
}

//template<class NslNumType, int NslTypeId>
void nsl_num_0::initialize(const char* str,
	nsl_public* m,int sfg,int fg,int rfg)
{
	nsl_data_layer::initialize("num_data",str,m,sfg,fg,rfg);
	init_num_data();
	v = 0;
}

// init

//template<class NslNumType, int NslTypeId>
int nsl_num_0::init_num_data()
{
	//set_type_id(NslTypeId);

	v = 0;
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::memAlloc()
{
	v = 0;
	return 1;
}

// nsl_num_0 set values
//template<class NslNumType, int NslTypeId>
void nsl_num_0::set_value(float val)
{
	v = (NslNumType) val;
}
//template<class NslNumType, int NslTypeId>
void nsl_num_0::set_value(double val)
{
	v = (NslNumType) val;
}
//template<class NslNumType, int NslTypeId>
void nsl_num_0::set_value(int val)
{
	v = (NslNumType) val;
}

// nsl_num_0 addition

//template<class NslNumType, int NslTypeId>
nsl_num_0 nsl_num_0::operator+() const
{
	nsl_num_0 c;
	c = get_data();
	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_0 nsl_num_0::operator+(const
	nsl_num_0& b) const
{
	nsl_num_0 c;
	c = get_data() + b.get_data();
	return c;
}
//template<class NslNumType, int NslTypeId>
nsl_num_0 nsl_num_0::operator+(const
	NslNumType b) const
{
	nsl_num_0 c;
	c = get_data() + b;
	return c;
}

// nsl_num_0 assignment

//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_0::operator=(const NslFloat0& a)
{
	v = (NslNumType) a.get_value();

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return v;
}

//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_0::operator=(const float a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return v;
}
//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_0::operator=(const double a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return v;
}
//template<class NslNumType, int NslTypeId>
NslNumType nsl_num_0::operator=(const int a)
{
	v = (NslNumType) a;

	if (TRACE_FG == 1 && NSL_FILE != NULL && m_parent != NULL && (nsl_system*)m_parent != SYSTEM)
	{
		m_parent->print(*NSL_FILE);
		print(*NSL_FILE);
	}

	return v;
}
// print

//template<class NslNumType, int NslTypeId>
int nsl_num_0::print_num_data_status() const
{
	print_data_layer_status();
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::nslStatus() const
{
	print_num_data_status();
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::print_num_data() const
{
	if (sub_layer_fg == 0)
		print_data_layer();

	NSLoutput("\t",v);
	NSLoutput(" ");

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::nslPrint() const
{
	print_num_data();
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::print_num_data_status(ostream& out) const
{
	print_data_layer_status(out);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::print_status(ostream& out) const
{
	print_num_data_status(out);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::print_num_data(ostream& out) const
{
	if (sub_layer_fg == 0)
		print_data_layer(out);

	NSLoutput(v,out);
	NSLoutput(" ",out);

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::print(ostream& out) const
{
	print_num_data(out);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::reset_num_data(nsl_buffer* buf)
{
	if (buf == NULL)
		v = 0;
	else
		*buf >> v;

	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::reset(nsl_buffer* buf)
{
	reset_num_data(buf);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::write_num_data(nsl_buffer& buf)
{
	buf << (NslNumType) v;
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::write(nsl_buffer& buf)
{
	write_num_data(buf);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::read_num_data(nsl_buffer& buf)
{
	buf >> v;
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::read(nsl_buffer& buf)
{
	read_num_data(buf);
	return 1;
}

//template<class NslNumType, int NslTypeId>
int nsl_num_0::write_num_data(nsl_char_buf& buf)
{
	sprintf(buf.get_sbuf(),"%f", v);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::write(nsl_char_buf& buf)
{
	write_num_data(buf);
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::read_num_data(nsl_char_buf& buf)
{
	//buf >> v;
	return 1;
}
//template<class NslNumType, int NslTypeId>
int nsl_num_0::read(nsl_char_buf& buf)
{
	read_num_data(buf);
	return 1;
}

