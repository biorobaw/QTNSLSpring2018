/* SCCS  @(#)xnsl_tcltk_application.C	1.1---95/08/13--21:01:48 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_application.C:  Class that initialises the Xview application.
//
//			       Also has the function which puts the 
//			       program into the event loop.
//		
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
//#include "xnsl_tcltk_include.h"
#include "xnsl_tcltk_application.h"

extern void xnsl_interrupt_handler(xnsl_tcltk_application*);

xnsl_tcltk_application::xnsl_tcltk_application () : xnsl_tcltk_widget()
{
 	set_type("application");
	_argv = NULL;
	_argc = 0;
	
}  // End function xnsl_tcltk_application

xnsl_tcltk_application::~xnsl_tcltk_application ()
{

}  // End function ~xnsl_tcltk_application

xnsl_widget* xnsl_tcltk_application::make_widget()
{
	return new xnsl_tcltk_application;
}

xnsl_widget* xnsl_tcltk_application::create_widget(
	const char *wname,xnsl_widget* w, int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
	_X0		= x;
	_Y0		= y;
	_width		= width;
	_height		= height;

	return (this);

} //End function create_widget

void  xnsl_tcltk_application::handle_events ()
{
}  // End handle_events

int xnsl_tcltk_application::output(char* str)
{
    	return 1;
}

	
// End of file.
