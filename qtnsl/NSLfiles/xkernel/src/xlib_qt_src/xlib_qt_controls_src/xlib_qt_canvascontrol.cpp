#include "xlib_qt_canvascontrol.h"
#include "xlib_qt_framecontrol.h"

xlib_qt_canvascontrol::xlib_qt_canvascontrol(QWidget *W) : xlib_qt_control(W)
{

}

xlib_qt_canvascontrol::~xlib_qt_canvascontrol()
{
}

void xlib_qt_canvascontrol::Configure(int h, int w)
{
	if ((xlib_qt_framecontrol*)parent() == NULL) //not functional without parent
		return;

	xlib_qt_framecontrol *qparent = (xlib_qt_framecontrol*)parent();

	int xpos = qparent->GetNextChildPos();

	qparent->NewChildEvent(h, w);

	resize(w, h);
	move(xpos, 2);

}

void xlib_qt_canvascontrol::Display()
{
show();
}
