/************************************/
/*   nsl_link_vector_data_matrix.h  */
/************************************/

#ifndef _NSL_LINK_VECTOR_DATA_MATRIX_H
#define _NSL_LINK_VECTOR_DATA_MATRIX_H
#include "nsl_link_vector_matrix.h"
class nsl_link_vector_data_matrix : public nsl_link_vector_matrix
{
public:
	nsl_link_vector_data_matrix(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_vector_data_matrix();

	virtual int run();
};
#endif