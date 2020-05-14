/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_3_vector.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_spatial_graph_3_vector::xnsl_spatial_graph_3_vector(
	xnsl_display_canvas* win,nsl_layer* m) : xnsl_spatial_graph_3(win)
{
        set_type("spatial_graph_3_vector");

	if (m != NULL)
	{
		_layer = m;
		_layer0 = m;

		_imax = ((nsl_vector_layer*) _layer)->get_imax();
		_i0 = 0;
		_i1 = _imax - 1;
		_vec_type = NSL_ROW;
 	}
//	else
//		cmd_error("xnsl_spatial_graph_3_vec: NULL layer");
}
xnsl_spatial_graph_3_vector::~xnsl_spatial_graph_3_vector()
{
}

xnsl_widget * xnsl_spatial_graph_3_vector::make_widget()
{
    return new xnsl_spatial_graph_3_vector((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_spatial_graph_3_vector::display()
{
	display_spatial_graph_3(_widget,_wx0,_wy0,_wx1,_wy1,_wymin,_wymax);
 
	return 1;
}
int xnsl_spatial_graph_3_vector::display_spatial_graph_3(xnsl_widget*,
	int,int,int,int,num_type, num_type) 
{
	cmd_error("xnsl_spatial_graph_3_vec: CANNOT display vector in 3D");
	return 1;
}
int xnsl_spatial_graph_3_vector::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_3_vector::write_to_database()
{
	return 1;
}
int xnsl_spatial_graph_3_vector::print(ostream& out) const
{
	xnsl_spatial_graph_3::print(out);

	return 1;
}

