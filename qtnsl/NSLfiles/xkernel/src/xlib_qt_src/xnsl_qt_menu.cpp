#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_include.h"

xnsl_qt_menu::xnsl_qt_menu () : xnsl_qt_panel_item()
{
	set_type("menu");
}

xnsl_qt_menu::~xnsl_qt_menu ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_menu

xnsl_widget*  xnsl_qt_menu::create_widget(const char *wname,
	xnsl_widget *pxnsl_widget,int,int,int,int,int,int,int,int,int,int,
	const char*,const char*)
{
	return (this);
}

void xnsl_qt_menu::set_menu_item (const char *wname)
{
}

xnsl_widget *xnsl_qt_menu::make_widget()
{
	return new xnsl_qt_menu();
}
