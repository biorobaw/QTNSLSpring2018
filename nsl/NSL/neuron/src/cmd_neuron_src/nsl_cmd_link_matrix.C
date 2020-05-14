/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_matrix.C                        */
/*                                                            */
/**************************************************************/
#include "nsl_neuron.h"
#include "nsl_cmd_link_matrix.h"
#include "nsl_layer.h"
#include "nsl_base_list.h"

nsl_cmd_link_matrix::nsl_cmd_link_matrix() : nsl_cmd_link_layer()
{
	set_type("link_matrix");
}

nsl_cmd_link_matrix::~nsl_cmd_link_matrix()
{
}

int nsl_cmd_link_matrix::init_cmd_link_matrix()
{
	return set_cmd_link_matrix();
}
int nsl_cmd_link_matrix::set_cmd_link_matrix()
{
	return 0;
}
int nsl_cmd_link_matrix::create_link(nsl_layer*, nsl_layer*, nsl_layer*, int)
{
	return 0;
}

// commands

int nsl_cmd_link_matrix::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_matrix::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_matrix::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_matrix::print_cmd_link_matrix(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_matrix::print(std::ostream& out) const // virtual
{
	print_cmd_link_matrix(out);
	return 1;
}

