//
//	nsl_sat_library.h
//

#ifndef _NSL_SAT_LIBRARY_H
#define _NSL_SAT_LIBRARY_H
#include "nsl_thresh_library.h"
#include "nsl_sat_library.h"

class nsl_sat_library : public nsl_thresh_library
{
public:
	nsl_sat_library(const char*,int=0);
	~nsl_sat_library();

	virtual nsl_layer* make_par_copy(int) = 0;

	virtual int run(nsl_layer*,nsl_layer*) = 0; // c,a

	virtual nsl_library* make_copy(nsl_layer*) = 0;
};

class nsl_sat_data_library : public nsl_sat_library
{
public:
	nsl_sat_data_library(nsl_layer*,int=0);
	~nsl_sat_data_library();

	virtual nsl_layer* make_par_copy(int);

	int run(nsl_layer*,nsl_layer*);

	virtual nsl_library* make_copy(nsl_layer*);
};

class nsl_sat_vector_library : public nsl_sat_library
{
public:
	nsl_sat_vector_library(nsl_layer*,int=0);
	~nsl_sat_vector_library();

	virtual nsl_layer* make_par_copy(int);

	int run(nsl_layer*,nsl_layer*);

	virtual nsl_library* make_copy(nsl_layer*);
};

class nsl_sat_matrix_library : public nsl_sat_library
{
public:
	nsl_sat_matrix_library(nsl_layer*,int=0);
	~nsl_sat_matrix_library();

	virtual nsl_layer* make_par_copy(int);

	int run(nsl_layer*,nsl_layer*);

	virtual nsl_library* make_copy(nsl_layer*);
};
#endif
