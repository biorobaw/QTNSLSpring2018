/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_canvas.h
//
#ifndef _XNSL_CMD_DISPLAY_CANVAS_H
#define _XNSL_CMD_DISPLAY_CANVAS_H
#include "xnsl_cmd_window.h"
class nsl_interpreter;
class nsl_base;
class xnsl_text_label_canvas;
class xnsl_cmd_display_canvas : public xnsl_cmd_window
{
public:
		xnsl_cmd_display_canvas();
		virtual ~xnsl_cmd_display_canvas();

        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);

 	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
 	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	virtual int create_text(nsl_base*,xnsl_text_label_canvas* = 0,
		const char* = 0,const char* = 0,int = 0,int = 0);
	virtual int update_text(nsl_base*,const char* = 0,const char* = 0);
	virtual int update_text(nsl_base*,const char* = 0,num_type = 0);
	virtual int update_text(nsl_base*,const char* = 0,int = 0);

	virtual int create_top_text(nsl_base*,
		const char* = 0,const char* = 0,int = 0);
	virtual int create_bot_text(nsl_base*,
		const char* = 0,const char* = 0,int = 0);
	virtual int create_top_text(nsl_base*,
		const char* = 0,int = 0,int = 0);
	virtual int create_bot_text(nsl_base*,
		const char* = 0,int = 0,int = 0);
	virtual int create_top_text(nsl_base*,
		const char* = 0,num_type = 0.0,int = 0);
	virtual int create_bot_text(nsl_base*,
		const char* = 0,num_type = 0.0,int = 0);

	virtual int create_grid(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		on_off_enum = NSL_OFF);
	virtual int create_line(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		num_type = 0.0, num_type = 1.0);

	virtual int create_graph(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		nsl_layer* = 0,const char* = "");

	virtual int update_graph(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		nsl_layer* = 0,const char* = "");
};
#endif
