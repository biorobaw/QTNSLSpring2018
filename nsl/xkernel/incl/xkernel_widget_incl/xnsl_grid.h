/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_grid.h:Class that creates a generic grid widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef _XNSL_GRID_H
#define _XNSL_GRID_H
#include "xnsl_widget_graph.h"
class xnsl_display_canvas;
class xnsl_grid : public xnsl_widget_graph
{
private:
protected:
	on_off_enum text_fg;

public:

	xnsl_grid(xnsl_display_canvas* = 0);
	virtual ~xnsl_grid();
	
	on_off_enum get_text_fg() { return text_fg; }
	void set_text_fg(on_off_enum var) { text_fg = var; }

       	virtual xnsl_widget *make_widget();

      	virtual int display();

    	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int=10,int=10,const char* = "",const char* = "");

};
#endif
//End of file.
