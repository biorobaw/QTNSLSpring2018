/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_canvas_area_level.h
//
#ifndef _XNSL_CMD_DISPLAY_CANVAS_AREA_LEVEL_H
#define _XNSL_CMD_DISPLAY_CANVAS_AREA_LEVEL_H
#include "xnsl_cmd_display_canvas.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_canvas_area_level : public xnsl_cmd_display_canvas
{
public:
	xnsl_cmd_display_canvas_area_level();
	virtual ~xnsl_cmd_display_canvas_area_level();

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