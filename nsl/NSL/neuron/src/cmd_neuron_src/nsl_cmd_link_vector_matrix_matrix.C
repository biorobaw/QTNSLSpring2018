/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_vector_matrix_matrix.C          */
/*                                                            */
/**************************************************************/

#include "nsl_neuron.h"

nsl_cmd_link_vector_matrix_matrix::nsl_cmd_link_vector_matrix_matrix() : 
	nsl_cmd_link_vector_matrix()
{
	set_type("link_vector_matrix_matrix");
}

nsl_cmd_link_vector_matrix_matrix::~nsl_cmd_link_vector_matrix_matrix()
{
}

int nsl_cmd_link_vector_matrix_matrix::init_cmd_link_vector_matrix_matrix()
{
	return set_cmd_link_vector_matrix_matrix();
}
int nsl_cmd_link_vector_matrix_matrix::set_cmd_link_vector_matrix_matrix()
{
	return 0;
}
int nsl_cmd_link_vector_matrix_matrix::create_link(nsl_layer* to, nsl_layer* from, nsl_layer* w, int sign)
{
	if (to == NULL || from == NULL || w == NULL)
	{
	    cmd_error("nsl_cmd_link_vector_matrix_matrix::create_link: NULL layer");
	    return 0;
	}

	nsl_link_layer* link = new nsl_link_vector_matrix_matrix(*from,*to,
		*w,sign);
	nsl_site_layer* site_in;

	if ((site_in = ((nsl_neuron_layer*) to)->get_site_in()) != NULL)
	    site_in->add_link(link);
	else
	    cmd_out("nsl_cmd_link_vector_matrix_matrix::create_link: NULL site");

	return 1;
}

// commands

int nsl_cmd_link_vector_matrix_matrix::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_vector_matrix_matrix::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_vector_matrix_matrix::print_cmd_link_vector_matrix_matrix(
	ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_vector_matrix_matrix::print(ostream& out) const // virtual
{
	print_cmd_link_vector_matrix_matrix(out);
	return 1;
}

