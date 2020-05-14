/************************************/
/*       nsl_link_data_vector.C     */
/************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_neuron_include.h"
 
#include <stddef.h>
#include "nsl_link_data_vector.h"
#include "nsl_neuron.h"
#include "nsl_base_list.h"
#include "nsl_num_library.h"
#include "nsl_num_vector.h"
#include "nsl_num_data.h"

using namespace std;

typedef nsl_base_list nsl_list;

extern void cmd_out(const char *);

nsl_link_data_vector::nsl_link_data_vector(nsl_layer& f,nsl_layer& t,
	nsl_layer& w,int s) : nsl_link_vector(f,t,w,s)
{
}

nsl_link_data_vector::nsl_link_data_vector(nsl_layer& f,nsl_layer& t,
	int s) : nsl_link_vector(f,t,s)
{
}

nsl_link_data_vector::~nsl_link_data_vector()
{
}

void NSLadd_equal_FX(nsl_num_vector& out,const nsl_num_data& a)
{
	int outmax = out.get_imax();

	for (int i = 0; i < outmax; i++)
		out[i] = a.get_data();
}

int nsl_link_data_vector::run() //TODO: VERIFY -bn7
{
	nsl_layer* out;
	//nsl_link_layer *self = this; //temporary fix -bn7

	if (link_layer != NULL)
		link_layer->print(cout);
	else
	{
		cmd_out("nsl_link_data_vector::run: NULL link_layer");
		return 1;
	}

	if (from != NULL &&
		(out = from->get_output()) != NULL)
	{
		out->print(cout);
	}
	else
	{
		cmd_out("nsl_link_data_vector::run: NULL from/output");
		return 1;
	}

	NSLadd_equal_FX(*((nsl_num_vector*) this->link_layer),*((nsl_num_data*) out));

	this->link_layer->print(cout);

	return 1;
}
