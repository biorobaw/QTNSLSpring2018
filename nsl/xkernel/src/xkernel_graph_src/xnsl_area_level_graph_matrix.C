/* SCCS  %W%---%E%--%U% */
//
//	xnsl_area_level_graph_matrix.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_area_level_graph_matrix::xnsl_area_level_graph_matrix(
	xnsl_display_canvas* win,nsl_layer* m) : xnsl_area_level_graph(win) 
{
    set_type("area_level_graph_matrix");
	int id = 0;

	if (m != NULL)
	{
		_layer = m;
		_imax = ((nsl_matrix_layer*) _layer)->get_imax();
		_jmax = ((nsl_matrix_layer*) _layer)->get_jmax();
		_i0 = 0;
		_i1 = _imax - 1;
		_j0 = 0;
		_j1 = _jmax - 1;
		id = m->get_type_id();
		if (id == 0)
			_layer0 = new NslFloat2(_imax,_jmax);
		else if (id == 1)
			_layer0 = new NslFloat2(_imax,_jmax);
		else if (id == 2)
			_layer0 = new NslFloat2(_imax,_jmax);
		else
			cmd_out("Bad Type ID: ",id);
	}
//	else
//		cmd_error("xnsl_area_level_graph_mat: NULL layer");
}
xnsl_area_level_graph_matrix::~xnsl_area_level_graph_matrix()
{
}

xnsl_widget * xnsl_area_level_graph_matrix::make_widget()
{
    return new xnsl_area_level_graph_matrix((xnsl_display_canvas*) m_parent,_layer);
}
int xnsl_area_level_graph_matrix::clear()
{
	int id = _layer->get_type_id();
	if (id == 0)
		*((NslFloat2*) _layer0) = 0;
	else if (id == 1)
		*((NslFloat2*) _layer0) = 0;
	else if (id == 2)
		*((NslFloat2*) _layer0) = 0;
	else
		cmd_out("Bad Type ID: ",id);

	return 1;
}
int xnsl_area_level_graph_matrix::display()
{
    display_area_level_graph(_widget,_wx0,_wy0,_wxs,_wys,_wymin,_wymax);
    	 
	return 1;
}
int xnsl_area_level_graph_matrix::display_area_level_graph(xnsl_widget* widget,
	int wx0,int wy0,int wxs,int wys,
	num_type wymin, num_type wymax,int,int,int)
{
	int fg; // redraw fg
	int i,j,ni,nj;
	num_type val,val0;

	// nsl_num_matrix* m0 = ((nsl_num_2*) _layer0);
	// nsl_num_matrix* m = ((nsl_num_2*) _layer);
	int id = _layer->get_type_id();

//	if ((fg = parent_canvas->get_redraw_fg()) == 1)
//		parent_canvas->set_redraw_fg(0);

 	for (j = wy0, ni = _i0; ni <= _i1; j = j + wys, ni++)
	    for (i = wx0, nj = _j0; nj <= _j1; i = i + wxs, nj++)
	    {
//			val = (*m)[ni][nj];
//			val0 = (*m0)[ni][nj];
			if (id == 0) {
				val = (*((NslFloat2*) _layer))[ni][nj]; 
				val0 = (*((NslFloat2*) _layer0))[ni][nj]; 
			} else if (id == 1) {
				val = (*((NslFloat2*) _layer))[ni][nj]; 
				val0 = (*((NslFloat2*) _layer0))[ni][nj]; 
			} else if (id == 2) {
				val = (*((NslFloat2*) _layer))[ni][nj]; 
				val0 = (*((NslFloat2*) _layer0))[ni][nj]; 
			} else
				cmd_out("Bad Type ID: ",id);
	
//AW99		if (val != val0 /*|| fg == 1*/) // new different values only
			{
//	 			if (val < val0 || val < 0)
//				clear_area_level(i,j,wxs,wys);
				display_area_level_graph_val(widget,i,j,wxs,wys,val,val0,wymin,wymax,ni,nj);
			}
	    }

/*	for (i = 0; i < _imax; i++)
	   for (j = 0; j < _jmax; j++)
		m0[i][j] = m[i][j];
*/
//	*m0 = *m;
	if (id == 0) 
		*((NslFloat2*) _layer0) = *((NslFloat2*) _layer);
	else if (id == 1)
		*((NslFloat2*) _layer0) = *((NslFloat2*) _layer);
	else if (id == 2)
		*((NslFloat2*) _layer0) = *((NslFloat2*) _layer);
	else
		cmd_out("Bad Type ID: ",id);

	return 1;
}

int xnsl_area_level_graph_matrix::read_from_database()
{
	return 1;
}
int xnsl_area_level_graph_matrix::write_to_database()
{
	return 1;
}
int xnsl_area_level_graph_matrix::input(int x_pos,int y_pos,int fg)
{
/*	float val;
	int i,j,ni,nj;

	num_type** m0 = ((nsl_num_2*) layer0_ptr)->get_matrix();
	num_type** m = ((nsl_num_2*) layer_ptr)->get_matrix();

	if (fg == 1)
	   val = 0.0;
	else
	   parent_window->get_general_data("val_in",&val);

	if (y_pos <= wy1 && y_pos >= wy0 && x_pos <= wx1 && x_pos >= wx0)
	{
// x,y crossed
//	    for (i = wx0, ni = i0; i + wxs <= x_pos; ni++, i = i + wxs);
//	    for (j = wy0, nj = j0; j + wys <= y_pos; nj++, j = j + wys);
	    for (i = wx0, nj = j0; i + wxs <= x_pos; nj++, i = i + wxs);
	    for (j = wy0, ni = i0; j + wys <= y_pos; ni++, j = j + wys);

    	    draw_xnsl_area_level_val(canvas,i,j,wxs,wys,val,wymin,wymax);

	    m0[ni][nj] = val;
	    m[ni][nj] = val;
	}
*/
	return 1;
}
int xnsl_area_level_graph_matrix::output(int x_pos,int y_pos)
{
/*	float val;
	int i,j,ni,nj;

	if (y_pos <= wy1 && y_pos >= wy0 && x_pos <= wx1 && x_pos >= wx0)
	{
// x,y crossed
//	    for (i = wx0, ni = i0 ; i + wxs <= x_pos; ni++, i = i + wxs);
//	    for (j = wy0, nj = j0; j + wys <= y_pos; nj++, j = j + wys);
	    for (i = wx0, nj = j0; i + wxs <= x_pos; nj++, i = i + wxs);
	    for (j = wy0, ni = i0; j + wys <= y_pos; ni++, j = j + wys);

	    if (ni < imax && nj < jmax)
	    {
	    	val = ((nsl_num_2*) layer_ptr)->elem(ni,nj);

	    	parent_window->set_general_data("elem_i",ni);
	    	parent_window->set_general_data("elem_j",nj);
	    	parent_window->set_general_data("val_out",val);
	    }
	}
*/
	return 1;
}
int xnsl_area_level_graph_matrix::print(ostream& out) const
{
	xnsl_area_level_graph::print(out);

	return 1;
}

