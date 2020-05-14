/************************************/
/*  nsl_link_vector_vector_vector.C */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_vector_vector_vector.h"

nsl_link_vector_vector_vector::nsl_link_vector_vector_vector(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_vector_vector(f,t,w,s)
{
}

nsl_link_vector_vector_vector::~nsl_link_vector_vector_vector()
{
}

int nsl_link_vector_vector_vector::run()
{
	return 1;
}
