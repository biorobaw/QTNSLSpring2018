/************************************/
/*  nsl_link_vector_matrix_matrix.C */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_vector_matrix_matrix.h"

nsl_link_vector_matrix_matrix::nsl_link_vector_matrix_matrix(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_vector_matrix(f,t,w,s)
{
}

nsl_link_vector_matrix_matrix::~nsl_link_vector_matrix_matrix()
{
}

int nsl_link_vector_matrix_matrix::run()
{
	return 1;
}
