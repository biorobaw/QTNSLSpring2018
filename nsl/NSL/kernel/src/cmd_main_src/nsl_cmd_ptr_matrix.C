/* SCCS  @(#)nsl_cmd_ptr_matrix.C	1.1---95/10/13--16:34:21 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_ptr_matrix.C                     */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_ptr_matrix.h"
#include "nsl_base.h"
#include "nsl_interpreter.h"

nsl_cmd_ptr_matrix::nsl_cmd_ptr_matrix() : nsl_cmd_matrix_layer("ptr_matrix")
{
}

nsl_cmd_ptr_matrix::~nsl_cmd_ptr_matrix()
{
}
int nsl_cmd_ptr_matrix::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_ptr_matrix::print_cmd_ptr_matrix(std::ostream& out) const
{
	print_cmd_matrix_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_ptr_matrix::print(std::ostream& out) const // virtual
{
	print_cmd_ptr_matrix(out);
	return 1;
}

