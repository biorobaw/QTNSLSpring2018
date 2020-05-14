/************************************/
/*    nsl_link_vector_matrix_data.C */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_vector_matrix_data.h"

nsl_link_vector_matrix_data::nsl_link_vector_matrix_data(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_vector_data(f,t,w,s)
{
}

nsl_link_vector_matrix_data::~nsl_link_vector_matrix_data()
{
}

int nsl_link_vector_matrix_data::run()
{
	return 1;
}
