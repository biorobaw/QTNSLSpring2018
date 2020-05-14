/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*          xnsl_cmd_display_canvas_temporal.c                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_canvas_temporal::xnsl_cmd_display_canvas_temporal()
{
        set_type("display_canvas_temporal_graph");
}
xnsl_cmd_display_canvas_temporal::~xnsl_cmd_display_canvas_temporal()
{
}
int xnsl_cmd_display_canvas_temporal::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
        nsl_layer* data;
  	nsl_list* list = 0;
	num_type t = 0;
        nsl_base* pbase;

   	if (win != NULL)
	{
/* AW98	    create_grid(win,x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys,NSL_ON);
	    create_line(win,x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);//0.0
*/
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

/*          if (list != NULL)
            {
            	if ((data = (nsl_layer*) list->get_by_name("t0")) != NULL)
	    	{
	            t = ((nsl_num_data*) data)->get_value();
           	    create_bot_text((xnsl_window*)win,"t0",t);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 't0' obj");

           	if ((data = (nsl_layer*) list->get_by_name("t1")) != NULL)
	    	{
	            t = ((nsl_num_data*) data)->get_value();
           	    create_bot_text((xnsl_window*)win,"t1",t);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 't1' obj");
	    }
*/
 	}
  	else
		cmd_error("cmd_display_canvas_temporal: NULL window");

	return 1;
}
int xnsl_cmd_display_canvas_temporal::update_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
	xnsl_graph* cw;
 	nsl_list* list = 0;
	nsl_list* dlist = 0;
        nsl_base* pbase;
	num_type t0 = 0.0, t1 = 1.0;
	num_type wymin = 0.0, wymax = 1.0, wystep = 1.0, wxstep = 1.0;
	nsl_layer* data;

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
               	if ((data = (nsl_layer*) dlist->get_by_name("t0")) != NULL)
	       	{
	            t0 = ((nsl_num_data*) data)->get_value();
		    ((xnsl_temporal_graph*) cw)->set_t0(t0);
 		    ((xnsl_temporal_graph*) cw)->set_wxmin(t0);
	       	}
               	else
                    cmd_error("cmd_display_canvas_temporal: NULL 't0' obj");

               	if ((data = (nsl_layer*) dlist->get_by_name("t1")) != NULL)
	       	{
	            t1 = ((nsl_num_data*) data)->get_value();
		    ((xnsl_temporal_graph*) cw)->set_t1(t1);
 		    ((xnsl_temporal_graph*) cw)->set_wxmax(t1);
	       	}
               	else
                    cmd_error("cmd_display_canvas_temporal: NULL 't1' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("wymin")) != NULL)
	    	{
	            wymin = ((nsl_num_data*) data)->get_value();
 		    ((xnsl_temporal_graph*) cw)->set_wymin(wymin);
 	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'wymin' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("wymax")) != NULL)
	    	{
	            wymax = ((nsl_num_data*) data)->get_value();
 		    ((xnsl_temporal_graph*) cw)->set_wymax(wymax);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'wymax' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("wystep")) != NULL)
	    	{
	            wystep = ((nsl_num_data*) data)->get_value();
 		    ((xnsl_temporal_graph*) cw)->set_wystep(wystep);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'wystep' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("wxstep")) != NULL)
	    	{
	            wxstep = ((nsl_num_data*) data)->get_value();
 		    ((xnsl_temporal_graph*) cw)->set_wxstep(wxstep);
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'wxstep' obj");

/* AW98	    	if ((cw = (xnsl_graph*) list->get_by_name("grid")) != NULL)
	    	{
	    		cw->set_wx0(wx0);
	    		cw->set_wx1(wx1);
	    		cw->set_wy0(wy0);
	    		cw->set_wy1(wy1);
	    		cw->set_wxs(wxs);
	    		cw->set_wys(wys);

		    	cw->set_wxmin(t0);
		    	cw->set_wxmax(t1);
		    	
		    	cw->set_wymin(wymin);
		    	cw->set_wymax(wymax);  
		    	
		    	cw->set_wxstep(wxstep);
		    	cw->set_wystep(wystep);	   	
		}
  	    	else
			cmd_error("cmd_display_canvas_temporal: NULL grid");

	    	if ((cw = (xnsl_graph*) list->get_by_name("line")) != NULL)
	    	{
	    		cw->set_wx0(wx0);
	    		cw->set_wx1(wx1);
	    		cw->set_wy0(wy0);
	    		cw->set_wy1(wy1);
	    		cw->set_wxs(wxs);
	    		cw->set_wys(wys);

		    	cw->set_wxmin(t0);
		    	cw->set_wxmax(t1);  

		    	cw->set_wymin(wymin);
		    	cw->set_wymax(wymax);

		    	cw->set_wxstep(wxstep);
		    	cw->set_wystep(wystep);	   	
	    	}
	    	else
			cmd_error("cmd_display_canvas_area_level: NULL line");
*/	    }
            else
                cmd_error("cmd_display_canvas_temporal: NULL data list");

  	}
  	else
		cmd_error("cmd_display_canvas_temporal: NULL window");

	return 1;
}
int xnsl_cmd_display_canvas_temporal::create_graph(nsl_base*,
	int,int,int,int,int,int,int,int,int,int,nsl_layer*,const char*)
{
  	return 1;
}
int xnsl_cmd_display_canvas_temporal::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
	xnsl_cmd_display_canvas::update_graph(win,x,y,w,h,
		wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

