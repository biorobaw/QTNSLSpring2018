/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*        xnsl_cmd_display_canvas_area_level.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

// area level graph canvas

xnsl_cmd_display_canvas_area_level::xnsl_cmd_display_canvas_area_level()
{
        set_type("display_canvas_area_level_graph");
}
xnsl_cmd_display_canvas_area_level::~xnsl_cmd_display_canvas_area_level()
{
}
int xnsl_cmd_display_canvas_area_level::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
/* AW98 if (win != NULL)
	{
	 	create_grid((xnsl_window*)win,x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);
  	}
  	else
		cmd_error("cmd_display_canvas_area_level: NULL window");
*/

	return 1;
}
int xnsl_cmd_display_canvas_area_level::update_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
/* AW98	xnsl_graph* cw;
 	nsl_list* list = 0;

   	if (win != NULL &&
	    (list = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
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
		cmd_error("cmd_display_canvas_area_level: NULL window");
 	}
  	else
		cmd_error("cmd_display_canvas_area_level: NULL window");
*/

	return 1;
}

int xnsl_cmd_display_canvas_area_level::create_graph(nsl_base*,
	int,int,int,int,int,int,int,int,int,int,nsl_layer*,const char*)
{
	return 1;
}
int xnsl_cmd_display_canvas_area_level::update_graph(nsl_base* win,
	int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer *layer,
	const char*)
{
	xnsl_cmd_display_canvas::update_graph(win, 
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);

	return 1;
}

