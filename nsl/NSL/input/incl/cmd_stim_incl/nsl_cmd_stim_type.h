/**************************************************************/
/*                                                            */
/*                   nsl_cmd_stim_type.h                      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_STIM_TYPE_H
#define _NSL_CMD_STIM_TYPE_H
#include "nsl_cmd_type.h"


class nsl_cmd_stim_type : public nsl_cmd_type
{
protected:
	stim_type_enum stim_type;
public:
		nsl_cmd_stim_type(const char*,stim_type_enum = NSL_BLOCK);
		~nsl_cmd_stim_type();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
 	virtual int update(nsl_cmd_type*);

	void	set_stim_type(stim_type_enum ft) {  stim_type = ft; }
	stim_type_enum get_stim_type() { return stim_type; }

	int print_cmd_stim_type(std::ostream&) const;
	virtual int print(std::ostream&) const;
};



#endif
