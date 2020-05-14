/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_canvas_item.h:Class that creates a generic canvas widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_CANVAS_ITEM_H
#define XNSL_CANVAS_ITEM_H
#include "xnsl_widget.h"
class xnsl_display_canvas;
class xnsl_canvas_item:public xnsl_widget
{
private:

protected:
	//Nothing yet.
public:

	xnsl_canvas_item(xnsl_display_canvas* = 0);
	virtual ~xnsl_canvas_item();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");
        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0, int=0, int=100, int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //not defined -bn7
};
#endif

//End of file.
