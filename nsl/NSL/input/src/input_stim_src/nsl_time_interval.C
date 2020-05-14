/* SCCS  %W%---%E%--%U% */
//
//	nsl_time_interval.c
//
#include "nsl_input.h"
#include "nsl_time_interval.h"

nsl_time_interval::nsl_time_interval()
{
  	time_type = NSL_ON;
	t0 = 0.0;
	t1 = 0.0;
}
nsl_time_interval::~nsl_time_interval()
{
}
int nsl_time_interval::print(std::ostream& out) const
{
	return print_time(out);
}
int nsl_time_interval::print_time(std::ostream& out) const
{
 /* 	if (time_type == 1) 
	   out << "set time_interval time_type ON\n";
	else // if (time_type == 0)
	   out << "set time_interval OFF\n";
*/	out << "set time_interval t0 " << t0 << "\n";
	out << "set time_interval t1 " << t1 << "\n";

 	out.flush();

	return 1;
}
int nsl_time_interval::print_status(std::ostream& out) const
{
	return print_time_status(out); 
}
int nsl_time_interval::print_time_status(std::ostream& out) const
{
	return print_base(out); 
}

