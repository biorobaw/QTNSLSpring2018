/* SCCS  @(#)xnsl_area_level_graph_data.h	1.1---96/02/20--18:36:47 */
//
// 	xnsl_area_level_graph_data.h
//
#ifndef _XNSL_AREA_LEVEL_GRAPH_DATA_H
#define _XNSL_AREA_LEVEL_GRAPH_DATA_H
#include "xnsl_area_level_graph.h"
#include "nsl_num_decl.h"
class xnsl_display_canvas;
class xnsl_area_level_graph_data : public xnsl_area_level_graph
{
public:
	xnsl_area_level_graph_data(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_area_level_graph_data();

        virtual xnsl_widget *make_widget();

	virtual int clear();

        virtual int display();
        virtual int display_area_level_graph(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		num_type = 0.0, num_type = 1.0,int = 0, int = 0, int = 0);

	virtual int read_from_database();
	virtual int write_to_database();
	virtual int input(int = 0,int = 0, int = 0);
	virtual int output(int = 0,int = 0);
	virtual int print(ostream&) const;
};
#endif
