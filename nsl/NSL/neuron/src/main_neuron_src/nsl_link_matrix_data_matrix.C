/************************************/
/*    nsl_link_matrix_data_matrix.C */
/************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_neuron_include.h"
#include "nsl_neuron.h"
#include "nsl_link_matrix_data_matrix.h"
#include "nsl_num_library.h"
#include "nsl_num_data.h"
#include "nsl_num_matrix.h"

extern void cmd_out(const char *);

nsl_link_matrix_data_matrix::nsl_link_matrix_data_matrix(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_matrix_matrix(f,t,w,s)
{
}

nsl_link_matrix_data_matrix::~nsl_link_matrix_data_matrix()
{
}

int nsl_link_matrix_data_matrix::run()
{
	nsl_layer* out;

	if (link_layer == NULL)
	{
		cmd_out("nsl_link_matrix_data_matrix::run: NULL link_layer");
		return 1;
	}

	if (from != NULL && 
		(out = from->get_output()) != NULL)
	{
//		out->print(cout);
	}
	else
	{
		cmd_out("nsl_link_matrix_data_matrix::run: NULL from/output");
		return 1;
	}

	if (weight == NULL)
	{
		cmd_out("nsl_link_data_matrix_matrix::run: NULL weight");
		return 1;
	}

	NSLmult_equal(*((nsl_num_matrix*) link_layer),
		*((nsl_num_matrix*) out), *((nsl_num_data*) weight));

//	link_layer->print(cout);

	return 1;
}
