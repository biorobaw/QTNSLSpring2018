/************************************/
/*    nsl_link_data_matrix_matrix.h */
/************************************/

#ifndef _NSL_LINK_DATA_MATRIX_MATRIX_H
#define _NSL_LINK_DATA_MATRIX_MATRIX_H
#include "nsl_link_data_matrix.h"
class nsl_link_data_matrix_matrix : public nsl_link_data_matrix
{
public:
	nsl_link_data_matrix_matrix(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_data_matrix_matrix();

	virtual int run();
};
#endif
