/* SCCS  @(#)xnsl_display_window.h	1.1---95/08/13--23:41:21 */
//
// 	xnsl_display_window.h
//
#ifndef _XNSL_DISPLAY_WINDOW_H
#define _XNSL_DISPLAY_WINDOW_H
#include "xnsl_window.h"
class xnsl_display_window : public xnsl_window
{
 	xnsl_display_canvas* window_canvas;	// window canvas
	xnsl_display_panel* control_panel;	// control panel

// window main (name,layer,graph)
 	nsl_string	graph_name;		// graph name
	int graph_type;

	nsl_string	layer_name;		// layer name
	int layer_type;
	nsl_layer* layer;			// layer object
	nsl_list* layer_list;			// layer list	
public:
		xnsl_display_window(xnsl_display_frame*,char*);
		~xnsl_display_window();

	xnsl_display_canvas* get_window_canvas() { return window_canvas; }
	xnsl_display_panel* get_control_panel() { return control_panel; }

	void set_window_canvas(xnsl_display_canvas* c) { window_canvas = c; }
	void set_control_panel(xnsl_display_panel* p) { control_panel = p; }

  	void 	set_layer_type(int i) { layer_type = i; }
	void 	set_graph_type(int i) { graph_type = i; }
	void	set_graph_name(char* str) { strcpy(graph_name,str); }
	void	set_layer_name(char* str) { strcpy(layer_name,str); }
  	void 	set_layer(nsl_layer* l) { layer = l; }

	int 	get_layer_type() { return layer_type; }
	int 	get_graph_type() { return graph_type; }
	char*	get_graph_name() { return graph_name; }
	char* 	get_layer_name() { return layer_name; }
 	nsl_layer* 	get_layer() { return layer; }

// resize 
	int	resize(int,int,int,int); 
// create
	int	create();		
	int	create(int,int,int,int); 
// reset
	int	reset(nsl_buffer* = (nsl_buffer*)0);	// reset all window
// init
	int	init();		// init window data
 
// clear
	int	clear();
// update
	int	update();
//	int	update_from_panel();
//	int 	update_window_layer(); // set layer_name first
//	int	update_window_graph(); // set graph_name first
//	int 	update_window_layer(char*); // set layer_name first
//	int	update_window_graph(char*); // set graph_name first

// db
	int	read_from_database(); 	// read data
	int	write_to_database();	// write data
// display
	int	display();
// mouse input
	int	input(int,int,int);
	int	output(int,int);		
	
// print window data
	virtual int	print_status(std::ostream&) const;
	int	print_display_window_status(std::ostream&) const;
	int	print_display_window_status(std::ostream&,char*) const;
	int	print_display_window_status(std::ostream&,int) const;
	virtual int	print(std::ostream&) const;
	int	print_display_window(std::ostream&) const;
 
	int	print_canvas_status(std::ostream&) const;
	int	print_panel_status(std::ostream&) const;
};
#endif
