/* SCCS  @(#)xnsl_area_level_graph_data.C	1.1---96/02/20--19:21:44 */
//
//	xnsl_area_level_graph_data.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_area_level_graph_data::xnsl_area_level_graph_data(
	xnsl_display_canvas* win, nsl_layer* m) : xnsl_area_level_graph(win)
{
    set_type("area_level_graph_data");
	int id;

	if (m != NULL)
	{
		_layer = m;
		id = m->get_type_id();
		if (id == 0)
			_layer0 = new NslFloat0();
		else if (id == 1)
			_layer0 = new NslFloat0();
		else if (id == 2)
			_layer0 = new NslFloat0();
		else
			cmd_out("Bad Type ID: ",id);
	}
//	else
//		cmd_error("xnsl_area_level_graph_dat: NULL layer");
}
xnsl_area_level_graph_data::~xnsl_area_level_graph_data()
{
}
xnsl_widget * xnsl_area_level_graph_data::make_widget()
{
    return new xnsl_area_level_graph_data((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_area_level_graph_data::clear()
{
	int id = _layer->get_type_id();
	if (id == 0)
		((NslFloat0*) _layer0)->set_value(0);
	else if (id == 1)
		((NslFloat0*) _layer0)->set_value(0);
	else if (id == 2)
		((NslFloat0*) _layer0)->set_value(0);
	else
		cmd_out("Bad Type ID: ",id);


	return 1;
}
int xnsl_area_level_graph_data::display()
{
    display_area_level_graph(_widget,_wx0,_wy0,_wxs,_wys,_wymin,_wymax);
    
	return 1;
}
int xnsl_area_level_graph_data::display_area_level_graph(xnsl_widget* widget,
	int wx0,int wy0,int wxs,int wys,
	num_type wymin, num_type wymax,int,int,int) 
{
	int fg; // redraw fg
	int id = _layer->get_type_id();

//	num_type val0 = ((nsl_num_0*) _layer0)->get_data();
//	num_type val = ((nsl_num_0*) _layer)->get_data();
	float val, val0;

	if (id == 0) {
		val = ((NslFloat0*) _layer)->get_data(); 
		val0 = ((NslFloat0*) _layer0)->get_data(); 
	} else if (id == 1) {
		val = ((NslFloat0*) _layer)->get_data(); 
		val0 = ((NslFloat0*) _layer0)->get_data(); 
	} else if (id == 2) {
		val = ((NslFloat0*) _layer)->get_data(); 
		val0 = ((NslFloat0*) _layer0)->get_data(); 
	} else
		cmd_out("Bad Type ID: ",id);

//	if ((fg = parent_canvas->get_redraw_fg()) == 1)
//		parent_canvas->set_redraw_fg(0);

//AW99	if (val != val0 /*|| fg == 1*/) // new different values only
	{
//	     if (val < val0 || val < 0)
//		clear_area_level(wx0,wy0,wxs,wys);
 	     display_area_level_graph_val(widget,wx0,wy0,wxs,wys,val,val0,wymin,wymax);
	}

	id = _layer->get_type_id();
	if (id == 0)
		((NslFloat0*) _layer0)->set_value(val);
	else if (id == 1)
		((NslFloat0*) _layer0)->set_value(val);
	else if (id == 2)
		((NslFloat0*) _layer0)->set_value(val);
	else
		cmd_out("Bad Type ID: ",id);


	return 1;
}

int xnsl_area_level_graph_data::read_from_database()
{
//	parent_window->set_win_sector(0,0,0,0,1,1); // update win sector
//	xnsl_area_level_graph::read_from_database(); // read in new win sector

	return 1;
}
int xnsl_area_level_graph_data::write_to_database()
{
//	xnsl_area_level_graph::write_to_database();

	return 1;
}
int xnsl_area_level_graph_data::input(int x_pos,int y_pos,int fg)
{
/*	float val;

	num_type m0 = ((nsl_num_0*) _layer0)->get_data();
	num_type m = ((nsl_num_0*) _layer)->get_data();

	if (fg == 1)
	   val = 0.0;
	else
	   parent_window->get_general_data("val_in",&val);

	if (y_pos <= wy1 && y_pos >= wy0 && x_pos <= wx1 && x_pos >= wx0)
	{
    	    display_area_level_graph_val(wx0,wy0,wxs,wys,val,wymin,wymax);

	    ((nsl_num_0*) _layer0)->set_value(val);
	    ((nsl_num_0*) _layer)->set_value(val);
	}
*/
	return 1;
}
int xnsl_area_level_graph_data::output(int x_pos,int y_pos)
{
/*	float val;

	if (y_pos <= wy1 && y_pos >= wy0 && x_pos <= wx1 && x_pos >= wx0)
	{
	    val = ((nsl_num_0*) layer_ptr)->get_value();

	    parent_window->set_general_data("val_out",val);
	}
*/
	return 1;
}
int xnsl_area_level_graph_data::print(ostream& out) const
{
	xnsl_area_level_graph::print(out);

	return 1;
}
