/************************************/
/*       nsl_neuron_matrix.h        */
/************************************/


#ifndef _NSL_NEURON_MATRIX_H
#define _NSL_NEURON_MATRIX_H
#include "nsl_neuron_layer.h"
class nsl_neuron_matrix : public nsl_neuron_layer
{
public:
	nsl_neuron_matrix(const char*,int,int,int = 1);
	~nsl_neuron_matrix();

	void init_pars();

	virtual int init();
	virtual int run();
	virtual int run_in();
	virtual int run_out();
};
#endif
