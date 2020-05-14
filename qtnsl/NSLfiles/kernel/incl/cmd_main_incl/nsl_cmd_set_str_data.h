/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_str_data.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_STR_DATA_H
#define _NSL_CMD_SET_STR_DATA_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_str_data : public nsl_cmd_set
{
public:
		nsl_cmd_set_str_data(const char*,const char* = "") { };//NEVER DEFINED -bn7
		~nsl_cmd_set_str_data() { };

	virtual int init(){return 0; };
	virtual int set(nsl_interpreter&){return 0; };
	virtual int get(nsl_buffer&){return 0; };
  	virtual int update(nsl_cmd_type*){return 0; };

	int print_cmd_set_str_data(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
