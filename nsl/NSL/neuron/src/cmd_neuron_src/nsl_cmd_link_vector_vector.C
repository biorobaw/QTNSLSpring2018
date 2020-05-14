/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_vector_vector.C                 */
/*                                                            */
/**************************************************************/
#include "nsl_neuron.h"
#include "nsl_cmd_link_vector_vector.h"
#include "nsl_link_vector_vector.h"
#include "nsl_layer.h"
#include "nsl_neuron_layer.h"
#include "nsl_link_layer.h"
#include "nsl_base_list.h"
#include "nsl_site_layer.h"

extern void cmd_out(const char *);

nsl_cmd_link_vector_vector::nsl_cmd_link_vector_vector() : 
	nsl_cmd_link_vector()
{
	set_type("link_vector_vector");
}

nsl_cmd_link_vector_vector::~nsl_cmd_link_vector_vector()
{
}

int nsl_cmd_link_vector_vector::init_cmd_link_vector_vector()
{
	return set_cmd_link_vector_vector();
}
int nsl_cmd_link_vector_vector::set_cmd_link_vector_vector()
{
	return 0;
}
int nsl_cmd_link_vector_vector::create_link(nsl_layer* to, nsl_layer* from, 
	nsl_layer*, int sign)
{
	if (to == NULL || from == NULL)
	{
	     cmd_error("nsl_cmd_link_vector_vector::create_link: NULL layer");
	     return 0;
	}

	nsl_link_layer* link = new nsl_link_vector_vector(*from,*to,sign);
	nsl_site_layer* site_in;

	if ((site_in = ((nsl_neuron_layer*) to)->get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("nsl_cmd_link_vector_vector::create_link: NULL layer site");

	return 1;
}

// commands

int nsl_cmd_link_vector_vector::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_vector_vector::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_vector_vector::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_vector_vector::print_cmd_link_vector_vector(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_vector_vector::print(std::ostream& out) const // virtual
{
	print_cmd_link_vector_vector(out);
	return 1;
}

