/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_pic_button.h:Class that creates a generic push_button widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_PIC_BUTTON_H
#define XNSL_PIC_BUTTON_H
#include "xnsl_panel_item.h"
class xnsl_display_canvas;
class xnsl_display_panel;
class xnsl_pic_button:public xnsl_panel_item
{
private:
	xnsl_widget *_pxnsl_widget;
protected:
	//Nothing yet.

public:

	xnsl_pic_button(xnsl_display_panel* = 0);
	virtual ~xnsl_pic_button();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");

};
#endif

//End of file.
