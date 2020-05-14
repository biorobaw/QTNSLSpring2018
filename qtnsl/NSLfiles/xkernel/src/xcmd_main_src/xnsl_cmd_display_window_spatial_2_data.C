/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_spatial_2_data.C         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_spatial_2_data::
	xnsl_cmd_display_window_spatial_2_data()
{
        set_type("display_window_spatial_graph_2_data");
}

xnsl_cmd_display_window_spatial_2_data::
	~xnsl_cmd_display_window_spatial_2_data()
{
}
int xnsl_cmd_display_window_spatial_2_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_data::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_data::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_data::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_data::init_data(nsl_base*)
{
         return 1;
}
int xnsl_cmd_display_window_spatial_2_data::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_2_data::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}

