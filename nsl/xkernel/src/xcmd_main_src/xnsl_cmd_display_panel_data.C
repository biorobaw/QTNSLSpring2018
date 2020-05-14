/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*              xnsl_cmd_display_panel_data.C                 */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel_data::xnsl_cmd_display_panel_data()
{
	set_type("display_panel_data");
}
xnsl_cmd_display_panel_data::~xnsl_cmd_display_panel_data()
{
}
int xnsl_cmd_display_panel_data::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int xnsl_cmd_display_panel_data::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
} 
 
