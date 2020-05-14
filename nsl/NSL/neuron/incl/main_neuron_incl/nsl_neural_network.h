/************************************/
/*        nsl_neural_network.h      */
/************************************/

#ifndef _NSL_NEURAL_NETWORK_H
#define _NSL_NEURAL_NETWORK_H
#include "nsl_model.h"
class nsl_neural_network : public nsl_model
{
public:
	nsl_neural_network(const char* name = " ",int = 1);
	~nsl_neural_network();

	virtual int run();
};

#endif
