/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_scrollable_panel.C:Class that creates a generic scrollable widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 
 
xnsl_scrollable_panel::xnsl_scrollable_panel():xnsl_panel()
{
} //End function xnsl_scrollable_panel

xnsl_scrollable_panel::~xnsl_scrollable_panel()
{
	//Nothing yet.

} //End function ~ xnsl_scrollable_panel

xnsl_widget * xnsl_scrollable_panel::make_widget()
{
	return new xnsl_scrollable_panel;
}

xnsl_widget * xnsl_scrollable_panel::create_widget(const char *wname,
 	xnsl_widget * pxnsl_widget,int x,int y,int width,int height,
	int wx0,int wy0,int wx1,int wy1,int wx,int wy,
	const char* label,const char* message) 
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;
 
	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	pwidget =  pxnsl_manager->create_manager_widget("scroll_panel", 
		pxnsl_widget, wname, x, y, width, height,
		wx0,wy0,wx1,wy1,wx,wy,label,message);
	
	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if (_pxnsl_lib_widget == NULL)
		cerr << "create_scrollable_panel failed to create a panel.\n";
	return this;

} //End function create_widget

// End of file.
