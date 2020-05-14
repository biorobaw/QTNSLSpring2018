/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_layer.h                          */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_LAYER_H
#define _NSL_CMD_LAYER_H
#include "nsl_cmd_type.h"
class nsl_cmd_layer : public nsl_cmd_type
{
public:
		nsl_cmd_layer(const char*);
		nsl_cmd_layer();
		~nsl_cmd_layer();

	int init_cmd_layer();
	int set_cmd_layer();

	// cmds
//	virtual int cmd_assign(nsl_interpreter&);
	virtual int cmd_connect(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_elem(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_file_disable(nsl_interpreter&);
	virtual int cmd_file_enable(nsl_interpreter&);
	virtual int cmd_get(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);


		int print_cmd_layer(ostream&) const;
	virtual int print(ostream&) const;
};



#endif
