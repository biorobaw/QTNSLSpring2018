/* SCCS  %W%---%E%--%U% */
//
//	nsl_stim_data.h
//

#ifndef _NSL_STIM_DATA_H
#define _NSL_STIM_DATA_H

#ifndef _NSL_SET
class nsl_input_data;
#endif

#include "nsl_stim.h"
class nsl_stim_data : public nsl_stim
{
public:

	nsl_stim_data(nsl_input_data*);
 	~nsl_stim_data();

	virtual int run();
	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_stim_data(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_stim_data_status(std::ostream&) const;
};

#endif
