/**************************************************************/
/*                                                            */
/*                   nsl_cmd_input_data.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_INPUT_DATA_H
#define _NSL_CMD_INPUT_DATA_H
#include "nsl_cmd_num_data.h"
class nsl_cmd_input_data : public nsl_cmd_num_data
{
public:
		nsl_cmd_input_data();
		~nsl_cmd_input_data();

	virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

	virtual int init_data(nsl_base*);
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
                int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif
