/************************************/
/*       nsl_link_vector.h          */
/************************************/

#ifndef _NSL_LINK_VECTOR_H
#define _NSL_LINK_VECTOR_H
#include "nsl_link_layer.h"


class nsl_link_vector : public nsl_link_layer
{
public:
	nsl_link_vector(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	nsl_link_vector(nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_vector();

	virtual int run();
};
#endif
