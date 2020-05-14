/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_frame.h:Class that creates a generic frame widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_FRAME_H
#define XNSL_FRAME_H
#include "xnsl_widget.h"
class xnsl_frame:public xnsl_widget
{
private:
	xnsl_widget *_pxnsl_widget;
protected:

	//Nothing yet.

public:

	xnsl_frame();
        virtual ~xnsl_frame();

	virtual xnsl_widget  *make_widget();

 	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");

	virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0, int=0, int=100, int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7

};
#endif

//End of file.
