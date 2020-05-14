/* SCCS  %W%---%E%--%U% */
//
//	nsl_ptr_vector.h
//

#ifndef _NSL_PTR_VECTOR_H
#define _NSL_PTR_VECTOR_H
#include "nsl_vector_layer.h"
class nsl_ptr_vector : public nsl_vector_layer
{
protected:
	nsl_base** v; 
public:
		nsl_ptr_vector(const int = 0,int=0,int=0,int=1);
		nsl_ptr_vector(const char*,nsl_model* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=0,int=1);
		nsl_ptr_vector(const nsl_ptr_vector&,int=0,int=0,int=1);

		~nsl_ptr_vector();

	int	init_ptr_vector();
	int	init_ptr_vector(const int);
	int	alloc_mem(const int);

// get value
	nsl_base**	get_vector() const { return v; }

// element retrieval
	nsl_base*&	operator[](const int);
	nsl_base*&	elem(const int);

	// set value
	nsl_base*	set_value(const int,nsl_base*);

// assignment
	nsl_base** 	operator=(const nsl_ptr_vector&);
	nsl_base** 	operator=(const nsl_ptr_data&);

// also functions
	nsl_ptr_matrix expand_col(const int);
	nsl_ptr_matrix expand_row(const int);
	nsl_ptr_matrix expand(const int);

	nsl_ptr_vector transpose_col();
	nsl_ptr_vector transpose_row();
	nsl_ptr_vector transpose();

	// sector
	nsl_ptr_vector 	get_sector(const int,const int) const; 
	nsl_ptr_vector 	set_sector(const nsl_ptr_vector&,const int);
	nsl_ptr_vector 	put_sector(const nsl_ptr_vector&,const int); 

// print
	virtual int	print(ostream&) const;
	int	print_ptr_vector(ostream&) const;
	int	print_ptr_vector(ostream&,const int, const int) const;
	virtual int	print_status(ostream&) const;
	int	print_ptr_vector_status(ostream&) const;

	int 	reset_ptr_vector(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_ptr_vector(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_ptr_vector(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
