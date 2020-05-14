/* SCCS  %W%---%E%--%U% */
//
//	nsl_4_layer.h
//

#ifndef _NSL_4_LAYER_H
#define _NSL_4_LAYER_H
#include "nsl_layer.h"
#include <iostream>
class nsl_buffer;
class nsl_model;
class nsl_4_layer : public nsl_layer
{
protected:
	int i0,i1,j0,j1,k0,k1,l0,l1;
	int imax,jmax,kmax,lmax;
public:
// creation without memory allocation
	nsl_4_layer(int = 0,int=0,int=1); 
	nsl_4_layer(const char*,nsl_public* = 0,int = 0,int=0,int=1);
	nsl_4_layer(const char*,const char*,nsl_public* = 0,int=0,int=0,int=1);
// creation with memory allocation
	nsl_4_layer(const int,const int,const int,const int,int=0,int=0,int=1); 
	nsl_4_layer(const char*,const char*,nsl_public* = 0,
		const int = 0,const int = 0,
		const int = 0,const int = 0,int = 0,int=0,int=1); 

	virtual ~nsl_4_layer();

	void initialize(const char*,const char*,nsl_public* = 0,
		const int = 0,const int = 0,
		const int = 0,const int = 0,int = 0,int=0,int=1);

	int init_4_layer();
	int init_4_layer(const int,const int,const int,const int);

	// get
	int	get_i0() const { return i0; }
	int	get_i1() const { return i1; }
	int	get_j0() const { return j0; }
	int	get_j1() const { return j1; }
	int	get_k0() const { return k0; }
	int	get_k1() const { return k1; }
	int	get_l0() const { return l0; }
	int	get_l1() const { return l1; }
	int	get_imax() const { return imax; }
	int	get_jmax() const { return jmax; }
	int	get_kmax() const { return kmax; }
	int	get_lmax() const { return lmax; }

	// set
	void	set_i0(int i) { i0 = i; }
	void	set_i1(int i) { i1 = i; }
	void	set_j0(int i) { j0 = i; }
	void	set_j1(int i) { j1 = i; }
	void	set_k0(int i) { k0 = i; }
	void	set_k1(int i) { k1 = i; }
	void	set_l0(int i) { l0 = i; }
	void	set_l1(int i) { l1 = i; }

// print
	virtual int	nslPrint() const;
	int	print_4_layer() const;
	virtual int	nslStatus() const;
	int	print_4_layer_status() const;

	virtual int	print(std::ostream&) const;
	int	print_4_layer(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_4_layer_status(std::ostream&) const;

	int 	reset_4_layer(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_4_layer(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_4_layer(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

#endif
