/* SCCS  @(#)xnsl_tcltk_menu.C	1.1---95/08/13--21:01:51 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_menu.C: Class that create a tcltk pulldown menu
//				widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

xnsl_tcltk_menu::xnsl_tcltk_menu () : xnsl_tcltk_panel_item()
{
	set_type("menu");
}  // End function xnsl_tcltk_menu

xnsl_tcltk_menu::~xnsl_tcltk_menu ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_menu

xnsl_widget*  xnsl_tcltk_menu::create_widget(const char *wname, 
	xnsl_widget *pxnsl_widget,int,int,int,int,int,int,int,int,int,int,
	const char*,const char*)
{
	return (this);

} //End function create_widget

void xnsl_tcltk_menu::set_menu_item (const char	*wname)
{
}  // End of function set_env

xnsl_widget *xnsl_tcltk_menu::make_widget()
{
	return new xnsl_tcltk_menu();
}

// End of file.
