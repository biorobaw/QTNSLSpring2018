/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_2_data.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_spatial_graph_2_data::xnsl_spatial_graph_2_data(xnsl_display_canvas* win, 
	nsl_layer* m) : xnsl_spatial_graph_2(win)
{
    set_type("spatial_graph_2_data");

	if (m != NULL)
	{
		_layer = m;
		_layer0 = m;
	}
//	else
//		cmd_error("xnsl_spatial_graph_2_dat: NULL layer");
}
xnsl_spatial_graph_2_data::~xnsl_spatial_graph_2_data()  
{
}
xnsl_widget * xnsl_spatial_graph_2_data::make_widget()
{
    return new xnsl_spatial_graph_2_data((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_spatial_graph_2_data::display()
{
 	display_spatial_graph_2(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
 
	return 1;
}
int xnsl_spatial_graph_2_data::display_spatial_graph_2(xnsl_widget* widget,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type wymin, num_type wymax) 
{
	int fg; // redraw fg

	num_type val;
	int id = _layer0->get_type_id();
	if (id == 0) {
		val = ((NslFloat0*) _layer0)->get_value();
	} else if (id == 1) {
		val = ((NslFloat0*) _layer0)->get_value(); 
	} else if (id == 2) {
		val = ((NslFloat0*) _layer0)->get_value(); 
	} else
		cmd_out("Bad Type ID: ",id);


//        pulsefg = 0; 

//        num_type u0 = (num_type) wx0;
//        num_type u1 = (num_type) (wx1 - wx0);
        num_type v0 = (num_type) wy0;
        num_type v1 = (num_type) (wy1 - wy0);

        int yp = coord_transform(val,wymin,wymax,v0,v1);

        draw_line(widget,wx0,yp,wx1,yp,0,0,0,0);

	return 1;
}

int xnsl_spatial_graph_2_data::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_2_data::write_to_database()
{
	return 1;
}
int xnsl_spatial_graph_2_data::print(ostream& out) const
{
	xnsl_spatial_graph_2::print(out);

	return 1;
}

