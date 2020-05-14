/* SCCS  @(#)xnsl_cmd_display_panel.h	1.1---95/08/13--23:39:58 */
//
// 	xnsl_cmd_display_panel_data.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_DATA_H
#define _XNSL_CMD_DISPLAY_PANEL_DATA_H
#include "xnsl_cmd_display_panel.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_data : public xnsl_cmd_display_panel
{
public:
	xnsl_cmd_display_panel_data();
	virtual ~xnsl_cmd_display_panel_data();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
 	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif