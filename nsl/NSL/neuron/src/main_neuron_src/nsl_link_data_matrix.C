/************************************/
/*       nsl_link_data_matrix.C     */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_data_matrix.h"
#include "nsl_layer.h"
#include "nsl_num_library.h"
#include "nsl_num_data.h"

nsl_link_data_matrix::nsl_link_data_matrix(nsl_layer& f,nsl_layer& t,
	nsl_layer& w,int s) : nsl_link_matrix(f,t,w,s)
{
}

nsl_link_data_matrix::nsl_link_data_matrix(nsl_layer& f,nsl_layer& t,
	int s) : nsl_link_matrix(f,t,s)
{
}

nsl_link_data_matrix::~nsl_link_data_matrix()
{
}

int nsl_link_data_matrix::run()
{
	nsl_layer* out;

	if (link_layer != NULL)
		link_layer->print(cout);
	else
	{
		cmd_out("nsl_link_data_matrix::run: NULL link_layer");
		return 1;
	}

	if (from != NULL && 
		(out = from->get_output()) != NULL)
	{
		out->print(cout);
	}
	else
	{
		cmd_out("nsl_link_data_matrix::run: NULL from/output");
		return 1;
	}

	NSLadd_equal(*((nsl_num_matrix*) link_layer),*((nsl_num_data*) out));

	link_layer->print(cout);

	return 1;
}
