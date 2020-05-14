/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_set_vec_type.h                   */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_SET_VEC_TYPE_H
#define _NSL_CMD_SET_VEC_TYPE_H
#include "nsl_cmd_set.h"
enum vec_enum { }; //TODO: where is vec_enum defined???? -bn7
class nsl_cmd_set_vec_type : public nsl_cmd_set
{
protected:
	vec_enum vec_type;
public:
		nsl_cmd_set_vec_type(const char*,vec_enum = NSL_ROW);
		~nsl_cmd_set_vec_type();

	virtual int init();
	virtual int set(nsl_interpreter&);
	virtual int get(nsl_buffer&);
	virtual int update(nsl_cmd_type*);

	void	set_vec_type(vec_enum dt) {  vec_type = dt; }
	vec_enum get_vec_type() { return vec_type; }

	int print_cmd_set_vec_type(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
 #endif
