/************************************/
/*  nsl_link_vector_vector_matrix.C */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_vector_vector_matrix.h"

nsl_link_vector_vector_matrix::nsl_link_vector_vector_matrix(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_vector_matrix(f,t,w,s)
{
}

nsl_link_vector_vector_matrix::~nsl_link_vector_vector_matrix()
{
}

int nsl_link_vector_vector_matrix::run()
{
	return 1;
}
