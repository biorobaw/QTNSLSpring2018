/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_data.C                          */
/*                                                            */
/**************************************************************/
#include "nsl_neuron.h"
#include "nsl_cmd_link_data.h"
#include "nsl_layer.h"
#include "nsl_base_list.h"

nsl_cmd_link_data::nsl_cmd_link_data() : nsl_cmd_link_layer()
{
	set_type("link_data");
}

nsl_cmd_link_data::~nsl_cmd_link_data()
{
}

int nsl_cmd_link_data::init_cmd_link_data()
{
	return set_cmd_link_data();
}
int nsl_cmd_link_data::set_cmd_link_data()
{
	return 0;
}
int nsl_cmd_link_data::create_link(nsl_layer*, nsl_layer*, nsl_layer*, int)
{
	return 0;
}

// commands

int nsl_cmd_link_data::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_data::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_data::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_data::print_cmd_link_data(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_data::print(std::ostream& out) const // virtual
{
	print_cmd_link_data(out);
	return 1;
}

