//
// 	nsl_cmd_neuron_matrix.h
//

#ifndef _NSL_CMD_NEURON_MATRIX_H
#define _NSL_CMD_NEURON_MATRIX_H
#include "nsl_cmd_neuron_layer.h"
class nsl_cmd_neuron_matrix : public nsl_cmd_neuron_layer
{
public:
		nsl_cmd_neuron_matrix();
		~nsl_cmd_neuron_matrix();

	int init_cmd_neuron_matrix();
	int set_cmd_neuron_matrix();

	// cmds
        virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_cont(nsl_interpreter&);
	virtual int cmd_connect(nsl_interpreter&);
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

		int print_cmd_neuron_matrix(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
