//
// 	nsl_cmd_neural_network.h
//

#ifndef _NSL_CMD_NEURAL_NETWORK_H
#define _NSL_CMD_NEURAL_NETWORK_H
#include "nsl_cmd_model.h"
#include <iostream>
class nsl_cmd_neural_network : public nsl_cmd_model
{
public:
		nsl_cmd_neural_network();
		~nsl_cmd_neural_network();

	int init_cmd_neural_network();
	int set_cmd_neural_network();

	// cmds
        virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_connect(nsl_interpreter&);
	virtual int cmd_cont(nsl_interpreter&);
        virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_init(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_run(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_step(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);

		int print_cmd_neural_network(ostream&) const;
	virtual int print(ostream&) const;
};
#endif
