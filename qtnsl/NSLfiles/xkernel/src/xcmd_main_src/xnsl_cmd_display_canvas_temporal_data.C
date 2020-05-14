/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_canvas_temporal_data.C          */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_canvas_temporal_data::
	xnsl_cmd_display_canvas_temporal_data()
{
        set_type("display_canvas_temporal_graph_data");
}
xnsl_cmd_display_canvas_temporal_data::
	~xnsl_cmd_display_canvas_temporal_data()
{
}
int xnsl_cmd_display_canvas_temporal_data::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
 	xnsl_cmd_display_canvas_temporal::create_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}
int xnsl_cmd_display_canvas_temporal_data::update_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
 	xnsl_cmd_display_canvas_temporal::update_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}
int xnsl_cmd_display_canvas_temporal_data::create_graph(nsl_base* win,
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
            cw = new xnsl_temporal_graph_data((xnsl_display_canvas*) win,layer);
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
	    cmd_error("cmd_display_canvas_temporal_dat: Cannot create graph");

 	return 1;
}
int xnsl_cmd_display_canvas_temporal_data::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
//AW98	xnsl_cmd_display_canvas_temporal::update_graph(win,
//		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

