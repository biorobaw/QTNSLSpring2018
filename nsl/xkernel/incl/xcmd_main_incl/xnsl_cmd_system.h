/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_cmd_system.h
//

#ifndef _XNSL_CMD_SYSTEM_H
#define _XNSL_CMD_SYSTEM_H
#include "xnsl_cmd_window.h"
class nsl_interpreter;
class xnsl_cmd_system : public xnsl_cmd_window
{
public:
		xnsl_cmd_system();
		~xnsl_cmd_system();

        virtual int cmd_create(nsl_interpreter&);
        virtual int cmd_init(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);
};
#endif