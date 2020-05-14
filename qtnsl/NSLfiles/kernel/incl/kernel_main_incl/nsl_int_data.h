/* SCCS  %W%---%E%--%U% */
//
//	nsl_int_data.h
//
#include "nsl_data_layer.h"

#ifndef _NSL_INT_DATA_H
#define _NSL_INT_DATA_H
class nsl_int_data : public nsl_data_layer
{
protected:
	int v;
public:
		nsl_int_data(const int=0,int=1);			
		nsl_int_data(const char*,const int=0,int=0,int=1); 
		nsl_int_data(const nsl_int_data&,int=1);

		~nsl_int_data();

	int	init_int_data();

// get value
	int get_data()  const { return v; }
	int get_value() const { return v; }
	int& elem() 	{ return v; }

// set value
	int	set_value(const int);
	int	set_value(const float);
	int	set_value(const double);
// assignment
	int 	operator=(const nsl_int_data&);
	int 	operator=(const int);
	int 	operator=(const float);
	int 	operator=(const double);

// print
	virtual int	print(std::ostream&) const;
	int	print_int_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_int_data_status(std::ostream&) const;

	int 	reset_int_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_int_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_int_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

//typedef nsl_int_data nsl_integer_data; //added typedef to resolve nsl_int_data constructor calls -bn7
#endif
