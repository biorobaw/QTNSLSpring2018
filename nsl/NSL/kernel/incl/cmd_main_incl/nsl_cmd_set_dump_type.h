/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_dump_type.h                  */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_DUMP_TYPE_H
#define _NSL_CMD_SET_DUMP_TYPE_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_dump_type : public nsl_cmd_set
{
protected:
	dump_enum dump_type;
public:
		nsl_cmd_set_dump_type(const char*,dump_enum = NSL_LP);
		~nsl_cmd_set_dump_type();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
	virtual int update(nsl_cmd_type*);

	void	set_dump_type(dump_enum dt) {  dump_type = dt; }
	dump_enum get_dump_type() { return dump_type; }

	int print_cmd_set_dump_type(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif