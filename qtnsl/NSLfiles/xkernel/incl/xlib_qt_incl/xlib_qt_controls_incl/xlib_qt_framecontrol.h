#ifndef _XLIB_FRAME_CONTROL_H
#define _XLIB_FRAME_CONTROL_H
#include "xlib_qt_control.h"
//the "window frame" for child windows
class xlib_qt_framecontrol : public xlib_qt_control
{
private:
	Q_OBJECT

private slots:

protected:
	int cpos;

public:
	explicit xlib_qt_framecontrol(QWidget *W = 0);
	~xlib_qt_framecontrol();

	void Configure(int height, int width);
	void Display();
	void NewChildEvent(int h, int w);

	inline int GetNextChildPos() { return cpos; };
};

#endif
