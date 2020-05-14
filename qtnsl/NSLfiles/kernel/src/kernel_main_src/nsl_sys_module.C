/* SCCS  @(#)nsl_sys_module.C	1.2---95/10/03--14:17:52 */
//
//	nsl_sys_module.C
//
#include "nsl_kernel.h"
#include "nsl_sys_module.h"
#include "nsl_base.h"
#include "nsl_system.h"
#include <stddef.h>

extern void cmd_error(const char *);

nsl_sys_module::nsl_sys_module()
{
	set_base_type("module");
	set_type("sys_module");
}
nsl_sys_module::nsl_sys_module(char* str,void (*f)(),int tfg)
{
	init_sys_module(str,f,tfg);
}
nsl_sys_module::~nsl_sys_module()
{
}

int nsl_sys_module::init_sys_module(char* str,void (*f)(),int tfg)
{
	set_name(str);
	set_type("module");
	set_base_type("module");

//	if (tfg == -1)
//		disable(); // disable from regular processing
//	else
//		enable();

	if (SYSTEM == NULL)
	{
		SYSTEM = new nsl_system;
	}

	/*if (f != NULL) //deprecated? insert_proc expects nsl_function type -bn7
	{
		mod_func = f;

		if (tfg == 0)
			SYSTEM->insert_proc(this);
		else
			SYSTEM->add_proc(this);
	}	
	else*/
		cmd_error("nsl_sys_module: Unknown module function");

	return 1;
}
