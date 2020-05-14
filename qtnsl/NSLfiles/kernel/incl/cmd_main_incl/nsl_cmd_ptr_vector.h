/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_ptr_vector.h                     */
/*                                                            */
/**************************************************************/
#ifndef _NSL_CMD_PTR_VECTOR
#define _NSL_CMD_PTR_VECTOR
#include "nsl_cmd_vector_layer.h"
class nsl_cmd_ptr_vector : public nsl_cmd_vector_layer
{
public:
		nsl_cmd_ptr_vector();
		~nsl_cmd_ptr_vector();

	virtual int cmd_create(nsl_interpreter&);

		int print_cmd_ptr_vector(std::ostream&) const;
	virtual int print(std::ostream&) const;
};

#endif
