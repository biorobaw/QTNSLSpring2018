/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_text_label_panel.h:Class that creates a generic text_label_panel 
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_TEXT_LABEL_PANEL_H
#define XNSL_TEXT_LABEL_PANEL_H
#include "xnsl_panel_item.h"
class xnsl_display_panel;
class xnsl_text_label_panel:public xnsl_panel_item
{
private:
 
protected:
	//Nothing yet.

public:

	xnsl_text_label_panel(xnsl_display_panel* = 0);
	virtual ~xnsl_text_label_panel();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100, int=100,int=10,int=10,
		const char* = "",const char* = "");
};
#endif

//End of file.
