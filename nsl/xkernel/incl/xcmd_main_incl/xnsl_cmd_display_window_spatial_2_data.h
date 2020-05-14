/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_window_spatial_2_data.h
//

#ifndef _XNSL_CMD_DISPLAY_WINDOW_SPATIAL_2_DATA_H
#define _XNSL_CMD_DISPLAY_WINDOW_SPATIAL_2_DATA_H
#include "xnsl_cmd_display_window_spatial_2.h"
class nsl_base;
class nsl_interpreter;
class xnsl_cmd_display_window_spatial_2_data : public 
	xnsl_cmd_display_window_spatial_2
{
public:
		xnsl_cmd_display_window_spatial_2_data();
		~xnsl_cmd_display_window_spatial_2_data();

        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);

        virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);  
        virtual int init_data(nsl_base*);  
        virtual int reset_data(nsl_base*);  
        virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10); 
};
#endif