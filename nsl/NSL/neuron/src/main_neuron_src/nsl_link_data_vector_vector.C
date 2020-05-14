/************************************/
/*   nsl_link_data_vector_vector.C  */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_data_vector_vector.h"
#include "nsl_layer.h"

nsl_link_data_vector_vector::nsl_link_data_vector_vector(nsl_layer& f,
	nsl_layer& t, nsl_layer& w,int s) : nsl_link_data_vector(f,t,w,s)
{
}

nsl_link_data_vector_vector::~nsl_link_data_vector_vector()
{
}

int nsl_link_data_vector_vector::run()
{
	return 1;
}
