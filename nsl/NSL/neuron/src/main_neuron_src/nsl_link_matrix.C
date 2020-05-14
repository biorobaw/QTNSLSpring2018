/************************************/
/*       nsl_link_matrix.C          */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_matrix.h"
#include "nsl_num_matrix.h"
#include "nsl_layer.h"

nsl_link_matrix::nsl_link_matrix(nsl_layer& f,nsl_layer& t,
	nsl_layer& w,int s) : nsl_link_layer(f,t,w,s)
{
	nsl_string str;

	sprintf(str,"%s_to_%s",f.get_name(),t.get_name());

	int s1 = t.get_size(0);
	int s2 = t.get_size(1);

	link_layer = new nsl_num_matrix(str,s1,s2,1);
}

nsl_link_matrix::nsl_link_matrix(nsl_layer& f,nsl_layer& t,int s) : 
	nsl_link_layer(f,t,s)
{
	nsl_string str;

	sprintf(str,"%s_to_%s",f.get_name(),t.get_name());

	int s1 = t.get_size(0);
	int s2 = t.get_size(1);

	link_layer = new nsl_num_matrix(str,s1,s2,1);
}

nsl_link_matrix::~nsl_link_matrix()
{
}

int nsl_link_matrix::run()
{
//	print(cout);

	if (to != NULL)
		to->print(cout);
	else
		cmd_out("nsl_link_matrix::run:from");

	if (from != NULL)
		from->print(cout);
	else
		cmd_out("nsl_link_matrix::run:from");

	if (weight != NULL)
		weight->print(cout);
	else
		cmd_out("nsl_link_matrix::run:weight");

//	mult_equal((nsl_num_matrix*) link_matrix,
//		(nsl_num_matrix*) from->get_output(), weight);

	return 1;
}
