/************************************/
/*          nsl_neuron_data.h       */
/************************************/

#ifndef _NSL_NEURON_DATA_H
#define _NSL_NEURON_DATA_H
#include "nsl_neuron_layer.h"
class nsl_neuron_data : public nsl_neuron_layer
{
public:
	nsl_neuron_data(const char*,int = 1);
	~nsl_neuron_data();

	void init_pars();

	virtual int init();
	virtual int run();
	virtual int run_in();
	virtual int run_out();
};
#endif
