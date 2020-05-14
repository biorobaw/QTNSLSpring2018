/* SCCS  @(#)nsl_public.C	1.1---95/10/13--16:37:03 */
//
// nsl_public.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_public.h"

nsl_public::nsl_public(const char* str,int i) : nsl_base(str,i)
{
	init_public(i);
}
nsl_public::nsl_public(int i) : nsl_base(i)
{
	init_public(i);
}
nsl_public::~nsl_public()
{
}
void nsl_public::init_public(int)
{
	set_verbose_fg(NSL_ON); 	// 1 - run verbose
	set_print_time_fg(NSL_ON);	// '1' - print time 
	set_time_fg(0); 	// 0 - all time, 1 - t = 0 only, 2 - t > 0 only
	set_flag(0);		// user defined
	set_status(1);	
}
int nsl_public::display()
{
	return 1;
}
