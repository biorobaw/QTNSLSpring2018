#ifndef _XNSL_QT_GRAPH_H
#define _XNSL_QT_GRAPH_H
#include "xnsl_qt_widget.h"
#include "xnsl_qt_canvas.h"
#include <QPixmap>
class xnsl_qt_graph : public xnsl_qt_widget
{
protected:
	int gflags;
	xnsl_qt_canvas *myCanvas;
	QPixmap *drawmap;

public:
	xnsl_qt_graph();
	virtual ~xnsl_qt_graph();

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
