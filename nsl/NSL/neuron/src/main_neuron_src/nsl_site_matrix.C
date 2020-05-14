/************************************/
/*        nsl_site_matrix.C   	    */
/************************************/

#include "nsl_neuron.h"
#include "nsl_num_library.h"

nsl_site_matrix::nsl_site_matrix(const char* str, int s1,int s2) : 
	nsl_site_layer("site_layer",str)
{
	site_layer = new nsl_num_matrix(str,s1,s2,1);
}

nsl_site_matrix::~nsl_site_matrix()
{
}

int nsl_site_matrix::run()
{
	if (site_layer != NULL)
	{
		*((nsl_num_matrix*) site_layer) = 0;
//		site_layer->set_to_zero(); // equivalnet
	}
	else
	{
		cmd_out("nsl_site_matrix::run: NULL site_layer");
		return 1;
	}

	link_list.wind_up();

	nsl_link_matrix* link;
	nsl_layer* link_layer;

	while ((link = (nsl_link_matrix*) link_list.next()) != NULL)
	{
		if ((link_layer = link->get_link_layer()) == NULL)
		{
			cmd_out("nsl_site_matrix::run: NULL link_layer");
			return 1;
		}
		link->run();
		if (link->get_sign() == 1)
			NSLadd_plus(*((nsl_num_matrix*) site_layer),
				*((nsl_num_matrix*) link_layer));
		else
			NSLadd_minus(*((nsl_num_matrix*) site_layer),
				*((nsl_num_matrix*) link_layer));
	}

	return 1;
}
