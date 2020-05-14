/************************************/
/*    nsl_link_data_matrix_data.C   */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_data_matrix_data.h"
#include "nsl_layer.h"

nsl_link_data_matrix_data::nsl_link_data_matrix_data(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_data_data(f,t,w,s)
{
}

nsl_link_data_matrix_data::~nsl_link_data_matrix_data()
{
}

int nsl_link_data_matrix_data::run()
{
	return 1;
}
