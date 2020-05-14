/************************************/
/*         nsl_neuron_matrix.C      */
/************************************/

#include "nsl_neuron_matrix.h"
#include "nsl_num_library.h"
#include "nsl_num_matrix.h"
#include "nsl_matrix_math.h"
#include "nsl_thresh_library.h"
#include "nsl_neuron.h"
#include "nsl_num.h"


extern void cmd_error(const char *);

nsl_neuron_matrix::nsl_neuron_matrix(const char* str,int s1,int s2,int fg) : 
	nsl_neuron_layer("neuron_matrix",str,fg) 
{
	nsl_string nstr;

	size_fg = 2;
	size = new int[2];
	size[0] = s1; size[1] = s2;

	sprintf(nstr,"%s_mp",str);

     	m = new nsl_num_matrix(nstr,s1,s2,1);

	sprintf(nstr,"%s_out",str);

     	M = new nsl_num_matrix(nstr,s1,s2,1);

	sprintf(nstr,"%s_site",str);

     	site_in = new nsl_site_matrix(nstr,s1,s2); // ,1

	set_abstract_type("matrix");
}

nsl_neuron_matrix::~nsl_neuron_matrix()
{
}

void nsl_neuron_matrix::init_pars()
{
	nsl_string sname;
	if (par != NULL && size_fg == 1)
	{
		for (int i = 0; i < par_size; i++)
		{
			sprintf(sname,"par%d",i);
			(*par)[i] = new nsl_num_matrix(sname,size[0]);
		}
	}
	else
		cmd_error("neuron_matrix: NULL par and/or size");
}

int nsl_neuron_matrix::run()
{
	run_in();
	run_out();

	return 1;
}

//temp fix
extern void NSLadd_equal(nsl_num_2& out,const nsl_num_0& a);
extern void NSLadd_minus(nsl_num_2& out,const nsl_num_0& a);

int nsl_neuron_matrix::init()
{
	NSLadd_equal(*((nsl_num_2*) m),inp);
	NSLadd_equal(*((nsl_num_2*) M),inf); 	//changed nsl_Num_matrix to nsl_num_2 -bn7

	return 1;
}

int nsl_neuron_matrix::run_in()
{
	nsl_layer* site_layer;

	if (site_in != NULL && (site_layer = site_in->get_site_layer()) != NULL)
		site_in->run();
	else
	{
		cmd_out("nsl_neuron_matrix::run_in: NULL site_in");
		return 1;
	}

//	if (site_out != NULL)
//		site_out->run();
//	else
//		cmd_out("nsl_neuron_matrix::run_in: NULL site_out");

	NSLadd_minus(*((nsl_num_2*) site_layer),h); //chasnged num_matrix to matrix -bn7

	if (diff_model != NULL)
	{
		diff_model->set_tm(tm.elem());
		diff_model->set_dt(delta.elem());
		diff_model->run(m,site_layer);
	}
	else
		cmd_error("neuron_matrix::run: NULL diff model");

	return 1;
}

int nsl_neuron_matrix::run_out()
{
	if (thresh != NULL)
		thresh->run(M,m);
	else 
		cmd_error("neuron_matrix::run: NULL threshold library");

	return 1;
}
