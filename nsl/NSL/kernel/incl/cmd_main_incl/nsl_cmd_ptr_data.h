/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_ptr_data.h                       */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_PTR_DATA_H
#define _NSL_CMD_PTR_DATA_H
#include "nsl_cmd_data_layer.h"
class nsl_cmd_ptr_data : public nsl_cmd_data_layer
{
public:
		nsl_cmd_ptr_data();
		~nsl_cmd_ptr_data();

	virtual int cmd_create(nsl_interpreter&);

		int print_cmd_ptr_data(std::ostream&) const;
	virtual int print(std::ostream&) const;
};

#endif
