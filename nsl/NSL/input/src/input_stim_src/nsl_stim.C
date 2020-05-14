/* SCCS  @(#)nsl_stim.C	1.1---95/08/13--20:55:07 */
//
//	nsl_stim.c
//
#include "nsl_input.h"
#include "nsl_time_interval.h"
#include "nsl_base_list.h"


nsl_stim::nsl_stim(nsl_layer* l)
{
	set_type("stim");
	set_abstract_type("stim");
		
	m_parent = l; // input_layer parent
	
	time_total = 0;
	time_list = new nsl_list("time_interval");

	m_children_list->append(time_list);

	val = 1.0;
//	stim_type = NSL_BLOCK;
	spec_type = NSL_CORNER;
 	add_fg = 0; // not used
	mode = 0;
	step = 1;
}
nsl_stim::~nsl_stim()
{
}

int nsl_stim::add_time_interval(nsl_time_interval* obj)
{
 	obj->set_index(++time_total);
	time_list->append(obj);
 	obj->set_m_parent(this);

	return time_total;
}

int nsl_stim::proc()
{
	return 1;
}

int nsl_stim::run()
{
 	return 1;
}

int nsl_stim::print(std::ostream& out) const
{
	return print_stim(out);
}
int nsl_stim::print_stim(std::ostream& out) const
{
//	print_base(out);

  	if (spec_type == NSL_CORNER) 
	   out << "set stim spec_type CORNER\n";
	else // if (spec_type == 0)
	   out << "set stim spec_type CENTER\n";
  	if (mode == 1) 
	   out << "set stim interval ON\n";
	else // if (mode == 0)
	   out << "set stim interval OFF\n";
	out << "set stim step " << step << "\n";

 	time_list->wind_up();
	nsl_time_interval* obj;
	while (obj = (nsl_time_interval*)time_list->next())
	   obj->print(out);

	return 1;
}
int nsl_stim::print_status(std::ostream& out) const
{
	return print_stim_status(out);
}
int nsl_stim::print_stim_status(std::ostream& out) const
{
	print_base_status(out);
	out << "// time_interval_total:\t" << time_total << "\n";
	out.flush();

	return 1;
}
