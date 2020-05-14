/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_vector.C                        */
/*                                                            */
/**************************************************************/
#include "nsl_neuron.h"
#include "nsl_cmd_link_vector.h"
#include "nsl_base_list.h"


nsl_cmd_link_vector::nsl_cmd_link_vector() : nsl_cmd_link_layer()
{
	set_type("link_vector");
}

nsl_cmd_link_vector::~nsl_cmd_link_vector()
{
}

int nsl_cmd_link_vector::init_cmd_link_vector()
{
	return set_cmd_link_vector();
}
int nsl_cmd_link_vector::set_cmd_link_vector()
{
	return 0;
}
int nsl_cmd_link_vector::create_link(nsl_layer*, nsl_layer*, nsl_layer*, int)
{
	return 0;
}

// commands

int nsl_cmd_link_vector::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_vector::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_vector::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_vector::print_cmd_link_vector(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_vector::print(std::ostream& out) const // virtual
{
	print_cmd_link_vector(out);
	return 1;
}

