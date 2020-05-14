#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_panel.h"
xnsl_qt_panel::xnsl_qt_panel() : xnsl_qt_widget()
{
	set_type("panel");
}

xnsl_qt_panel::~xnsl_qt_panel ()
{
}

xnsl_widget*  xnsl_qt_panel::create_widget(const char *wname,
	xnsl_widget    *pxnsl_widget,int x,int	y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
   strcpy(_wname,wname);
   _X0			= x;
   _Y0			= y;
   _width		= width;
   _height		= height;
   return (this);
}

xnsl_widget *xnsl_qt_panel::make_widget()
{
	return new xnsl_qt_panel();
}
