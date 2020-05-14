/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_on_off.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_ON_OFF_H
#define _NSL_CMD_SET_ON_OFF_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_on_off : public nsl_cmd_set
{
protected:
	on_off_enum on_off;
public:
		nsl_cmd_set_on_off(const char*,on_off_enum = NSL_OFF);
		~nsl_cmd_set_on_off();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
	virtual int update(nsl_cmd_type*);

	void	set_on_off(on_off_enum of) {  on_off = of; }
	on_off_enum get_on_off() { return on_off; }

	int print_cmd_set_on_off(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif