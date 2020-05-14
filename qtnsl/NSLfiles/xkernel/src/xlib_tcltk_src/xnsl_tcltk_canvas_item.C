/* SCCS  @(#)xnsl_tcltk_canvas_item.C	1.1---95/08/13--21:01:50 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_canvas_item.C: Class that creates a tcltk menu bar widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_canvas_item.h"
//#include "xnsl_tcltk_include.h"

xnsl_tcltk_canvas_item::xnsl_tcltk_canvas_item () : xnsl_tcltk_widget()
{
	set_type("canvas_item");
}  // End function xnsl_tcltk_canvas_item

xnsl_tcltk_canvas_item::~xnsl_tcltk_canvas_item ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_canvas_item

xnsl_widget*  xnsl_tcltk_canvas_item::create_widget (const char *wname, 
	xnsl_widget     *pxnsl_widget,int  x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
    strcpy(_wname,wname);
    _X0			= x;
    _Y0			= y;
    _width		= width;
    _height		= height;

   return (this);

}   // End function create_widget

xnsl_widget *xnsl_tcltk_canvas_item::make_widget()
{
	return new xnsl_tcltk_canvas_item();
}

void xnsl_tcltk_canvas_item::set_menu(xnsl_widget *m)
{
}

void xnsl_tcltk_canvas_item::set_callback(xnsl_callback* callback)
{
	_callback = callback;
}

// End of file.
