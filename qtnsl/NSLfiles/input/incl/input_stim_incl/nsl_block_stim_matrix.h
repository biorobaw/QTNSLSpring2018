/* SCCS  %W%---%E%--%U% */
//
//	nsl_block_stim_matrix.h
//

#ifndef _NSL_BLOCK_STIM_MATRIX_H
#define _NSL_BLOCK_STIM_MATRIX_H
#include "nsl_stim_matrix.h"
class nsl_block_stim_matrix : public nsl_stim_matrix
{
public:

	nsl_block_stim_matrix(nsl_input_matrix*);
 	~nsl_block_stim_matrix();

	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_block_stim_matrix(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_block_stim_matrix_status(std::ostream&) const;
};
#endif
