/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_module.h                         */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_MODULE_H
#define _NSL_CMD_MODULE_H
#include "nsl_cmd_type.h"
class nsl_cmd_module : public nsl_cmd_type
{
public:
		nsl_cmd_module();
		~nsl_cmd_module();

	int init_cmd_module();
	int set_cmd_module();

	// cmds
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_exec(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);

		int print_cmd_module(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
