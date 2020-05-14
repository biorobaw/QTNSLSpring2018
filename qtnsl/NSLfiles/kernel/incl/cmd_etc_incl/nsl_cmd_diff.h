/* SCCS  @(#)nsl_cmd_diff.h	1.2---95/10/30--15:54:59 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_diff.h                           */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_DIFF_H
#define _NSL_CMD_DIFF_H
#include "nsl_cmd_type.h"
class nsl_cmd_diff : public nsl_cmd_type 
{
public:
		nsl_cmd_diff(const char* = "diff");
		~nsl_cmd_diff();

	virtual int init_data(nsl_base*); 
	virtual int update_data(nsl_base*,int = 0,int = 0,int = 100,int = 100,
		int = 0,int = 0,int = 100,int = 100,int = 10,int = 10);

	int init_cmd_diff();
	int set_cmd_diff();

	// cmds
	virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_update(nsl_interpreter&);

		int print_cmd_diff(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
