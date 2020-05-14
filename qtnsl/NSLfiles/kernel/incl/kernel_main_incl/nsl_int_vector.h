/* SCCS  @(#)nsl_int_vector.h	1.1---95/08/13--23:37:15 */
//
//	nsl_int_vector.h
//


#ifndef _NSL_INT_VECTOR_H
#define _NSL_INT_VECTOR_H
#include <iostream>
#include "nsl_vector_layer.h"

#ifndef _NSL_SET
class nsl_buffer;
class nsl_int_data;
class nsl_int_matrix;
#endif

class nsl_int_vector : public nsl_vector_layer
{
protected:
	int* v; 
public:
		nsl_int_vector(const int = 0,int=1);
		nsl_int_vector(const char*,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=1);
		nsl_int_vector(const nsl_int_vector&,int=1);

		~nsl_int_vector();

	int	init_int_vector();
	int	init_int_vector(const int);
	int	alloc_mem(const int);

// get value
	int*	get_vector() const { return v; }

// element retrieval
	int&	operator[](const int);
	int&	elem(const int);

	// set value
	int	set_value(const int,const int);
	int	set_value(const int,const float);
	int	set_value(const int,const double);

// assignment
	int* 	operator=(const nsl_int_vector&);
	int* 	operator=(const nsl_int_data&);
	int* 	operator=(const double);
	int* 	operator=(const float);
	int* 	operator=(const int);

        int        max();
        int        min();

        int        max(int*); // return index
        int        min(int*);

	// sum
	int	sum();

// also functions
	nsl_int_matrix expand_col(const int);
	nsl_int_matrix expand_row(const int);
	nsl_int_matrix expand(const int);

	nsl_int_vector transpose_col();
	nsl_int_vector transpose_row();
	nsl_int_vector transpose();

	// sector
	nsl_int_vector 	get_sector(const int,const int) const;
	nsl_int_vector 	set_sector(const nsl_int_vector&,const int);
	// same as set_sector
	nsl_int_vector 	put_sector(const nsl_int_vector&,const int); 

// print
	virtual int	print(std::ostream&) const;
	int	print_int_vector(std::ostream&) const;
	int	print_int_vector(std::ostream&,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_int_vector_status(std::ostream&) const;

	int 	reset_int_vector(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_int_vector(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_int_vector(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
