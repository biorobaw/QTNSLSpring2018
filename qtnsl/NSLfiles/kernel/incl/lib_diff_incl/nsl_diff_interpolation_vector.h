/* SCCS  %W%---%E%--%U% */
//
//	nsl_diff_interpolation_vector.h
//

#ifndef _NSL_DIFF_INTERPOLATION_VECTOR_H
#define _NSL_DIFF_INTERPOLATION_VECTOR_H
#include "nsl_diff_interpolation.h"
#include "nsl_num.h"
class nsl_diff_interpolation_vector : public nsl_diff_interpolation
{
public:
		nsl_diff_interpolation_vector();
		~nsl_diff_interpolation_vector();

	int 	init_diff_interpolation_vector();
	
// 	assignment
	  int exec(const num_type);
	  int exec(const NslFloat0&);
	  int exec(const NslFloat1&);
	  int exec(const NslFloat2&);
	  int exec(const NslFloat3&);
	  int exec(const NslFloat4&);

	int run(nsl_layer*,nsl_layer*);

	nsl_diff_method* make_copy();
};
#endif
