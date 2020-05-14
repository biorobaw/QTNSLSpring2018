/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_scrollable_panel.h:Class that creates a generic panel widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_SCROLLABLE_PANEL_H
#define XNSL_SCROLLABLE_PANEL_H
#include "xnsl_panel.h"
class xnsl_scrollable_panel:public xnsl_panel
{
private:
protected:
	//Nothing yet.
	xnsl_widget *_pxnsl_widget;

public:

	xnsl_scrollable_panel();
	virtual ~xnsl_scrollable_panel();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int=0,int=0,int=100,int=100,int=10,int=10,
		const char* = "",const char* = "");

        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0,int=0,int=100,int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7
};
#endif

//End of file.
