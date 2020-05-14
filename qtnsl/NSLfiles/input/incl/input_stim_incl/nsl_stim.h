/* SCCS  @(#)nsl_stim.h	1.1---95/08/13--23:45:45 */
//
//	nsl_stim.h
//

#ifndef _NSL_STIM_H
#define _NSL_STIM_H
#include <iostream>
#include "nsl_public.h"

#ifndef _NSL_SET
class nsl_time_interval;
#endif

class nsl_stim : public nsl_public
{
protected:
	spec_type_enum spec_type;	// CORNER, CENTER
        int add_fg;              	// 1 - overlapping inputs are added
        int mode;               	// 0 - run all time
                                        // 1 - run specified time interval 
	float val;			// value used for block stim
	int step;			// recalc step
	int time_total;			// interval list total
	nsl_list* time_list;		// interval list

public:

	nsl_stim(nsl_layer*);
 	~nsl_stim();

// set
	void	set_val(float s) { val = s; }
 	void	set_addfg(int i) { add_fg = i; }
	void	set_mode(int i) { mode = i; }
	void	set_step(int i) { step = i; }
	void	set_spec_type(spec_type_enum t) { spec_type = t; }

// get
	float	get_val() { return val; }
 	int	get_addfg() { return add_fg; }
	int	get_mode() { return mode; }
	int	get_step() { return step; }
	spec_type_enum get_spec_type() { return spec_type; }
	nsl_list* get_time_list() { return time_list; }

 	int add_time_interval(nsl_time_interval*);

	virtual int run();
	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_stim(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_stim_status(std::ostream&) const;
};
#endif
