/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
// This is where all the xnsl-qt objects are added to the XNSL manager
// so that the respective XNSL objects can execute them once they are
// linked to them
//
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xnsl_qt_include.h"
#include "xnsl_manager.h"
#include "xnsl_system.h"

extern xnsl_system* XNSL_SYSTEM;;

void   xnsl_qt_init()
{
	xnsl_manager   *pxnsl_manager;
	xnsl_lib_widget    *pxnsl_widget;

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;

	if ((pxnsl_manager = XNSL_SYSTEM->get_xnsl_manager()) == NULL)
	{
		cmd_error("qt_manager_init: NULL manager");
		return;
	}

	///////////////////////////////////////////////////////
	// Create and add the manager to the list.
	///////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_application();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	///////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_graph();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_frame();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_canvas();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	//pxnsl_widget = new xnsl_qt_scrollable_canvas();

	//pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_panel();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	//pxnsl_widget = new xnsl_qt_scrollable_panel();

	//pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_menu();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_pic_button();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_push_button();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_text_menu_button();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	pxnsl_widget = new xnsl_qt_text_label_input();

	pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	//pxnsl_widget = new xnsl_qt_text_label_panel();

	//pxnsl_manager->add_manager_lib_widget(pxnsl_widget);

 	////////////////////////////////////////////////////////
}
