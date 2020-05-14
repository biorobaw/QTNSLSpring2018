
#ifndef _NSL_CMD_FUNCTION_H
#define _NSL_CMD_FUNCTION_H
#include "nsl_cmd_type.h"
class nsl_cmd_function : public nsl_cmd_type
{
public:
		nsl_cmd_function();
		~nsl_cmd_function();

	int init_cmd_function();
	int set_cmd_function();

	// cmds
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_exec(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);

		int print_cmd_function(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
