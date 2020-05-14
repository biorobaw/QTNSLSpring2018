/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_int_data.h                       */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_DATA_LAYER_H
#define _NSL_CMD_DATA_LAYER_H
#include "nsl_cmd_data_layer.h"
#include <iostream>
class nsl_interpreter;
class nsl_cmd_int_data : public nsl_cmd_data_layer
{
public:
		nsl_cmd_int_data();
		~nsl_cmd_int_data();

	virtual int cmd_create(nsl_interpreter&);

		int print_cmd_int_data(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
