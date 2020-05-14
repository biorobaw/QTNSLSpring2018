/* SCCS  %W%---%E%--%U% */
//
//	nsl_icon_stim_vector.h
//


#ifndef _NSL_ICON_STIM_VECTOR
#define _NSL_ICON_STIM_VECTOR
#include "nsl_stim_vector.h"
#include "nsl_num_vector.h"
#include "nsl_num.h"
class nsl_icon_stim_vector : public nsl_stim_vector
{
protected:
	nsl_num_1* icon;

public:

	nsl_icon_stim_vector(nsl_input_vector*);
  	~nsl_icon_stim_vector();

 	void set_icon(nsl_num_1* dat) { icon = dat; }
	nsl_num_1* get_icon() { return icon; }

	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_icon_stim_vector(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_icon_stim_vector_status(std::ostream&) const;
};

#endif
