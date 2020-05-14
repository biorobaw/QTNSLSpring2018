/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_ptr_matrix.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_PTR_MATRIX_H
#define _NSL_CMD_PTR_MATRIX_H
#include "nsl_cmd_matrix_layer.h"
class nsl_cmd_ptr_matrix : public nsl_cmd_matrix_layer
{
public:
		nsl_cmd_ptr_matrix();
		~nsl_cmd_ptr_matrix();

	virtual int cmd_create(nsl_interpreter&);

		int print_cmd_ptr_matrix(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
