/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_3_data.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_spatial_graph_3_data::xnsl_spatial_graph_3_data(xnsl_display_canvas* win,
	nsl_layer* m) : xnsl_spatial_graph_3(win)
{
    set_type("spatial_graph_3_data");

	if (m != NULL)
	{
		_layer = m;
		_layer0 = m;
	}
//	else
//		cmd_error("xnsl_spatial_graph_3_dat: NULL layer");
}
xnsl_spatial_graph_3_data::~xnsl_spatial_graph_3_data()
{
}

xnsl_widget * xnsl_spatial_graph_3_data::make_widget()
{
    return new xnsl_spatial_graph_3_data((xnsl_display_canvas*) m_parent,(nsl_num_0*)_layer);
}
int xnsl_spatial_graph_3_data::display()
{
	display_spatial_graph_3(_widget,_wx0,_wy0,_wx1,_wy1,_wymin,_wymax);
	 
	return 1;
}
int xnsl_spatial_graph_3_data::display_spatial_graph_3(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,
	num_type wymin, num_type wymax) 
{
	cmd_error("xnsl_spatial_graph_3_dat: CANNOT display data in 3D");
	return 1;
}

int xnsl_spatial_graph_3_data::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_3_data::write_to_database()
{
	return 1;
}
int xnsl_spatial_graph_3_data::print(ostream& out) const
{
	xnsl_spatial_graph_3::print(out);

	return 1;
}

