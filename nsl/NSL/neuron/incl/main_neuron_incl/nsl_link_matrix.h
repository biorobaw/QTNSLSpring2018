/************************************/
/*       nsl_link_matrix.h          */
/************************************/

#ifndef _NSL_LINK_MATRIX_H
#define _NSL_LINK_MATRIX_H
#include "nsl_link_layer.h"
class nsl_link_matrix : public nsl_link_layer
{
public:
	nsl_link_matrix(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	nsl_link_matrix(nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_matrix();

	virtual int run();
};
#endif
