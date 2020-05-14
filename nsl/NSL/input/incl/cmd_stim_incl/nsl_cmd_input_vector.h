/**************************************************************/
/*                                                            */
/*                   nsl_cmd_input_vector                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_INPUT_VECTOR_H
#define _NSL_CMD_INPUT_VECTOR_H
#include "nsl_cmd_num_vector.h"
class nsl_cmd_input_vector : public nsl_cmd_num_vector
{
public:
		nsl_cmd_input_vector();
		~nsl_cmd_input_vector();

	virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

	virtual int init_data(nsl_base*);
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
                int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
};
#endif
