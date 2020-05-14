/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_canvas_4.h
//
#ifndef _XNSL_CMD_DISPLAY_CANVAS_4_H
#define _XNSL_CMD_DISPLAY_CANVAS_4_H
#include "xnsl_cmd_display_canvas.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_canvas_4 : public xnsl_cmd_display_canvas
{
public:
	xnsl_cmd_display_canvas_4();
	virtual ~xnsl_cmd_display_canvas_4();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
 	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif
