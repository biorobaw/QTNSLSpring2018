/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*           xnsl_cmd_display_window_temporal_matrix.C        */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_temporal_matrix::
	xnsl_cmd_display_window_temporal_matrix()
{
        set_type("display_window_temporal_graph_matrix");
}

xnsl_cmd_display_window_temporal_matrix::
	~xnsl_cmd_display_window_temporal_matrix()
{
}
int xnsl_cmd_display_window_temporal_matrix::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_matrix::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_matrix::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_matrix::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_temporal_matrix::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
//	xnsl_cmd_display_window_temporal::create_data(win);

	return 1;
}
int xnsl_cmd_display_window_temporal_matrix::init_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_temporal_matrix::reset_data(nsl_base*)
{
        return 1;
}
int xnsl_cmd_display_window_temporal_matrix::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
//	xnsl_cmd_display_window_temporal::update_data(win);

        return 1;
}
