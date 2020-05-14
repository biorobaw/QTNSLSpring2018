/************************************/
/*        nsl_site_matrix.h   	    */
/************************************/

#ifndef _NSL_SITE_MATRIX_H
#define _NSL_SITE_MATRIX_H
#include "nsl_site_layer.h"
class nsl_site_matrix : public nsl_site_layer
{
public:
	nsl_site_matrix(const char*,int,int);
	~nsl_site_matrix();

	virtual int run();
};
#endif