/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_canvas_spatial_3_vector.C       */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 


xnsl_cmd_display_canvas_spatial_3_vector::
	xnsl_cmd_display_canvas_spatial_3_vector()
{
        set_type("display_canvas_spatial_graph_3_vector");
}
xnsl_cmd_display_canvas_spatial_3_vector::
	~xnsl_cmd_display_canvas_spatial_3_vector()
{
}
int xnsl_cmd_display_canvas_spatial_3_vector::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
 	xnsl_cmd_display_canvas_spatial_3::create_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}
int xnsl_cmd_display_canvas_spatial_3_vector::update_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
 	xnsl_cmd_display_canvas_spatial_3::update_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}
int xnsl_cmd_display_canvas_spatial_3_vector::create_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
	xnsl_widget* canvas;
 	xnsl_canvas_item* cw;
 	nsl_list* dlist = 0;
	nsl_string str;
 
  	if (win != NULL && 
	    (dlist = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
            cw = new xnsl_spatial_graph_3_vector((xnsl_display_canvas*) win,(nsl_num_1*)layer);
            ((xnsl_window*) win)->add_data(cw);

	    strcpy(str,win->get_name());

  	    if (cw != NULL && (canvas = ((xnsl_window*) win)->
						get_widget()) != NULL)
	    {
		cw->set_name("graph");
		cw->set_wname(str);
   		cw->create_widget(str,canvas,x,y,w,h,
			wx0,wy0,wx1,wy1,wxs,wys);
	    }
  	}
	else
	    cmd_error("cmd_display_canvas_spatial_3_vec: Cannot create graph");

 	return 1;
}
int xnsl_cmd_display_canvas_spatial_3_vector::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
	xnsl_graph* cw;
 	nsl_list* list = 0;
	nsl_list* dlist = 0;
        nsl_base* pbase;
	int i = 0;
	nsl_layer* data;

   	if (win != NULL &&
	    (list = ((xnsl_window*) win)->get_data_list()) &&
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
		    ((xnsl_spatial_graph_3_vector*) cw)->set_i0(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'i0' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("i1")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
		    ((xnsl_spatial_graph_3_vector*) cw)->set_i1(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'i1' obj");
	    }
  	}
  	else
		cmd_error("cmd_display_canvas_spatial_3_vector: NULL window");

	xnsl_cmd_display_canvas_spatial_3::update_graph(win, 
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

