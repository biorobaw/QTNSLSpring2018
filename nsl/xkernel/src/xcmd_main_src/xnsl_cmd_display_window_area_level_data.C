/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*        xnsl_cmd_display_window_area_level_data.c           */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_area_level_data::
	xnsl_cmd_display_window_area_level_data()
{
        set_type("display_window_area_level_graph_data");
}

xnsl_cmd_display_window_area_level_data::
	~xnsl_cmd_display_window_area_level_data()
{
}
int xnsl_cmd_display_window_area_level_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_data::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_data::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_data::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
int xnsl_cmd_display_window_area_level_data::init_data(nsl_base*)
{
         return 1;
}
int xnsl_cmd_display_window_area_level_data::reset_data(nsl_base*)
{
         return 1;
}
int xnsl_cmd_display_window_area_level_data::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
         return 1;
}
