/************************************/
/*    nsl_link_vector_matrix_data.h */
/************************************/

#ifndef _NSL_LINK_VECTOR_MATRIX_DATA_H
#define _NSL_LINK_VECTOR_MATRIX_DATA_H
#include "nsl_link_vector_data.h"
class nsl_link_vector_matrix_data : public nsl_link_vector_data
{
public:
	nsl_link_vector_matrix_data(nsl_layer&,nsl_layer&,nsl_layer&,int= 1);
	~nsl_link_vector_matrix_data();

	virtual int run();
};
#endif