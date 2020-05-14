/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_text_menu_buttonh:Class that creates a generic pop_up_menu widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TEXT_MENU_BUTTON_H
#define XNSL_TEXT_MENU_BUTTON_H
#include "xnsl_panel_item.h"
class xnsl_display_panel;
class xnsl_text_menu_button:public xnsl_panel_item
{
private:

xnsl_widget	*_pxnsl_widget;
protected:
	//Nothing yet.

public:

	xnsl_text_menu_button(xnsl_display_panel* = 0);
         virtual ~xnsl_text_menu_button();

	virtual xnsl_widget    *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");

        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0, int=0, int=100, int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7
};
#endif

//End of file.
