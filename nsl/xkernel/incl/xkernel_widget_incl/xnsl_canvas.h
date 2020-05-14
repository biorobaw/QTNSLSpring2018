/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_canvas.h:Class that creates a generic canvas widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_CANVAS_H
#define XNSL_CANVAS_H
#include "xnsl_widget.h"
class xnsl_canvas:public xnsl_widget
{
private:

protected:
	//Nothing yet.

public:

	xnsl_canvas();
	virtual ~xnsl_canvas();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100, int=0, int=0, int=100, 
		int=100,int=10,int=10,const char* = "",const char* = "");

	virtual void redraw();
	virtual int clear_area(xnsl_widget*,int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int = 1,int = 0);
};
#endif

//End of file.
