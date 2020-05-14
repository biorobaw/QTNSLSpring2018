/* SCCS  %W%---%E%--%U% */
//
//	nsl_time_interval.h
//


#ifndef _NSL_TIME_INTERVAL_H
#define _NSL_TIME_INTERVAL_H
#include <iostream>
#include "nsl_public.h"

class nsl_time_interval : public nsl_public
{
protected:
	int time_type;               	// 0 - discrete inputs (t0 is used)
                                        // 1 - input interval (t0<-dt->t1)
	float t0,t1;			// time interval
public:

	nsl_time_interval();
 	~nsl_time_interval();

// set
 	void	set_time_type(int i) { time_type = i; }
 	void	set_t0(float s) { t0 = s; }
	void	set_t1(float s) { t1 = s; }

// get
 	int	get_time_type() { return time_type; }
 	float	get_t0() { return t0; }
	float	get_t1() { return t1; }

	virtual int print(std::ostream&) const;
	int print_time(std::ostream&) const;
	virtual int print_status(std::ostream&) const;
	int print_time_status(std::ostream&) const;
};

#endif
