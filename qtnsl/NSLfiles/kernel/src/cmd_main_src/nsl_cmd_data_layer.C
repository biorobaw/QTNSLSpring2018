/* SCCS  @(#)nsl_cmd_data_layer.C	1.1---95/10/13--16:34:18 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_data_layer.C                     */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_data_layer.h"
#include "nsl_interpreter.h"

nsl_cmd_data_layer::nsl_cmd_data_layer() : nsl_cmd_layer("data_layer")
{
}
nsl_cmd_data_layer::nsl_cmd_data_layer(const char* str) : nsl_cmd_layer(str)
{
}

nsl_cmd_data_layer::~nsl_cmd_data_layer()
{
}
int nsl_cmd_data_layer::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_data_layer::cmd_elem(nsl_interpreter& nsl)
{
	return cmd_assign(nsl);
}
int nsl_cmd_data_layer::print_cmd_data_layer(std::ostream& out) const
{
	print_cmd_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_data_layer::print(std::ostream& out) const // virtual
{
	print_cmd_data_layer(out);
	return 1;
}

