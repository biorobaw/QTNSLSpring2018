/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_layer.C                         */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_neuron_include.h"

//try extern class first, if not use header to cmd_type_ functions
#include "nsl_neuron.h"
#include "nsl_cmd_link_layer.h"
#include "nsl_base.h"
#include "nsl_cmd_type.h"
#include "nsl_layer.h"
#include "nsl_base_list.h"

nsl_cmd_link_layer::nsl_cmd_link_layer() : nsl_cmd_layer()
{
	set_type("link_layer");
	set_abstract_type("link_layer");
}

nsl_cmd_link_layer::~nsl_cmd_link_layer()
{
}

int nsl_cmd_link_layer::init_cmd_link_layer()
{
	return set_cmd_link_layer();
}
int nsl_cmd_link_layer::set_cmd_link_layer()
{
	return 0;
}
int nsl_cmd_link_layer::create_link(nsl_layer*, nsl_layer*, nsl_layer*, int)
{
	return 0;
}

// commands

int nsl_cmd_link_layer::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_layer::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_layer::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_layer::print_cmd_link_layer(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_layer::print(std::ostream& out) const // virtual
{
	print_cmd_link_layer(out);
	return 1;
}

