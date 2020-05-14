/************************************/
/*  nsl_link_matrix_vector_matrix.h */
/************************************/


#ifndef _NSL_LINK_MATRIX_VECTOR_MATRIX_H
#define _NSL_LINK_MATRIX_VECTOR_MATRIX_H
#include "nsl_link_matrix_matrix.h"
class nsl_link_matrix_vector_matrix : public nsl_link_matrix_matrix
{
public:
	nsl_link_matrix_vector_matrix(nsl_layer&,nsl_layer&,nsl_layer&,int=1);
	~nsl_link_matrix_vector_matrix();

	virtual int run();
};
#endif
