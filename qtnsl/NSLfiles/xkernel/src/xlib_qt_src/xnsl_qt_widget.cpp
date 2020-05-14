#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_widget.h"

xnsl_qt_widget::xnsl_qt_widget ()
{
   set_type("qt_widget");
   set_abstract_type("qt_widget");
   set_base_type("widget");
   widget = NULL;
}

xnsl_qt_widget::~xnsl_qt_widget ()
{
}

void  xnsl_qt_widget::redraw()
{
}

void  xnsl_qt_widget::show_widget()
{
}

void  xnsl_qt_widget::unshow_widget()
{
}

void  xnsl_qt_widget::destroy_widget ()
{
}

xnsl_widget* xnsl_qt_widget::create_widget (const char*,xnsl_widget*,
	int,int,int,int,int,int,int,int,int,int,const char*,const char*)
{
	return 0;
}

xnsl_widget* xnsl_qt_widget::make_widget()
{
	return 0;
}

void xnsl_qt_widget::set_env_x(int x)
{
}

void xnsl_qt_widget::set_env_y(int y)
{
}

void xnsl_qt_widget::set_env_width(int)
{
}

void xnsl_qt_widget::set_env_height(int)
{
}

void xnsl_qt_widget::set_env_name(const char *)
{
}





