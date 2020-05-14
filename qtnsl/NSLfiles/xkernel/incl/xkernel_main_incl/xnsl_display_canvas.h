/* SCCS  @(#)xnsl_display_canvas.h	1.1---95/08/13--23:41:19 */
//
// 	xnsl_display_canvas.h
//
#ifndef _XNSL_DISPLAY_CANVAS_H
#define _XNSL_DISPLAY_CANVAS_H
#include "xnsl_window.h"
class xnsl_display_window;
class xnsl_display_canvas : public xnsl_window
{
protected:
// 	xnsl_display_graph*	canvas_graph;	// graphics
  
public:
		xnsl_display_canvas(xnsl_display_window*,char*);
		~xnsl_display_canvas();

//	xnsl_display_graph*	get_canvas_graph() { return canvas_graph; }
//	void	set_canvas_graph(xnsl_display_graph* graph) 
//		{ canvas_graph=graph; }

// resize
	int	resize(int,int,int,int); 
// reset
	virtual int	reset(nsl_buffer* = 0);
// init	
	virtual int	init();	
// create  
	int	create();
	int	create(int,int,int,int,const char*); 
// update
	int	update();
// clear
	int	clear();
// database updates
	int	read_from_database();
	int	write_to_database();
// display
	int	display();
// mouse input
	int	input(int,int,int);
	int	output(int,int);
	
// print
	virtual int	print_status(std::ostream&) const;
	virtual int	print(std::ostream&) const;

	int	print_display_canvas_status(std::ostream&) const;
	int	print_display_canvas(std::ostream&) const;

	int	print_display_canvas_status(std::ostream&,char*) const;
	int	print_display_canvas_status(std::ostream&,int) const;
	int	print_display_canvas(std::ostream&,char*) const;
	int	print_display_canvas(std::ostream&,int) const;
};
#endif
