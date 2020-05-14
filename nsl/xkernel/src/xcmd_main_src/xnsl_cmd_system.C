/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_cmd_system.c   	              */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_system::xnsl_cmd_system() : xnsl_cmd_window()
{
        set_type("xsystem");
  
	OBJ = XSYSTEM;

//	create_data(); // create all data for all types
}

xnsl_cmd_system::~xnsl_cmd_system()
{
}

int xnsl_cmd_system::cmd_create(nsl_interpreter& nsl)
{
        cmd_type_create(nsl);

        return 1;
}
int xnsl_cmd_system::cmd_init(nsl_interpreter& nsl)
{
        cmd_type_init(nsl);

        return 1;
}
int xnsl_cmd_system::cmd_reset(nsl_interpreter& nsl)
{
        cmd_type_reset(nsl);

        return 1;
}
int xnsl_cmd_system::cmd_update(nsl_interpreter& nsl)
{
        cmd_type_update(nsl);

        return 1;
}
