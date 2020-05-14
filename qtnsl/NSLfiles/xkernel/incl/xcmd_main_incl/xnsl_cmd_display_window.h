/* SCCS  @(#)xnsl_cmd_display_window.h	1.1---95/08/13--23:40:00 */
//
// 	xnsl_cmd_display_window.h
//

#ifndef _XNSL_CMD_DISPLAY_WINDOW_H
#define _XNSL_CMD_DISPLAY_WINDOW_H
#include "xnsl_cmd_window.h"
class nsl_interpreter;
class nsl_base;
class xnsl_window;
class xnsl_cmd_display_window : public xnsl_cmd_window
{
public:
		xnsl_cmd_display_window();
		~xnsl_cmd_display_window();

        virtual int cmd_clear(nsl_interpreter&);
        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);

	virtual int set_win_sector(xnsl_window*,
		int=0,int=0,int=0,int=0,int=0,int=0);

        virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);  
        virtual int init_data(nsl_base*);  
        virtual int reset_data(nsl_base*);  
        virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10); 
};
#endif
