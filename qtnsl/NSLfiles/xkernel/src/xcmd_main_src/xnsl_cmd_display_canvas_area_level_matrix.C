/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_canvas_area_level_matrix.C      */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_canvas_area_level_matrix::
	xnsl_cmd_display_canvas_area_level_matrix()
{
        set_type("display_canvas_area_level_graph_matrix");
}
xnsl_cmd_display_canvas_area_level_matrix::
	~xnsl_cmd_display_canvas_area_level_matrix()
{
}
int xnsl_cmd_display_canvas_area_level_matrix::create_data(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
 	xnsl_cmd_display_canvas_area_level::create_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}
int xnsl_cmd_display_canvas_area_level_matrix::update_data(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
 	xnsl_cmd_display_canvas_area_level::update_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}
int xnsl_cmd_display_canvas_area_level_matrix::create_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char* side)
{
	xnsl_widget* canvas;
 	xnsl_canvas_item* cw;
 	nsl_list* dlist = 0;
	nsl_string str;
 
  	if (win != NULL && 
	    (dlist = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
            cw = new xnsl_area_level_graph_matrix((xnsl_display_canvas*) win,layer);
            ((xnsl_window*) win)->add_data(cw);

	    strcpy(str,win->get_name());

  	    if (cw != NULL && (canvas = ((xnsl_window*) win)->
						get_widget()) != NULL)
	    {
		cw->set_name("graph");
		cw->set_wname(str);
   		cw->create_widget(str,canvas,x,y,w,h,
			wx0,wy0,wx1,wy1,wxs,wys,side);
	    }
  	}
	else
	    cmd_error("cmd_display_canvas_area_level_mat: Cannot create graph");

 	return 1;
}
int xnsl_cmd_display_canvas_area_level_matrix::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer* layer,const char*)
{
	xnsl_graph* cw;
 	nsl_list* list = 0;
	nsl_list* dlist = 0;
    nsl_base* pbase;
	int i = 0,imax,jmax;
	nsl_layer* data;
	
/*	if (layer != NULL) {
		imax = ((nsl_num_2*) layer)->get_imax();
		jmax = ((nsl_num_2*) layer)->get_jmax();
	}
	else {
		cmd_out("xnsl_cmd_display_canvas_area_level_matrix::NULL layer");
		return 1;
	}
*/
   	if (win != NULL &&
	    (list = ((xnsl_window*) win)->get_data_list()) != NULL &&
	    (cw = (xnsl_graph*) list->get_by_name("graph")) != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                dlist = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (dlist != NULL)
            {
            	if ((data = (nsl_layer*) dlist->get_by_name("i0")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
				((xnsl_area_level_graph_matrix*) cw)->set_i0(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'i0' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("i1")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
				((xnsl_area_level_graph_matrix*) cw)->set_i1(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'i1' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("j0")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
				((xnsl_area_level_graph_matrix*) cw)->set_j0(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'j0' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("j1")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
				((xnsl_area_level_graph_matrix*) cw)->set_j1(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'j1' obj");
	    }
  	}
  	else
		cmd_error("cmd_display_canvas_area_level_matrix: NULL window");

	xnsl_cmd_display_canvas_area_level::update_graph(win, 
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

