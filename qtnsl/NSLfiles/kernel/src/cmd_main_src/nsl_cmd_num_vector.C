/* SCCS  @(#)nsl_cmd_num_vector.C	1.1---95/10/13--16:34:08 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_num_vector.C                     */
/*                                                            */
/**************************************************************/

#include "nsl.h"
#include "nsl_cmd_num_vector.h"
#include "nsl_stream.h"
#include "nsl_model.h"
#include "nsl_num_vector.h"
#include "nsl_kernel.h"

nsl_cmd_num_vector::nsl_cmd_num_vector() : nsl_cmd_vector_layer("num_vector")
{
}

nsl_cmd_num_vector::~nsl_cmd_num_vector()
{
}
int nsl_cmd_num_vector::cmd_create(nsl_interpreter& nsl)
{
	nsl_string str;
	int size;

	nsl >> str; // layer name

	nsl >> size; // layer size

	nsl_num_vector* layer = new nsl_num_vector(str,0,NSL_ROW,size); //was (nsl_model*)0 -bn7
	nsl.add_object(layer);
	set_ptr(layer);

	return 1;
}
int nsl_cmd_num_vector::print_cmd_num_vector(std::ostream& out) const
{
	print_cmd_vector_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_num_vector::print(std::ostream& out) const // virtual
{
	print_cmd_num_vector(out);
	return 1;
}

