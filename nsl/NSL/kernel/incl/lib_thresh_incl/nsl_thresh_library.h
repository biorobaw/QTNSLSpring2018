//
//	nsl_thresh_library.h
//

#ifndef _NSL_THRESH_LIBRARY_H
#define _NSL_THRESH_LIBRARY_H
#include "nsl_library.h"
class nsl_thresh_library : public nsl_library
{
public:
	nsl_thresh_library(const char*,int,int=0);
	~nsl_thresh_library();

	virtual nsl_layer* make_par_copy(int) = 0;

	virtual int run(nsl_layer*,nsl_layer*) = 0; // c,a

	virtual nsl_library* make_copy(nsl_layer*) = 0;
};

#endif
