//
// 	xnsl_cmd_display_window_data.h
//

#ifndef _XNSL_CMD_DISPLAY_WINDOW_DATA_H
#define _XNSL_CMD_DISPLAY_WINDOW_DATA_H
#include "xnsl_cmd_display_window.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_window_data : public xnsl_cmd_display_window
{
public:
		xnsl_cmd_display_window_data();
		~xnsl_cmd_display_window_data();

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