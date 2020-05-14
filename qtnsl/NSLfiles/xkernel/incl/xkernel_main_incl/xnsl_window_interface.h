/* SCCS  @(#)xnsl_window_interface.h	1.1---95/08/13--23:41:22 */
//
// 	xnsl_window_interface.h
//
#ifndef _XNSL_WINDOW_INTERFACE_H
#define _XNSL_WINDOW_INTERFACE_H
#include "xnsl_window.h"
class xnsl_display_frame;
class xnsl_display_window;
class xnsl_window_interface : public xnsl_window
{
protected:
 // frame_list
	int frame_total; 		// total number of frames
	nsl_list* nsl_frame_list;	// pointer to all nsl frames

public:
		xnsl_window_interface(const char* = "");
 		~xnsl_window_interface();
// frames
	int 	get_frame_total() { return frame_total; }
	nsl_list* get_frame_list() { return nsl_frame_list; }

	virtual int 	create();
	int 	create_window_interface();

	int	add_frame(xnsl_display_frame*);

	xnsl_display_frame*  get_display_frame(char*);	// frame name
	xnsl_display_frame*  get_display_frame(int);	// frame index
	xnsl_display_window* get_display_window(char*); // window name
	xnsl_display_window* get_display_window(int,int);// frame & window index

	void handle_events();
	// update all frame windows
	int	update(); // update all frames
	int	display();
	int	clear();
	int	print(ostream&) const;
	int	print_status(ostream&) const;
/*	int	print_frame_status(ostream&);
	int	print_frame_status(ostream&,char*);
	int	print_frame_status(ostream&,int);
	int	print_window_status(ostream&);
	int	print_window_status(ostream&,char*);
	int	print_window_status(ostream&,int,int);
*/
	int output(char*);
};
#endif
