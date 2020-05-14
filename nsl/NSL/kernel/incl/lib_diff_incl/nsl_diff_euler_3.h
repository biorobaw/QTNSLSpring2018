
#ifndef _NSL_DIFF_EULER_3_H
#define _NSL_DIFF_EULER_3_H
#include "nsl_diff_euler.h"
class nsl_diff_euler_3 : public nsl_diff_euler
{
public:
		nsl_diff_euler_3();
		~nsl_diff_euler_3();

	int 	init_diff_euler_3();

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
