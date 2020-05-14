/* SCCS  @(#)xnsl_tcltk_graph.h	1.1---95/08/13--23:42:41 */
//
// 	xnsl_tcltk_graph.h
//

// general drawing graphics object for tcltk on a canvas
#ifndef _XNSL_TCLTK_GRAPH_H
#define _XNSL_TCLTK_GRAPH_H
#include "xnsl_tcltk_widget.h"
class xnsl_tcltk_graph : public xnsl_tcltk_widget
{
protected:
 
public:
	xnsl_tcltk_graph();
	virtual ~xnsl_tcltk_graph();
 
      virtual xnsl_widget* make_widget();

      virtual int display();

      virtual int xflush();
      virtual int clear_area(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int = 0, int = 0, int = 1,int = 0);
      virtual int fill_rectangle(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int = 0, int = 0, int = 1,int = 0);
      virtual int draw_line(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int = 0,int = 0, int = 0, int = 1,const char* = "",int = 0);
      virtual int draw_grid(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int = 100, int = 100,
      		num_type = 0,num_type = 0, num_type = 1, num_type = 1,
      		num_type = 1, num_type = 1,int = 0);
      virtual int draw_text(xnsl_widget* = 0,int = 0,int = 0,const char* = "");

      virtual xnsl_widget* create_widget(const char * = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
                int = 0, int = 0,int = 100, int = 100, int = 10, int = 10,
		const char* = "", const char* = "");

		virtual int	print(ostream&) const;
};
#endif
