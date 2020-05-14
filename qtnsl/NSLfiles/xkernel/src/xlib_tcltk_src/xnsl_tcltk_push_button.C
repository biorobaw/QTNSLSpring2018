/* SCCS  @(#)xnsl_tcltk_push_button.C	1.1---95/08/13--21:01:53 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_push_button.C: Class that Creates the tcltk cascade 
//                               button widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_base.h"
#include "xnsl_tcltk_push_button.h"

xnsl_tcltk_push_button::xnsl_tcltk_push_button () : xnsl_tcltk_panel_item()
{
	//set_type("push_button");
}  // End function xnsl_tcltk_push_button

xnsl_tcltk_push_button::~xnsl_tcltk_push_button ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_push_button

xnsl_widget*  xnsl_tcltk_push_button::create_widget(const char *wname, 
	xnsl_widget    *pxnsl_widget,int,int,int,int,int,int,
	int,int,int,int,const char* label,const char* message)
{
   return ((xnsl_widget*)(this));
}   // End function create_widget

xnsl_widget *xnsl_tcltk_push_button::make_widget()
{
	return (xnsl_widget*)(new xnsl_tcltk_push_button());
}

// End of file.
