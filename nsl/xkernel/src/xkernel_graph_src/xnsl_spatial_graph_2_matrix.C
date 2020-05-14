/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_2_matrix.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_spatial_graph_2_matrix::xnsl_spatial_graph_2_matrix(
	xnsl_display_canvas* win,
	nsl_layer* m) : xnsl_spatial_graph_2(win)
{
        set_type("spatial_graph_2_matrix");

	if (m != NULL)
	{
		_layer = m;
		_layer0 = m;

		_imax = ((nsl_matrix_layer*) _layer)->get_imax();
		_jmax = ((nsl_matrix_layer*) _layer)->get_jmax();
		_i0 = 0;
		_j0 = 0;
		_i1 = _imax - 1;
		_j1 = _jmax - 1;
 	}
//	else
//		cmd_error("xnsl_spatial_graph_2_mat: NULL layer");
}
xnsl_spatial_graph_2_matrix::~xnsl_spatial_graph_2_matrix()  
{
}
xnsl_widget * xnsl_spatial_graph_2_matrix::make_widget()
{
        return new xnsl_spatial_graph_2_matrix((xnsl_display_canvas*) m_parent,
		(nsl_num_2*) _layer);
}
int xnsl_spatial_graph_2_matrix::display()
{
	display_spatial_graph_2(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
 
	return 1;
}

int xnsl_spatial_graph_2_matrix::display_spatial_graph_2(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type wymin, num_type wymax) 
{
//	num_type** m = ((nsl_num_2*) _layer)->get_matrix();

//	int wy00 = wy0;
//	int wy11 = wy00 + wys;
//	for (int i=y0; i<=y1; i++)
//	{
//		set_spatial_graph_2_vector(canvas,m,
//			wx0,wy00,wx1,wy11,wxs,wys,x0,x1,wymin,wymax,pulsefg);
//		wy00 = wy00 + wys;
//		wy11 = wy11 + wys;
//	}
 	cmd_error("xnsl_spatial_graph_2_mat:CANNOT display matrix as vector");

	return 1;
}
int xnsl_spatial_graph_2_matrix::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_2_matrix::write_to_database()
{
	xnsl_spatial_graph_2::write_to_database();

	return 1;
}
int xnsl_spatial_graph_2_matrix::print(ostream& out) const
{
	xnsl_spatial_graph_2::print(out);

	return 1;
}

