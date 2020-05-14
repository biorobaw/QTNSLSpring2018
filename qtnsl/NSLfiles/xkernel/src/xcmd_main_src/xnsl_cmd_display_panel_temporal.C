/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*          xnsl_cmd_display_panel_temporal.c                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel_temporal::xnsl_cmd_display_panel_temporal()
{
        set_type("display_panel_temporal_graph");
}
xnsl_cmd_display_panel_temporal::~xnsl_cmd_display_panel_temporal()
{
}
int xnsl_cmd_display_panel_temporal::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
        nsl_layer* data;
  	nsl_list* list = 0;
	num_type t = 0;
        nsl_base* pbase;
 	xnsl_window* pwin;
  	xnsl_panel_item* pw;

   	if ((pwin = (xnsl_window*) m_parent->get_ptr()) != NULL && win != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (list != NULL)
            {
            	if ((data = (nsl_layer*) list->get_by_name("t0")) != NULL)
	    	{
	            t = ((nsl_num_data*) data)->get_value();
		    pw = new xnsl_text_label_input((xnsl_display_panel*) win);
		    create_panel_item(win,pw,"t0",t);
  	    	}
            	else
                    cmd_error("cmd_display_panel: NULL 't0' obj");

           	if ((data = (nsl_layer*) list->get_by_name("t1")) != NULL)
	    	{
	            t = ((nsl_num_data*) data)->get_value();
		    pw = new xnsl_text_label_input((xnsl_display_panel*) win);
		    create_panel_item(win,pw,"t1",t);
  	    	}
            	else
                    cmd_error("cmd_display_panel: NULL 't1' obj");
	    }
 	}
  	else
		cmd_error("cmd_display_panel_temporal: NULL window");

	return 1;
}

