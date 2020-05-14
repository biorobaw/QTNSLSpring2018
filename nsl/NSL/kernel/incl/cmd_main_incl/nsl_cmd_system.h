/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_system.h                         */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SYSTEM_H
#define _NSL_CMD_SYSTEM_H
#include "nsl_cmd_type.h"
class nsl_cmd_system : public nsl_cmd_type 
{
public:
		nsl_cmd_system();
		~nsl_cmd_system();

	int init_cmd_system();
	int set_cmd_system();

	// cmds
	virtual int cmd_cont(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_init(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_run(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_step(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

		int print_cmd_system(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif