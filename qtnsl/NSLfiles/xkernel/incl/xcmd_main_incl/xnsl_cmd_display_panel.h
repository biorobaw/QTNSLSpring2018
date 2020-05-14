/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_panel.h
//

#ifndef _XNSL_CMD_DISPLAY_PANEL_H
#define _XNSL_CMD_DISPLAY_PANEL_H
#include "xnsl_cmd_window.h"
class nsl_interpreter;
class nsl_base;
class xnsl_panel_item;
class xnsl_cmd_display_panel : public xnsl_cmd_window
{
public:
		xnsl_cmd_display_panel();
		virtual ~xnsl_cmd_display_panel();

        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);

 	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
 	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	virtual int create_panel_item(nsl_base*,xnsl_panel_item* = 0,
		const char* = "",const char* = "",int = 0);

	virtual int create_panel_item(nsl_base*,xnsl_panel_item* = 0,
		const char* = "",int = 0,int = 0);

	virtual int create_panel_item(nsl_base*,xnsl_panel_item* = 0,
		const char* = "",float = 0,int = 0);
};
#endif
