/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_menu.h:Class that creates a generic menu widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_MENU_H
#define XNSL_MENU_H

/////////////////////////////////////////////////////////////////////////
//
//Class defintion
//
/////////////////////////////////////////////////////////////////////////
#include "xnsl_widget.h"
class xnsl_menu:public xnsl_widget
{
private:
	xnsl_widget *_menu;
protected:
	//Nothing yet.

public:

	xnsl_menu();
	virtual ~xnsl_menu();

       	virtual xnsl_widget *make_widget();

    	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int=10,int=10,const char* = "",const char* = "");

        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0, int=0, int=100, int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7
};
#endif

//End of file.
