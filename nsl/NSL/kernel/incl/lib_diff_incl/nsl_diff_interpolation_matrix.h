/* SCCS  %W%---%E%--%U% */
//
//	nsl_diff_interpolation_matrix.h
//

#ifndef _NSL_DIFF_INTERPOLATION_MATRIX_H
#define _NSL_DIFF_INTERPOLATION_MATRIX_H
#include "nsl_diff_interpolation.h"
#include "nsl_num.h"
class nsl_diff_interpolation_matrix : public nsl_diff_interpolation
{
public:
		nsl_diff_interpolation_matrix();
		~nsl_diff_interpolation_matrix();

	int 	init_diff_interpolation_matrix();
	
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
