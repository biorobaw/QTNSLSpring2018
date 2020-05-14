/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_text_label_input.C:Class that creates a generic text_label widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_text_label_input::xnsl_text_label_input(xnsl_display_panel* win) :
	xnsl_panel_item(win)
{
} //End function xnsl_text_label_input

xnsl_text_label_input::~xnsl_text_label_input()
{
	//Nothing yet.

} //End function ~ xnsl_text_label_input

xnsl_widget * xnsl_text_label_input::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,int x,int y,int width,int height,
 	int,int,int,int,int,int,const char* label,const char* message) 
{
	xnsl_manager	*pxnsl_manager;
  
	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	_pxnsl_lib_widget =  (xnsl_lib_widget*) 
		pxnsl_manager->create_manager_widget(
		"text_label_input", pxnsl_widget, 
		wname, x, y, width,height,0,0,0,0,0,0,label,message);
 
	if (_pxnsl_lib_widget== NULL)
		cerr << "create_text_label_canvas_widget failed.\n";

	return this;
} //End function create_widget
