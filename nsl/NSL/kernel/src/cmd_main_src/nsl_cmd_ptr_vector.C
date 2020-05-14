/* SCCS  @(#)nsl_cmd_ptr_vector.C	1.1---95/10/13--16:34:22 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_ptr_vector.C                     */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_ptr_vector.h"
#include "nsl_base_list.h"
#include "nsl_base.h"

nsl_cmd_ptr_vector::nsl_cmd_ptr_vector() : nsl_cmd_vector_layer("ptr_vector")
{
}

nsl_cmd_ptr_vector::~nsl_cmd_ptr_vector()
{
}
int nsl_cmd_ptr_vector::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_ptr_vector::print_cmd_ptr_vector(std::ostream& out) const
{
	print_cmd_vector_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_ptr_vector::print(std::ostream& out) const // virtual
{
	print_cmd_ptr_vector(out);
	return 1;
}

