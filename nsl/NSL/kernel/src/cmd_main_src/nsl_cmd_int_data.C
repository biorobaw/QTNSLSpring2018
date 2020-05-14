/* SCCS  @(#)nsl_cmd_int_data.C	1.1---95/10/13--16:33:20 */

/**************************************************************/
/*                                                            */
/*                   nsl_cmd_int_data.C                       */
/*                                                            */
/**************************************************************/
#include "nsl_cmd_int_data.h"
#include "nsl_base_list.h"
#include "nsl_base.h"
#include "nsl_kernel.h"
typedef nsl_base_list nsl_list;

nsl_cmd_int_data::nsl_cmd_int_data() : nsl_cmd_data_layer("int_data")
{
}

nsl_cmd_int_data::~nsl_cmd_int_data()
{
}
int nsl_cmd_int_data::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_int_data::print_cmd_int_data(std::ostream& out) const
{
	print_cmd_data_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_int_data::print(std::ostream& out) const // virtual
{
	print_cmd_int_data(out);
	return 1;
}

