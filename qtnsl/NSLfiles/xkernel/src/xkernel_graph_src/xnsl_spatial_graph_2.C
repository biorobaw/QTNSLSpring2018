/* SCCS  %W%---%E%--%U% */
//
//	xnsl_spatial_graph_2.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_spatial_graph_2::xnsl_spatial_graph_2(xnsl_display_canvas* win) : 
	xnsl_graph(win)
{
    set_type("spatial_graph_2");

//  if (win != NULL)
//        win->set_clear_fg(NSL_ON);

//  clear_fg = 1;

//	pulsefg = 0;
//	set_menu_canvas_events(canvas);
}
xnsl_spatial_graph_2::~xnsl_spatial_graph_2()  
{
}

xnsl_widget * xnsl_spatial_graph_2::make_widget()
{
	cmd_error("xnsl_spatial_graph_2: CANNOT create widget");
        return 0;
}

int xnsl_spatial_graph_2::display()
{
//      display_spatial_graph_2(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys,_wymin,_wymax);
         
       	return 1;
}
int xnsl_spatial_graph_2::display_spatial_graph_2(xnsl_widget*,
	int,int,int,int,int,int,
	num_type, num_type)
{
 	return 1;
}

int xnsl_spatial_graph_2::read_from_database()
{
	return 1;
}
int xnsl_spatial_graph_2::write_to_database()
{
	return 1;
}
int xnsl_spatial_graph_2::input(int x_pos,int y_pos,int fg)
{
	return 1;
}
int xnsl_spatial_graph_2::output(int x_pos,int y_pos)
{
	return 1;
}
int xnsl_spatial_graph_2::print(ostream& out) const
{
	return 1;
}
