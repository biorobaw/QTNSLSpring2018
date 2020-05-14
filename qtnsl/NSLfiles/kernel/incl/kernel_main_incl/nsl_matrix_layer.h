/* SCCS  %W%---%E%--%U% */
//
//	nsl_matrix_layer.h
//

#ifndef _NSL_MATRIX_LAYER_H
#define _NSL_MATRIX_LAYER_H
#include "nsl_layer.h"
class nsl_matrix_layer : public nsl_layer
{
protected:
	int i0,i1,j0,j1;
	int imax,jmax;
public:
// creation without memory allocation
	nsl_matrix_layer(int = 0,int=0,int=1);

	nsl_matrix_layer(bool, int = 0,int=0,int=1); //remove ambiguity from constructors -bn7
	nsl_matrix_layer(const char*,const char*,
			const int,const int,int = 0,int=0,int=1);

	nsl_matrix_layer(const int,const int,int = 0,int=0,int=1);
// creation with memory allocation
	nsl_matrix_layer(const char*,nsl_public* = 0,int = 0,int=0,int=1);
	nsl_matrix_layer(const char*,const char*,nsl_public* = 0,
		int = 0,int=0,int=1);
	nsl_matrix_layer(const char*,const char*,nsl_public* = 0,
		const int=0,const int=0,int = 0,int=0,int=1);

	void initialize(const char*,const char*,nsl_public* = 0,
		const int=0,const int=0,int = 0,int=0,int=1);

	virtual ~nsl_matrix_layer();

	int init_matrix_layer();
	int init_matrix_layer(const int,const int);

	// old get
	int	get_x0() const { return i0; }
	int	get_x1() const { return i1; }
	int	get_y0() const { return j0; }
	int	get_y1() const { return j1; }
	int	get_xn() const { return imax; }
	int	get_yn() const { return jmax; }
	// get
	int	get_i0() const { return i0; }
	int	get_i1() const { return i1; }
	int	get_j0() const { return j0; }
	int	get_j1() const { return j1; }
	int	get_imax() const { return imax; }
	int	get_jmax() const { return jmax; }
	int	get_rows() const { return imax; }
	int	get_cols() const { return jmax; }
	int	getRows() const { return imax; }
	int	getCols() const { return jmax; }

	// set
	void	set_i0(int i) { i0 = i; }
	void	set_i1(int i) { i1 = i; }
	void	set_j0(int i) { j0 = i; }
	void	set_j1(int i) { j1 = i; }

// print
	virtual int	nslPrint() const;
	int	print_matrix_layer() const;
	virtual int	nslStatus() const;
	int	print_matrix_layer_status() const;

	virtual int	print(std::ostream&) const;
	int	print_matrix_layer(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_matrix_layer_status(std::ostream&) const;

	int 	reset_matrix_layer(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_matrix_layer(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_matrix_layer(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

#endif
