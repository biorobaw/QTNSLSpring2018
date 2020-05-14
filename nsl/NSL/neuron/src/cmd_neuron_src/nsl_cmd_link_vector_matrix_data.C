/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_vector_matrix_data.C            */
/*                                                            */
/**************************************************************/

#include "nsl_neuron.h"
#include <stddef.h>

extern void cmd_error(const char *);
extern void cmd_out(const char *);



nsl_cmd_link_vector_matrix_data::nsl_cmd_link_vector_matrix_data() : 
	nsl_cmd_link_vector_data()
{
	set_type("link_vector_matrix_data");
}

nsl_cmd_link_vector_matrix_data::~nsl_cmd_link_vector_matrix_data()
{
}

int nsl_cmd_link_vector_matrix_data::init_cmd_link_vector_matrix_data()
{
	return set_cmd_link_vector_matrix_data();
}
int nsl_cmd_link_vector_matrix_data::set_cmd_link_vector_matrix_data()
{
	return 0;
}
int nsl_cmd_link_vector_matrix_data::create_link(nsl_layer* to, nsl_layer* from, 
	nsl_layer* w, int sign)
{
	if (to == NULL || from == NULL || w == NULL)
	{
	  cmd_error("nsl_cmd_link_vector_matrix_data::create_link: NULL layer");
	  return 0;
	}

	nsl_link_layer* link = new nsl_link_vector_matrix_data(*from,*to,
		*w,sign);
	nsl_site_layer* site_in;

	if ((site_in = ((nsl_neuron_layer*) to)->get_site_in()) != NULL)
	    site_in->add_link(link);
	else
	    cmd_out("nsl_cmd_link_vector_matrix_data::create_link: NULL site");

	return 1;
}

// commands

int nsl_cmd_link_vector_matrix_data::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_vector_matrix_data::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_data::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_vector_matrix_data::print_cmd_link_vector_matrix_data(
	std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_vector_matrix_data::print(std::ostream& out) const // virtual
{
	print_cmd_link_vector_matrix_data(out);
	return 1;
}

