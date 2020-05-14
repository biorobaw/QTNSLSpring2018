/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_cmd_window_interface.c              */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_window_interface::xnsl_cmd_window_interface() : xnsl_cmd_window()
{
        set_type("window_interface");
 
	if (XSYSTEM != NULL)
		OBJ = XSYSTEM->get_interface();
	else
		cmd_error("cmd_window_interface: NULL XSYSTEM");

//	create_data(); // create all data for all types
}

xnsl_cmd_window_interface::~xnsl_cmd_window_interface()
{
}

int xnsl_cmd_window_interface::cmd_create(nsl_interpreter& nsl)
{
 
        return 1;
}
int xnsl_cmd_window_interface::cmd_init(nsl_interpreter& nsl)
{
 
        return 1;
}
int xnsl_cmd_window_interface::cmd_reset(nsl_interpreter& nsl)
{
 
        return 1;
}
int xnsl_cmd_window_interface::cmd_update(nsl_interpreter& nsl)
{
 
        return 1;
}
