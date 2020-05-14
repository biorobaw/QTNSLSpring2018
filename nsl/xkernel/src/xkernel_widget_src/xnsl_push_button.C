/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_push_button.C:Class that creates a generic push_button widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 
 
xnsl_push_button::xnsl_push_button(xnsl_display_panel* win) : 
	xnsl_panel_item(win)
{

	// Nothing yet.

} //End function xnsl_push_button

xnsl_push_button::~xnsl_push_button()
{

	//Nothing yet.

} //End function ~ xnsl_push_button

xnsl_widget * xnsl_push_button::make_widget()
{
	return new xnsl_push_button;
}

xnsl_widget * xnsl_push_button::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,
 	int,int,int,int,int,int,int,int,int,int,
	const char* label,const char* message) 
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;

	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	pwidget =  pxnsl_manager->create_manager_widget("push_button", 
			pxnsl_widget);

	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if (_pxnsl_lib_widget != NULL)
	{
//		_pxnsl_lib_widget->set_env(wname);
		_pxnsl_lib_widget->set_menu((xnsl_lib_widget *)_menu);
//		_pxnsl_lib_widget->set_widget_label(label);
	}

	return this;
} //End function create_widget


// End of file.
