/* SCCS  @(#)nsl_vector_layer.h	1.1---95/08/13--23:37:24 */
//
//	nsl_vector_layer.h
//

#ifndef _NSL_VECTOR_LAYER_H
#define _NSL_VECTOR_LAYER_H
#include "nsl_layer.h"

#ifndef _NSL_SET
class nsl_buffer;
class nsl_model;
#endif
class nsl_vector_layer : public nsl_layer
{
protected:
	int i0,i1;
	int imax;

	row_col_enum vec_type;	// 0 - row vector, 1 - col vector
public:
// creation without memory allocation
	nsl_vector_layer(int = 0,int=0,int = 1);
	nsl_vector_layer(bool = false, int = 0, int = 0, int = 1); //to remove constructor ambiguity in nsl_int_vector,matrix,data, -bn7
	nsl_vector_layer(const int,int = 0,int=0,int = 1);
// creation with memory allocation
	nsl_vector_layer(const char*,nsl_public* = 0,int = 0,int=0,int = 1);
	nsl_vector_layer(const char*,const char*,nsl_public* = 0,
		int = 0,int=0,int = 1);
	nsl_vector_layer(const char*,const char*,nsl_public* = 0,
		const int = 0,row_col_enum = NSL_ROW,int = 0,int=0,int=1); 

	virtual ~nsl_vector_layer();

	void initialize(const char*,const char*,nsl_public* = 0,
		const int = 0,row_col_enum = NSL_ROW,int = 0,int=0,int=1);

	int init_vector_layer();
	int init_vector_layer(const int);

	// old get
	int	get_x0() const { return i0; }
	int	get_x1() const { return i1; }
	int	get_xn() const { return imax; }
	// get
	int	get_i0() const { return i0; }
	int	get_i1() const { return i1; }
	int	get_imax() const { return imax; }
	int	get_size() const { return imax; }

	// set
	void	set_i0(int i) { i0 = i; }
	void	set_i1(int i) { i1 = i; }

	// transpose vector
	row_col_enum 	set_vec_type(row_col_enum i) 
			{ return vec_type = i; }
	row_col_enum	get_vec_type() const { return vec_type; }

// print
	virtual int	nslPrint() const;
	int	print_vector_layer() const;
	virtual int	nslStatus() const;
	int	print_vector_layer_status() const;

	virtual int	print(std::ostream&) const;
	int	print_vector_layer(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_vector_layer_status(std::ostream&) const;

	int 	reset_vector_layer(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_vector_layer(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_vector_layer(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif

