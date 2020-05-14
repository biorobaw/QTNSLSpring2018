#include "nsl_base.h"
#include "xnsl_qt_push_button.h"

xnsl_qt_push_button::xnsl_qt_push_button () : xnsl_qt_panel_item()
{
	set_type("push_button");
}

xnsl_qt_push_button::~xnsl_qt_push_button ()
{
}

xnsl_widget*  xnsl_qt_push_button::create_widget(const char *wname,
	xnsl_widget    *pxnsl_widget,int,int,int,int,int,int,
	int,int,int,int,const char* label,const char* message)
{
   return ((xnsl_widget*)(this));
}

xnsl_widget *xnsl_qt_push_button::make_widget()
{
	return (xnsl_widget*)(new xnsl_qt_push_button());
}
