/* SCCS  @(#)xnsl_area_level_graph_vector.h	1.1---96/02/20--18:36:58 */
//
// 	xnsl_area_level_graph_vector.h
//
#ifndef _XNSL_AREA_LEVEL_GRAPH_VECTOR_H
#define _XNSL_AREA_LEVEL_GRAPH_VECTOR_H
#include "xnsl_area_level_graph.h"
#include "nsl_num_decl.h"
class xnsl_display_canvas;
class xnsl_area_level_graph_vector : public xnsl_area_level_graph
{
	int _i0,_i1;		// vector range
	int _imax;		// vector size
	row_col_enum _vec_type;	// NSL_ROW, NSL_COL
public:
	xnsl_area_level_graph_vector(xnsl_display_canvas* = 0,nsl_layer* = 0);
	virtual ~xnsl_area_level_graph_vector();

	int init_area_level_graph_vector(nsl_layer*);

	void set_i0(int i) { _i0 = i; }
	void set_i1(int i) { _i1 = i; }
	void set_imax(int i) { _imax = i; }
	void set_vec_type(row_col_enum i) { _vec_type = i; }

	int get_i0() { return _i0; }
	int get_i1() { return _i1; }
	int get_imax() { return _imax; }
	row_col_enum get_vec_type() { return _vec_type; }

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
