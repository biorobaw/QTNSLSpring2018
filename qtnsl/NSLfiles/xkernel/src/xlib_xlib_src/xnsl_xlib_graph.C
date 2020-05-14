/* SCCS  @(#)xnsl_xlib_graph.C	1.1---95/08/13--21:05:31 */
//
//	xnsl_xlib_graph.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 
# include "xnsl_xlib_include.h"
#include "xnsl_xlib_graph.h"

xnsl_xlib_graph::xnsl_xlib_graph() : xnsl_xlib_widget()
{
        set_type("graph");
        set_abstract_type("graph");
}
xnsl_xlib_graph::~xnsl_xlib_graph()
{
}
xnsl_widget* xnsl_xlib_graph::make_widget()
{
	return new xnsl_xlib_graph;
}

int xnsl_xlib_graph::display()
{
	return 1;
}
int xnsl_xlib_graph::xflush()
{
//	XFlush(_dpy);

	return 1;
}

int xnsl_xlib_graph::clear_area(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,int)
{
/*
// XClearArea(_dpy,_xwin,wx0,wy0,wx1,wy1,0); // 0 = FALSE
// SET GC WHITE FOR DRAWING
	XSetForeground(_dpy,_gc,WhitePixelOfScreen(_sc));
// CLEAR PIXMAP WITH WHITE
	XFillRectangle(_dpy,_xwin,_gc,wx0,wy0,wx1,wy1);
// SET GC BLACK FOR DRAWING
	XSetForeground(_dpy,_gc,BlackPixelOfScreen(_sc));
*/
	return 1;
}
int xnsl_xlib_graph::fill_rectangle(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,int,int,int,int)
{
//       XFillRectangle(_dpy,_xwin,_gc,wx0,wy0,wx1,wy1);

	return 1;
}
int xnsl_xlib_graph::draw_line(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	const char* color, int fg)
{
//        XDrawLine(_dpy,_xwin,_gc,wx0,_height-wy0,wx1,_height-wy1);

	return 1;
}
int xnsl_xlib_graph::draw_text(xnsl_widget* widget,int wx,int wy,const char* str)
{
        unsigned int len = strlen(str);

//        XDrawString(_dpy,_xwin,_gc,wx,_height - wy,str,len);

	return 1;
}

xnsl_widget* xnsl_xlib_graph::create_widget(const char *,
	xnsl_widget* pxnsl_widget,int,int,int,int,
	int wx0,int wy0,int wx1,int wy1,int wx,int wy,
	const char*,const char*)
{
/*        if (pxnsl_widget != NULL) // correct setup ???? ** check **
        {
                set_GC(((xnsl_xlib_widget*) pxnsl_widget)->get_GC());
                set_window(((xnsl_xlib_widget*) pxnsl_widget)->get_window());
                set_display(((xnsl_xlib_widget*) 
 			pxnsl_widget)->get_display());
                set_screen(((xnsl_xlib_widget*) 
 			pxnsl_widget)->get_screen());
                _height = pxnsl_widget->get_widget_height();
        }
        else
                cmd_error("xlib_text_label_canvas: NULL parent widget");
*/
	return this;
}

int xnsl_xlib_graph::read_from_database()
{
	return 1;
}
int xnsl_xlib_graph::write_to_database()
{
	return 1;
}
int xnsl_xlib_graph::graph_input(int,int,int)
{
	return 1;
}
int xnsl_xlib_graph::graph_output(int,int)
{
	return 1;
}
int xnsl_xlib_graph::print(ostream&) const
{
	return 1;
}


