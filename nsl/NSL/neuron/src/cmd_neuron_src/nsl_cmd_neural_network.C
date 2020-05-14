/**************************************************************/
/*                                                            */
/*               nsl_cmd_neural_network.C                     */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_neural_network.h"
#include "nsl_neural_network.h"
#include "nsl_model.h"
#include "nsl_base.h"
#include "nsl_base_list.h"
#include "nsl_neuron.h"
#include "nsl_interpreter.h"
#include "nsl_system.h"
#include "nsl.h"

typedef nsl_base_list nsl_list;

extern void cmd_out(const char *);


nsl_cmd_neural_network::nsl_cmd_neural_network() : nsl_cmd_model()
{
	set_type("neural_network");
	set_abstract_type("model");
	set_base_type("model");
}

nsl_cmd_neural_network::~nsl_cmd_neural_network()
{
}

int nsl_cmd_neural_network::init_cmd_neural_network()
{
	return set_cmd_neural_network();
}
int nsl_cmd_neural_network::set_cmd_neural_network()
{
 	return 1;
}

// commands

int nsl_cmd_neural_network::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_connect(nsl_interpreter& nsl)
{
	nsl_string to_str, from_str, w_str, link_type;
	nsl_layer *to_layer,*from_layer,*w_layer;
	nsl_base* pbase;
	int fg; // +1/-1

	w_layer = NULL; 

	nsl >> to_str; // to neuron
/*
	if ((to_layer = ((nsl_model*) OBJ)->get_layer(to_str)) == NULL) //TODO: what is get_layer supposed to do ? undefined -bn7
		return 0;

	nsl >> from_str; // from neuron

	if ((from_layer = ((nsl_model*) OBJ)->get_layer(from_str)) == NULL)	//get_layer
		return 0;

	if (nsl.get_str_cnt() > 1)
 	{
		nsl >> w_str;
		if ((w_layer = ((nsl_model*) OBJ)->get_layer(w_str)) == NULL)
			return 0;

		sprintf(link_type,"link_%s_%s_%s",
				from_layer->get_abstract_type(),
				w_layer->get_abstract_type(),
				to_layer->get_abstract_type());
	}
	else
	{
		sprintf(link_type,"link_%s_%s",
				from_layer->get_abstract_type(),
				to_layer->get_abstract_type());
	}
*/
	if (nsl.get_str_cnt() > 0)
		nsl >> fg;
	else
		fg = 1;

        if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		get_mi_by_type(link_type)) != NULL)
	{
		((nsl_cmd_link_layer*) pbase)->create_link(to_layer,
			from_layer,w_layer,fg);
 	}
	else
		 cmd_error("cmd_neural_network: Bad type ",link_type);

	return 1;
}
int nsl_cmd_neural_network::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_create(nsl_interpreter& nsl)
{
	nsl_string str;

	nsl >> str; // network name

	nsl_neural_network* nn = new nsl_neural_network(str,2);
//	nsl.add_object(nn); // option 2 above does this in nsl_model
	set_ptr(nn);

	// all this should be taken out by having everything under cmd_model
	// instead of here
	nsl_cmd_buf* CMD_SHELL;
	nsl_cmd_model* cmd_model;
	nsl_list* type_list;
	if ((CMD_SHELL = (nsl_cmd_buf*) 
		nsl.get_shell_list()->get_top()) != NULL)
	{
		type_list = CMD_SHELL->get_type_list();
		cmd_model = (nsl_cmd_model*) type_list->get_mi_by_type("model");
		if (cmd_model != NULL)
			cmd_model->set_ptr(nn);
		else
			cmd_out("nsl_cmd_neural_network: NULL cmd_model");
	}
	else
		cmd_out("nsl_cmd_neural_network: NULL CMD SHELL");

	return 1;
}
int nsl_cmd_neural_network::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_run(nsl_interpreter& nsl)
{
	nsl_cmd_model::cmd_run(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_neural_network::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_neural_network::cmd_update(nsl_interpreter& nsl)
{
	nsl_cmd_model::cmd_update(nsl);

	return 1;
}

// local print

int nsl_cmd_neural_network::print_cmd_neural_network(ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_neural_network::print(ostream& out) const // virtual
{
	print_cmd_neural_network(out);
	return 1;
}

