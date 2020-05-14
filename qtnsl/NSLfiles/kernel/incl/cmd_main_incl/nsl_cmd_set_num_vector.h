/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_num_vector.h                 */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_NUM_VECTOR_H
#define _NSL_CMD_SET_NUM_VECTOR_H
#include "nsl_cmd_set.h"
class nsl_cmd_set_num_vector : public nsl_cmd_set
{
public:
		nsl_cmd_set_num_vector(const char*,const num_type = 0.0) { }; //NEVER DEFINED -bn7
		~nsl_cmd_set_num_vector() { };

	virtual int init(){return 0; };
	virtual int set(nsl_interpreter&){return 0; };
	virtual int get(nsl_buffer&){return 0; };
  	virtual int update(nsl_cmd_type*){return 0; };

	int print_cmd_set_num_vector(std::ostream&) const{return 0; };
	virtual int print(std::ostream&) const{return 0; };
};
#endif
