//
//	nsl_library.h
//

#ifndef _NSL_LIBRARY_H
#define _NSL_LIBRARY_H
#include "nsl_public.h"
class nsl_library : public nsl_public
{
protected:
	int par_size;
	nsl_ptr_vector* par; // additional parameters as needed
public:
	nsl_library(const char*,int,int = 0);
	~nsl_library();

	void set_par(int,nsl_layer*);
	nsl_layer* get_par(int);
	nsl_ptr_vector*& get_par_vector() { return par; }
	
	void set_par_size(int s) { par_size = s; }
	int get_par_size() { return par_size; }

	virtual nsl_layer* make_par_copy(int) = 0;

	virtual int run(nsl_layer*,nsl_layer*) = 0; // out,in

	virtual nsl_library* make_copy(nsl_layer*) = 0;
};

#endif
