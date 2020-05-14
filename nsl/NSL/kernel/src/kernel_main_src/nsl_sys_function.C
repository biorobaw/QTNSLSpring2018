
#include "nsl_sys_function.h"
#include "nsl_kernel.h"

nsl_sys_function::nsl_sys_function()
{
	set_base_type("function");
	set_type("sys_function");
}
nsl_sys_function::nsl_sys_function(char* str,void (*f)(),int tfg)
{
	init_sys_function(str,f,tfg);
}
nsl_sys_function::~nsl_sys_function()
{
}

int nsl_sys_function::init_sys_function(char* str,void (*f)(),int tfg)
{
	set_name(str);
	set_type("function");
	set_base_type("function");

//	if (tfg == -1)
//		disable(); // disable from regular processing
//	else
//		enable();

	if (SYSTEM == NULL)
	{
		SYSTEM = new nsl_system;
	}

	if (f != NULL)
	{
		mod_func = f;

		if (tfg == 0)
			SYSTEM->insert_proc(this);
		else
			SYSTEM->add_proc(this);
	}
	else
		cmd_error("nsl_sys_function: Unknown function function");

	return 1;
}
