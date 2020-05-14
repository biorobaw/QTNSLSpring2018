/* SCCS  @(#)xnsl_cmd_display_window_area_level_vector.C	1.1---96/02/02--18:14:53 */
/**************************************************************/
/*                                                            */
/*        xnsl_cmd_display_window_area_level_vector.C         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_area_level_vector::
	xnsl_cmd_display_window_area_level_vector()
{
        set_type("display_window_area_level_graph_vector");
}

xnsl_cmd_display_window_area_level_vector::
	~xnsl_cmd_display_window_area_level_vector()
{
}
int xnsl_cmd_display_window_area_level_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_vector::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_vector::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_vector::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_vector::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
 	return 1;
}
int xnsl_cmd_display_window_area_level_vector::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_area_level_vector::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_area_level_vector::update_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
