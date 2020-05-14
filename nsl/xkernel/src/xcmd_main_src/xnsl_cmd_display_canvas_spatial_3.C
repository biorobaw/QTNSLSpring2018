/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*         xnsl_cmd_display_canvas_spatial_3.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_canvas_spatial_3::xnsl_cmd_display_canvas_spatial_3()
{
        set_type("display_canvas_spatial_graph_3");
}
xnsl_cmd_display_canvas_spatial_3::~xnsl_cmd_display_canvas_spatial_3()
{
}
int xnsl_cmd_display_canvas_spatial_3::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_canvas_spatial_3::update_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_canvas_spatial_3::create_graph(nsl_base*,
	int,int,int,int,int,int,int,int,int,int,nsl_layer*,const char*)
{
  	return 1;
}
int xnsl_cmd_display_canvas_spatial_3::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
	xnsl_spatial_graph_3* cw;
 	nsl_list* list = 0;
	nsl_list* dlist = 0;
        nsl_base* pbase;
	num_type s = 0;
	int i = 0;
	nsl_layer* data;

   	if (win != NULL &&
	    (list = ((xnsl_window*) win)->get_data_list()) &&
	    (cw = (xnsl_spatial_graph_3*) list->get_by_name("graph")) != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                dlist = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (dlist != NULL)
            {
            	if ((data = (nsl_layer*) dlist->get_by_name("ax")) != NULL)
	    	{
	            s = ((nsl_num_data*) data)->get_value();
		    cw->set_ax(s);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'ax' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("by")) != NULL)
	    	{
	            s = ((nsl_num_data*) data)->get_value();
		    cw->set_by(s);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'by' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("cz")) != NULL)
	    	{
	            s = ((nsl_num_data*) data)->get_value();
		    cw->set_cz(s);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'cz' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("sx")) != NULL)
	    	{
	            s = ((nsl_num_data*) data)->get_value();
		    cw->set_sx(s);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'sx' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("sy")) != NULL)
	    	{
	            s = ((nsl_num_data*) data)->get_value();
		    cw->set_sy(s);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'sy' obj");

            
            	if ((data = (nsl_layer*) dlist->get_by_name("sz")) != NULL)
	    	{
	            s = ((nsl_num_data*) data)->get_value();
		    cw->set_sz(s);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'sz' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("hidden"))
            		 != NULL)
	    	{
	            i = ((nsl_on_off_data*) data)->get_value();
		    cw->set_hidden_fg(i);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'hidden' obj");
	    }
  	}
  	else
		cmd_error("cmd_display_canvas_spatial_2_vector: NULL window");

	xnsl_cmd_display_canvas::update_graph(win,x,y,w,h,
		wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

