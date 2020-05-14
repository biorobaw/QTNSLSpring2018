/* SCCS  %W%---%E%--%U% */
//
//	nsl_diff_euler_matrix.h
//

#ifndef _NSL_DIFF_EULER_MATRIX
#define _NSL_DIFF_EULER_MATRIX
#include "nsl_diff_euler.h"
class nsl_diff_euler_matrix : public nsl_diff_euler
{
public:
		nsl_diff_euler_matrix();
		~nsl_diff_euler_matrix();

	int 	init_diff_euler_matrix();

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
