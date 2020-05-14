/************************************/
/*            nsl_site_layer.C      */
/************************************/
#include "nsl_neuron.h"
#include "nsl_site_layer.h"
#include "nsl_link_layer.h"

nsl_site_layer::nsl_site_layer(const char* ltype, const char* lname) : 
	nsl_layer(ltype,lname)
{
}
nsl_site_layer::~nsl_site_layer()
{
}

void nsl_site_layer::add_link(nsl_link_layer* link)
{
	link_list.append((nsl_link_layer*) link);
}
/*
nsl_link_layer* nsl_site_layer::del_link()
{
	return NULL;
}
*/
