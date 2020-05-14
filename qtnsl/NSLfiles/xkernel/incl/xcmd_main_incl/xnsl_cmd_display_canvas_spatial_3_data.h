/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_canvas_spatial_3_data.h
//
#ifndef _XNSL_CMD_DISPLAY_CANVAS_SPATIAL_3_DATA_H
#define _XNSL_CMD_DISPLAY_CANVAS_SPATIAL_3_DATA_H
#include "xnsl_cmd_display_canvas_spatial_3.h"
class nsl_interpreter;
class nsl_base;
class nsl_layer;
class xnsl_cmd_display_canvas_spatial_3_data : 
	public xnsl_cmd_display_canvas_spatial_3
{
public:
	xnsl_cmd_display_canvas_spatial_3_data();
	virtual ~xnsl_cmd_display_canvas_spatial_3_data();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	virtual int create_graph(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		nsl_layer* = 0,const char* = "");

	virtual int update_graph(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		nsl_layer* = 0,const char* = "");
};
#endif
