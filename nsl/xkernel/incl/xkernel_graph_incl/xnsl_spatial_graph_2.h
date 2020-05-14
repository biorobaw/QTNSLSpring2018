/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_spatial_graph_2.h
//
#ifndef _XNSL_SPATIAL_GRAPH_2_H
#define _XNSL_SPATIAL_GRAPH_2_H
#include "xnsl_graph.h"
class xnsl_display_canvas;
class xnsl_spatial_graph_2 : public xnsl_graph
{
protected:
	int pulsefg;
public:
	xnsl_spatial_graph_2(xnsl_display_canvas* = 0);
	virtual ~xnsl_spatial_graph_2();

    virtual xnsl_widget *make_widget();

    virtual int display();
    virtual int display_spatial_graph_2(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		int = 10, int = 10, num_type = 0.0, num_type = 1.0);
 
	virtual int	read_from_database();
	virtual int	write_to_database();
	virtual int	print(ostream&) const;
 	virtual	int	input(int,int,int);
	virtual	int	output(int,int);
};
#endif
