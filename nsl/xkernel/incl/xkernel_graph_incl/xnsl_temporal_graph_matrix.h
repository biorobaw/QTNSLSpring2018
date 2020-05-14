/* SCCS  @(#)xnsl_temporal_graph_matrix.h	1.1---96/02/20--18:37:09 */
//
// 	xnsl_temporal_graph_matrix.h
//
#ifndef _XNSL_TEMPORAL_GRAPH_MATRIX_H
#define _XNSL_TEMPORAL_GRAPH_MATRIX_H
#include "xnsl_temporal_graph.h"
#include "nsl_num_decl.h"
class xnsl_display_canvas;
class xnsl_temporal_graph_matrix : public xnsl_temporal_graph
{
	int _i0,_i1;		// row range
	int _j0,_j1;		// col range
	int _imax,_jmax;	// matrix size
public:
	xnsl_temporal_graph_matrix(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_temporal_graph_matrix();

	void set_i0(int i) { _i0 = i; }
	void set_i1(int i) { _i1 = i; }
	void set_imax(int i) { _imax = i; }
	void set_j0(int i) { _j0 = i; }
	void set_j1(int i) { _j1 = i; }
	void set_jmax(int i) { _jmax = i; }

	int get_i0() { return _i0; }
	int get_i1() { return _i1; }
	int get_imax() { return _imax; }
	int get_j0() { return _j0; }
	int get_j1() { return _j1; }
	int get_jmax() { return _jmax; }

        virtual xnsl_widget *make_widget();

        virtual int display();
        virtual int display_temporal_graph(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		int=10,int=10,num_type = 0.0, num_type = 1.0);

	virtual int	read_from_database() {return 0; }; //not defined -bn7
	virtual int	write_to_database() { return 0;}; //not defined -bn7
	virtual int	print(ostream&) const {return 0; }; //not defined -bn7
};
#endif
