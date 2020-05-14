/* SCCS  @(#)xnsl_system.h	1.1---95/08/13--23:41:21 */
//
// 	xnsl_system.h
//
#ifndef _XNSL_SYSTEM_H
#define _XNSL_SYSTEM_H
#include "xnsl_xpublic.h"
class xnsl_window_interface;
class xnsl_manager;
class xnsl_system : public xnsl_xpublic
{
// system
	int* argc_ptr;
	char** argv_ptr;
	
// interface
	on_off_enum server_fg;
	xnsl_manager* MANAGER;
	xnsl_window_interface* INTERFACE; // pointer to all models

// graph list
	int graph_total;		// total number of graph types
	nsl_list* nsl_graph_list;	// pointer to all graph types
public:
		xnsl_system();
		~xnsl_system();

	virtual int 	create();
	int 	create_system();
// system
	void set_argc_ptr(int* ptr) { argc_ptr = ptr; }
	int* get_argc_ptr() { return argc_ptr; }
	void set_argv_ptr(char** ptr) { argv_ptr = ptr; }
	char** get_argv_ptr() { return argv_ptr; }

// interface
	void set_server_fg(on_off_enum i) { server_fg = i; }
	on_off_enum get_server_fg() { return server_fg; }

	void set_manager(xnsl_manager* m) { MANAGER = m; }
	xnsl_manager* get_manager() { return MANAGER; }
	xnsl_manager* get_xnsl_manager() { return MANAGER; }

	void set_interface(xnsl_window_interface* w) { INTERFACE = w; }
	xnsl_window_interface* get_interface() { return INTERFACE; }

 // graph list
	int 	get_graph_total() { return graph_total; }
	nsl_list* get_graph_list() { return nsl_graph_list; }

 	int 	add_graph(const char*);
  	int	get_graph(const char*);
 
// print status
	int print_status(ostream&) const;
	virtual int print(ostream&) const;

	virtual int display();

	int output(char*);
};
#endif
