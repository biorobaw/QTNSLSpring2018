//
// 	xnsl_cmd_window.h
//
#ifndef _XNSL_CMD_WINDOW_H
#define _XNSL_CMD_WINDOW_H
#include "nsl_cmd_type.h"
class nsl_interpreter;
class xnsl_system;
class xnsl_cmd_window : public nsl_cmd_type
{
protected:
	xnsl_system* XSYSTEM;
public:
		xnsl_cmd_window();
		~xnsl_cmd_window();

	void set_xsystem(xnsl_system* x) { XSYSTEM = x; }
	xnsl_system* get_xsystem() { return XSYSTEM; }

        virtual int cmd_clear(nsl_interpreter&);
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

        virtual int create_graph(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		nsl_layer* = 0, const char* = "");  
        virtual int update_graph(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10,
		nsl_layer* = 0, const char* = "");  
};
#endif
