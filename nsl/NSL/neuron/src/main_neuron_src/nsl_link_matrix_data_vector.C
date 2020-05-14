/************************************/
/*    nsl_link_matrix_data_vector.C */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_matrix_data_vector.h"
#include "nsl_link_layer.h"
#include "nsl_base.h"
#include "nsl_num_library.h"
#include "nsl_num_vector.h"
#include "nsl_num_data.h"
#include "nsl_num_matrix.h"

#define NULL 0

extern void cmd_out (const char *);

 
nsl_link_matrix_data_vector::nsl_link_matrix_data_vector(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_matrix_vector(f,t,w,s)
{
}

nsl_link_matrix_data_vector::~nsl_link_matrix_data_vector()
{
}

int nsl_link_matrix_data_vector::run()
{
	nsl_layer* out;

	if (link_layer == NULL)
	{
		cmd_out("nsl_link_matrix_data_vector::run: NULL link_layer");
		return 1;
	}

	if (from != NULL && 
		(out = from->get_output()) != NULL)
	{
//		out->print(cout);
	}
	else
	{
		cmd_out("nsl_link_matrix_data_vector::run: NULL from/output");
		return 1;
	}

	if (weight == NULL)
	{
		cmd_out("nsl_link_data_vector_matrix::run: NULL weight");
		return 1;
	}

	NSLmult_equal(*((nsl_num_vector*) link_layer),
		*((nsl_num_matrix*) out), *((nsl_num_data*) weight));

//	link_layer->print(cout);

	return 1;
}
