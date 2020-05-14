/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_panel.h:Class that creates a generic panel widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef XNSL_PANEL_H
#define XNSL_PANEL_H
#include "xnsl_widget.h"
class xnsl_panel: public xnsl_widget
{
private:
protected:
	//Nothing yet.

public:

	xnsl_panel();
	virtual ~xnsl_panel();

	virtual xnsl_widget  *make_widget();

  	virtual xnsl_widget  *create_widget(const char* = "", xnsl_widget* = 0, 
		int = 0, int = 0, int = 100, int = 100,
		int=0, int=0, int=100,int=100,int=10,int=10,
		const char* = "",const char* = "");

        virtual void set_env(const char* = "", int = 0, int = 0,
		int = 100, int = 100, int=0,int=0,int=100,int=100,
		int=10,int=10,const char* = "",const char* = "") { }; //never defined -bn7
};
#endif

//End of file.
