/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_data_layer.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_DATA_LAYERX_H
#define _NSL_CMD_DATA_LAYERX_H
#include "nsl_cmd_layer.h"
class nsl_cmd_data_layer : public nsl_cmd_layer
{
public:
		nsl_cmd_data_layer(const char*);
		nsl_cmd_data_layer();
		~nsl_cmd_data_layer();

	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_elem(nsl_interpreter&);

		int print_cmd_data_layer(std::ostream&) const;
	virtual int print(std::ostream&) const;
};

#endif
