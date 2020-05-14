/* SCCS  @(#)nsl_cmd_type.h	1.2---95/10/30--15:58:07 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_type.h                           */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_TYPE_H
#define _NSL_CMD_TYPE_H
#include <iostream>
#include "nsl_cmd_public.h"

#ifndef _NSL_SET
class nsl_interpreter;
#endif

class nsl_cmd_type : public nsl_cmd_public 
{
protected:
		nsl_cmd_type(const char*);
		nsl_cmd_type();
		virtual ~nsl_cmd_type();

public:
	int init_cmd_type();

	virtual int create_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);
	virtual int init_data(nsl_base*); 
	virtual int reset_data(nsl_base*); 
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	virtual int print_cmd_type(ostream&) const;
	virtual int print(ostream&) const;

// needed as root virtual methods
	virtual int cmd_assign(nsl_interpreter&);
	virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_close(nsl_interpreter&);
	virtual int cmd_cont(nsl_interpreter&);
	virtual int cmd_connect(nsl_interpreter&);
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_elem(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_exec(nsl_interpreter&);
	virtual int cmd_file_disable(nsl_interpreter&);
	virtual int cmd_file_enable(nsl_interpreter&);
	virtual int cmd_get(nsl_interpreter&);
	virtual int cmd_help(nsl_interpreter&);
	virtual int cmd_init(nsl_interpreter&);
	virtual int cmd_load(nsl_interpreter&);
	virtual int cmd_makeconn(nsl_interpreter&);
	virtual int cmd_open(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_run(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_step(nsl_interpreter&);
	virtual int cmd_stop(nsl_interpreter&);
	virtual int cmd_train(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);
	virtual int cmd_write(nsl_interpreter&);

	int get_obj_name(nsl_interpreter& nsl, char *buf, unsigned int sz);

	int cmd_type_assign(nsl_interpreter&);
	int cmd_type_clear(nsl_interpreter&);
	int cmd_type_close(nsl_interpreter&);
	int cmd_type_connect(nsl_interpreter&);
	int cmd_type_cont(nsl_interpreter&);
	int cmd_type_create(nsl_interpreter&);
	int cmd_type_disable(nsl_interpreter&);
	int cmd_type_elem(nsl_interpreter&);
	int cmd_type_enable(nsl_interpreter&);
	int cmd_type_exec(nsl_interpreter&);
	int cmd_type_file_disable(nsl_interpreter&);
	int cmd_type_file_enable(nsl_interpreter&);
	int cmd_type_get(nsl_interpreter&);
	int cmd_type_help(nsl_interpreter&);
	int cmd_type_init(nsl_interpreter&);
	int cmd_type_load(nsl_interpreter&);
	int cmd_type_makeconn(nsl_interpreter&);
	int cmd_type_open(nsl_interpreter&);
	int cmd_type_print(nsl_interpreter&);
	int cmd_type_reset(nsl_interpreter&);
	int cmd_type_run(nsl_interpreter&);
	int cmd_type_set(nsl_interpreter&);
	int cmd_type_status(nsl_interpreter&);
	int cmd_type_step(nsl_interpreter&);
	int cmd_type_stop(nsl_interpreter&);
	int cmd_type_train(nsl_interpreter&);
	int cmd_type_update(nsl_interpreter&);
	int cmd_type_write(nsl_interpreter&);
};



#endif
