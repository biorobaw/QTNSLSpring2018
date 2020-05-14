/* SCCS  %W%---%E%--%U% */
//
//	xnsl_temporal_graph.C
//

#include "nsl_all_kernel_include.h"
#include "xkernel.h"

xnsl_temporal_graph::xnsl_temporal_graph(xnsl_display_canvas* win) : 
	xnsl_graph(win)
{
        set_type("temporal_graph");

//	pulsefg = 0;
	_t0 = 0;
	_t1 = 0;

//	set_menu_canvas_events(canvas);
//	parent_canvas->set_clear_fg(0);
}
xnsl_temporal_graph::~xnsl_temporal_graph()  
{
}

xnsl_widget * xnsl_temporal_graph::make_widget ()
{
	cmd_error("xnsl_area_level_graph: CANNOT create widget");
        return 0;
}

int xnsl_temporal_graph::display()
{
//	display_temporal_graph(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);

 	return 1;
}
int xnsl_temporal_graph::display_temporal_graph(xnsl_widget*,
	int,int,int,int,int,int,num_type, num_type)
{
 	return 1;
}

int xnsl_temporal_graph::read_from_database()
{
	return 1;
}
int xnsl_temporal_graph::write_to_database()
{
	return 1;
}
int xnsl_temporal_graph::input(int x_pos,int y_pos,int fg)
{
	return 1;
}
int xnsl_temporal_graph::output(int x_pos,int y_pos)
{
	return 1;
}
int xnsl_temporal_graph::print(ostream& out) const
{
	return 1;
}

