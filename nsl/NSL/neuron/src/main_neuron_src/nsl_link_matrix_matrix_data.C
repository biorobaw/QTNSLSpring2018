/************************************/
/*    nsl_link_matrix_matrix_data.C */
/************************************/

#include "nsl_neuron.h"
#include "nsl_num_library.h"
#include <stddef.h>

extern void cmd_out(const char *);


nsl_link_matrix_matrix_data::nsl_link_matrix_matrix_data(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_matrix_data(f,t,w,s)
{
}

nsl_link_matrix_matrix_data::~nsl_link_matrix_matrix_data()
{
}

int nsl_link_matrix_matrix_data::run()
{
	nsl_layer* out;

	if (link_layer == NULL)
	{
		cmd_out("nsl_link_matrix_matrix_data::run: NULL link_layer");
		return 1;
	}

	if (from != NULL && 
		(out = from->get_output()) != NULL)
	{
//		out->print(cout);
	}
	else
	{
		cmd_out("nsl_link_matrix_matrix_data::run: NULL from/output");
		return 1;
	}

	if (weight == NULL)
	{
		cmd_out("nsl_link_matrix_data_matrix::run: NULL weight");
		return 1;
	}

	NSLmult_equal(*((nsl_num_data*) link_layer),
		*((nsl_num_matrix*) out), *((nsl_num_data*) weight));

//	link_layer->print(cout);

	return 1;
}
