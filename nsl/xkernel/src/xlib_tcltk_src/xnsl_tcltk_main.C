/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_main.C
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

void   xnsl_tcltk_init()
{
	xnsl_manager   *pxnsl_manager;
	xnsl_lib_widget    *pxnsl_widget;

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;

	if ((pxnsl_manager = XNSL_SYSTEM->get_xnsl_manager()) == NULL)
	{
		cmd_error("tcltk_manager_init: NULL manager");
		return;
	}

	///////////////////////////////////////////////////////
	// Create and add the manager to the list.
	///////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_application();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	///////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_graph();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_frame();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_canvas();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_scrollable_canvas();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_panel();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_scrollable_panel();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_menu();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_pic_button();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_push_button();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_text_menu_button();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_text_label_input();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_tcltk_text_label_panel();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////
}
// nsl_sys_module nsl_mod_tcltk_init("tcltk",xnsl_tcltk_init,1);

