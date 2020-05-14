/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_window_interface.h
//
#ifndef _XNSL_CMD_WINDOW_INTERFACE_H
#define _XNSL_CMD_WINDOW_INTERFACE_H
#include "xnsl_cmd_window.h"
class xnsl_cmd_window_interface : public xnsl_cmd_window
{
public:
		xnsl_cmd_window_interface();
		~xnsl_cmd_window_interface();

        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);
};
#endif