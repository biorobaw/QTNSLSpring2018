/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_panel_temporal_vector.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_TEMPORAL_VECTOR_H
#define _XNSL_CMD_DISPLAY_PANEL_TEMPORAL_VECTOR_H
#include "xnsl_cmd_display_panel_temporal.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_temporal_vector : 
	public xnsl_cmd_display_panel_temporal
{
public:
	xnsl_cmd_display_panel_temporal_vector();
	virtual~xnsl_cmd_display_panel_temporal_vector();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif
