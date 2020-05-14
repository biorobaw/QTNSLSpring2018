/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_application.C:  Class that acts as a superclass for all applications
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_application::xnsl_application() 
{
   set_type("application");
}  // End function xnsl_application

xnsl_application::~xnsl_application()
{

   // Nothing yet

}  // End function ~xnsl_application

xnsl_widget * xnsl_application::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget, int x, int y, int width, int height,
	int wx0, int wy0, int wx1, int wy1, int wx, int wy,
	const char* label,const char* message) 
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;
 
	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	pwidget =  pxnsl_manager->create_manager_widget("application", 
		pxnsl_widget, wname, x, y, width, height,
		wx0, wy0, wx1, wy1, wx,wy,label,message);
	
	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if (_pxnsl_lib_widget == NULL)
		cerr << "failed to create a application.\n";
	return this;
} //End function create_widget

xnsl_widget* xnsl_application::make_widget()
{
	return new xnsl_application;
}

//////////////////////////////////////////////////////////////////////////
//
//   Function    : exec
//   
//   Description : Actions to be performed by the application
//                 
/////////////////////////////////////////////////////////////////////////

void  xnsl_application::handle_events ()
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->handle_events();
	else
		cmd_error("application: NULL lib widget");
}

int xnsl_application::output(char* str)
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->output(str);
	else
		cmd_error("application: NULL lib widget");

	return 1;
}
