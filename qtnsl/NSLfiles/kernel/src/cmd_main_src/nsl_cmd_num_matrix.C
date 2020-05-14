/* SCCS  @(#)nsl_cmd_num_matrix.C	1.1---95/10/13--16:34:20 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_num_matrix.C                     */
/*                                                            */
/**************************************************************/

#include "nsl.h"
#include "nsl_cmd_num_matrix.h"
#include "nsl_num_matrix.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"

nsl_cmd_num_matrix::nsl_cmd_num_matrix() : nsl_cmd_matrix_layer("num_matrix")
{
}

nsl_cmd_num_matrix::~nsl_cmd_num_matrix()
{
}
int nsl_cmd_num_matrix::cmd_create(nsl_interpreter& nsl)
{
	nsl_string str;
	int size1,size2;

	nsl >> str; // layer name

	nsl >> size1; // layer size1

	nsl >> size2; // layer size2

	nsl_num_matrix* layer = new 
		nsl_num_matrix(str,0,size1,size2,1); //added 1 to refer to proper constructor -bn7

// AW98 	nsl.add_object(layer);
	set_ptr(layer);

	return 1;
}
int nsl_cmd_num_matrix::print_cmd_num_matrix(std::ostream& out) const
{
	print_cmd_matrix_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_num_matrix::print(std::ostream& out) const // virtual
{
	print_cmd_num_matrix(out);
	return 1;
}

