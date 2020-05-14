/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_panel_spatial_3.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_SPATIAL_3_H
#define _XNSL_CMD_DISPLAY_PANEL_SPATIAL_3_H
#include "xnsl_cmd_display_panel.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_spatial_3 : public xnsl_cmd_display_panel
{
public:
	xnsl_cmd_display_panel_spatial_3();
	virtual ~xnsl_cmd_display_panel_spatial_3();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif