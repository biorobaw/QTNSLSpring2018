/* SCCS  @(#)nsl_cmd_macro.C	1.1---95/10/13--16:29:36 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_macro.C                          */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_kernel.h"
#include "nsl_cmd_macro.h"

nsl_cmd_macro::nsl_cmd_macro(const char* str,const int n) : nsl_public(str)
{
	str_cnt = n;
}
nsl_cmd_macro::nsl_cmd_macro(const char* str,const char* val,const int n) :
	 nsl_public(str)
{
	set_name(val); // alias
	str_cnt = n;
}

nsl_cmd_macro::nsl_cmd_macro()
{
}
nsl_cmd_macro::~nsl_cmd_macro()
{
}
int nsl_cmd_macro::exec(nsl_interpreter&)
{
	return 2;
}
int nsl_cmd_macro::print_cmd_macro(std::ostream& out) const
{
	print_base(out);
	return 1;
}
int nsl_cmd_macro::print(std::ostream& out) const // virtual
{
	print_cmd_macro(out);
	return 1;
}

