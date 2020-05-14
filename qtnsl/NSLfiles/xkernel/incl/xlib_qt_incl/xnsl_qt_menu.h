#ifndef XNSL_QT_MENU_H
#define XNSL_QT_MENU_H
#include "xnsl_qt_panel_item.h"
class xnsl_qt_menu : public xnsl_qt_panel_item
{
   private:
   protected:
   public:

	xnsl_qt_menu  ();
    virtual ~xnsl_qt_menu ();

       virtual xnsl_widget* make_widget();

      	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

	void set_menu_item(const char*);
};
#endif
