/* SCCS  @(#)nsl_cmd_exec.h	1.1---95/10/30--15:56:19 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec.h                           */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_EXECX_H
#define _NSL_CMD_EXECX_H
#include "nsl_public.h"
class nsl_base_list;
class nsl_interpreter;
typedef nsl_base_list nsl_list;
class nsl_cmd_exec : public nsl_public
{
protected:
	nsl_list* dir_list; // help files dirs
public:
		nsl_cmd_exec(const char*);
		nsl_cmd_exec();
		~nsl_cmd_exec();

	virtual int exec(nsl_interpreter&);

	virtual int help(const char*);
	int help_file(const char*);
 	int add_help_file(const char*,const char*);

	virtual int print_cmd_exec(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
