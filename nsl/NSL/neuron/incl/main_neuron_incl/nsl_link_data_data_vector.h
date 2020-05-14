/************************************/
/*    nsl_link_data_data_vector.h   */
/************************************/

#ifndef _NSL_LINK_DATA_DATA_VECTOR_H
#define _NSL_LINK_DATA_DATA_VECTOR_H
#include "nsl_link_data_vector.h"
class nsl_link_data_data_vector : public nsl_link_data_vector
{
public:
	nsl_link_data_data_vector(nsl_layer&,nsl_layer&,nsl_layer&,int = 1);
	~nsl_link_data_data_vector();

	virtual int run();
};
#endif
