/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_panel_spatial_2_data.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_SPATIAL_2_DATA_H
#define _XNSL_CMD_DISPLAY_PANEL_SPATIAL_2_DATA_H
#include "xnsl_cmd_display_panel_spatial_2.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_spatial_2_data : 
	public xnsl_cmd_display_panel_spatial_2
{
public:
	xnsl_cmd_display_panel_spatial_2_data();
	virtual ~xnsl_cmd_display_panel_spatial_2_data();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif