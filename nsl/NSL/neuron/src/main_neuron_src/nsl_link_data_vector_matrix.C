/************************************/
/*   nsl_link_data_vector_matrix.C  */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_data_vector_matrix.h"
#include "nsl_layer.h"

nsl_link_data_vector_matrix::nsl_link_data_vector_matrix(nsl_layer& f,
	nsl_layer& t, nsl_layer& w,int s) : nsl_link_data_matrix(f,t,w,s)
{
}

nsl_link_data_vector_matrix::~nsl_link_data_vector_matrix()
{
}

int nsl_link_data_vector_matrix::run()
{
	return 1;
}
