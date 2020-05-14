#ifndef _XLIB_QT_CANVASCONTROL_H
#define _XLIB_QT_CANVASCONTROL_H
#include "xlib_qt_control.h"
#include <QFrame>
class xlib_qt_canvascontrol : public xlib_qt_control
{
private:

protected:
	QFrame *canvasArea; //this is an outlined area in which all the child visual objects are to be drawn

public:
	explicit xlib_qt_canvascontrol(QWidget *W = 0);
	~xlib_qt_canvascontrol();

	virtual void Configure(int height, int width);
	virtual void Display();
};
#endif
