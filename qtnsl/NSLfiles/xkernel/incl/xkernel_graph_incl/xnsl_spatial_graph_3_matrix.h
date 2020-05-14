/* SCCS  @(#)xnsl_spatial_graph_3_matrix.h	1.1---96/02/20--18:37:08 */
//
// 	xnsl_spatial_graph_3_matrix.h
//
#ifndef _XNSL_SPATIAL_GRAPH_3_MATRIX_H
#define _XNSL_SPATIAL_GRAPH_3_MATRIX_H
#include "xnsl_spatial_graph_3.h"
#include "nsl_num_decl.h"
class xnsl_display_canvas;
class xnsl_spatial_graph_3_matrix : public xnsl_spatial_graph_3
{
	int _i0,_i1;		// row range
	int _j0,_j1;		// col range
	int _imax,_jmax;		// matrix size
public:
	xnsl_spatial_graph_3_matrix(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_spatial_graph_3_matrix();

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
        virtual int display_spatial_graph_3(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		num_type = 0.0, num_type = 1.0);

	virtual int read_from_database();
	virtual int write_to_database();
//	virtual int input(int = 0,int = 0, int = 0);
//	virtual int output(int = 0,int = 0);
	virtual int print(ostream&) const;

	int draw_3D_axis(xnsl_widget*,int,int,num_type,num_type);

	int draw_hide(xnsl_widget*,int,int);
	int draw_no_hide(xnsl_widget*,int,int);
};
#endif
