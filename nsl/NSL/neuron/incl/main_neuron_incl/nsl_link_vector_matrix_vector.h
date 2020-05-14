/************************************/
/*  nsl_link_vector_matrix_vector.h */
/************************************/

#ifndef _NSL_LINK_VECTOR_MATRIX_VECTOR_H
#define _NSL_LINK_VECTOR_MATRIX_VECTOR_H
#include "nsl_link_vector_vector.h"
class nsl_link_vector_matrix_vector : public nsl_link_vector_vector
{
public:
	nsl_link_vector_matrix_vector(nsl_layer&,nsl_layer&,nsl_layer&,int=1);
	~nsl_link_vector_matrix_vector();

	virtual int run();
};
#endif