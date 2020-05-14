/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_scrollable_canvas.h:Class that creates a generic canvas widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_SCROLLABLE_CANVAS_H
#define XNSL_SCROLLABLE_CANVAS_H
#include "xnsl_canvas.h"
class xnsl_scrollable_canvas:public xnsl_canvas
{
private:
	xnsl_widget	*_pxnsl_widget;
protected:
	//Nothing yet.

public:

	xnsl_scrollable_canvas();
	virtual ~xnsl_scrollable_canvas();

	virtual xnsl_widget  *make_widget();

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
