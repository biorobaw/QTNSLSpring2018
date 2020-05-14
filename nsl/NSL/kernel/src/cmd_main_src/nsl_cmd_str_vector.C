/* SCCS  @(#)nsl_cmd_str_vector.C	1.1---95/10/13--16:34:26 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_str_vector.C                     */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_kernel.h"
#include "nsl_cmd_str_vector.h"
#include "nsl_base_list.h"

nsl_cmd_str_vector::nsl_cmd_str_vector() : nsl_cmd_vector_layer("str_vector")
{
}

nsl_cmd_str_vector::~nsl_cmd_str_vector()
{
}
int nsl_cmd_str_vector::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_str_vector::print_cmd_str_vector(std::ostream& out) const
{
	print_cmd_vector_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_str_vector::print(std::ostream& out) const // virtual
{
	print_cmd_str_vector(out);
	return 1;
}

