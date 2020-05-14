/************************************/
/*         nsl_neuron_layer.C       */
/************************************/
#include "nsl_neuron.h"
#include "nsl_neuron_layer.h"
#include "nsl_diff_method.h"
#include "nsl_diff.h"
#include "nsl_ptr_vector.h"

nsl_neuron_layer::nsl_neuron_layer(const char* ltype, const char* lname, int fg) : nsl_layer(ltype, lname, 0, fg) //todo: ??? no such constructor nsl_layer(char char int)
{
//	set_type("neuron_layer");
	set_base_type("layer"); // this used for look up in "assign" command
	set_abstract_type("neuron");

	h = 0;
	inp = 0;
	inf = 0;
}
nsl_neuron_layer::~nsl_neuron_layer()
{

}

void nsl_neuron_layer::set_diff_method(nsl_diff_method* lib)
{
	if (diff_model != NULL)
		diff_model->set_diff_method(lib);
	else
		cmd_error("neuron_layer::set_diff_method: NULL diff_model");
}

nsl_diff_method* nsl_neuron_layer::get_diff_method()
{
	nsl_diff_method* mdiff = 0;

	if (diff_model != NULL)
		mdiff = diff_model->get_diff_method();
	else
		cmd_error("neuron_layer::get_diff_method: NULL diff_model");

	return mdiff;
}

void nsl_neuron_layer::init_par(int i)
{
	if (par != NULL) // delete old par values and types
		delete par;
	par = new nsl_ptr_vector("par",i);
	append_m_child(par);
}
void nsl_neuron_layer::set_par(int i,nsl_layer* p) 
{ 
	if (par != NULL && (*par)[i] != NULL)
		(*par)[i] = p; 
	else
		cmd_error("neuron_layer::set_par: BAD par: ",i);
}
nsl_layer* nsl_neuron_layer::get_par(int i) 
{ 
	if (par != NULL && (*par)[i] != NULL)
		return (nsl_layer*) (*par)[i];
	else
	{
		cmd_error("neuron_layer::get_par: BAD par: ",i);
		return 0;
	}
}


int nsl_neuron_layer::print(ostream& out) const
{
	if (m != NULL)
		m->print(out);
	else
		cmd_out("nsl_neuron_layer::print: NULL m");

	if (M != NULL)
		M->print(out);
	else
		cmd_out("nsl_neuron_layer::print: NULL M");

	return 1;
}

