/* SCCS  %W%---%E%--%U% */
//
//	nsl_str_data.h
//

#ifndef _NSL_STR_DATA_H
#define _NSL_STR_DATA_H
#include "nsl_data_layer.h"
class nsl_str_data : public nsl_data_layer
{
protected:
	nsl_string sval;
public:
		nsl_str_data(int=0,int=1,int=1);
		nsl_str_data(const char*,nsl_public*,int=0,int=1,int=1); // nsl_public* = 0
		nsl_str_data(const char*,const char*,nsl_public* = 0,
			int=0,int=1,int=1);
		nsl_str_data(const nsl_str_data&,int=0,int=1,int=1);
		nsl_str_data(const char*,int=0,int=1,int=1);

		~nsl_str_data();

	int	init_str_data();

	void initialize(const char*, nsl_public* = 0,int=0,int=1,int=1);

// get value
	const char* get_data() const { return sval; }
	const char* get_value() const { return sval; }
	char* elem() 	{ return sval; }

// set value
	char*	set_value(const char*);

	int get_size() 	{ return strlen(sval); }

	char 	operator[](const int);

	// assignment
	char* 	operator=(const nsl_str_data&);
	char*	operator=(const char*);

// I/O
	virtual int	print(std::ostream&) const;
	int	print_str_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_str_data_status(std::ostream&) const;

	int 	reset_str_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_str_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_str_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
