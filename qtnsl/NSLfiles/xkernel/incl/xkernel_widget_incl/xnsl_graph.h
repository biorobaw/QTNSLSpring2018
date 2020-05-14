/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_graph.h:Class that creates a generic graph widget.
//
////////////////////////////////////////////////////////////////////////
#ifndef _XNSL_GRAPH_H
#define _XNSL_GRAPH_H
#include "xnsl_widget_graph.h"
class xnsl_display_canvas;
class xnsl_graph : public xnsl_widget_graph
{
private:
protected:
		// previously nsl_layer
        nsl_layer* _layer;   	// new layer value ptr
        nsl_layer* _layer0;  	// old layer value ptr

public:

		xnsl_graph(xnsl_display_canvas* = 0);
		virtual ~xnsl_graph();
/*
       	virtual xnsl_widget *make_widget();

		virtual int clear();
        virtual int display();
        virtual int xflush();
        virtual int clear_area(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,int = 0);
        virtual int fill_rectangle(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int=0,int=0,int=1,int=0);
        virtual int draw_line(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			const char* = "",int = 0);
        virtual int draw_grid(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int = 100, int = 100,
        	num_type = 0,num_type = 0, num_type = 1, num_type = 1,
        	num_type = 1, num_type = 1,int = 0);
        virtual int draw_text(xnsl_widget* = 0,int = 0,int = 0, const char* = "");

    	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
			int = 0, int = 0, int = 100, int = 100,
			int = 0, int = 0,int = 100, int = 100,
			int=10,int=10,const char* = "",const char* = "");
*/
};
#endif
//End of file.
