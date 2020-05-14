/* SCCS  @(#)nsl_diff_euler.h	1.2---95/10/30--16:02:50 */
//
//	nsl_diff_euler.h
//

#ifndef _NSL_DIFF_EULER_H
#define _NSL_DIFF_EULER_H
#include "nsl_diff_method.h"

#ifndef _NSL_SET
class nsl_num_data;
class nsl_num_vector;
class nsl_num_matrix;
#endif

class nsl_diff_euler : public nsl_diff_method
{
protected:
	num_type p;
public:
		nsl_diff_euler();
		virtual ~nsl_diff_euler();

	int	init();
	int 	init_diff_euler();

// 	assignment
	  virtual int exec(const num_type);
	  virtual int exec(const NslFloat0&);
	  virtual int exec(const NslFloat1&);
	  virtual int exec(const NslFloat2&);
	  virtual int exec(const NslFloat3&);
	  virtual int exec(const NslFloat4&);

	  int execute(num_type,num_type,num_type,const num_type);
	  int execute(NslFloat0&,num_type,num_type,const NslFloat0&);
	  int execute(NslFloat0&,NslFloat0&,num_type,const NslFloat0&);
	  int execute(NslFloat1&,num_type,num_type,const NslFloat1&);
	  int execute(NslFloat1&,NslFloat0&,num_type,const NslFloat1&);
	  int execute(NslFloat2&,num_type,num_type,const NslFloat2&);
	  int execute(NslFloat2&,NslFloat0&,num_type,const NslFloat2&);
	  int execute(NslFloat3&,num_type,num_type,const NslFloat3&);
	  int execute(NslFloat3&,NslFloat0&,num_type,const NslFloat3&);
	  int execute(NslFloat4&,num_type,num_type,const NslFloat4&);
	  int execute(NslFloat4&,NslFloat0&,num_type,const NslFloat4&);

	int run(nsl_layer*,nsl_layer*);

	virtual nsl_diff_method* make_copy();
};
#endif
