#ifndef XNSL_QT_PANEL_H
#define XNSL_QT_PANEL_H
#include "xnsl_qt_widget.h"
class xnsl_qt_panel : public xnsl_qt_widget
{
   private:
   protected:
   public:

	xnsl_qt_panel  ();
    virtual ~xnsl_qt_panel ();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "",
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7

      virtual xnsl_widget* make_widget();
};
#endif
