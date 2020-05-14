/************************************/
/*        nsl_site_vector.h   	    */
/************************************/

#ifndef _NSL_SITE_VECTOR_H
#define _NSL_SITE_VECTOR_H
#include "nsl_site_layer.h"
class nsl_site_vector : public nsl_site_layer
{
public:
	nsl_site_vector(const char*,int);
	~nsl_site_vector();

	virtual int run();
};
#endif
