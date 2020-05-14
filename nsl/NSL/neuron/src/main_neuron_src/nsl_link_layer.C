/************************************/
/*           nsl_link_layer.C       */
/************************************/
#include "nsl_neuron.h"
#include "nsl_link_layer.h"
#include "nsl_layer.h"

nsl_link_layer::nsl_link_layer(nsl_layer& f,nsl_layer& t,nsl_layer& w,int s)
{
	from = &f;
	to = &t;
	weight = &w;
	sign = s;
}
nsl_link_layer::nsl_link_layer(nsl_layer& f,nsl_layer& t,int s)
{
	from = &f;
	to = &t;
	weight = 0;
	sign = s;
}
nsl_link_layer::~nsl_link_layer()
{
}

