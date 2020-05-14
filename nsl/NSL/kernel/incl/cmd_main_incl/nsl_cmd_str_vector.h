/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_str_vector.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_STR_VECTOR_H
#define _NSL_CMD_STR_VECTOR_H
#include "nsl_cmd_vector_layer.h"
class nsl_cmd_str_vector : public nsl_cmd_vector_layer
{
public:
		nsl_cmd_str_vector();
		~nsl_cmd_str_vector();

	virtual int cmd_create(nsl_interpreter&);

		int print_cmd_str_vector(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
