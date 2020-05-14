/* SCCS  %W%---%E%--%U% */
//
//	nsl_input_data.h
//


#ifndef _NSL_INPUT_DATA_H
#define _NSL_INPUT_DATA_H

#ifndef _NSL_SET
class nsl_input_data;
class nsl_input_layer;
#endif

#include "nsl_num_data.h"

class nsl_input_data : public nsl_num_data
{
protected:
	nsl_input_layer* input_layer;

public:

	nsl_input_data(const char*,int=0,int=0);
 	~nsl_input_data();

	nsl_input_layer* get_input_layer() { return input_layer; }

// 	assignment
	num_type 	operator=(const nsl_input_data&);
	num_type 	operator=(const nsl_num_data&);
	num_type 	operator=(const num_type);
	num_type 	operator=(const int);

	int run();

// print status
	virtual int print_status(std::ostream&) const;
	int print_input_data_status(std::ostream&) const;

	virtual int print(std::ostream&) const;
	virtual int print(std::ostream&,int) const;
};
#endif
