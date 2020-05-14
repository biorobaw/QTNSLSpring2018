#include "xlib_qt_framecontrol.h"

xlib_qt_framecontrol::xlib_qt_framecontrol(QWidget *W) : cpos(0)
{
}

xlib_qt_framecontrol::~xlib_qt_framecontrol()
{
}

void xlib_qt_framecontrol::Configure(int height, int width)
{
	//theme and dimensions
	resize(width, height);
	setStyleSheet("background-color: white");
}

void xlib_qt_framecontrol::Display() //probably getparent()->Display() for child widgets?
{
show();
}

void xlib_qt_framecontrol::NewChildEvent(int h, int w)
{
	cpos += h + 2;

	int newheight = (cpos > size().height()) ? cpos : size().height();
	int newwidth = (w > size().width()) ? w : size().width();

	resize(newwidth, newheight);
}
