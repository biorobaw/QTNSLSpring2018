/************************************/
/*       nsl_link_data.C            */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_data.h"
#include "nsl_num_data.h"
#include "nsl_layer.h"

nsl_link_data::nsl_link_data(nsl_layer& f,nsl_layer& t,nsl_layer& w,int s) : 
	nsl_link_layer(f,t,w,s)
{
	nsl_string str;

	sprintf(str,"%s_to_%s",f.get_name(),t.get_name());

	link_layer = new nsl_num_data(str,0,1);
}

nsl_link_data::nsl_link_data(nsl_layer& f,nsl_layer& t,int s) : 
	nsl_link_layer(f,t,s)
{
	nsl_string str;

	sprintf(str,"%s_to_%s",f.get_name(),t.get_name());

	link_layer = new nsl_num_data(str,0,1);
}

nsl_link_data::~nsl_link_data()
{
}

int nsl_link_data::run()
{
	return 1;
}
