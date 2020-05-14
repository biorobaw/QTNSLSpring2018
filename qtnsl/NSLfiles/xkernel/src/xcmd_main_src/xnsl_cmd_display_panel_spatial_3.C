/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*         xnsl_cmd_display_panel_spatial_3.C                 */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel_spatial_3::xnsl_cmd_display_panel_spatial_3()
{
        set_type("display_panel_spatial_graph_3");
}
xnsl_cmd_display_panel_spatial_3::~xnsl_cmd_display_panel_spatial_3()
{
}
int xnsl_cmd_display_panel_spatial_3::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
   	if (win != NULL)
	{
  	}
  	else
		cmd_error("cmd_display_panel_spatial_3: NULL window");

	return 1;
}

