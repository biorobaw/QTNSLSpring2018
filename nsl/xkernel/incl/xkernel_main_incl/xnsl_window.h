/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_window.h
//
#ifndef _XNSL_WINDOW_H
#define _XNSL_WINDOW_H
#include "xnsl_widget.h"
class xnsl_window : public xnsl_widget
{
protected:
	on_off_enum done_fg;	// ON - dead, OFF - alive 	
	on_off_enum redraw_fg; 	// ON - redraw when processing
	on_off_enum resize_fg; 	// ON - resize automatically
	on_off_enum clear_fg;	// ON - clear graphics
	on_off_enum overlay_fg;	// ON - overlay graphics

//	xnsl_widget* widget; // window widget

// window items		
	int item_total;			// data total
	nsl_list* item_list; 		// data base
public:
		xnsl_window(const char*,const char*);
		virtual ~xnsl_window();

// set functions
	void	set_done_fg(on_off_enum i) { done_fg = i; }
	void	set_redraw_fg(on_off_enum fg) { redraw_fg = fg; }
	void	set_resize_fg(on_off_enum fg) { resize_fg = fg; }
  	void 	set_clear_fg(on_off_enum i) { clear_fg = i; }
   	void 	set_overlay_fg(on_off_enum i) { overlay_fg = i; }
//	void 	set_widget(xnsl_widget* w) { widget = w; }

// get functions
	on_off_enum	get_done_fg() { return done_fg; }
	on_off_enum	get_redraw_fg() { return redraw_fg; }
	on_off_enum	get_resize_fg() { return resize_fg; }
 	on_off_enum 	get_clear_fg() { return clear_fg; }
   	on_off_enum 	get_overlay_fg() { return overlay_fg; }
//	xnsl_widget*	get_widget() { return widget; }

	int 	get_item_total() { return item_total; }
	nsl_list* get_item_list() { return item_list; }

	xnsl_widget* get_item(const int);
	xnsl_widget* get_item(const char*);

	int enable_item(const int);
	int enable_item(const char*);
	int enable_all_item();

	int disable_item(const int);
	int disable_item(const char*);
	int disable_all_item();

 	virtual	int clear() { return 1; }
	virtual	int create() { return 1; }
	virtual	int display() { return 1; }
//	virtual	int display(char*) { return 1; }
	virtual	int init() { return 1; }
	virtual	int refresh() { return 1; }
	virtual	int reset(nsl_buffer* = (nsl_buffer*)0) { return 1; }
	virtual	int update() { return 1; }
	virtual int read_from_database() { return 1; }
	virtual int write_to_database() { return 1; }
};
#endif

