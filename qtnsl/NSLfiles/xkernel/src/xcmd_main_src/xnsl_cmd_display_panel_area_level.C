/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*        xnsl_cmd_display_panel_area_level.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

// area level graph panel

xnsl_cmd_display_panel_area_level::xnsl_cmd_display_panel_area_level()
{
        set_type("display_panel_area_level_graph");
}
xnsl_cmd_display_panel_area_level::~xnsl_cmd_display_panel_area_level()
{
}
int xnsl_cmd_display_panel_area_level::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
   	if (win != NULL)
	{
  	}
  	else
		cmd_error("cmd_display_panel_area_level: NULL window");

	return 1;
}

