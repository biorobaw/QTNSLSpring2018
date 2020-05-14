#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_frame.h"

xnsl_qt_frame::xnsl_qt_frame () : xnsl_qt_widget()
{
	set_type("frame");
}

xnsl_qt_frame::~xnsl_qt_frame ()
{
}

xnsl_widget*  xnsl_qt_frame::create_widget(const char     *wname,
	xnsl_widget    *pxnsl_widget,int  x,int	 y,int  width,int  height,
	int,int,int,int,int,int,const char*,const char*)
{
    strcpy(_wname,wname);
    _X0			= x;
    _Y0			= y;
    _width		= width;
    _height		= height;

    //set up associated qt control
    widget = new xlib_qt_framecontrol();
	((xlib_qt_framecontrol*)widget)->Configure(height, width);
	((xlib_qt_framecontrol*)widget)->Display();

    return (this);
}

void xnsl_qt_frame::set_env (const 	char*,
	int	x,int	y,int	width,int	height,
	int,int,int,int,int,int,const char*,const char*)
{
	_X0		= x;
	_Y0		= y;
	_width		= width;
	_height		= height;

	if (widget != NULL)
	{
		((xlib_qt_framecontrol*)widget)->Configure(height, width);
		((xlib_qt_framecontrol*)widget)->Display();
	}

}  // End of function set_env

xnsl_widget *xnsl_qt_frame::make_widget()
{
	return new xnsl_qt_frame();
}
