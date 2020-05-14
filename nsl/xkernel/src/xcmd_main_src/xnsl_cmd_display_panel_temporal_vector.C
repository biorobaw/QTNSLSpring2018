/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_panel_temporal_vector.C         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel_temporal_vector::
	xnsl_cmd_display_panel_temporal_vector()
{
        set_type("display_panel_temporal_graph_vector");
}
xnsl_cmd_display_panel_temporal_vector::
	~xnsl_cmd_display_panel_temporal_vector()
{
}
int xnsl_cmd_display_panel_temporal_vector::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
   	if (win != NULL)
	{
 	    xnsl_cmd_display_panel_temporal::create_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);
  	}
  	else
		cmd_error("cmd_display_panel_temporal: NULL window");

	return 1;
}

