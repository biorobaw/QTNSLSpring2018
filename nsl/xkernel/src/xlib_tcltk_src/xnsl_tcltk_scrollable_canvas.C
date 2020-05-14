/* SCCS  @(#)xnsl_tcltk_scrollable_canvas.C	1.1---95/08/13--21:01:53 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_scrollable_canvas.C: Class that creates a tcltk scrolled window
//                             widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

xnsl_tcltk_scrollable_canvas::xnsl_tcltk_scrollable_canvas () : 
	xnsl_tcltk_canvas()
{
	set_type("scrollable_canvas");
}  // End function xnsl_tcltk_scrollable_canvas

xnsl_tcltk_scrollable_canvas::~xnsl_tcltk_scrollable_canvas ()
{

}  // End function ~xnsl_tcltk_scrollable_canvas

xnsl_widget*  xnsl_tcltk_scrollable_canvas::create_widget(const char *wname, 
	xnsl_widget    *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
   return (this);
}   // End function create_widget

xnsl_widget *xnsl_tcltk_scrollable_canvas::make_widget()
{
	return new xnsl_tcltk_scrollable_canvas();
}
	
// End of file.
