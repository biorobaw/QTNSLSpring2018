#ifndef XNSL_QT_TEXT_MENU_BUTTON_H
#define XNSL_QT_TEXT_MENU_BUTTON_H
#include "xnsl_qt_panel_item.h"
class xnsl_qt_text_menu_button : public xnsl_qt_panel_item
{
   private:
   protected:
   public:

	xnsl_qt_text_menu_button  ();
    virtual  ~xnsl_qt_text_menu_button ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "",
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //TODO: never defined -bn7

      void set_menu(xnsl_widget*);
};
#endif
