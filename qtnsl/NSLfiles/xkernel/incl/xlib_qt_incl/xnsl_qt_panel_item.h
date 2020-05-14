#ifndef XNSL_QT_PANEL_ITEM_H
#define XNSL_QT_PANEL_ITEM_H
#include "xnsl_qt_widget.h"
class xnsl_qt_panel_item : public xnsl_qt_widget
{
   protected:

        char		*_value;
	char		*_bitmap;
	xnsl_widget	*_menu;

   public:

	xnsl_qt_panel_item();
      virtual ~xnsl_qt_panel_item();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "");

      virtual void set_env(const char * = "",
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //never defined -bn7

      virtual int get_env(char *); // { };  -bn7

      virtual void set_bitmap (const char *, int, int);
      virtual void set_menu (xnsl_widget * m);
      virtual void set_value (const char*);
};
#endif










