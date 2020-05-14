#ifndef XNSL_QT_CANVAS_ITEM_H
#define XNSL_QT_CANVAS_ITEM_H
#include "xnsl_qt_widget.h"
class xnsl_qt_canvas_item : public xnsl_qt_widget
{
protected:
 	xnsl_lib_widget	*_menu;

public:
 	  xnsl_qt_canvas_item();
      virtual ~xnsl_qt_canvas_item();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "",
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { };

      virtual void set_menu (xnsl_widget *);
};
#endif
