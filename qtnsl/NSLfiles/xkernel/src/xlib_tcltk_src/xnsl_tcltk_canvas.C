/* SCCS  @(#)xnsl_tcltk_canvas.C	1.1---95/08/13--21:01:49 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_canvas.C: Class that creates the tcltk drawing area widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

extern int NSL_TK_FLUSH;
extern int TK_DRAW;
/*
extern void Nsl_IdleProc(ClientData);

static void xnslTkExposeEventProc(ClientData clientData, XEvent *eventPtr)
{
	/*
    Display  *_dpy;
    Window  _xwin;
    GC _gc;
	Screen *_sc;
	int _scnum;
	int _depth;
	Pixmap _pixmap;
	Tk_Window _tkwin;

	if (eventPtr->type == Expose) // 12 - Expose, 14 - ?
	   NSLoutput("Expose");
	else
		return;

	xnsl_tcltk_canvas* widget = (xnsl_tcltk_canvas*) clientData;
	
	Tk_Window _tkmain = ((xnsl_tcltk_widget*) widget)->get_tkmain(); // Tk_MainWindow(NSL_TCL_INTERP);

	if (_tkmain != NULL)
		_tkwin = ((xnsl_tcltk_widget*) widget)->get_tkwin(); // Tk_NameToWindow(NSL_TCL_INTERP,str,_tkmain);
	else
		cmd_error(" xnsl_tcltk_graph::draw_line NULL tkmain");

	nsl_string str;
	strcpy(str, widget->get_wname());
	
	int width = widget->get_width();
	int height = widget->get_height();
*/
/*	if (tkmain != NULL)
		tkwin = Tk_NameToWindow(NSL_TCL_INTERP,str,tkmain);
	else
		cmd_error(" xnsl_tcltk_graph::draw_line NULL tkmain");
*/
	/*
	if (_tkmain != NULL && _tkwin != NULL) 
	{
			_sc = ((xnsl_tcltk_widget*) widget)->get_screen(); // Tk_Screen(_tkwin);
			_scnum = ((xnsl_tcltk_widget*) widget)->get_screen_num(); // Tk_ScreenNumber(_tkwin);
			_dpy = ((xnsl_tcltk_widget*) widget)->get_display(); // Tk_Display(_tkwin);
			_xwin = Tk_WindowId(_tkwin);
			_gc = ((xnsl_tcltk_widget*) widget)->get_GC(); // DefaultGC(_dpy, DefaultScreen(_dpy));
			
			XCopyArea(_dpy, _pixmap,_xwin,
	        	_gc, 0, 0, width, height, 0, 0);
//			XCopyPlane(_dpy, _pixmap,_xwin,
//	        	_gc, 0, 0, width, height, 0, 0,1);	   
	}*/

//}



xnsl_tcltk_canvas::xnsl_tcltk_canvas() : xnsl_tcltk_widget()
{
	set_type("canvas");
}  

xnsl_tcltk_canvas::~xnsl_tcltk_canvas()
{
}  

int xnsl_tcltk_canvas::clear_area(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
//	(wx0,wy0) is lower left corner.
//	 wx1: width, wy1: height

	if (TK_DRAW == 1)
		fg = 1;

	if (fg == 1) {
		char c = ' '; // 'p';
		//nsl_long_string str;

//		sprintf(str,"%s create rectangle %d%c %d%c %d%c %d%c -fill white -outline white",_wname,wx0,c,wy0,c,wx0+wx1,c,wy0+wy1,c);
//		clear_area(widget,wx0,wy0,wx1,wy1);

//		//Tcl_Eval(NSL_TCL_INTERP,str);
	} 
	else {
		//XSetForeground(_dpy,_gc,_white); // SET GC WHITE FOR DRAWING
		//XFillRectangle(_dpy,_xwin,_gc,wx0,wy0,wx1,wy1);
//		XFillRectangle(_dpy,_pixmap,_gc,wx0,wy0,wx1,wy1);
	}

	return 1;
}
void  xnsl_tcltk_canvas::redraw() //called every step of a simulation -bn7
{
//     XCopyPlane(XtDisplay(_object), _xwin,XtWindow(_object),
//        _gc, 0, 0, _width,_height, 0, 0, 1);

	//if (NSL_TK_FLUSH == 1) //AW01
		////Tcl_Eval(NSL_TCL_INTERP,"update"); // idletasks
}
	
xnsl_widget*  xnsl_tcltk_canvas::create_widget(const char   *wname, 
	xnsl_widget     *pxnsl_widget, int, int,
	int width, int height, int, int, int, int, int, int,
	const char* side, const char*) // side taken from label
{
     strcpy(_wname,wname);
     _width = width;
     _height = height;

	nsl_string str;

	char c = ' '; // 'p'

/*	sprintf(str,"frame %s -relief groove -borderwidth 4",wname);

	//Tcl_Eval(NSL_TCL_INTERP,str);

	sprintf(str,"pack %s -side %s",wname,side); // left, top

	//Tcl_Eval(NSL_TCL_INTERP,str);
*/
	sprintf(str,"canvas %s -width %d%c -height %d%c -background white",wname,_width,c,_height,c);

	//Tcl_Eval(NSL_TCL_INTERP,str);

	sprintf(str,"pack %s -side %s",wname,side); // left, top
	// sprintf(str,"pack %s",wname);

	//Tcl_Eval(NSL_TCL_INTERP,str);

	init_widget(_wname);

	// create clear area rectangle for later reconfigure
//	nsl_string str1;
//	sprintf(str1,"%s create rectangle %d%c %d%c %d%c %d%c -tags %s -fill white -outline white",_wname,0,c,0,c,width,c,height,c,_wname);

//	//Tcl_Eval(NSL_TCL_INTERP,str1);

	//_tkmain = Tk_MainWindow(NSL_TCL_INTERP);

	//if (_tkmain != NULL)
	///	_tkwin = Tk_NameToWindow(NSL_TCL_INTERP,_wname,_tkmain);
	//else
		//cmd_error(" xnsl_tcltk_graph::draw_line NULL tkmain");

//	nsl_string wn;
//	strcpy(wn,wname);
//	_tkwin = Tk_CreateWindow(NSL_TCL_INTERP, _tkmain, wn, NULL);
/*
	Tk_MakeWindowExist(_tkwin);

	if (_tkmain != NULL && _tkwin != NULL) {
		Tk_CreateEventHandler(_tkwin,ExposureMask,xnslTkExposeEventProc,this);
		_pixmap = Tk_GetPixmap(_dpy,_xwin,_width,_height,_depth);
//		_pixmap = XCreatePixmap(_dpy,_xwin,_width,_height,_depth);
//		_pixmap = XCreatePixmap(_dpy,RootWindow(_dpy,n),_width,_height,_depth);
	}
*/	
   	return (this);

}   // End function create_widget			

xnsl_widget *xnsl_tcltk_canvas::make_widget()
{
	return new xnsl_tcltk_canvas();
}



