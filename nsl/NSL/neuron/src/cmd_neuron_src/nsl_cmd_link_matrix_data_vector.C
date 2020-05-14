/**************************************************************/
/*                                                            */
/*               nsl_cmd_link_matrix_data_vector.C            */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_link_matrix_data_vector.h"
#include "nsl_link_matrix_data_vector.h"
#include "nsl_neuron.h"

extern void cmd_error(const char *);
extern void cmd_out(const char *);

nsl_cmd_link_matrix_data_vector::nsl_cmd_link_matrix_data_vector() : 
	nsl_cmd_link_matrix_vector()
{
	set_type("link_matrix_data_vector");
}

nsl_cmd_link_matrix_data_vector::~nsl_cmd_link_matrix_data_vector()
{
}

int nsl_cmd_link_matrix_data_vector::init_cmd_link_matrix_data_vector()
{
	return set_cmd_link_matrix_data_vector();
}
int nsl_cmd_link_matrix_data_vector::set_cmd_link_matrix_data_vector()
{
	return 0;
}
int nsl_cmd_link_matrix_data_vector::create_link(nsl_layer* to, nsl_layer* from, 
	nsl_layer* w, int sign)
{
	if (to == NULL || from == NULL || w == NULL)
	{
	    cmd_error("nsl_cmd_link_matrix_data_vector::create_link: NULL layer");
	    return 0;
	}

	nsl_link_layer* link = new nsl_link_matrix_data_vector(*from,*to,*w,sign);
	nsl_site_layer* site_in;

	if ((site_in = ((nsl_neuron_layer*) to)->get_site_in()) != NULL)
	    site_in->add_link(link);
	else
	    cmd_out("nsl_cmd_link_matrix_data_vector::create_link: NULL site");

	return 1;
}

// commands

int nsl_cmd_link_matrix_data_vector::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_link_matrix_data_vector::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_link_matrix_data_vector::cmd_update(nsl_interpreter& nsl)
{
	cmd_type_update(nsl);

	return 1;
}

// local print

int nsl_cmd_link_matrix_data_vector::print_cmd_link_matrix_data_vector(
	ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_link_matrix_data_vector::print(ostream& out) const // virtual
{
	print_cmd_link_matrix_data_vector(out);
	return 1;
}

