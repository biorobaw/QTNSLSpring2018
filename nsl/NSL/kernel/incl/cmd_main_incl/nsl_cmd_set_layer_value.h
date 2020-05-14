/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_layer_value.h                */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_LAYER_VALUE_H
#define _NSL_CMD_SET_LAYER_VALUE_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_layer_value : public nsl_cmd_set
{
public:
		nsl_cmd_set_layer_value(const char*,const num_type = 0.0);
		~nsl_cmd_set_layer_value();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
  	virtual int update(nsl_cmd_type*);

	int print_cmd_set_layer_value(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif