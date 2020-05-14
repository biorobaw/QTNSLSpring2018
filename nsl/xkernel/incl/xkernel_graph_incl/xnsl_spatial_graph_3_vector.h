/* SCCS  @(#)xnsl_spatial_graph_3_vector.h	1.1---96/02/20--18:36:59 */
//
// 	xnsl_spatial_graph_3_vector.h
//
#ifndef _XNSL_SPATIAL_GRAPH_3_VECTOR_H
#define _XNSL_SPATIAL_GRAPH_3_VECTOR_H
#include "xnsl_spatial_graph_3.h"
class nsl_num_1;
//typedef nsl_num_1 nsl_num_1;
class xnsl_display_canvas;
class xnsl_spatial_graph_3_vector : public xnsl_spatial_graph_3
{
	int _i0,_i1;		// vecor range
	int _imax;		// vector size
	row_col_enum _vec_type;	// NSL_ROW, NSL_COL
public:
	xnsl_spatial_graph_3_vector(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_spatial_graph_3_vector();

	void set_i0(int i) { _i0 = i; }
	void set_i1(int i) { _i1 = i; }
	void set_imax(int i) { _imax = i; }
	void set_vec_type(row_col_enum i) { _vec_type = i; }

	int get_i0() { return _i0; }
	int get_i1() { return _i1; }
	int get_imax() { return _imax; }
	row_col_enum get_vec_type() { return _vec_type; }

        virtual xnsl_widget *make_widget();

        virtual int display();
        virtual int display_spatial_graph_3(xnsl_widget* = 0,int=0,int=0,int=10,int=10,
		num_type = 0.0, num_type = 1.0);

	virtual int read_from_database();
	virtual int write_to_database();
//	virtual int input(int = 0,int = 0, int = 0);
//	virtual int output(int = 0,int = 0);
	virtual int print(ostream&) const;
};
#endif
