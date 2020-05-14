/* SCCS  %W%---%E%--%U% */
//
//	nsl_ptr_matrix.h
//

#ifndef _NSL_PTR_MATRIX_H
#define _NSL_PTR_MATRIX_H
#include "nsl_matrix_layer.h"
class nsl_ptr_matrix : public nsl_matrix_layer
{
protected:
	nsl_base*** v; 
public:
		nsl_ptr_matrix(const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_ptr_matrix(const char*,nsl_model* = 0,
			const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_ptr_matrix(const nsl_ptr_matrix&,int=0,int=0,int=1);

		~nsl_ptr_matrix();

	int	init_ptr_matrix(const int = 0,const int = 0);
	int	alloc_mem(const int,const int);

// get value
	nsl_base***	get_matrix() const { return v; }

// element retrieval
	nsl_base*&	elem(const int,const int);

	// set value
	nsl_base*	set_value(const int,const int,nsl_base*);

// assignment
	nsl_base*** 	operator=(const nsl_ptr_matrix&);
	nsl_base*** 	operator=(const nsl_ptr_data&);
	nsl_base*** 	operator=(nsl_base*);

	nsl_ptr_matrix 	get_sector(const int,const int,const int,
		const int) const;
	nsl_ptr_matrix 	set_sector(const nsl_ptr_matrix&,const int,const int);
	nsl_ptr_matrix 	put_sector(const nsl_ptr_matrix&,const int,const int);

	nsl_ptr_vector	get_row(const int) const;
	nsl_ptr_vector	get_col(const int) const;
	nsl_ptr_matrix	set_row(const nsl_ptr_vector&,const int);
	nsl_ptr_matrix	set_col(const nsl_ptr_vector&,const int);

// print
	virtual int	print(ostream&) const;
	int	print_ptr_matrix(ostream&) const;
	int	print_ptr_matrix(ostream&,const int,const int,const int,
		const int) const;
	virtual int	print_status(ostream&) const;
	int	print_ptr_matrix_status(ostream&) const;

	int 	reset_ptr_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_ptr_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_ptr_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
