#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_text_menu_button.h"
#include "xnsl_qt_frame.h"

xnsl_qt_text_menu_button::xnsl_qt_text_menu_button () :
	xnsl_qt_panel_item()
{
	set_type("text_menu_button");
}  // End function xnsl_tcltk_text_menu_button

xnsl_qt_text_menu_button::~xnsl_qt_text_menu_button ()
{
}

xnsl_widget* xnsl_qt_text_menu_button::create_widget(const char *wname,
	xnsl_widget	*pxnsl_widget,
	int x,int y,int,int,int,int,int,int,int,int,
	const char* label,const char* message)
{
   return (this);
}

void xnsl_qt_text_menu_button::set_menu(xnsl_widget *menu)
{
	_menu = menu;
}

xnsl_widget *xnsl_qt_text_menu_button::make_widget()
{
	return new xnsl_qt_frame();
}
