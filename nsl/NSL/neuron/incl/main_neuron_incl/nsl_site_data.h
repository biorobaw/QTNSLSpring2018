/************************************/
/*        nsl_site_data.h   	    */
/************************************/


#ifndef _NSL_SITE_DATA_H
#define _NSL_SITE_DATA_H
#include "nsl_site_layer.h"
class nsl_site_data : public nsl_site_layer
{
public:
	nsl_site_data(const char*);
	~nsl_site_data();

	virtual int run();
};

#endif
