/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_display_frame.h
//

#ifndef _XNSL_CMD_DISPLAY_FRAME_H
#define _XNSL_CMD_DISPLAY_FRAME_H
#include "xnsl_cmd_window.h"
class nsl_interpreter;
class nsl_base;
class xnsl_cmd_display_frame : public xnsl_cmd_window
{
public:
		xnsl_cmd_display_frame();
		~xnsl_cmd_display_frame();

        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);
};
#endif