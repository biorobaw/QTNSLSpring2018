/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*         xnsl_cmd_display_canvas_spatial_2.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_canvas_spatial_2::xnsl_cmd_display_canvas_spatial_2()
{
        set_type("display_canvas_spatial_graph_2");
}
xnsl_cmd_display_canvas_spatial_2::~xnsl_cmd_display_canvas_spatial_2()
{
}
int xnsl_cmd_display_canvas_spatial_2::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
   	if (win != NULL)
	{
// AW98	    create_grid((xnsl_window*)win,x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);
//	    create_line((xnsl_window*)win,x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);//0.0
 	}
  	else
		cmd_error("cmd_display_canvas_spatial_2: NULL window");

	return 1;
}
int xnsl_cmd_display_canvas_spatial_2::update_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
	xnsl_graph* cw = 0;
 	nsl_list* list = 0;
	num_type wymin = 0.0, wymax = 1.0;
	nsl_layer* data = 0;

   	if (win != NULL &&
	    (list = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
/* AW 98    if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL)
	    {
	            wymin = ((nsl_num_data*) data)->get_value();
  	    }
            else
                    cmd_error("cmd_display_canvas: NULL 'wymin' obj");

            if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL)
	    {
	            wymax = ((nsl_num_data*) data)->get_value();
  	    }
            else
                    cmd_error("cmd_display_canvas: NULL 'wymax' obj");

	    if ((cw = (xnsl_graph*) list->get_by_name("grid")) != NULL)
	    {
	    	cw->set_wx0(wx0);
	    	cw->set_wx1(wx1);
	    	cw->set_wy0(wy0);
	    	cw->set_wy1(wy1);
	    	cw->set_wxs(wxs);
	    	cw->set_wys(wys);
	    }
	    else
		cmd_error("cmd_display_canvas_spatial_2: NULL grid");

	    if ((cw = (xnsl_graph*) list->get_by_name("line")) != NULL)
	    {
	    	cw->set_wx0(wx0);
	    	cw->set_wx1(wx1);
	    	cw->set_wy0(wy0);
	    	cw->set_wy1(wy1);
	    	cw->set_wxs(wxs);
	    	cw->set_wys(wys);

		cw->set_wymin(wymin);
		cw->set_wymax(wymax);
	    }
	    else
		cmd_error("cmd_display_canvas_spatial_2: NULL line");
*/  	}
  	else
		cmd_error("cmd_display_canvas_spatial_2: NULL window");

	return 1;
}
int xnsl_cmd_display_canvas_spatial_2::create_graph(nsl_base*,
	int,int,int,int,int,int,int,int,int,int,nsl_layer*,const char*)
{
	return 1;
}
int xnsl_cmd_display_canvas_spatial_2::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
	xnsl_cmd_display_canvas::update_graph(win, 
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

