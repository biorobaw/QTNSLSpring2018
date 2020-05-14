/************************************/
/*         nsl_neuron_vector.C      */
/************************************/

#include "nsl_num.h"
#include "nsl_neuron_vector.h"
#include "nsl_num_vector.h"
#include "nsl_neuron.h"
#include "nsl_num_library.h"
#include "nsl_diff.h"
#include "nsl_ptr_vector.h"
#include "nsl_site_vector.h"

nsl_neuron_vector::nsl_neuron_vector(const char* str,int s,int fg) : 
	nsl_neuron_layer("neuron_vector",str,fg) 
{
	nsl_string nstr;

	size_fg = 1;
	size = new int[1];
	size[0] = s;

	sprintf(nstr,"%s_mp",str);

     	m = new nsl_num_vector(nstr,s,NSL_ROW,1);

	sprintf(nstr,"%s_out",str);

     	M = new nsl_num_vector(nstr,s,NSL_ROW,1);

	sprintf(nstr,"%s_site",str);

     	site_in = new nsl_site_vector(nstr,s); // ,1

	set_abstract_type("vector");
}

nsl_neuron_vector::~nsl_neuron_vector()
{
}

void nsl_neuron_vector::init_pars()
{
	nsl_string sname;
	if (par != NULL && size_fg == 1)
	{
		for (int i = 0; i < par_size; i++)
		{
			sprintf(sname,"par%d",i);
			(*par)[i] = new nsl_num_vector(sname,size[0]);
		}
	}
	else
		cmd_error("neuron_vector: NULL par and/or size");
}

int nsl_neuron_vector::run()
{
	run_in();
	run_out();

	return 1;
}
//temp fix -bn7


int nsl_neuron_vector::init()
{
	NSLadd_equal(*((nsl_num_vector*) m),inp);
	NSLadd_equal(*((nsl_num_vector*) M),inf);

	return 1;
}


int nsl_neuron_vector::run_in()
{
	nsl_layer* site_layer;

	if (site_in != NULL && (site_layer = site_in->get_site_layer()) != NULL)
		site_in->run();
	else
	{
		cmd_out("nsl_neuron_vector::run_in: NULL site_in");
		return 1;
	}

//	if (site_out != NULL)
//		site_out->run();
//	else
//		cmd_out("nsl_neuron_vector::run_in: NULL site_out");

	NSLadd_minus(*((nsl_num_vector*) site_layer),h);

	if (diff_model != NULL)
	{
		diff_model->set_tm(tm.elem());
		diff_model->set_dt(delta.elem());
		diff_model->run(m,site_layer);
	}
	else
		cmd_error("neuron_vector::run: NULL diff model");

	return 1;
}

int nsl_neuron_vector::run_out()
{
	if (thresh != NULL)
		thresh->run(M,m);
	else 
		cmd_error("neuron_vector::run: NULL threshold library");

	return 1;
}
