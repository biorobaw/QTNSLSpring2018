/* SCCS  @(#)nsl_cmd_str_data.C	1.1---95/10/13--16:33:38 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_str_data.C                       */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_str_data.h"
#include "nsl_base_list.h"

nsl_cmd_str_data::nsl_cmd_str_data() : nsl_cmd_data_layer("str_data")
{
}

nsl_cmd_str_data::~nsl_cmd_str_data()
{
}
int nsl_cmd_str_data::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_str_data::print_cmd_str_data(std::ostream& out) const
{
	print_cmd_data_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_str_data::print(std::ostream& out) const // virtual
{
	print_cmd_str_data(out);
	return 1;
}

