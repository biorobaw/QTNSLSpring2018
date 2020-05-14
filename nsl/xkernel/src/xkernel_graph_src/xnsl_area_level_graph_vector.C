/* SCCS  @(#)xnsl_area_level_graph_vector.C	1.1---96/02/20--19:21:53 */
//
//	xnsl_area_level_graph_vector.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 
#include "xnsl_area_level_graph_vector.h"

xnsl_area_level_graph_vector::xnsl_area_level_graph_vector(xnsl_display_canvas* win,nsl_layer* m) : xnsl_area_level_graph(win)
{
    set_type("area_level_graph_vector");

	init_area_level_graph_vector(m);

}

xnsl_area_level_graph_vector::~xnsl_area_level_graph_vector()
{
}

xnsl_widget * xnsl_area_level_graph_vector::make_widget()
{
    return new xnsl_area_level_graph_vector((xnsl_display_canvas*) m_parent,_layer);
}

int xnsl_area_level_graph_vector::init_area_level_graph_vector(nsl_layer* m)
{
	int id;

	if (m != NULL)
	{
		_layer = m;
		_imax = ((nsl_vector_layer*) _layer)->get_imax();
		_i0 = 0;
		_i1 = _imax - 1;
		_vec_type = NSL_ROW;
		id = m->get_type_id();
		if (id == 0)
			_layer0 = new NslFloat1(_imax);
		else if (id == 1)
			_layer0 = new NslFloat1(_imax);
		else if (id == 2)
			_layer0 = new NslFloat1(_imax);
		else
			cmd_out("Bad Type ID: ",id);
 	}
//	else
//		cmd_error("xnsl_area_level_graph_vec: NULL layer");

	return 1;
}
int xnsl_area_level_graph_vector::clear()
{
	int id = _layer->get_type_id();
	if (id == 0)
		*((NslFloat1*) _layer0) = 0;
	else if (id == 1)
		*((NslFloat1*) _layer0) = 0;
	else if (id == 2)
		*((NslFloat1*) _layer0) = 0;
	else
		cmd_out("Bad Type ID: ",id);


	return 1;
}

int xnsl_area_level_graph_vector::display()
{
//	set_env("",_X0,_Y0,_width,_height,_wx0,_wy0,_wx1,_wy1,_wxs,_wys);
    	display_area_level_graph(_widget,_wx0,_wy0,_wxs,_wys,_wymin,_wymax);
    	 
	return 1;
}

int xnsl_area_level_graph_vector::display_area_level_graph(xnsl_widget* widget,
	int wx0,int wy0,int wxs,int wys,
	num_type wymin, num_type wymax,int,int,int) 
{
	int fg; // redraw fg
	int i,ni;
	num_type val,val0;

//  nsl_num_vector* m0 = ((nsl_num_1*) _layer0);
//	nsl_num_vector* m = ((nsl_num_1*) _layer);
	int id = _layer->get_type_id();

//	if ((fg = parent_canvas->get_redraw_fg()) == 1)
//		parent_canvas->set_redraw_fg(0);

	int pos = 0;

 	if (_vec_type == NSL_ROW)
	    for (i = wx0, ni = _i0; ni <= _i1; i = i + wxs, ni++)
	    {
//			val = (*m)[ni];
//	     	val0 = (*m0)[ni];
			if (id == 0) {
				val = (*((NslFloat1*) _layer))[ni]; 
				val0 = (*((NslFloat1*) _layer0))[ni]; 
			} else if (id == 1) {
				val = (*((NslFloat1*) _layer))[ni]; 
				val0 = (*((NslFloat1*) _layer0))[ni]; 
			} else if (id == 2) {
				val = (*((NslFloat1*) _layer))[ni]; 
				val0 = (*((NslFloat1*) _layer0))[ni]; 
			} else
				cmd_out("Bad Type ID: ",id);
//AW99		if (val != val0) // || fg == 1) // new different values only
		{
//	 	    if (val < val0 || val < 0)
//				clear_area(widget,i+1,wy0+1,wxs-1,wys-1,pos);
		    display_area_level_graph_val(widget,i,wy0,wxs,wys,val,val0,wymin,wymax,ni);
		}
	    }
	else
	    for (i = wy0, ni = _i0; ni <= _i1; i = i + wys, ni++)
	    {
//			val = (*m)[ni];
//	     	val0 = (*m0)[ni];
			if (id == 0) {
				val = (*((NslFloat1*) _layer))[ni]; 
				val0 = (*((NslFloat1*) _layer0))[ni]; 
			} else if (id == 1) {
				val = (*((NslFloat1*) _layer))[ni]; 
				val0 = (*((NslFloat1*) _layer0))[ni]; 
			} else if (id == 2) {
				val = (*((NslFloat1*) _layer))[ni]; 
				val0 = (*((NslFloat1*) _layer0))[ni]; 
			} else
				cmd_out("Bad Type ID: ",id);
//		if (val != val0) // || fg == 1) // new different values only
		{
//	 	    if (val < val0 || val < 0)
//			clear_area_level(wx0,i,wxs,wys);
		    display_area_level_graph_val(widget,wx0,i,wxs,wys,val,val0,wymin,wymax,ni);
		}
	    }

//	for (i = 0; i < _imax; i++)
//		(*m0)[i] = (*m)[i];

//	*m0 = *m;

	if (id == 0) 
		*((NslFloat1*) _layer0) = *((NslFloat1*) _layer);
	else if (id == 1)
		*((NslFloat1*) _layer0) = *((NslFloat1*) _layer);
	else if (id == 2)
		*((NslFloat1*) _layer0) = *((NslFloat1*) _layer);
	else
		cmd_out("Bad Type ID: ",id);

	return 1;
}

int xnsl_area_level_graph_vector::read_from_database()
{
	xnsl_area_level_graph::read_from_database(); // read in new win sector

	return 1;
}
int xnsl_area_level_graph_vector::write_to_database()
{
	xnsl_area_level_graph::write_to_database();

	return 1;
}
int xnsl_area_level_graph_vector::input(int x_pos,int y_pos,int fg)
{
/*
	float val;
	int i,ni;

	num_type* m0 = ((nsl_num_1*) layer0_ptr)->get_vector();
	num_type* m = ((nsl_num_1*) layer_ptr)->get_vector();

	if (fg == 1)
	   val = 0.0;
	else
	   parent_window->get_general_data("val_in",&val);

	if (y_pos <= wy1 && y_pos >= wy0 && x_pos <= wx1 && x_pos >= wx0)
	{
	    if (vec_type == 0)
	    {
	       for (i = wx0, ni = i0 ; i + wxs <= x_pos; ni++, i = i + wxs);
    	       draw_xnsl_area_level_val(canvas,i,wy0,wxs,wys,val,wymin,wymax);
	    }
	    else
	    {
	    	for (i = wy0, ni = i0 ; i + wys <= y_pos; ni++, i = i + wys);
    	    	draw_xnsl_area_level_val(canvas,wx0,i,wxs,wys,val,wymin,wymax);
	    }
	    m0[ni] = val;
	    m[ni] = val;
	}
*/
	return 1;
}
int xnsl_area_level_graph_vector::output(int x_pos,int y_pos)
{
	return 1;
}

int xnsl_area_level_graph_vector::print(ostream& out) const
{
	xnsl_area_level_graph::print(out);

	return 1;
}

