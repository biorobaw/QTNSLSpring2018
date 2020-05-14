/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_spatial_2_vector.C       */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_spatial_2_vector::
	xnsl_cmd_display_window_spatial_2_vector()
{
        set_type("display_window_spatial_graph_2_vector");
}

xnsl_cmd_display_window_spatial_2_vector::
	~xnsl_cmd_display_window_spatial_2_vector()
{
}
int xnsl_cmd_display_window_spatial_2_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::init_data(nsl_base*)
{
         return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::reset_data(nsl_base*)
{
         return 1;
}
int xnsl_cmd_display_window_spatial_2_vector::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
         return 1;
}

