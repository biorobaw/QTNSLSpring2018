/* SCCS  @(#)xnsl_display_frame.h	1.1---95/08/13--23:41:20 */
//
// 	xnsl_display_frame.h
//
#ifndef _XNSL_DISPLAY_FRAME_H
#define _XNSL_DISPLAY_FRAME_H
#include "xnsl_window.h"
class xnsl_display_frame : public xnsl_window
{
 // init data
	nsl_list* window_list;   	// pointer to frame's window list
	int window_total;		// total number of windows

	int window_cols;		// total number of window cols
	int window_rows;		// total number of window rows
public:
		xnsl_display_frame(xnsl_window*,char*);
		~xnsl_display_frame();
// set functions
 	void	set_window_cols(int i) { window_cols = i; }
	void 	set_window_rows(int i) { window_rows = i; }
//	void 	set_window_total(int i) { window_total = i; }
// get functions
 	int 	get_window_cols() { return window_cols; }
	int 	get_window_rows() { return window_rows; }
 	int 	get_window_total() { return window_total; }
	nsl_list*	get_window_list() { return window_list; }
// add window
 	int 	add_window(xnsl_display_window*);
// get window
	xnsl_display_window* get_display_window(char*);
	xnsl_display_window* get_display_window(int);

	int	resize(int,int,int,int);	// resize frame only
	int	resize();			// auto window resize

	int	reset(nsl_buffer* =(nsl_buffer*)0); // reset frame window
	int	init();			// init 
	int	create(int,int,int,int);// 
	int	create();		// create frame
	int	create(int,char**);
	int	display();
	int	update();		// update all windows
	int	update_from_panel(); 	// update all windows from panels
	int	clear();

	virtual int	print(std::ostream&) const;
	int	print_display_frame(std::ostream&) const;
	int	print_display_frame(std::ostream&,int) const;
	int	print_display_frame(std::ostream&,char*) const;
	virtual int	print_status(std::ostream&) const;
	int	print_display_frame_status(std::ostream&) const;
	int	print_display_frame_status(std::ostream&,int) const;
	int	print_display_frame_status(std::ostream&,char*) const;
};
#endif