/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_motif_main.C
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"

void   xnsl_motif_init()
{
	xnsl_manager   *pxnsl_manager;
	xnsl_lib_widget    *pxnsl_widget;

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;

	if ((pxnsl_manager = XNSL_SYSTEM->get_xnsl_manager()) == NULL)
	{
		cmd_error("motif_manager_init: NULL manager");
		return;
	}

	///////////////////////////////////////////////////////
	// Create and add the manager to the list.
	///////////////////////////////////////////////////////
/*//none of these classes exist -bn7
	pxnsl_widget = new xnsl_motif_application();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	///////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_frame();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_canvas();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_scrollable_canvas();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_panel();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_scrollable_panel();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_menu();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_pic_button();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_push_button();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_text_menu_button();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_text_label_input();

	//pxnsl_manager->add_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_motif_text_label_panel();
*/
	//pxnsl_manager->add_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////
}
// nsl_sys_module nsl_mod_motif_init("motif",xnsl_motif_init,1);

