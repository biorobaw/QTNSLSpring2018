/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*              xnsl_cmd_display_window_data.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_data::xnsl_cmd_display_window_data()
{
        set_type("display_window_data");
}

xnsl_cmd_display_window_data::~xnsl_cmd_display_window_data()
{
}
int xnsl_cmd_display_window_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_data::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_data::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_data::set_win_sector(xnsl_window* win,
	int,int,int,int,int,int)
{
 	if (win != NULL)
		xnsl_cmd_display_window::set_win_sector(win,0,0,0,0,1,1); 
	else
		cmd_error("cmd_display_window_data: NULL window");

 	return 1;
}
int xnsl_cmd_display_window_data::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_window_data::init_data(nsl_base*)
{
 	return 1;
}
int xnsl_cmd_display_window_data::reset_data(nsl_base*)
{
 	return 1;
}
int xnsl_cmd_display_window_data::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
 	return 1;
}
 
