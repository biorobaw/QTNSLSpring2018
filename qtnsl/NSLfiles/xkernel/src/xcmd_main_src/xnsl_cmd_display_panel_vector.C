/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*              xnsl_cmd_display_panel_vector.C               */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel_vector::xnsl_cmd_display_panel_vector()
{
	set_type("display_panel_vector");
}
xnsl_cmd_display_panel_vector::~xnsl_cmd_display_panel_vector()
{
}
int xnsl_cmd_display_panel_vector::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        nsl_layer* data;
  	nsl_list* list = 0;
	int i = 0;
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
            	if ((data = (nsl_layer*) list->get_by_name("i0")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
		    pw = new xnsl_text_label_input((xnsl_display_panel*) win);
		    create_panel_item(win,pw,"i0",i);
  	    	}
            	else
                    cmd_error("cmd_display_panel: NULL 'i0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("i1")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
		    pw = new xnsl_text_label_input((xnsl_display_panel*) win);
		    create_panel_item(win,pw,"i1",i);
  	    	}
            	else
                    cmd_error("cmd_display_panel: NULL 'i1' obj");

            	if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL)
	    	{
	            i = ((nsl_int_data*) data)->get_value();
		    pw = new xnsl_text_label_panel((xnsl_display_panel*) win);
		    create_panel_item(win,pw,"imax",i);
  	    	}
            	else
                    cmd_error("cmd_display_panel: NULL 'imax' obj");
	    }
            else
                cmd_error("cmd: NULL list");
  	}
	else
		cmd_error("cmd_display_panel_vector: CANNOT add data");
 
	return 1; 
}
int xnsl_cmd_display_panel_vector::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
} 

