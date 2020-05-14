/* SCCS  @(#)nsl_cmd_exec_delay.C	1.1---95/10/13--16:35:07 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_delay.C                     */
/*                                                            */
/**************************************************************/

# include "nsl_cmd_exec_delay.h"
#include "nsl_interpreter.h"

nsl_cmd_exec_delay::nsl_cmd_exec_delay() : nsl_cmd_exec("delay")
{
}

nsl_cmd_exec_delay::~nsl_cmd_exec_delay()
{
}

#ifdef NSL_PC
void sleep( clock_t wait )
{
	clock_t goal;
	goal = wait + clock();
	while( goal > clock() )
		;
}
#else
//#include <sys/ddi.h>
//extern "C" void delay(long);
extern "C" void sleep(long);
#endif

int nsl_cmd_exec_delay::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int segs = 5;

	if (nsl.get_str_cnt() != 0)
	{
	   	nsl >> str;
	   	sscanf(str,"%l",segs);
//		sleep(segs);
	}
//	else
#ifdef NSL_PC
	sleep((clock_t) segs*CLOCKS_PER_SEC);
#else
	sleep(segs);
#endif

	return 1;
}
int nsl_cmd_exec_delay::help(const char*)
{
	return 1;
}

