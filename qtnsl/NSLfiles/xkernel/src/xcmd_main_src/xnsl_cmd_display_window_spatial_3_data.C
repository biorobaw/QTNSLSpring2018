/* SCCS  @(#)xnsl_cmd_display_window_spatial_3_data.C	1.1---96/02/02--18:14:56 */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_spatial_3_data.C         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_spatial_3_data::
	xnsl_cmd_display_window_spatial_3_data()
{
        set_type("display_window_spatial_graph_3_data");
}

xnsl_cmd_display_window_spatial_3_data::
	~xnsl_cmd_display_window_spatial_3_data()
{
}
int xnsl_cmd_display_window_spatial_3_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_data::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_data::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_data::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_data::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_data::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_data::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
