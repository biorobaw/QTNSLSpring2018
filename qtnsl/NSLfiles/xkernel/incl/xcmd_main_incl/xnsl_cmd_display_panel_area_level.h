/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_panel_area_level.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_AREA_LEVEL_H
#define _XNSL_CMD_DISPLAY_PANEL_AREA_LEVEL_H
#include "xnsl_cmd_display_panel.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_area_level : public xnsl_cmd_display_panel
{
public:
	xnsl_cmd_display_panel_area_level();
	virtual ~xnsl_cmd_display_panel_area_level();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif