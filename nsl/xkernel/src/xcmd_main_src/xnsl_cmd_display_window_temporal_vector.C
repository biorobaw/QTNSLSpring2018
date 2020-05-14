/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_temporal_vector.C        */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_temporal_vector::
	xnsl_cmd_display_window_temporal_vector()
{
        set_type("display_window_temporal_graph_vector");
}

xnsl_cmd_display_window_temporal_vector::
	~xnsl_cmd_display_window_temporal_vector()
{
}
int xnsl_cmd_display_window_temporal_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_vector::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_vector::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_vector::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_vector::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
//	xnsl_cmd_display_window_temporal::create_data(win);

	return 1;
}
int xnsl_cmd_display_window_temporal_vector::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_temporal_vector::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_temporal_vector::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
//	xnsl_cmd_display_window_temporal::update_data(win);

        return 1;
}

