/* SCCS  @(#)nsl_input_layer.C	1.1---95/08/13--20:55:05 */
//
//	nsl_input_layer.c
//

#include "nsl_input.h"

extern void cmd_out(const char *, const char *);
extern void cmd_out(const char *, int);

nsl_input_layer::nsl_input_layer(const char* str,nsl_layer* l,int rfg)
	: nsl_public(rfg)
{
	set_type("input_layer");
	set_name(str);
	
	m_parent=l;
	
 	overlap_fg = NSL_OFF;

	stim_total = 0;
	stim_list = new nsl_list("stim");

	m_children_list->append(stim_list);
}
nsl_input_layer::~nsl_input_layer()
{
}
int nsl_input_layer::reset(nsl_buffer*)
{
	stim_total = 0;
	stim_list = new nsl_list;

	return 1;
}
int nsl_input_layer::run()
{
 	if (stim_list != NULL)
	{
	   stim_list->wind_up();
	   nsl_stim* stim_obj;
	   while (stim_obj = (nsl_stim*)stim_list->next())
	   {
	    	if (stim_obj->get_able_fg() == 0)
			continue;

		stim_obj->run();
	   }
	}
	else
	   cmd_out("NULL 'stim_list'");

	return 1;
}
int nsl_input_layer::add_stim(nsl_stim* obj)
{
	obj->set_index(++stim_total);
	stim_list->append(obj);
	obj->set_m_parent(this);

	return stim_total;
}
nsl_stim* nsl_input_layer::get_stim(int i)
{
	if (stim_list != NULL)
	{
	   stim_list->wind_up();
	   nsl_stim* stim_obj;
	   while (stim_obj = (nsl_stim*)stim_list->next())
	   {
		if (stim_obj->get_index() == i)
			return stim_obj;
	   }
	   cmd_out("NULL stim_obj: ",i);
	}
	else
	   cmd_out("NULL 'stim_list'");

	return (nsl_stim*) 0;
}
nsl_stim* nsl_input_layer::get_stim(char* str)
{
	if (stim_list != NULL)
	{
	   stim_list->wind_up();
	   nsl_stim* stim_obj;
	   while (stim_obj = (nsl_stim*)stim_list->next())
	   {
		if (strcmp(stim_obj->get_name(),str) == 0)
			return stim_obj;
	   }
	   cmd_out("NULL stim_obj: ",str);
	}
	else
	   cmd_out("NULL 'stim_list'");

	return (nsl_stim*) 0;
}

int nsl_input_layer::print_status(ostream& out) const
{
	return print_input_layer_status(out);
}
int nsl_input_layer::print_input_layer_status(ostream& out) const
{
	out << "// stim_total: " << stim_total << "\n";
	out.flush();
 
	return 1;
}
int nsl_input_layer::print(ostream& out) const
{
	if (overlap_fg == 1)
		out << "set input_layer overlap ON\n";
	else
		out << "set input_layer overlap OFF\n";

	out.flush();

	return print_input_layer(out);
}
int nsl_input_layer::print_input_layer(ostream& out) const
{
	if (stim_list != NULL)
	   stim_list->print_all(out);
	else
	   cmd_out("NULL 'stim_list'");

	return 1;
}
int nsl_input_layer::print(ostream& out,int i) const
{
	if (overlap_fg == 1)
		out << "set stim overlap ON\n";
	else
		out << "set stim overlap OFF\n";

	out.flush();

	return print_input_layer(out,i);
}
int nsl_input_layer::print_input_layer(ostream& out,int i) const
{
	nsl_stim* obj;

	if (stim_list != NULL)
	{
	   if ((obj = (nsl_stim*) stim_list->get_by_index(i)) != NULL)
	   	obj->print(out);
	   else
		cmd_error("NULL stim obj: ",i);

	}
	else
	   cmd_out("NULL 'stim_list'");

	return 1;
}
