/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_3.h
//

//template<class NslNumType>
#ifndef _NSL_NUM_3_H
#define _NSL_NUM_3_H
#include "nsl_3_layer.h"
class nsl_num_3 : public nsl_3_layer
{
protected:
	nsl_num_2/*NslNumType*/ **v; 
public:
		nsl_num_3(const int = 0,const int = 0,
			const int = 0,int=0,int=0,int=1);
		nsl_num_3(const char*,nsl_model* = 0,
			const int = 0,const int = 0,const int = 0,
			int=0,int=1,int=1);
		nsl_num_3(const nsl_num_3/*NslNumType*/&,int=0,int=0,int=1);

		~nsl_num_3();

	int	init_num_3(const int = 0,const int = 0,
			const int = 0);
	int	alloc_mem(const int,const int,const int);

// get value
	nsl_num_2/*NslNumType*/**	get_v() const { return v; }
	nsl_num_2/*NslNumType*/&	get_matrix(const int i) const;
	nsl_num_2/*NslNumType*/&	operator[](const int) const;
	NslNumType&	elem(const int,const int,const int);

// set value
	void	set_value(const int,const int,const int,const NslNumType);

// assignment
	nsl_num_3/*NslNumType*/& 	operator=(const nsl_num_3/*NslNumType*/&);
	nsl_num_3/*NslNumType*/& 	operator=(const nsl_num_0/*NslNumType*/&);
	nsl_num_3/*NslNumType*/& 	operator=(const NslNumType);

        NslNumType        max();
        NslNumType        min();

        NslNumType        max(int*,int*,int*); // return index
        NslNumType        min(int*,int*,int*); // where max/min is found


	// sum
	NslNumType	sum();

// also functions
	nsl_num_3/*NslNumType*/ get_sector(const int,const int,const int,
		const int,const int,const int) const;
	nsl_num_3/*NslNumType*/ set_sector(const nsl_num_3/*NslNumType*/&,
		const int,const int,const int);
	nsl_num_3/*NslNumType*/ put_sector(const nsl_num_3/*NslNumType*/&,
		const int,const int,const int);

// print

	virtual int	print(std::ostream&) const;
	int	print_num_3(std::ostream&) const;
	int	print_num_3(std::ostream&,const int,const int,const int,
		const int,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_num_3_status(std::ostream&) const;

	int 	reset_num_3(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_3(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_3(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
