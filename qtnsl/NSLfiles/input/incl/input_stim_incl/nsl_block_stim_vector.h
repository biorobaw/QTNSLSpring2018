/* SCCS  %W%---%E%--%U% */
//
//	nsl_block_stim_vector.h
//

#ifndef _NSL_BLOCK_STIM_VECTOR_H
#define _NSL_BLOCK_STIM_VECTOR_H
#include "nsl_stim_vector.h"
class nsl_block_stim_vector : public nsl_stim_vector
{
public:

	nsl_block_stim_vector(nsl_input_vector*); // aa 95-7-14
 	~nsl_block_stim_vector();

	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_block_stim_vector(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_block_stim_vector_status(std::ostream&) const;
};

#endif
