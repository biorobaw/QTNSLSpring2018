/* SCCS  %W%---%E%--%U% */
//
//	nsl_icon_stim_matrix.h
//
#ifndef _NSL_ICON_STIM_MATRIX_H
#define _NSL_ICON_STIM_MATRIX_H
#include "nsl_num_matrix.h"
#include "nsl_stim_matrix.h"
#include "nsl_num.h"
class nsl_icon_stim_matrix : public nsl_stim_matrix
{
protected:
	nsl_num_2* icon;
public:

	nsl_icon_stim_matrix(nsl_input_matrix*);
 	~nsl_icon_stim_matrix();

	void set_icon(nsl_num_2* dat) { icon = dat; }
	nsl_num_2* get_icon() { return icon; }

	virtual int proc();

	virtual int print(std::ostream&) const;
	int print_icon_stim_matrix(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_icon_stim_matrix_status(std::ostream&) const;
};
#endif
