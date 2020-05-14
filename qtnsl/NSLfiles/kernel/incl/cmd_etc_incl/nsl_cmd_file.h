/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_file.h                           */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_FILE_H
#define _NSL_CMD_FILE_H
#include "nsl_cmd_type.h"
class nsl_cmd_file : public nsl_cmd_type 
{
public:
		nsl_cmd_file(const char* = "file");
		~nsl_cmd_file();

	int init_cmd_file();
	int set_cmd_file();

	// cmds
 	virtual	int cmd_close(nsl_interpreter&);
 	virtual	int cmd_cont(nsl_interpreter&);
 	virtual	int cmd_create(nsl_interpreter&);
 	virtual	int cmd_init(nsl_interpreter&);
	virtual int cmd_load(nsl_interpreter&);
	virtual int cmd_open(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_read(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_stop(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);
	virtual int cmd_write(nsl_interpreter&);

		int print_cmd_file(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif