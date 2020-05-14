/* SCCS  @(#)nsl_cmd_int_vector.C	1.1---95/10/13--16:34:01 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_int_vector.C                     */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_cmd_int_vector.h"
#include "nsl_base_list.h"
#include "nsl_kernel.h"
nsl_cmd_int_vector::nsl_cmd_int_vector() : nsl_cmd_vector_layer("int_vector")
{
}

nsl_cmd_int_vector::~nsl_cmd_int_vector()
{
}
int nsl_cmd_int_vector::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_int_vector::print_cmd_int_vector(std::ostream& out) const
{
	print_cmd_vector_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_int_vector::print(std::ostream& out) const // virtual
{
	print_cmd_int_vector(out);
	return 1;
}

