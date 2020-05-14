/* SCCS  %W%---%E%--%U% */
//
//	nsl_icon_stim_data.h
//

#ifndef _NSL_ICON_STIM_DATA_H
#define _NSL_ICON_STIM_DATA_H
#include "nsl_stim_data.h"

#ifndef _NSL_SET
class nsl_num_data;
#endif

class nsl_icon_stim_data : public nsl_stim_data
{
protected:
	nsl_num_0* icon;
public:

	nsl_icon_stim_data(nsl_input_data*);
  	~nsl_icon_stim_data();

	void set_icon(nsl_num_0* dat) { icon = dat; }
	nsl_num_0* get_icon() { return icon; }

	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_icon_stim_data(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_icon_stim_data_status(std::ostream&) const;
};
#endif
