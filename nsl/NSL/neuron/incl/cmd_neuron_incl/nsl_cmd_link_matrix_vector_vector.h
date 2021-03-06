//
// 	nsl_cmd_link_matrix_vector_vector.h
//

#ifndef _NSL_CMD_LINK_MATRIX_VECTOR_VECTOR_H
#define _NSL_CMD_LINK_MATRIX_VECTOR_VECTOR_H
#include "nsl_cmd_link_matrix_vector.h"
class nsl_cmd_link_matrix_vector_vector : public nsl_cmd_link_matrix_vector
{
public:
		nsl_cmd_link_matrix_vector_vector();
		~nsl_cmd_link_matrix_vector_vector();

	int init_cmd_link_matrix_vector_vector();
	int set_cmd_link_matrix_vector_vector();

	virtual int create_link(nsl_layer*, nsl_layer*, nsl_layer*, int);

	// cmds
        virtual int cmd_clear(nsl_interpreter&);
	virtual int cmd_cont(nsl_interpreter&);
        virtual int cmd_create(nsl_interpreter&);
	virtual int cmd_disable(nsl_interpreter&);
	virtual int cmd_enable(nsl_interpreter&);
	virtual int cmd_init(nsl_interpreter&);
	virtual int cmd_print(nsl_interpreter&);
        virtual int cmd_reset(nsl_interpreter&);
	virtual int cmd_run(nsl_interpreter&);
	virtual int cmd_set(nsl_interpreter&);
	virtual int cmd_status(nsl_interpreter&);
	virtual int cmd_step(nsl_interpreter&);
        virtual int cmd_update(nsl_interpreter&);

		int print_cmd_link_matrix_vector_vector(std::ostream&) const;
	virtual int print(std::ostream&) const;
};
#endif
