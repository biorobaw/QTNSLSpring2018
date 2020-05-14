/* SCCS  @(#)nsl_cmd_model.h	1.2---95/10/30--15:57:36 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_model.h                          */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_MODEL_H
#define _NSL_CMD_MODEL_H
#include "nsl_cmd_type.h"
class nsl_cmd_model : public nsl_cmd_type
{
public:
		nsl_cmd_model();
		~nsl_cmd_model();

	virtual int init_data(nsl_base*); 
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	int init_cmd_model();
	int set_cmd_model();

	int model_run(nsl_model*,num_type,num_type);
	int model_train(nsl_model*,num_type,num_type);

	// cmds
	virtual int cmd_cont(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_init(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_get(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_run(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_step(nsl_interpreter&);
	virtual int cmd_train(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

		int print_cmd_model(ostream&) const;
	virtual int print(ostream&) const;
};
#endif
