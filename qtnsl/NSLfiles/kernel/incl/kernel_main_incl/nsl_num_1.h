/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_1.h
//

//template<class NslNumType>
#ifndef _NSL_NUM_1_H
#define _NSL_NUM_1_H
#include "nsl_vector_layer.h"
class nsl_num_vector;
class nsl_num_1 : public nsl_vector_layer
{
protected:
	NslNumType *v; 
public:
		nsl_num_1(const int = 0,int = 0,int=0,int=1);
		nsl_num_1(const char*,nsl_public* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=1,int=1);
		nsl_num_1(const NslFloat1&,int=0,int=0,int=1);
		~nsl_num_1();

	void initialize(const char*,nsl_public* = 0,const int = 0,
			row_col_enum = NSL_ROW,int=0,int=1,int=1);

	int	init_num_vector(const int = 0);
	int	memAlloc(const int);

// get value
	NslNumType*	get_v() const { return v; }
	NslNumType&	operator[](const int) const;
	NslNumType&	elem(const int);

// set value
	void	set_value(const int,const NslNumType);

// assignment
	nsl_num_1&  operator=(const nsl_num_vector&);
	nsl_num_1& 	operator=(const NslFloat1&);
	nsl_num_1& 	operator=(const NslFloat0&);
	nsl_num_1& 	operator=(const float);
	nsl_num_1& 	operator=(const double);
	nsl_num_1& 	operator=(const int);

        NslNumType        max();
        NslNumType        min();

        NslNumType        max(int&); // return index
        NslNumType        min(int&);

	// sum
	NslNumType	sum();

// also functions
	nsl_num_2 expand_col(const int);
	nsl_num_2 expand_row(const int);
	nsl_num_2 expand(const int);

	nsl_num_1 transpose_col();
	nsl_num_1 transpose_row();
	nsl_num_1 transpose();

	// sector
	nsl_num_1 	get_sector(const int,const int) const;
	nsl_num_1		set_sector(const
					nsl_num_1&,const int);
	nsl_num_1 	put_sector(const
					nsl_num_1&,const int);

// print
	virtual int	nslPrint() const;
	int	print_num_vector() const;
	int	print_num_vector(const int,const int) const;
	virtual int	nslStatus() const;
	int	print_num_vector_status() const;

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

	int 	write_num_vector(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_num_vector(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);
};
#endif
