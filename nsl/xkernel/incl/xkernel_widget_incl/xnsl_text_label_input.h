/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_text_label_input.h:Class that creates a generic text_label widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TEXT_LABEL_INPUT_H
#define XNSL_TEXT_LABEL_INPUT_H
#include "xnsl_panel_item.h"
class xnsl_display_panel;
class xnsl_text_label_input:public xnsl_panel_item
{
private:

protected:
	//Nothing yet.

public:

	xnsl_text_label_input(xnsl_display_panel* = 0);
	virtual ~xnsl_text_label_input();

 	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");
};
#endif

//End of file.
