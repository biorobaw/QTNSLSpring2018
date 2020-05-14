/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_area_level_graph.h
//
#ifndef _XNSL_AREA_LEVEL_GRAPH_H
#define _XNSL_AREA_LEVEL_GRAPH_H
#include "xnsl_graph.h"
class xnsl_display_canvas;
class xnsl_area_level_graph : public xnsl_graph
{
public:
	xnsl_area_level_graph(xnsl_display_canvas* = 0);
	virtual ~xnsl_area_level_graph();

    virtual xnsl_widget *make_widget();

	virtual int clear();

    virtual int display();
    virtual int display_area_level_graph(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		num_type = 0.0, num_type = 1.0,int = 0, int = 0, int = 0);
    int display_area_level_graph_val(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		num_type = 0.0, num_type = 0.0, num_type = 0.0, num_type = 1.0,int=0,int=0);

	virtual int read_from_database();
	virtual int write_to_database();
	virtual int input(int = 0,int = 0, int = 0);
	virtual int output(int = 0,int = 0);
	virtual int print(ostream&) const;
};
#endif
