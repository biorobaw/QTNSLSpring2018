/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*         xnsl_cmd_display_panel_spatial_2.c                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

// spatial graph 2 panel

xnsl_cmd_display_panel_spatial_2::xnsl_cmd_display_panel_spatial_2()
{
        set_type("display_panel_spatial_graph_2");
}
xnsl_cmd_display_panel_spatial_2::~xnsl_cmd_display_panel_spatial_2()
{
}
int xnsl_cmd_display_panel_spatial_2::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
   	if (win != NULL)
	{
 	}
  	else
		cmd_error("cmd_display_panel_spatial_2: NULL window");

	return 1;
}

