/* SCCS  @(#)xnsl_cmd_display_window_spatial_3_vector.C	1.1---96/02/02--18:14:57 */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_spatial_3_vector.C       */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

#include "xnsl_cmd_display_window_spatial_3_vector.h"

xnsl_cmd_display_window_spatial_3_vector::
	xnsl_cmd_display_window_spatial_3_vector()
{
        set_type("display_window_spatial_graph_3_vector");
}

xnsl_cmd_display_window_spatial_3_vector::
	~xnsl_cmd_display_window_spatial_3_vector()
{
}
int xnsl_cmd_display_window_spatial_3_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_vector::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}

