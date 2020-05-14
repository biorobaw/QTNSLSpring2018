/* SCCS  @(#)nsl_block_stim_data.h	1.1---95/08/13--23:45:35 */
//
//	nsl_block_stim_data.h
//

#ifndef _NSL_BLOCK_STIM_DATA_H
#define _NSL_BLOCK_STIM_DATA_H
#include "nsl_stim_data.h"

#ifndef _NSL_SET
class nsl_input_data;
#endif

class nsl_block_stim_data : public nsl_stim_data
{
public:

	nsl_block_stim_data(nsl_input_data*); // aa 95-7-14
 	~nsl_block_stim_data();

	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_block_stim_data(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_block_stim_data_status(std::ostream&) const;
};

#endif
