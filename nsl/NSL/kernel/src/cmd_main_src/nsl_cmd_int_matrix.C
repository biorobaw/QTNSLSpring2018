/* SCCS  @(#)nsl_cmd_int_matrix.C	1.1---95/10/13--16:34:19 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_int_matrix.C                     */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_cmd_int_matrix.h"
#include "nsl_base.h"
#include "nsl_base_list.h"
#include "nsl_kernel.h"
nsl_cmd_int_matrix::nsl_cmd_int_matrix() : nsl_cmd_matrix_layer("int_matrix")
{
}

nsl_cmd_int_matrix::~nsl_cmd_int_matrix()
{
}
int nsl_cmd_int_matrix::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_int_matrix::print_cmd_int_matrix(std::ostream& out) const
{
	print_cmd_matrix_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_int_matrix::print(std::ostream& out) const // virtual
{
	print_cmd_int_matrix(out);
	return 1;
}

