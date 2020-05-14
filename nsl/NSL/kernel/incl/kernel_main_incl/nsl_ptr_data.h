/* SCCS  %W%---%E%--%U% */
//
//	nsl_ptr_data.h
//

#ifndef _NSL_PTR_DATA_H
#define _NSL_PTR_DATA_H
#include "nsl_data_layer.h"
class nsl_ptr_data : public nsl_data_layer
{
protected:
	nsl_base* ptr;
public:
		nsl_ptr_data(int=0,int=0,int = 1);
		nsl_ptr_data(const char*,
			nsl_base* = 0,nsl_model* = 0,int=0,int=0,int = 1); 
		nsl_ptr_data(const nsl_ptr_data&,int=0,int=0,int =1);

		~nsl_ptr_data();

	int	init_ptr_data();

// get value
	nsl_base* get_data()  const { return ptr; }
	nsl_base* get_value() const { return ptr; }
	nsl_base*& elem() 	 { return ptr; }

// set value
	nsl_base*	set_value(nsl_base*);

// assignment
	nsl_base* 	operator=(const nsl_ptr_data&);
	nsl_base*	operator=(nsl_base*);

// I/O
	virtual int	print(std::ostream&) const;
	int	print_ptr_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_ptr_data_status(std::ostream&) const;

	int 	reset_ptr_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_ptr_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_ptr_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
