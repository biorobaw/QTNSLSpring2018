/* SCCS  @(#)xnsl_xmain_manager.C	1.1---95/08/13--21:03:39 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_widget_main.C
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 
 
void   xnsl_widget_init()
{
	xnsl_manager   *pxnsl_manager;
	xnsl_widget    *pxnsl_widget;

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;

	if ((pxnsl_manager = XNSL_SYSTEM->get_xnsl_manager()) == NULL)
	{
		cmd_error("widget_manager_init: NULL manager");
		return;
	}

	///////////////////////////////////////////////////////
	// Create and add the manager to the list.
	///////////////////////////////////////////////////////
/*
	pxnsl_widget = new xnsl_application();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	///////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_frame();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_canvas();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_scrollable_canvas();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_panel();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_scrollable_panel();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_menu();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_pic_button();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_push_button();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_text_menu_button();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_text_label_input();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_text_label_panel();

	pxnsl_manager->add_manager_widget(pxnsl_widget);
*/
 	////////////////////////////////////////////////////////
}
// nsl_sys_module nsl_mod_xmain_init("widget",xnsl_widget_init,1);

