/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_menu.C:Class that creates a generic menu widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_menu::xnsl_menu():xnsl_widget()
{
	// Nothing yet.

} //End function xnsl_menu

xnsl_menu::~xnsl_menu()
{

	//Nothing yet.

} //End function ~ xnsl_menu

xnsl_widget * xnsl_menu::make_widget()
{
	return new xnsl_menu;
}

xnsl_widget * xnsl_menu::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,int,int,int,int,int,int,int,int,int,int,
	const char*,const char*) 
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;

	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	pwidget =  pxnsl_manager->create_manager_widget("menu", 	
		pxnsl_widget,wname);
	
	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if (_pxnsl_lib_widget == NULL)
		cerr << "create_menu_widget failed to create a menu\n";

	return this;
} //End function create_widget


// End of file.
