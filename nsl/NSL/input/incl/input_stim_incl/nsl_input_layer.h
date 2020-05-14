/* SCCS  %W%---%E%--%U% */
//
//	nsl_input_layer.h
//

#ifndef _NSL_INPUT_LAYER_H
#define _NSL_INPUT_LAYER_H
#include "nsl_public.h"
#include <iostream>

#ifndef _NSL_SET
class nsl_stim;
#endif

class nsl_input_layer : public nsl_public
{
protected:
	on_off_enum overlap_fg;		// overlap
	int stim_total;			// stim list total
	nsl_list* stim_list;		// stim list
public:
		nsl_input_layer(const char*,nsl_layer*,int = 0);
		~nsl_input_layer();

	void	set_stim_list(nsl_list* l) { stim_list = l; }
	void	set_overlapfg(on_off_enum i) { overlap_fg = i; }

	nsl_list*	get_stim_list() { return stim_list; }
 	int	get_stim_total() { return stim_total; }
	on_off_enum	get_overlapfg() { return overlap_fg; }

	int	add_stim(nsl_stim*);

 	nsl_stim* get_stim(int);
	nsl_stim* get_stim(char*);

	int run();
	int reset(nsl_buffer*); // clear stim

	virtual int print_status(std::ostream&) const;
	int print_input_layer_status(std::ostream&) const;
	virtual int print(std::ostream&) const;
	int print_input_layer(std::ostream&) const;
	virtual int print(std::ostream&,int) const;
	int print_input_layer(std::ostream&,int) const;
};

#endif
