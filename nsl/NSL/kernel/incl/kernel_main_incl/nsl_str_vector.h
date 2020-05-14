/* SCCS  @(#)nsl_str_vector.h	1.1---95/08/13--23:37:22 */
//
//	nsl_str_vector.h
//

#ifndef _NSL_STR_VECTOR_H
#define _NSL_STR_VECTOR_H
#include "nsl_vector_layer.h"
class nsl_str_vector : public nsl_vector_layer
{
protected:
	char** v; 
public:
		nsl_str_vector(const int = 0,int=0,int=0,int=1);
		nsl_str_vector(const char*,nsl_model* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=0,int=1);
		nsl_str_vector(const nsl_str_vector&,int=0,int=0,int=1);

		~nsl_str_vector();

	int	init_str_vector(const int = 0);
	int	alloc_mem(const int);

// get value
	char**	get_vector() const { return v; }

// element retrieval
	char*&	operator[](const int);
	char*&	elem(const int);

	// set value
	char*	set_value(const int,char*);

// assignment
	char** 	operator=(const nsl_str_vector&);
	char** 	operator=(const nsl_str_data&);
	char** 	operator=(const char*);

// also functions
	nsl_str_matrix expand_col(const int);
	nsl_str_matrix expand_row(const int);
	nsl_str_matrix expand(const int);

	nsl_str_vector transpose_col();
	nsl_str_vector transpose_row();
	nsl_str_vector transpose();

	// sector
	nsl_str_vector 	get_sector(const int,const int) const;
	nsl_str_vector 	set_sector(const nsl_str_vector&,const int);
	nsl_str_vector 	put_sector(const nsl_str_vector&,const int); 

// print
	virtual int	print(std::ostream&) const;
	int	print_str_vector(std::ostream&) const;
	int	print_str_vector(std::ostream&,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_str_vector_status(std::ostream&) const;

	int 	reset_str_vector(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_str_vector(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_str_vector(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
