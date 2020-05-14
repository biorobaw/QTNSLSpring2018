/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_int_data.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_INT_DATA_H
#define _NSL_CMD_SET_INT_DATA_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_int_data : public nsl_cmd_set ///!!!!! NO PROPER DEFINITIONS COULD BE FOUND -bn7
{
public:
		nsl_cmd_set_int_data(const char*,const int = 0) { };
		~nsl_cmd_set_int_data() { };

	virtual int init() { return 0; };
	virtual int set(nsl_interpreter&) { return 0; };
	virtual int get(nsl_buffer&) { return 0; };
  	virtual int update(nsl_cmd_type*) { return 0; };

	int print_cmd_set_int_data(std::ostream&) const { return 0; };
	virtual int print(std::ostream&) const;
};
#endif

