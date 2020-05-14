#ifndef XNSL_QT_FRAME_H
#define XNSL_QT_FRAME_H
#include "xnsl_qt_widget.h"
#include "xlib_qt_framecontrol.h"
class xnsl_qt_frame : public xnsl_qt_widget
{
   private:
   protected:
   public:

	xnsl_qt_frame  ();
    virtual ~xnsl_qt_frame ();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "",
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

      virtual xnsl_widget* make_widget();
};
#endif
