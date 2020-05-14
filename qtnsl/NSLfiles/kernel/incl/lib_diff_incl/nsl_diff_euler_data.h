/* SCCS  @(#)nsl_diff_euler_data.h	1.2---95/10/30--16:02:50 */
//
//	nsl_diff_euler_data.h
//

#ifndef _NSL_DIFF_EULER_DATA_H
#define _NSL_DIFF_EULER_DATA_H
#include "nsl_diff_euler.h"
#include "nsl_num.h"
class nsl_diff_euler_data : public nsl_diff_euler
{
public:
		nsl_diff_euler_data();
		~nsl_diff_euler_data();

	int 	init_diff_euler_data();

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
