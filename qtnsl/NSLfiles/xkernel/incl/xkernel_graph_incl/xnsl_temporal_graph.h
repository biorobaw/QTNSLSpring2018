/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_temporal_graph.h
//
#ifndef _XNSL_TEMPORAL_GRAPH_H
#define _XNSL_TEMPORAL_GRAPH_H
#include "xnsl_graph.h"
class xnsl_display_canvas;
class xnsl_temporal_graph : public xnsl_graph
{
protected:
	int pulsefg;
	num_type _t0,_t1;		// time range 
public:
	xnsl_temporal_graph(xnsl_display_canvas* = 0);
	virtual ~xnsl_temporal_graph();

	void set_t0(num_type t) { _t0 = t; }
	void set_t1(num_type t) { _t1 = t; }

	num_type get_t0() { return _t0; }
	num_type get_t1() { return _t1; }

        virtual xnsl_widget *make_widget();

        virtual int display();
        virtual int display_temporal_graph(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		int=10,int=10, num_type = 0.0, num_type = 1.0);
 
	virtual int	read_from_database();
	virtual int	write_to_database();
	virtual int	print(ostream&) const;
 	virtual	int	input(int,int,int);
	virtual	int	output(int,int);
};
#endif
