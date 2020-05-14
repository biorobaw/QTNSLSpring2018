/* SCCS  @(#)xnsl_tcltk_text_menu_button.C	1.1---95/08/13--21:01:58 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_text_menu_button.C: Class that Creates the tcltk cascade 
//                               button widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"
 
xnsl_tcltk_text_menu_button::xnsl_tcltk_text_menu_button () : 
	xnsl_tcltk_panel_item()
{
	set_type("text_menu_button");
}  // End function xnsl_tcltk_text_menu_button

xnsl_tcltk_text_menu_button::~xnsl_tcltk_text_menu_button ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_text_menu_button

xnsl_widget* xnsl_tcltk_text_menu_button::create_widget(const char *wname,
	xnsl_widget	*pxnsl_widget,
	int x,int y,int,int,int,int,int,int,int,int,
	const char* label,const char* message)
{
   return (this);
}   // End function create_widget

void xnsl_tcltk_text_menu_button::set_menu(xnsl_widget *menu)
{
	_menu = menu;

}  // End of function set_env

xnsl_widget *xnsl_tcltk_text_menu_button::make_widget()
{
	return new xnsl_tcltk_frame();
}
			
// End of file.
