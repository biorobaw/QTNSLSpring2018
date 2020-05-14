/**************************************************************/
/*                                                            */
/*                   nsl_cmd_block_stim_vector.h              */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_BLOCK_STIM_VECTOR_H
#define _NSL_CMD_BLOCK_STIM_VECTOR_H
#include "nsl_cmd_stim_vector.h"
class nsl_cmd_block_stim_vector : public nsl_cmd_stim_vector
{
public:
		nsl_cmd_block_stim_vector();
		~nsl_cmd_block_stim_vector();

	virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

	virtual int init_data(nsl_base*);
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
                int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};

#endif
