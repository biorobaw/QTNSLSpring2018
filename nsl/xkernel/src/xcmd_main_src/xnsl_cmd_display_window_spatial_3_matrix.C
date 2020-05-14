/* SCCS  @(#)xnsl_cmd_display_window_spatial_3_matrix.C	1.1---96/02/02--18:14:56 */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_spatial_3_matrix.C       */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_spatial_3_matrix::
	xnsl_cmd_display_window_spatial_3_matrix()
{
        set_type("display_window_spatial_graph_3_matrix");
}

xnsl_cmd_display_window_spatial_3_matrix::
	~xnsl_cmd_display_window_spatial_3_matrix()
{
}
int xnsl_cmd_display_window_spatial_3_matrix::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_spatial_3_matrix::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
