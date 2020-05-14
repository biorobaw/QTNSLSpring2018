/* SCCS  @(#)nsl_num_vector.h	1.1---95/08/13--23:37:20 */
//
//	nsl_num_vector.h
//

#ifndef _NSL_NUM_VECTOR_H
#define _NSL_NUM_VECTOR_H
#include "nsl_num_data.h"
#include "nsl_vector_layer.h"
class nsl_num_matrix;
class nsl_num_1;
class nsl_num_vector : public nsl_vector_layer
{
protected:
	num_type* v; 
public:
		nsl_num_vector(const int = 0,int=1);
		nsl_num_vector(const char*,const int = 0, row_col_enum = NSL_ROW,int=0,int=1);
		nsl_num_vector(const nsl_num_vector&,int=1);
		nsl_num_vector(const nsl_num_1&a);

		~nsl_num_vector();

	int	init_num_vector(const int = 0);
	int	alloc_mem(const int);

// get value
	num_type*	get_vector() const { return v; }

// element retrieval
	num_type&	operator[](const int) const;
	num_type&	elem(const int);

	// set value
	num_type	set_value(const int,const int);
	num_type	set_value(const int,const float);
	num_type	set_value(const int,const double);

	//!!added conversion operator -bn7
	num_type *operator=(const nsl_num_1&);


// assignment
	num_type* 	operator=(const nsl_num_vector&);
	num_type* 	operator=(const nsl_num_data&);
	num_type* 	operator=(const double);
	num_type* 	operator=(const float);
	num_type* 	operator=(const int);

        num_type        max();
        num_type        min();

        num_type        max(int*); // return index
        num_type        min(int*);

     //********!!operators -bn7*/
     nsl_num_vector operator*(float b) const
     {
    		int aimax = get_imax();

    		nsl_num_vector c(aimax,1);

    		for (int i = 0; i < aimax; i++)
    			c.v[i] = v[i] * b;

    		return c;
     }

     nsl_num_vector operator+(nsl_num_vector &b)
     {
 		int aimax = get_imax();

 		nsl_num_vector c(aimax,1);

 		for (int i = 0; i < aimax; i++)
 			c.v[i] = v[i] + b.v[i];

 		return c;
     }
     //-=------------------------------

	// sum
	num_type	sum();

// also functions
	nsl_num_matrix expand_col(const int);
	nsl_num_matrix expand_row(const int);
	nsl_num_matrix expand(const int);

	nsl_num_vector transpose_col();
	nsl_num_vector transpose_row();
	nsl_num_vector transpose();

	// sector
	nsl_num_vector 	get_sector(const int,const int) const;
	nsl_num_vector 	set_sector(const nsl_num_vector&,const int);
	nsl_num_vector 	put_sector(const nsl_num_vector&,const int); 

// print
	virtual int	print(std::ostream&) const;
	int	print_num_vector(std::ostream&) const;
	int	print_num_vector(std::ostream&,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_num_vector_status(std::ostream&) const;

	int 	reset_num_vector(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_vector(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_vector(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
/* 3.0 version
class nsl_num_vector : public nsl_vector_layer
{
protected:
	num_type* v;
public:
		nsl_num_vector(const int = 0,int=1);
		nsl_num_vector(const char*,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=1);
		nsl_num_vector(const nsl_num_vector&,int=1);

		~nsl_num_vector();

	int	init_num_vector(const int = 0);
	int	alloc_mem(const int);

// get value
	num_type*	get_vector() const { return v; }

// element retrieval
	num_type&	operator[](const int);
	num_type&	elem(const int);

	// set value
	num_type	set_value(const int,const int);
	num_type	set_value(const int,const float);
	num_type	set_value(const int,const double);

// assignment
	num_type* 	operator=(const nsl_num_vector&);
	num_type* 	operator=(const nsl_num_data&);
	num_type* 	operator=(const double);
	num_type* 	operator=(const float);
	num_type* 	operator=(const int);

        num_type        max();
        num_type        min();

        num_type        max(int*); // return index
        num_type        min(int*);

	// sum
	num_type	sum();

// also functions
	nsl_num_matrix expand_col(const int);
	nsl_num_matrix expand_row(const int);
	nsl_num_matrix expand(const int);

	nsl_num_vector transpose_col();
	nsl_num_vector transpose_row();
	nsl_num_vector transpose();

	// sector
	nsl_num_vector 	get_sector(const int,const int) const;
	nsl_num_vector 	set_sector(const nsl_num_vector&,const int);
	nsl_num_vector 	put_sector(const nsl_num_vector&,const int);

// print
	virtual int	print(ostream&) const;
	int	print_num_vector(ostream&) const;
	int	print_num_vector(ostream&,const int,const int) const;
	virtual int	print_status(ostream&) const;
	int	print_num_vector_status(ostream&) const;

	int 	reset_num_vector(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_vector(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_vector(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
}; */
#endif
