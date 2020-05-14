/* SCCS  @(#)xnsl_cmd_display_panel.h	1.1---95/08/13--23:39:58 */
//
// 	xnsl_cmd_display_panel_vector.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_VECTOR_H
#define _XNSL_CMD_DISPLAY_PANEL_VECTOR_H
#include "xnsl_cmd_display_panel.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_vector : public xnsl_cmd_display_panel
{
public:
	xnsl_cmd_display_panel_vector();
	virtual~xnsl_cmd_display_panel_vector();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
 	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif
