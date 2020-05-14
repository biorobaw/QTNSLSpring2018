/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_4.h
//

//template<class NslNumType>
#ifndef _NSL_NUM_4_H
#define _NSL_NUM_4_H
#include "nsl_4_layer.h"
class nsl_num_4 : public nsl_4_layer
{
protected:
	nsl_num_3/*NslNumType*/ **v; 
public:
		nsl_num_4(const int = 0,const int = 0,
			const int = 0,const int = 0,int=0,int=0,int=1);
		nsl_num_4(const char*,nsl_model* = 0,const int = 0,
			const int = 0,const int = 0,const int = 0,
			int = 0,int=1,int=1);
		nsl_num_4(const nsl_num_4/*NslNumType*/&,int = 0,int=0,int=1);

		~nsl_num_4();

	int	init_num_4(const int = 0,const int = 0,
			const int = 0,const int = 0);
	int	alloc_mem(const int,const int,const int,const int);

// get value
	nsl_num_3/*NslNumType*/**	get_v() const { return v; }
	nsl_num_2/*NslNumType*/&	get_matrix(const int i,const int j) const;
	nsl_num_3/*NslNumType*/&	operator[](const int) const;
	NslNumType&	elem(const int,const int,const int,const int);

// set value
	void	set_value(const int,const int,const int,const int,
		const NslNumType);

// assignment
	nsl_num_4/*NslNumType*/& 	operator=(const nsl_num_4/*NslNumType*/&);
	nsl_num_4/*NslNumType*/& 	operator=(const nsl_num_0/*NslNumType*/&);
	nsl_num_4/*NslNumType*/& 	operator=(const NslNumType);

        NslNumType        max();
        NslNumType        min();

        NslNumType        max(int*,int*,int*,int*); // return index
        NslNumType        min(int*,int*,int*,int*); // where max/min is found

	// sum
	NslNumType	sum();

// also functions
	nsl_num_4/*NslNumType*/ get_sector(const int,const int,const int,
		const int,const int,const int,const int,const int) const;
	nsl_num_4/*NslNumType*/ set_sector(const nsl_num_4/*NslNumType*/&,
		const int,const int,const int,const int);
	nsl_num_4/*NslNumType*/ put_sector(const nsl_num_4/*NslNumType*/&,
		const int,const int,const int,const int);
// print

	virtual int	print(std::ostream&) const;
	int	print_num_4(std::ostream&) const;
	int	print_num_4(std::ostream&,const int,const int,const int,
		const int,const int,const int,const int,const int) const;
	virtual int	print_status(std::ostream&) const;
	int	print_num_4_status(std::ostream&) const;

	int 	reset_num_4(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_4(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_4(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
#endif
