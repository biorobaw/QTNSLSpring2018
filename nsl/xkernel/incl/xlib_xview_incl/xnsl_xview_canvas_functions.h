/* SCCS  @(#)xnsl_xview_canvas_functions.h	1.1---95/08/13--23:44:22 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_xview_canvas_functions.h: 'Externs' for the callbacks behind the
//                                xview drawing area widget.
//
//                                This file must be included by any files
//                                that reference the "activate_callback",
//                                "input_callback" or "motion_callback"
//                                functions.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_XVIEW_CANVAS_FUNCTIONS_H
#define XNSL_XVIEW_CANVAS_FUNCTIONS_H

extern  void activate_callback(Panel_item, Event *);

extern  void input_callback(Xv_Window, Event *);

extern  void motion_callback(Xv_Window, Event *);

extern	void event_proc(Xv_window, Event *);

extern 	void repaint_proc(Canvas, Xv_Window, Display *, Window, Xv_xrectlist *);

#endif

// End of file.
