/* SCCS  %W%---%E%--%U% */
//
//	nsl_str_matrix.h
//

#ifndef _NSL_STR_MATRIX_H
#define _NSL_STR_MATRIX_H
#include "nsl_matrix_layer.h"
class nsl_str_matrix : public nsl_matrix_layer
{
protected:
	char*** v; 
public:
		nsl_str_matrix(const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_str_matrix(const char*,nsl_model* = 0,
			const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_str_matrix(const nsl_str_matrix&,int=0,int=0,int=1);

		~nsl_str_matrix();

	int	init_str_matrix(const int = 0,const int = 0);
	int	alloc_mem(const int,const int);

// get value
	char***	get_matrix() const { return v; }

// element retrieval
	char***&	elem(const int,const int);

	// set value
	char***	set_value(const int,const int,char*);

// assignment
	char*** 	operator=(const nsl_str_matrix&);
	char*** 	operator=(const nsl_str_data&);
	char*** 	operator=(const char*);

	nsl_str_matrix 	get_sector(const int,const int,const int,
		const int) const;
	nsl_str_matrix 	set_sector(const nsl_str_matrix&,const int,const int);
	nsl_str_matrix 	put_sector(const nsl_str_matrix&,const int,const int);

	nsl_str_vector	get_row(const int) const;
	nsl_str_vector	get_col(const int) const;
	nsl_str_matrix	set_row(const nsl_str_vector&,const int);
	nsl_str_matrix	set_col(const nsl_str_vector&,const int);

// print
	virtual int	print(std::ostream&) const;
	int	print_str_matrix(std::ostream&) const;
	int	print_str_matrix(std::ostream&,const int,const int,const int,
		const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_str_matrix_status(std::ostream&) const;

	int 	reset_str_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_str_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_str_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
