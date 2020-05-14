/************************************/
/*            nsl_site_data.C       */
/************************************/
#include "nsl_neuron.h"
#include "nsl_site_data.h"
#include "nsl_num_library.h"
#include "nsl_num_data.h"
#include "nsl_link_data.h"
#include <stddef.h>

extern void cmd_out(const char *);

nsl_site_data::nsl_site_data(const char* str) : 
	nsl_site_layer("site_layer",str)
{
     	site_layer = new nsl_num_data(str,0,1);
}

nsl_site_data::~nsl_site_data()
{
}

void NSLadd_minus_FX(nsl_num_data& out,const nsl_num_data& a)
{
	out.elem() -= a.get_data();
}

int nsl_site_data::run()
{
	if (site_layer != NULL)
	{
		*((nsl_num_data*) site_layer) = 0;
//		site_layer->set_to_zero(); // equivalnet
	}
	else
	{
		cmd_out("nsl_site_data::run: NULL site_layer");
		return 1;
	}

	link_list.wind_up();

	nsl_link_data* link;
	nsl_layer* link_layer;

	while ((link = (nsl_link_data*) link_list.next()) != NULL)
	{
		if ((link_layer = link->get_link_layer()) == NULL)
		{
			cmd_out("nsl_site_data::run: NULL link_layer");
			return 1;
		}
		link->run();
		if (link->get_sign() == 1)
			NSLadd_plus(*((nsl_num_data*) site_layer),
				*((nsl_num_data*) link_layer));
		else
			NSLadd_minus_FX(*((nsl_num_data*) site_layer),
				*((nsl_num_data*) link_layer));
	}

	return 1;
}
