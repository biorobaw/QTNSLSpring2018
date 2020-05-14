/* SCCS  @(#)nsl_int_matrix.h	1.1---95/08/13--23:37:15 */
//
//	nsl_int_matrix.h
//

#ifndef _NSL_INT_MATRIX_H
#define _NSL_INT_MATRIX_H
#include "nsl_matrix_layer.h"
class nsl_int_vector;
class nsl_int_matrix;

class nsl_int_matrix : public nsl_matrix_layer
{
protected:
	int** v; 
public:
		nsl_int_matrix(const int = 0,const int = 0,int=1);
		nsl_int_matrix(const char*,const int = 0,const int = 0,int=0,int=1);
		nsl_int_matrix(const nsl_int_matrix&,int=1);

		~nsl_int_matrix();

	int	init_int_matrix(const int = 0,const int = 0);
	int	alloc_mem(const int,const int);

// get value
	int**	get_matrix() const { return v; }

// element retrieval
	int&	elem(const int,const int);

	// set value
	int	set_value(const int,const int,const int);
	int	set_value(const int,const int,const float);
	int	set_value(const int,const int,const double);

// assignment
	int** 	operator=(const nsl_int_matrix&);
	int** 	operator=(const nsl_int_data&);
	int** 	operator=(const double);
	int** 	operator=(const float);
	int** 	operator=(const int);

        int        max();
        int        min();

        int        max(int*,int*); // return index
        int        min(int*,int*);


	// sum
	int	sum();

// also functions
	nsl_int_vector reduce_row();
	nsl_int_vector reduce_col();

	nsl_int_matrix 	get_sector(const int,const int,const int,
		const int) const;
	nsl_int_matrix 	set_sector(const nsl_int_matrix&,const int,const int);
	nsl_int_matrix 	put_sector(const nsl_int_matrix&,const int,const int);

	nsl_int_vector	get_row(const int) const;
	nsl_int_vector	get_col(const int) const;
	nsl_int_matrix	set_row(const nsl_int_vector&,const int);
	nsl_int_matrix	set_col(const nsl_int_vector&,const int);

// print
	virtual int	print(std::ostream&) const;
	int	print_int_matrix(std::ostream&) const;
	int	print_int_matrix(std::ostream&,
			const int,const int,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_int_matrix_status(std::ostream&) const;

	int 	reset_int_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_int_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_int_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
