/* SCCS  @(#)nsl_shell.C	1.1---95/08/13--19:21:02 */
/**************************************************************/
/*                                                            */
/*                       nsl_shell.C                          */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_shell.h"

nsl_shell::nsl_shell()
{
}
nsl_shell::~nsl_shell()
{
}


int nsl_shell::init()
{
	int shstatus = 1;

	cmd_error("NSL SHELL: Nothing to Init");

	return shstatus;
}
int nsl_shell::run(nsl_interpreter*)
{
	int shstatus = 1;

	cmd_error("NSL SHELL: Nothing to Run");

	return shstatus;
}

