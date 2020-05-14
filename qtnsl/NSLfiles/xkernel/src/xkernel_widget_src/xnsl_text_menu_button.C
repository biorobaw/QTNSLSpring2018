/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_text_menu_button.C:Class that creates a generic text_menu_button 
// widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_text_menu_button::xnsl_text_menu_button(xnsl_display_panel* win) :
	xnsl_panel_item(win)
{
} //End function xnsl_text_menu_button

xnsl_text_menu_button::~xnsl_text_menu_button()
{
	//Nothing yet.

} //End function ~ xnsl_text_menu_button

xnsl_widget * xnsl_text_menu_button::make_widget()
{
	return new xnsl_text_menu_button;
}

xnsl_widget * xnsl_text_menu_button::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,int x,int y,int width,int height,
 	int ,int,int,int ,int,int,const char* label,const char* message) 
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;
 
	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	pwidget =  pxnsl_manager->create_manager_widget("text_menu_button", 
			pxnsl_widget, wname, x, y,width,height, 0,0,0,0,0,0,
			label, message);

	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if(_pxnsl_lib_widget != NULL)
	{
//		_pxnsl_lib_widget->set_widget_label(label);
 		_pxnsl_lib_widget->set_menu(_menu);
//		_pxnsl_lib_widget->set_env(wname, x, y);
	}

	return this;

} //End function create_widget


// End of file.
