/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                       nsl_diff_method.C 		      */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//#include "../../incl/kernel_etc_incl/nsl_diff_method.h"
#include "nsl_diff_method.h"
#include "nsl_base.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"
#include "nsl_num_matrix.h"
#include "nsl_system.h"
#include "nsl_kernel.h"
extern void cmd_error(const char *);

nsl_diff_method::nsl_diff_method()
{
	init_diff_method();
}
nsl_diff_method::~nsl_diff_method()
{
}
int nsl_diff_method::init()
{
	cmd_error("nsl_diff_method: virtual init");

	return 1;
}
int nsl_diff_method::init_diff_method()
{
 	m_parent = SYSTEM;
	
	((nsl_system*) m_parent)->add_diff_method(this);

	return 1;
}
int nsl_diff_method::exec(const num_type)
{
	cmd_error("nsl_diff_method: Bad NumType Execution");

	return 1;
}
int nsl_diff_method::exec(const NslFloat0&)
{
	cmd_error("nsl_diff_method: Bad Data Execution");

	return 1;
}
int nsl_diff_method::exec(const NslFloat1&)
{
	cmd_error("nsl_diff_method: Bad Vector Execution");

	return 1;
}
int nsl_diff_method::exec(const NslFloat2&)
{
	cmd_error("nsl_diff_method: Bad Matrix Execution");

	return 1;
}
 
int nsl_diff_method::exec(const NslFloat3&)
{
	cmd_error("nsl_diff_method: Bad Vector Execution");

	return 1;
}
int nsl_diff_method::exec(const NslFloat4&)
{
	cmd_error("nsl_diff_method: Bad Matrix Execution");

	return 1;
}
