/* SCCS  @(#)xnsl_motif_canvas_functions.h	1.1---95/08/13--23:42:01 */
//////////////////////////////////////////////////////////////////////////
//
// xnsl_motif_canvas_functions.h: 'Externs' for the callbacks behind the
//                                motif drawing area widget.
//
//                                This file must be included by any files
//                                that reference the "activate_callback",
//                                "input_callback" or "motion_callback"
//                                functions.
//               
/////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MOTIF_CANVAS_FUNCTIONS_H
#define XNSL_MOTIF_CANVAS_FUNCTIONS_H
/*
extern  void activate_callback(Widget, XtPointer, XtPointer);

extern  void input_callback(Widget, XtPointer, XtPointer);

extern  void motion_callback(Widget, XtPointer, XEvent *);

extern	void event_proc(Widget, XEvent *); //comemnted out -bn7
*/
extern 	void repaint_proc();

#endif

// End of file.
