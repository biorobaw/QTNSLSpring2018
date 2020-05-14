#include "xlib_qt_control.h"

xlib_qt_control::xlib_qt_control(QWidget *W)
{
}

xlib_qt_control::~xlib_qt_control()
{
}

void xlib_qt_control::Configure(int height, int width)
{
	//theme and dimensions
	resize(width, height);
	setStyleSheet("background-color: white");
}

void xlib_qt_control::Display() //probably getparent()->Display() for child widgets?
{
show();
}
