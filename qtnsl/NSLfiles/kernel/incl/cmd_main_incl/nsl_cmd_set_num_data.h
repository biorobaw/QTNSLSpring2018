/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_num_data.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_NUM_DATA_H
#define _NSL_CMD_SET_NUM_DATA_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_num_data : public nsl_cmd_set
{
public:
		nsl_cmd_set_num_data(const char*,const float = 0.f) { }; //NEVER DEFINED! -bn7
		~nsl_cmd_set_num_data(){ };

	virtual int init(){return 0; };
	virtual int set(nsl_interpreter&){return 0; };
	virtual int get(nsl_buffer&){ return 0;};
  	virtual int update(nsl_cmd_type*){return 0; };

	int print_cmd_set_num_data(std::ostream&) const { return 0; };
	virtual int print(std::ostream&) const{ return 0; };
};
#endif
