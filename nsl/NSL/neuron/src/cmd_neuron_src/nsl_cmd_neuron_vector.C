/**************************************************************/
/*                                                            */
/*               nsl_cmd_neuron_vector.C                      */
/*                                                            */
/**************************************************************/

#include "nsl.h"
#include "nsl_neuron.h"
#include "nsl_cmd_neuron_vector.h"
#include "nsl_neuron_vector.h"
#include "nsl_base.h"
#include "nsl_base_list.h"
#include "nsl_interpreter.h"

extern void cmd_error(const char *);

nsl_cmd_neuron_vector::nsl_cmd_neuron_vector() : nsl_cmd_neuron_layer()
{
	set_type("neuron_vector");
	set_abstract_type("vector"); // used in generating links
}

nsl_cmd_neuron_vector::~nsl_cmd_neuron_vector()
{
}

int nsl_cmd_neuron_vector::init_cmd_neuron_vector()
{
	return set_cmd_neuron_vector();
}
int nsl_cmd_neuron_vector::set_cmd_neuron_vector()
{
	return 0;
}

// commands

int nsl_cmd_neuron_vector::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_connect(nsl_interpreter& nsl)
{
/*	nsl_string to_str, from_str, w_str, layer_type, link_type;
	nsl_layer *to_layer,*from_layer,*w_layer;
	nsl_base* pbase;
	int fg; // +1/-1

	nsl >> from_str; // from neuron

	if ((from_layer = SYSTEM->get_model()->get_layer(from_str)) == NULL)
		return 0;

	from_layer->print_status(cout);

	if (nsl.get_str_cnt() > 1)
 	{
		nsl >> w_str;
		if ((w_layer = SYSTEM->get_model()->get_layer(w_str)) == NULL)
			return 0;

		w_layer->print_status(cout);

		sprintf(link_type,"link_%s_%S_%S",
				to_layer->get_abstract_type(),
				w_layer->get_abstract_type(),
				from_layer->get_abstract_type());
	}

	if (nsl.get_str_cnt() > 0)
		nsl >> fg;
	else
		fg = 1;

	if (w_layer != NULL)
		NSLconnect(*to_layer,*from_layer,*w_layer,fg);
	else
		NSLconnect(*to_layer,*from_layer,fg);
*/		
	return 1;
}
int nsl_cmd_neuron_vector::cmd_create(nsl_interpreter& nsl)
{
	nsl_string str;
	int s;

	nsl >> str; // vector name

	nsl >> s; // vector size

	nsl_neuron_vector* neuron = new nsl_neuron_vector(str,s,2);

	if (neuron == NULL)
	{
		cmd_error("cmd_neuron_vector:cmd_create: CANNOT create neuron");
		return 0;
	}

	set_ptr(neuron);

//	nsl.add_object(neuron); // eq to option 2 in constructor in nsl_layer 

	nsl_layer* layer;

	if ((layer = neuron->get_m()) != NULL)
		nsl.add_object(layer); // add mp to obj list
	else
		cmd_error("cmd_neuron_vector::cmd_create: NULL neuron mp");

	if ((layer = neuron->get_M()) != NULL) // add out to obj list
		nsl.add_object(layer);
	else
		cmd_error("cmd_neuron_vector::cmd_create: NULL neuron out");

	return 1;
}
int nsl_cmd_neuron_vector::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_neuron_vector::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_neuron_vector::cmd_update(nsl_interpreter& nsl)
{
	nsl_cmd_neuron_layer::cmd_update(nsl);

	return 1;
}

// local print

int nsl_cmd_neuron_vector::print_cmd_neuron_vector(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_neuron_vector::print(std::ostream& out) const // virtual
{
	print_cmd_neuron_vector(out);
	return 1;
}

