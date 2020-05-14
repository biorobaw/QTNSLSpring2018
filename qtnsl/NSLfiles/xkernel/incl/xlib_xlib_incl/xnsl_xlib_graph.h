/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_xlib_graph.h
//

// general drawing graphics object for xlib on a canvas
 #ifndef _XNSL_XLIB_GRAPH_H
 #define _XNSL_XLIB_GRAPH_H
 #include "xnsl_xlib_widget.h"
class xnsl_xlib_graph : public xnsl_xlib_widget
{
protected:
 
public:
	xnsl_xlib_graph();
	virtual ~xnsl_xlib_graph();
 
      virtual xnsl_widget* make_widget();

      virtual int display();

      virtual int xflush();
      virtual int clear_area(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,int = 0);
      virtual int fill_rectangle(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		int=0,int=0,int=1,int = 0);
      virtual int draw_line(xnsl_widget* = 0,int = 0,int = 0, int = 100, int = 100,
		const char* = "",int = 0);
      virtual int draw_text(xnsl_widget* = 0,int = 0,int = 0,const char* = "");

      virtual xnsl_widget* create_widget(const char * = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100, 
                int = 0, int = 0,int = 100, int = 100, int = 10, int = 10,
		const char* = "", const char* = "");

// database updates
	virtual int	read_from_database();
	virtual int	write_to_database();

 	virtual int	print(ostream&) const;

	virtual	int	graph_input(int,int,int);
	virtual int	graph_output(int,int);
};
#endif
