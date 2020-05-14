/* SCCS  @(#)xnsl_temporal_graph_data.h	1.1---96/02/20--18:36:48 */
//
// 	xnsl_temporal_graph_data.h
//
#ifndef _XNSL_TEMPORAL_GRAPH_DATA_H
#define _XNSL_TEMPORAL_GRAPH_DATA_H
#include "xnsl_temporal_graph.h"
#include "nsl_num_decl.h"
class xnsl_display_canvas;
class xnsl_temporal_graph_data : public xnsl_temporal_graph
{
public:
	xnsl_temporal_graph_data(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_temporal_graph_data();

        virtual xnsl_widget *make_widget();

        virtual int display();
        virtual int display_temporal_graph(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		int=10,int=10, num_type = 0.0, num_type = 1.0);

	virtual int	read_from_database();
	virtual int	write_to_database();
	virtual int	print(ostream&) const;
};
#endif
