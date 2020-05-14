/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_xlib_main.C
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_xlib_include.h"

void   xnsl_xlib_init()
{
	xnsl_manager   *pxnsl_manager;
	xnsl_lib_widget    *pxnsl_widget;

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;

	if ((pxnsl_manager = XNSL_SYSTEM->get_xnsl_manager()) == NULL)
	{
		cmd_error("xlib_manager_init: NULL manager");
		return;
	}

	///////////////////////////////////////////////////////
	// Create and add the manager to the list.
	///////////////////////////////////////////////////////

   	pxnsl_widget = new xnsl_xlib_graph();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////
}
// nsl_sys_module nsl_mod_xlib_init("xlib",xnsl_xlib_init,1);

