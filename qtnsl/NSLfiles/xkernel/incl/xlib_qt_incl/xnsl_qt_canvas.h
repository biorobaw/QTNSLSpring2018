#ifndef XNSL_QT_CANVAS_H
#define XNSL_QT_CANVAS_H
#include "xnsl_qt_widget.h"
#include "xnsl_qt_frame.h"
#include <QLabel>
class xnsl_qt_canvas : public xnsl_qt_widget
{
private:
	int xpos;
	xnsl_qt_frame *masterFrame;

protected:

public:
	  xnsl_qt_canvas();
      virtual ~xnsl_qt_canvas();

      inline xnsl_qt_frame *GetFrame() { return masterFrame; };

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void redraw();
      virtual int clear_area(xnsl_widget* = 0,int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 1, int = 0);
};
#endif
