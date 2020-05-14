/* SCCS  %W%---%E%--%U% */
//
//	xnsl_system.c
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_system::xnsl_system() : xnsl_xpublic("xsystem")
{
	XSYSTEM = this;

 	argc_ptr = 0;
	argv_ptr = 0;

	server_fg = NSL_OFF;

	nsl_graph_list = new nsl_list; 
	graph_total = 0;

	MANAGER = new xnsl_manager;

	XSYSTEM->set_manager(MANAGER);
}
xnsl_system::~xnsl_system()
{
}
int xnsl_system::create()
{
	return create_system();
}
int xnsl_system::create_system()
{
	INTERFACE = new xnsl_window_interface("XNSL");

	return 1;
}
int xnsl_system::display()
{
	if (INTERFACE != NULL)
		INTERFACE->display();

	return 1;
}

// graphs

int xnsl_system::add_graph(const char* gname)
{
        if (nsl_graph_list != NULL)
        {
		nsl_num_0* graph = new nsl_num_0;
		graph->set_name(gname);
		graph->set_index(++graph_total);
		nsl_graph_list->append(graph);
	}

	return graph_total;
}
int xnsl_system::get_graph(const char* str)
{
        if (nsl_graph_list != NULL)
        {
   	    nsl_num_0* graph;
	    if ((graph = (nsl_num_0*)nsl_graph_list->get_by_name(str)) != NULL)
      		return graph->get_index();
        }
        else
           cmd_out("NULL 'nsl_graph_list'");

        return 0;
}

// print  

int xnsl_system::print(ostream& out) const
{
	out << "\n// window_interface:\n";

	if (INTERFACE != NULL)
		INTERFACE->print(out);

 	return 1;
}
int xnsl_system::print_status(ostream& out) const
{
	out << "\n// total graph: " << graph_total << "\n";
 
        if (nsl_graph_list != NULL)
        {
	    nsl_graph_list->wind_up();
	    nsl_num_0* graph;
	    while (graph = (nsl_num_0*)nsl_graph_list->next()) 
                graph->print_status(cout);
        }
        else
           cmd_out("NULL 'nsl_graph_list'");

	out << "\n// window_interface:\n";

	if (INTERFACE != NULL)
		INTERFACE->print_status(out);

	out.flush();

	return 1;
}

int xnsl_system::output(char* str)
{
	if (INTERFACE != NULL)
		INTERFACE->output(str);
	else
		cmd_error("xnsl_system: NULL INTERFACE");

	return 1;
}
