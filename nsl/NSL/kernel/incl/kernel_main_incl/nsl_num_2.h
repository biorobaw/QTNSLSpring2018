/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_2.h
//

#ifndef _NSL_NUM_2_H
#define _NSL_NUM_2_H
#include "nsl_matrix_layer.h"
//template<class NslNumType>
class nsl_num_2 : public nsl_matrix_layer
{
protected:
	nsl_num_1 **v;
public:
		nsl_num_2(const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_num_2(const char*,nsl_public* = 0,const int = 0,
			const int = 0,int=0,int=1,int=1);
		nsl_num_2(const NslFloat2&,int=0,int=0,int=1);

		~nsl_num_2();

	void initialize(const char*,nsl_public* = 0,const int = 0,
			const int = 0,int=0,int=1,int=1);

	int	init_num_matrix(const int = 0,const int = 0);
	int	memAlloc(const int,const int);

// get value
	nsl_num_1**	get_v() const { return v; }
	nsl_num_1&	get_vector(const int i) const;
	nsl_num_1**	get_matrix() const { return v; }
	nsl_num_1&	operator[](const int) const;
	NslNumType&	elem(const int,const int);

// set value
	void	set_value(const int,const int,const NslNumType);

// assignment
	nsl_num_2& operator=(const NslFloat2&);
//	nsl_num_2& operator=(const nsl_din_num_2&);
//	nsl_num_2& operator=(const nsl_dout_num_2&);
	nsl_num_2& operator=(const NslFloat0&);
//	nsl_num_2& operator=(const nsl_din_num_0&);
//	nsl_num_2& operator=(const nsl_dout_num_0&);
	nsl_num_2& operator=(const float);
	nsl_num_2& operator=(const double);
	nsl_num_2& operator=(const int);

        NslNumType        max();
        NslNumType        min();

        NslNumType        max(int&,int&); // return index
        NslNumType        min(int&,int&);

	// sum
	NslNumType	sum();

// also functions
	nsl_num_1 reduce_row();
	nsl_num_1 reduce_col();

	nsl_num_2 get_sector(const int,const int,const int,
		const int) const;
	nsl_num_2 set_sector(const nsl_num_2&,
		const int,const int);
	nsl_num_2 put_sector(const nsl_num_2&,
		const int,const int);

	nsl_num_1	get_row(const int) const;
	nsl_num_1	get_col(const int) const;
	nsl_num_2	set_row(const nsl_num_1&,const int);
	nsl_num_2	set_col(const nsl_num_1&,const int);

// print
	virtual int	nslPrint() const;
	int	print_num_matrix() const;
	int	print_num_matrix(const int,const int,const int,const int) const;
	virtual int	nslStatus() const;
	int	print_num_matrix_status() const;

	virtual int	print(std::ostream&) const;
	int	print_num_matrix(std::ostream&) const;
	int	print_num_matrix(std::ostream&,const int,const int,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_num_matrix_status(std::ostream&) const;

	int 	reset_num_matrix(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_matrix(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_matrix(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	write_num_matrix(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_num_matrix(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);
};
#endif
