/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_panel_item.h:Class that creates a generic panel widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_PANEL_ITEM_H
#define XNSL_PANEL_ITEM_H
#include "xnsl_widget.h"
class xnsl_display_canvas;
class xnsl_display_panel;
class xnsl_panel_item:public xnsl_widget
{
private:
protected:
	xnsl_widget	*_menu;
	nsl_string _value;
	xnsl_callback	*_callback;
	nsl_string _bitmap;

public:

	xnsl_panel_item(xnsl_display_panel* = 0);
	virtual ~xnsl_panel_item();

 	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");

        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0, int=0, int=100, int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7

	virtual  int get_env(char*) { }; //never defined -bn7

	char* get_value() { return _value; }
	xnsl_widget* get_menu() { return _menu; }
	xnsl_callback* get_callback() { return _callback; }
	char* get_bitmap() { return _bitmap; }

	void set_callback (xnsl_callback * c) { _callback = c; }
	void set_bitmap(const char* b, int=10, int=10) 
					{ strcpy(_bitmap,b); }
	void set_menu(xnsl_widget* w) { _menu = w; }
	void set_value(const char* v) { strcpy(_value,v); }
};
#endif

//End of file.
