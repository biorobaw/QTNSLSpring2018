/* SCCS  @(#)xnsl_cmd_display_panel_area_level_data.C	1.1---96/02/02--18:14:46 */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_panel_area_level_data.C         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel_area_level_data::
	xnsl_cmd_display_panel_area_level_data()
{
        set_type("display_panel_area_level_graph_data");
}
xnsl_cmd_display_panel_area_level_data::
	~xnsl_cmd_display_panel_area_level_data()
{
}
int xnsl_cmd_display_panel_area_level_data::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
   	if (win != NULL)
	{
 	    xnsl_cmd_display_panel_area_level::create_data((xnsl_window*)win,
		x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);
  	}
  	else
		cmd_error("cmd_display_panel_area_level: NULL window");

	return 1;
}

