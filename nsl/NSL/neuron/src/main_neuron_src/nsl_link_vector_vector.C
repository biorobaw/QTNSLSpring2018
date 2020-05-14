/************************************/
/*    nsl_link_vector_vector.C      */
/************************************/

#include "nsl_neuron.h"
#include "nsl_link_vector_vector.h"
#include "nsl_num_vector.h"
#include "nsl_layer.h"
#include "nsl_num_library.h"
#include "nsl_base.h"
#include "nsl_link_layer.h"
#include <stddef.h>

nsl_link_vector_vector::nsl_link_vector_vector(nsl_layer& f,
	nsl_layer& t,nsl_layer& w,int s) : nsl_link_vector(f,t,w,s)
{
}

nsl_link_vector_vector::nsl_link_vector_vector(nsl_layer& f,
	nsl_layer& t,int s) : nsl_link_vector(f,t,s)
{
}


nsl_link_vector_vector::~nsl_link_vector_vector()
{
}

int nsl_link_vector_vector::run()
{
	nsl_layer* out;
	nsl_link_layer* self = this;

	if (link_layer == NULL)	//TODO: link_layer is unresolved -bn7
	{
		cmd_out("nsl_link_vector_vector::run: NULL link_layer");
		return 1;
	}

	if (from != NULL &&
		(out = from->get_output()) != NULL)
	{
//		out->print(cout);
	}
	else
	{
		cmd_out("nsl_link_vector_vector::run: NULL from/output");
		return 1;
	}

	NSLadd_equal(*((nsl_num_vector*) link_layer),*((nsl_num_vector*) out));

//	link_layer->print(cout);

	return 1;
}
