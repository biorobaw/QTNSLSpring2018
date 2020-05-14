/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_panel_spatial_2_matrix.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_SPATIAL_2_MATRIX_H
#define _XNSL_CMD_DISPLAY_PANEL_SPATIAL_2_MATRIX_H
#include "xnsl_cmd_display_panel_spatial_2.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_panel_spatial_2_matrix : 
	public xnsl_cmd_display_panel_spatial_2
{
public:
	xnsl_cmd_display_panel_spatial_2_matrix();
	virtual ~xnsl_cmd_display_panel_spatial_2_matrix();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif