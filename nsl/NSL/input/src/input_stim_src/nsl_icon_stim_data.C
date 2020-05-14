/* SCCS  %W%---%E%--%U% */

//
//	nsl_icon_stim_data.c
//
#include "nsl_input.h"
#include "nsl_icon_stim_data.h"
#include "nsl_input_data.h"
#include "nsl_num_data.h"
#include "nsl_base.h"
#include "nsl_input_layer.h"
#include <stddef.h>

extern void cmd_out(const char *);
extern void cmd_error(const char *);

nsl_icon_stim_data::nsl_icon_stim_data(nsl_input_data* l) : nsl_stim_data(l)
{
	set_type("icon_stim_data");

	icon = 0;
}
nsl_icon_stim_data::~nsl_icon_stim_data()
{
}

int nsl_icon_stim_data::proc()
{
	nsl_input_data* Q;
	float k;

	if (m_parent != NULL)
		Q = (nsl_input_data*) m_parent->get_m_parent();
	else
		cmd_error("nsl_icon_stim_datax: NULL parent");
	
	if (Q != NULL)
	{
		k = (Q->get_input_layer()->get_overlapfg() == 1) ? 1.0 : 0.0;

        	Q->elem() = k*Q->elem() + icon->elem();
	}
	else
		cmd_error("nsl_icon_stim_data: NULL parent layer");
	
	return 1;
}

int nsl_icon_stim_data::print(std::ostream& out) const
{
	return print_icon_stim_data(out);
}
int nsl_icon_stim_data::print_icon_stim_data(std::ostream& out) const
{
 	if (icon != NULL)
		icon->print(out);
	else
		cmd_out("NULL icon");

	print_stim_data(out);

	return 1;
}
int nsl_icon_stim_data::print_status(std::ostream& out) const
{
	return print_icon_stim_data_status(out);
}
int nsl_icon_stim_data::print_icon_stim_data_status(std::ostream& out) const
{
	return print_stim_data_status(out);
}
 
