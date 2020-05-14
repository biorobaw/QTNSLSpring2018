/* SCCS  @(#)nsl_diff.h	1.1---95/08/13--23:36:37 */
//
//	nsl_diff.h
//

#ifndef _NSL_DIFF_H
#define _NSL_DIFF_H
#include "nsl_public.h"
#include "nsl_num_0.h"
#include "nsl_diff_method.h"

#ifndef _NSL_SET
class nsl_layer;
class nsl_num_data;
class nsl_num_vector;
class nsl_num_matrix;
class nsl_num_0;
//typedef nsl_num_0 nsl_num_0;
#endif

class nsl_diff : public nsl_public
{
private:
	on_off_enum update_fg;	// ON - update dobj
	nsl_num_0 delta;
	nsl_num_0 end_time;
	nsl_num_0 tm;	// time constant
	nsl_num_0 h;	// lump // nsl_layer* ?

protected:
 	nsl_diff_method* dobj;	// differential equation
 
public:
		nsl_diff(const char*,nsl_diff_manager* = 0,int=0);
		~nsl_diff();

	void set_delta(num_type dt) { delta = dt; }
	void set_dt(num_type dt) { delta = dt; }
	void set_end_time(num_type t) { end_time = t; }
	void set_tm(num_type t) { tm = t; }
	void set_h(num_type t) { h = t; }

	num_type get_dt() { return delta.get_data(); }
	num_type get_delta() { return delta.get_data(); }
	num_type get_end_time() { return end_time.get_data(); }
	num_type get_tm() { return tm.get_data(); }
	num_type get_h() { return h.get_data(); }

        void set_diff_method(nsl_diff_method* lib) { dobj = lib; }
	nsl_diff_method* get_diff_method() { return dobj; }

	int 	init_diff(nsl_diff_manager*,int);
  
 	void	set_update_fg(on_off_enum i) { update_fg = i; } 
 	on_off_enum	get_update_fg() const { return update_fg; }

 	int	set_diff_obj(nsl_layer* = 0);
	int 	update_diff_obj(nsl_layer*,num_type);

// print
 	virtual int 	print(ostream&) const;
	int 	print_diff(ostream&) const;
	virtual int 	print_status(ostream&) const;
	int 	print_diff_status(ostream&) const;

	virtual int 	print_all(ostream&) const;
	int 	print_diff_all(ostream&) const;
	virtual int 	print_all_status(ostream&) const;
	int 	print_diff_all_status(ostream&) const;

	int 	write_diff(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_diff(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

// assignment 
	nsl_diff&	eq(nsl_layer&,num_type);
	nsl_diff&	eq(nsl_layer&,nsl_num_0&);
 
	nsl_diff&	eq(nsl_layer*,num_type);
	nsl_diff&	eq(nsl_layer*,nsl_num_0&);
 
// assignment
	int 	operator=(const nsl_num_vector&);
	int 	operator=(const nsl_num_data&);
	int 	operator=(const num_type);
	int	operator=(const nsl_num_matrix&);

	virtual int run(nsl_layer*,nsl_layer*);

	virtual nsl_diff* make_copy();
};

//template<class NslNumType, int NslTypeId>

#endif
