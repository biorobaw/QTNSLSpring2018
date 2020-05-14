#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_qt_application.h"
#include "xlib_qt_interface.h"

extern NSLInterface *Interface;

xnsl_qt_application::xnsl_qt_application () : xnsl_qt_widget()
{
 	set_type("application");
	_argv = NULL;
	_argc = 0;
}

xnsl_qt_application::~xnsl_qt_application ()
{
}

xnsl_widget* xnsl_qt_application::make_widget()
{
	return new xnsl_qt_application;
}

xnsl_widget* xnsl_qt_application::create_widget(
	const char *wname,xnsl_widget* w, int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
	_X0		= x;
	_Y0		= y;
	_width		= width;
	_height		= height;

	return (this);

} //End function create_widget

void  xnsl_qt_application::handle_events ()
{
}

int xnsl_qt_application::output(char* str)
{
		if (Interface != NULL) //redirect application output to console
			Interface->Output(str);

    	return 1;
}
