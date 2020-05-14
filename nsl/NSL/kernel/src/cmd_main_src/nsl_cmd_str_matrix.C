/* SCCS  @(#)nsl_cmd_str_matrix.C	1.1---95/10/13--16:34:25 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_str_matrix.C                     */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_str_matrix.h"
#include "nsl_interpreter.h"

nsl_cmd_str_matrix::nsl_cmd_str_matrix() : nsl_cmd_matrix_layer("str_matrix")
{
}

nsl_cmd_str_matrix::~nsl_cmd_str_matrix()
{
}
int nsl_cmd_str_matrix::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_str_matrix::print_cmd_str_matrix(std::ostream& out) const
{
	print_cmd_matrix_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_str_matrix::print(std::ostream& out) const // virtual
{
	print_cmd_str_matrix(out);
	return 1;
}

