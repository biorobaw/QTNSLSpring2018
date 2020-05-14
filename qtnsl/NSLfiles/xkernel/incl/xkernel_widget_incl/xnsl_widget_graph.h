/* SCCS  %W%---%E%--%U% */
////////////////////////////////////////////////////////////////////////
//
//xnsl_widget_graph.h:Class that creates a generic graph widget.
//
////////////////////////////////////////////////////////////////////////

#ifndef _XNSL_WIDGET_GRAPH_H
#define _XNSL_WIDGET_GRAPH_H
#include "xnsl_canvas_item.h"
class xnsl_widget_graph : public xnsl_canvas_item
{
private:
protected:

        int _wx0,_wy0;          // window start point
        int _wx1,_wy1;          // window end point
        int _wxs,_wys;          // window layer element size
		num_type _wxmin,_wxmax;    // x min,max values
		num_type _wymin,_wymax;    // y min,max values
		num_type _wxstep,_wystep;  // x,y step values

public:

	xnsl_widget_graph(xnsl_display_canvas* = 0);
	virtual ~xnsl_widget_graph();

// set
        void    set_wx0(int s) { _wx0 = s; }
        void    set_wy0(int s) { _wy0 = s; }
        void    set_wx1(int s) { _wx1 = s; }
        void    set_wy1(int s) { _wy1 = s; }
        void    set_wxs(int s) { _wxs = s; }
        void    set_wys(int s) { _wys = s; }
        void    set_wxmin(float s) { _wxmin = s; }
        void    set_wxmax(float s) { _wxmax = s; }
        void    set_wymin(float s) { _wymin = s; }
        void    set_wymax(float s) { _wymax = s; }
        void    set_wxstep(float s) { _wxstep = s; }
        void    set_wystep(float s) { _wystep = s; }
// get
        int     get_wx0() { return _wx0; }
        int     get_wy0() { return _wy0; }
        int     get_wx1() { return _wx1; }
        int     get_wy1() { return _wy1; }
        int     get_wxs() { return _wxs; }
        int     get_wys() { return _wys; }
        float   get_wxmin() { return _wxmin; }
        float   get_wxmax() { return _wxmax; }
        float   get_wymin() { return _wymin; }
        float   get_wymax() { return _wymax; }
        float   get_wxstep() { return _wxstep; }
        float   get_wystep() { return _wystep; }

       	virtual xnsl_widget *make_widget();

		int coord_transform(num_type,num_type,num_type,num_type,num_type);

		virtual int clear();
        virtual int display();
        virtual int xflush();
        virtual int clear_area(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int=0,int=0,int=1,int = 0);
        virtual int fill_rectangle(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int=0,int=0,int=1,int=0);
        virtual int draw_line(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int = 0,int = 0, int = 0, int = 1,const char* = "",int = 0);
        virtual int draw_grid(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
			int = 100, int = 100,
        	num_type = 0,num_type = 0, num_type = 1, num_type = 1,
        	num_type = 1, num_type = 1,int = 0);
        virtual int draw_text(xnsl_widget* = 0,int = 0,int = 0, const char* = "");

    	virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
			int = 0, int = 0, int = 100, int = 100,
			int = 0, int = 0,int = 100, int = 100,
			int=10,int=10,const char* = "",const char* = "");

};
#endif
