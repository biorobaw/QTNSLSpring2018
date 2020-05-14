//
//	nsl_library.C
//

#include "nsl_library.h"
#include "nsl_layer.h"
#include "nsl_ptr_vector.h"
#include <stddef.h>

//extern void cmd_error(const char *);

nsl_library::nsl_library(const char* lname,int size,int fg) : nsl_public(lname)
{
	par_size = size;
	if (par_size > 0)
		par = new nsl_ptr_vector("par",par_size);
}

nsl_library::~nsl_library()
{
	delete[] par;
}

void nsl_library::set_par(int i,nsl_layer* p) 
{ 
	if (par != NULL && (*par)[i] != NULL)
		(*par)[i] = p; 
	else
		cmd_error("neuron_layer::set_par: BAD par: ",i);
}
nsl_layer* nsl_library::get_par(int i) 
{
	if (par != NULL && (*par)[i] != NULL)
		return (nsl_layer*) (*par)[i];
	else
	{
		cmd_error("neuron_layer::get_par: BAD par: ",i);
		return 0;
	}
}

