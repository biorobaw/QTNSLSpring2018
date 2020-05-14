/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_num_matrix.h                     */
/*                                                            */
/**************************************************************/

#ifndef _NSL_CMD_NUM_MATRIX_H
#define _NSL_CMD_NUM_MATRIX_H
#include "nsl_cmd_matrix_layer.h"
class nsl_cmd_num_matrix : public nsl_cmd_matrix_layer
{
public:
		nsl_cmd_num_matrix();
		~nsl_cmd_num_matrix();

	virtual int cmd_create(nsl_interpreter&);

		int print_cmd_num_matrix(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
