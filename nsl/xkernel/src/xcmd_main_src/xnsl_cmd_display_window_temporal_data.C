/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_temporal_data.C          */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_temporal_data::xnsl_cmd_display_window_temporal_data()
{
        set_type("display_window_temporal_graph_data");
}

xnsl_cmd_display_window_temporal_data::
	~xnsl_cmd_display_window_temporal_data()
{
}
int xnsl_cmd_display_window_temporal_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_data::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_data::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_data::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
//	xnsl_cmd_display_window_temporal::create_data(win);

	return 1;
}
int xnsl_cmd_display_window_temporal_data::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_temporal_data::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_temporal_data::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
//	xnsl_cmd_display_window_temporal::update_data(win);

        return 1;
}

