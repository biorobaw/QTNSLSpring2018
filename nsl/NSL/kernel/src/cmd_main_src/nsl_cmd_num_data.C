/* SCCS  @(#)nsl_cmd_num_data.C	1.1---95/10/13--16:33:30 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_num_data.C                       */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_num_data.h"
#include "nsl_num_data.h"
#include "nsl_base_list.h"
#include "nsl_interpreter.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"
nsl_cmd_num_data::nsl_cmd_num_data() : nsl_cmd_data_layer("num_data")
{
}

nsl_cmd_num_data::~nsl_cmd_num_data()
{
}
int nsl_cmd_num_data::cmd_create(nsl_interpreter& nsl)
{
	nsl_string str;

	nsl >> str; // layer name

	nsl_num_data* layer = new nsl_num_data(str); 
	nsl.add_object(layer);
	set_ptr(layer);

	return 1;
}
int nsl_cmd_num_data::print_cmd_num_data(std::ostream& out) const
{
	print_cmd_data_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_num_data::print(std::ostream& out) const // virtual
{
	print_cmd_num_data(out);
	return 1;
}

