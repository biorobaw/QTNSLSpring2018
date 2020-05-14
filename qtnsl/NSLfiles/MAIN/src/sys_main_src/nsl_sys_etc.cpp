/**************************************************************/
/*                                                            */
/*                       nsl_sys_etc.C                        */
/*                                                            */
/**************************************************************/


// this files gets compiled twice:
//	- without special inclusions
//	- with all inclusions

#include <cstdlib>
using namespace std;

# include "../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

void NSLetc()
{
#ifdef NSL_INPUT_FG
	extern void nsl_input_init();
	new nsl_sys_module("input",nsl_input_init,1);
#endif
}