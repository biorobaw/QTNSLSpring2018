/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_time_interval.h                  */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_TIME_INTERVAL_H
#define _NSL_CMD_TIME_INTERVAL_H
#include "nsl_cmd_type.h"
class nsl_cmd_time_interval : public nsl_cmd_type
{				
public:
		nsl_cmd_time_interval();
		~nsl_cmd_time_interval();

	virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

	virtual int init_data(nsl_base*);
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
                int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};



#endif
