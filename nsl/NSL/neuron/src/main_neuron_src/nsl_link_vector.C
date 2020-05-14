/************************************/
/*       nsl_link_vector.C          */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_vector.h"
#include "nsl_base.h"
#include "nsl_layer.h"
#include "nsl_link_layer.h"
#include "nsl_num_vector.h"
#include <stddef.h>

using namespace std;

extern void cmd_out(const char *);
 
nsl_link_vector::nsl_link_vector(nsl_layer& f,nsl_layer& t,
	nsl_layer& w,int s) : nsl_link_layer(f,t,w,s)
{
	nsl_string str;

	sprintf(str,"%s_to_%s",f.get_name(),t.get_name());

	int sz = t.get_size(0);

	link_layer = new nsl_num_vector(str,sz,NSL_ROW,1);
}

nsl_link_vector::nsl_link_vector(nsl_layer& f,nsl_layer& t,int s) : 
	nsl_link_layer(f,t,s)
{
	nsl_string str;

	sprintf(str,"%s_to_%s",f.get_name(),t.get_name());

	int sz = t.get_size(0);

	link_layer = new nsl_num_vector(str,sz,NSL_ROW,1);
}

nsl_link_vector::~nsl_link_vector()
{
}

int nsl_link_vector::run()
{
//	print(cout);

	if (to != NULL)
		to->print(cout);
	else
		cmd_out("nsl_link_vector::run:from");

	if (from != NULL)
		from->print(cout);
	else
		cmd_out("nsl_link_vector::run:from");

	if (weight != NULL)
		weight->print(cout);
	else
		cmd_out("nsl_link_vector::run:weight");

//	mult_equal((nsl_num_vector*) link_vector,
//		(nsl_num_vector*) from->get_output(), weight);

	return 1;
}
