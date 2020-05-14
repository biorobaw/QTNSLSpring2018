/************************************/
/*       nsl_link_data_data.h       */
/************************************/

#ifndef _NSL_LINK_DATA_DATA_H
#define _NSL_LINK_DATA_DATA_H
#include "nsl_link_data.h"
class nsl_link_data_data : public nsl_link_data
{
public:
	nsl_link_data_data(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	nsl_link_data_data(nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_data_data();

	virtual int run();
};
#endif
