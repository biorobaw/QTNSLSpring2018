/************************************/
/*         nsl_neuron_data.C        */
/************************************/

#include "nsl_neuron_data.h"
#include "nsl_neuron_layer.h"
#include "nsl_num_library.h"
#include "nsl_num_data.h"
#include "nsl_num.h"
#include "nsl_site_data.h"
#include "nsl_diff.h"
#include "nsl_layer.h"
#include "nsl_thresh_library.h"
#include "nsl_ptr_data.h"
#include "nsl_ptr_vector.h"
#include "nsl_ptr_matrix.h"
#include <stddef.h>

nsl_neuron_data::nsl_neuron_data(const char* str,int fg) : 
	nsl_neuron_layer("neuron_data", str, fg) 
{
	nsl_string nstr;

	size_fg = 0;

	sprintf(nstr,"%s_mp",str);

     	m = new nsl_num_data(nstr,0,1); // requires a value

	sprintf(nstr,"%s_out",str);

     	M = new nsl_num_data(nstr,0,1);

	sprintf(nstr,"%s_site",str);

     	site_in = new nsl_site_data(nstr); // , 1

	set_abstract_type("data");
}


nsl_neuron_data::~nsl_neuron_data()
{
}

void nsl_neuron_data::init_pars()
{
	nsl_string sname;
	if (par != NULL)
	{
		for (int i = 0; i < par_size; i++)
		{
			sprintf(sname,"par%d",i);
			(*par)[0] = new nsl_num_data(sname);
		}
	}
	else
		cmd_error("neuron_data: NULL par");
}

int nsl_neuron_data::run()
{
	run_in();
	run_out();

	return 1;
}

int nsl_neuron_data::init()
{
	NSLadd_equal(*((nsl_num_data*) m),inp);
	NSLadd_equal(*((nsl_num_data*) M),inf);

	return 1;
}

int nsl_neuron_data::run_in()
{
	nsl_layer* site_layer;

	if (site_in != NULL && (site_layer = site_in->get_site_layer()) != NULL)
		site_in->run();
	else
	{
		cmd_out("nsl_neuron_data::run_in: NULL site_in");
		return 1;
	}

//	if (site_out != NULL)
//		site_out->run();
//	else
//		cmd_out("nsl_neuron_data::run_in: NULL site_out");

	NSLadd_minus(*((nsl_num_data*) site_layer),h);

	if (diff_model != NULL)
	{
		diff_model->set_tm(tm.elem());
		diff_model->set_dt(delta.elem());
		diff_model->run(m,site_layer);
	}
	else
		cmd_error("neuron_data::run: NULL diff model");

	return 1;
}

int nsl_neuron_data::run_out()
{
	if (thresh != NULL)
		thresh->run(M,m);
	else 
		cmd_error("neuron_data::run: NULL threshold library");

	return 1;
}
