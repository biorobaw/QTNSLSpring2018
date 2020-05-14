/************************************/
/*        nsl_site_vector.C   	    */
/************************************/
#include "nsl_neuron.h"
#include "nsl_site_vector.h"
#include "nsl_layer.h"
#include "nsl_link_vector.h"
#include "nsl_num_vector.h"
#include "nsl_num_library.h"
#include <stddef.h>
extern void cmd_out(const char *);
 
nsl_site_vector::nsl_site_vector(const char* str, int lsize) : 
	nsl_site_layer("site_layer",str)
{
	site_layer = new nsl_num_vector(str,lsize,NSL_ROW,1);
}

nsl_site_vector::~nsl_site_vector()
{
}

int nsl_site_vector::run()
{
	if (site_layer != NULL)
	{
		*((nsl_num_vector*) site_layer) = 0;
//		site_layer->set_to_zero(); // equivalnet
	}
	else
	{
		cmd_out("nsl_site_vector::run: NULL site_layer");
		return 1;
	}

	link_list.wind_up();

	nsl_link_vector* link;
	nsl_layer* link_layer;

	while ((link = (nsl_link_vector*) link_list.next()) != NULL)
	{
		if ((link_layer = link->get_link_layer()) == NULL)
		{
			cmd_out("nsl_site_vector::run: NULL link_layer");
			return 1;
		}
		link->run();
		if (link->get_sign() == 1)
			NSLadd_plus(*((nsl_num_vector*) site_layer),
				*((nsl_num_vector*) link_layer));
		else
			NSLadd_minus(*((nsl_num_vector*) site_layer),
				*((nsl_num_vector*) link_layer));
	}

	return 1;
}
