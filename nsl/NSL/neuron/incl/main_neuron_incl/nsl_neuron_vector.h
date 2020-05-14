/************************************/
/*       nsl_neuron_vector.h        */
/************************************/

#ifndef _NSL_NEURON_VECTOR_H
#define _NSL_NEURON_VECTOR_H
#include "nsl_neuron_layer.h"

class nsl_neuron_vector : public nsl_neuron_layer
{
public:
	nsl_neuron_vector(const char*,int,int = 1);
	~nsl_neuron_vector();

	void init_pars();

	virtual int init();
	virtual int run();
	virtual int run_in();
	virtual int run_out();
};
#endif
