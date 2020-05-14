/* SCCS  @(#)xnsl_spatial_graph_2_data.h	1.1---96/02/20--18:36:47 */
//
// 	xnsl_spatial_graph_2_data.h
//
#ifndef _XNSL_SPATIAL_GRAPH_2_DATA_H
#define _XNSL_SPATIAL_GRAPH_2_DATA_H
#include "xnsl_spatial_graph_2.h"
#include "nsl_num_decl.h"
class xnsl_display_canvas;
class xnsl_spatial_graph_2_data : public xnsl_spatial_graph_2
{
public:
	xnsl_spatial_graph_2_data(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_spatial_graph_2_data();

        virtual xnsl_widget *make_widget();

        virtual int display();
        virtual int display_spatial_graph_2(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		int = 10, int = 10, num_type = 0.0, num_type = 1.0);

	virtual int read_from_database();
	virtual int write_to_database();
//	virtual int input(int = 0,int = 0, int = 0);
//	virtual int output(int = 0,int = 0);
	virtual int print(ostream&) const;
};
#endif
