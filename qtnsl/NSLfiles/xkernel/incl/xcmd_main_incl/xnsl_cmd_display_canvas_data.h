/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_canvas_data.h
//
#ifndef _XNSL_CMD_DISPLAY_CANVAS_DATA_H
#define _XNSL_CMD_DISPLAY_CANVAS_DATA_H
#include "xnsl_cmd_display_canvas.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_canvas_data : public xnsl_cmd_display_canvas
{
public:
	xnsl_cmd_display_canvas_data();
	virtual ~xnsl_cmd_display_canvas_data();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
 	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif
