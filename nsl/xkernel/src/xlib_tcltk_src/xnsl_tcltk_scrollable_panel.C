/* SCCS  @(#)xnsl_tcltk_scrollable_panel.C	1.1---95/08/13--21:01:54 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_scrollable_panel.C: Class that creates a tcltk scrolled window
//                             widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

xnsl_tcltk_scrollable_panel::xnsl_tcltk_scrollable_panel () : 
	xnsl_tcltk_panel()
{
	set_type("scrollable_panel");
}  // End function xnsl_tcltk_scrollable_panel

xnsl_tcltk_scrollable_panel::~xnsl_tcltk_scrollable_panel ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_scrollable_panel

xnsl_widget*  xnsl_tcltk_scrollable_panel::create_widget(const char *wname, 
	xnsl_widget    *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{

   return (this);

}   // End function create_widget

xnsl_widget *xnsl_tcltk_scrollable_panel::make_widget()
{
	return new xnsl_tcltk_scrollable_panel();
}
	
// End of file.
