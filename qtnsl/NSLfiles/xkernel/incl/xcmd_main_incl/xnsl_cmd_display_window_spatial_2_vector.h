/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_window_spatial_2_vector.h
//
#ifndef _XNSL_CMD_DISPLAY_WINDOW_SPATIAL_2_VECTOR_H
#define _XNSL_CMD_DISPLAY_WINDOW_SPATIAL_2_VECTOR_H
#include "xnsl_cmd_display_window_spatial_2.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_window_spatial_2_vector : public 
	xnsl_cmd_display_window_spatial_2
{
public:
		xnsl_cmd_display_window_spatial_2_vector();
		~xnsl_cmd_display_window_spatial_2_vector();

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

