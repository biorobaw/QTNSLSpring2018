/************************************/
/*         nsl_neuron_layer.h       */
/************************************/

#ifndef _NSL_NEURON_LAYER_H
#define _NSL_NEURON_LAYER_H
#include "nsl_layer.h"
#include "nsl_num_0.h"
#include <iostream>
#ifndef _NSL_SET
class nsl_site_layer;
//typedef nsl_num_0 nsl_num_0;
#endif

////typedef nsl_num_0 nsl_num_0; //localized typedef -bn7


class nsl_neuron_layer : public nsl_layer
{
protected:
	nsl_num_0 delta;
	nsl_num_0 end_time;
	nsl_num_0 tm;	// time constant
	nsl_num_0 h;	// input constant
	nsl_num_0 inp;	// init potential
	nsl_num_0 inf;	// init firing
	nsl_layer* m;	// membrane potential
	nsl_layer* M;	// firing
	nsl_thresh_library* thresh;	// step, ramp, etc.
	nsl_diff* diff_model;		// leaky, etc.
//	nsl_diff_method* diff_method;	// euler, etc. // not used
//	nsl_list site_list;
	nsl_site_layer* site_in;
	nsl_site_layer* site_out;
// general library parametrs 
	nsl_ptr_vector* par; 	// parameters needed per library
	int par_size; 		// number of parameters
public:
	nsl_neuron_layer(const char*, const char* = "",int = 1);
	~nsl_neuron_layer();

	void set_delta(num_type dt) { delta = dt; }
	void set_end_time(num_type t) { end_time = t; }
	void set_tm(num_type t) { tm = t; }
	void set_h(num_type t) { h = t; }
	void set_inp(num_type t) { inp = t; }
	void set_inf(num_type t) { inf = t; }

	num_type get_delta() { return delta.get_data(); }
	num_type get_end_time() { return end_time.get_data(); }
	num_type get_tm() { return tm.get_data(); }
	num_type get_h() { return h.get_data(); }
	num_type get_inp() { return inp.get_data(); }
	num_type get_inf() { return inf.get_data(); }

	void set_m(nsl_layer* l) { m = l; }
	void set_M(nsl_layer* l) { M = l; }

	nsl_layer* get_m() { return m; }
	nsl_layer* get_M() { return M; }

	virtual nsl_layer* get_output() { return M; }

	nsl_site_layer* get_site_in() { return site_in; }
	nsl_site_layer* get_site_out() { return site_out; }

        void set_thresh_library(nsl_thresh_library* lib) { thresh = lib; }
	nsl_thresh_library* get_thresh_library() { return thresh; }

        void set_diff_model(nsl_diff* lib) { diff_model = lib; }
	nsl_diff* get_diff_model() { return diff_model; }

//      void set_diff_method(nsl_diff_method* lib) { diff_method = lib; }
//	nsl_diff_method* get_diff_method() { return diff_method; }

        void set_diff_method(nsl_diff_method*);
	nsl_diff_method* get_diff_method();
// parameters
	void init_par(int);
	virtual void init_pars() = 0;
	void set_par(int,nsl_layer*);
	nsl_layer* get_par(int);
	void set_par_size(int s) { par_size = s; }
	int get_par_size() { return par_size; }

//	void add_site();
//	nsl_site* del_site();

	virtual int init() = 0;
	virtual int run() = 0;
	virtual int run_in() = 0;
	virtual int run_out() = 0;
	virtual int print(std::ostream&) const;
};
#endif
