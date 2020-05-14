/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_topology_graph_2.h
//
#ifndef _XNSL_TOPOLOGY_GRAPH_2_H
#define _XNSL_TOPOLOGY_GRAPH_2_H
#include "xnsl_display_graph.h"
class xnsl_topology_graph_2 : public xnsl_display_graph
{
public:
		xnsl_topology_graph_2();
		virtual ~xnsl_topology_graph_2();
// database updates
	virtual	void	read_from_database();
	virtual void	write_to_database();
};

class xnsl_topology_graph_2_mat : public xnsl_topology_graph_2
{
	int i0,i1;		// row range
	int j0,j1;		// col range
	int i1max,j1max;	// matrix size
	int i2max,j2max;

public:
		xnsl_topology_graph_2_mat(nsl_num_2*,nsl_num_2*);
		virtual ~xnsl_topology_graph_2_mat();
// database updates
	void	read_from_database();
	void	write_to_database();

	void	display();
};
#endif