/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_matrix.h
//

#ifndef _NSL_NUM_MATRIX_H
#define _NSL_NUM_MATRIX_H
#include "nsl_matrix_layer.h"

#ifndef _NSL_SET
class nsl_buffer;
class nsl_num_matrix;
class nsl_num_data;
class nsl_num_vector;
#endif

class nsl_num_matrix : public nsl_matrix_layer
{
protected:
	num_type** v; 
public:
		nsl_num_matrix(const int = 0,const int = 0,int=1);
		nsl_num_matrix(const char*,const int = 0,const int = 0,int=0,int=1);
		nsl_num_matrix(const nsl_num_matrix&,int=1);

		~nsl_num_matrix();

	int	init_num_matrix(const int = 0,const int = 0);
	int	alloc_mem(const int,const int);

// get value
	num_type**	get_matrix() const { return v; }

// element retrieval
	num_type&	elem(const int,const int);

	// set value
	num_type	set_value(const int,const int,const int);
	num_type	set_value(const int,const int,const float);
	num_type	set_value(const int,const int,const double);

// assignment
	num_type** 	operator=(const nsl_num_matrix&);
	num_type** 	operator=(const nsl_num_data&);
	num_type** 	operator=(const double);
	num_type** 	operator=(const float);
	num_type** 	operator=(const int);

        num_type        max();
        num_type        min();

        num_type        max(int*,int*); // return index
        num_type        min(int*,int*);

    	//***operators***/
    	//-bn7
    	num_type* operator[](unsigned int k) const
    	{
    		return v[k];
    	}

    	nsl_num_matrix operator*(const num_type af)
    	{
    		int aimax = get_imax();
    		int ajmax = get_jmax();

    		nsl_num_matrix c(aimax,ajmax,1);

    		for (int i = 0; i < aimax; i++)
    		   for (int j = 0; j < ajmax; j++)
    			c.v[i][j] = v[i][j] * af;

    		return c;
    	}


    	nsl_num_matrix operator+(const num_type af)
    	{
    		int aimax = get_imax();
    		int ajmax = get_jmax();

    		nsl_num_matrix c(aimax,ajmax,1);

    		for (int i = 0; i < aimax; i++)
    		   for (int j = 0; j < ajmax; j++)
    			c.v[i][j] = v[i][j] + af;

    		return c;
    	}


    	nsl_num_matrix operator+(const nsl_num_matrix& af)
    	{
    		int aimax = get_imax();
    		int ajmax = get_jmax();

    		nsl_num_matrix c(aimax,ajmax,1);

    		for (int i = 0; i < aimax; i++)
    		   for (int j = 0; j < ajmax; j++)
    			c.v[i][j] = v[i][j] + af.v[i][j];

    		return c;
    	}
    	//=========================


	// sum
	num_type	sum();

// also functions
	nsl_num_vector reduce_row();
	nsl_num_vector reduce_col();

	nsl_num_matrix 	get_sector(const int,const int,const int,
		const int) const;
	nsl_num_matrix 	set_sector(const nsl_num_matrix&,const int,const int);
	nsl_num_matrix 	put_sector(const nsl_num_matrix&,const int,const int);

	nsl_num_vector	get_row(const int) const;
	nsl_num_vector	get_col(const int) const;
	nsl_num_matrix	set_row(const nsl_num_vector&,const int);
	nsl_num_matrix	set_col(const nsl_num_vector&,const int);

// print
	virtual int	print(ostream&) const;
	int	print_num_matrix(ostream&) const;
	int	print_num_matrix(ostream&,const int,const int,const int,
		const int) const;
	virtual int	print_status(ostream&) const;
	int	print_num_matrix_status(ostream&) const;

	int 	reset_num_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

/* 3.0 version
class nsl_num_matrix : public nsl_matrix_layer
{
protected:
	num_type** v;
public:
		nsl_num_matrix(const int = 0,const int = 0,int=1);
		nsl_num_matrix(const char*,const int = 0,const int = 0,int=0,int=1);
		nsl_num_matrix(const nsl_num_matrix&,int=1);

		~nsl_num_matrix();

	int	init_num_matrix(const int = 0,const int = 0);
	int	alloc_mem(const int,const int);

// get value
	num_type**	get_matrix() const { return v; }

// element retrieval
	num_type&	elem(const int,const int);

	// set value
	num_type	set_value(const int,const int,const int);
	num_type	set_value(const int,const int,const float);
	num_type	set_value(const int,const int,const double);

// assignment
	num_type** 	operator=(const nsl_num_matrix&);
	num_type** 	operator=(const nsl_num_data&);
	num_type** 	operator=(const double);
	num_type** 	operator=(const float);
	num_type** 	operator=(const int);

        num_type        max();
        num_type        min();

        num_type        max(int*,int*); // return index
        num_type        min(int*,int*);


	// sum
	num_type	sum();

// also functions
	nsl_num_vector reduce_row();
	nsl_num_vector reduce_col();

	nsl_num_matrix 	get_sector(const int,const int,const int,
		const int) const;
	nsl_num_matrix 	set_sector(const nsl_num_matrix&,const int,const int);
	nsl_num_matrix 	put_sector(const nsl_num_matrix&,const int,const int);

	nsl_num_vector	get_row(const int) const;
	nsl_num_vector	get_col(const int) const;
	nsl_num_matrix	set_row(const nsl_num_vector&,const int);
	nsl_num_matrix	set_col(const nsl_num_vector&,const int);

// print
	virtual int	print(ostream&) const;
	int	print_num_matrix(ostream&) const;
	int	print_num_matrix(ostream&,const int,const int,const int,
		const int) const;
	virtual int	print_status(ostream&) const;
	int	print_num_matrix_status(ostream&) const;

	int 	reset_num_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

 * */
#endif
