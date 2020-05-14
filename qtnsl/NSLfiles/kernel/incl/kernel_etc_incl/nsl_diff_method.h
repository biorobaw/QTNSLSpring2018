/* SCCS  @(#)nsl_diff_method.h	1.1---95/08/13--23:36:37 */
/**************************************************************/
/*                                                            */
/*                       nsl_diff_method.h 		      */
/*                                                            */
/**************************************************************/

#ifndef _NSL_DIFF_METHOD_H
#define _NSL_DIFF_METHOD_H
#include "nsl_public.h"
class nsl_num_0;
class nsl_num_1;
class nsl_num_2;
class nsl_num_data;
class nsl_num_vector;
class nsl_num_matrix;
class nsl_layer;
class nsl_diff_method : public nsl_public
{
protected:
	nsl_layer* layer; 	// layer pointer
	num_type dt;		// time step
	num_type tm;		// time constant
	num_type h;		// constant
public:
		nsl_diff_method();
		virtual ~nsl_diff_method();

	virtual int init();
	int init_diff_method();

	void 	set_h(num_type f) { h = f; }
	void 	set_dt(num_type f) { dt = f; }
	void 	set_tm(num_type f) { tm = f; }

	void	set_layer(nsl_layer* l) { layer = l; }

	num_type get_h() { return h; }
	num_type get_dt() { return dt; }
	num_type get_tm() { return tm; }

	nsl_layer* get_layer() { return layer; }

	virtual int exec(const num_type);
	virtual int exec(const NslFloat0&);
	virtual int exec(const NslFloat1&);
	virtual int exec(const NslFloat2&);
	virtual int exec(const NslFloat3&);
	virtual int exec(const NslFloat4&);

	virtual int execute(num_type,num_type,num_type,const num_type) = 0;
	virtual int execute(NslFloat0&,num_type,num_type,const NslFloat0&) = 0;
	virtual int execute(NslFloat0&,NslFloat0&,num_type,const NslFloat0&) = 0;
	virtual int execute(NslFloat1&,num_type,num_type,const NslFloat1&) = 0;
	virtual int execute(NslFloat1&,NslFloat0&,num_type,const NslFloat1&) = 0;
	virtual int execute(NslFloat2&,num_type,num_type,const NslFloat2&) = 0;
	virtual int execute(NslFloat2&,NslFloat0&,num_type,const NslFloat2&) = 0;
	virtual int execute(NslFloat3&,num_type,num_type,const NslFloat3&) = 0;
	virtual int execute(NslFloat3&,NslFloat0&,num_type,const NslFloat3&) = 0;
	virtual int execute(NslFloat4&,num_type,num_type,const NslFloat4&) = 0;
	virtual int execute(NslFloat4&,NslFloat0&,num_type,const NslFloat4&) = 0;

	virtual int run(nsl_layer*,nsl_layer*) = 0;

	virtual nsl_diff_method* make_copy() = 0;
};
#endif
