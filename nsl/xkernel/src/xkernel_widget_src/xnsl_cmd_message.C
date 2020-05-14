/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_cmd_message.C:Class that creates a generic message widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_message::xnsl_cmd_message():xnsl_widget()
{
} //End function xnsl_cmd_message

xnsl_cmd_message::~xnsl_cmd_message()
{
	//Nothing yet.

} //End function ~ xnsl_cmd_message

xnsl_widget *xnsl_cmd_message::make_widget()
{
	return new xnsl_cmd_message;
}

xnsl_widget *xnsl_cmd_message::create_widget (const char *wname,
	xnsl_widget *pxnsl_widget,int x,int y,int width,int height,
	int wx0, int wy0, int wx1, int wy1, int wx, int wy,
	const char* label,const char* message)
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;

	pxnsl_manager = XSYSTEM->get_xnsl_manager();

	pwidget =  pxnsl_manager->create_manager_widget("cmd_message", 
		pxnsl_widget, wname, x, y, width, height,
		wx0,wy0,wx1,wy1,wx,wy,label,message);
 
	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if (_pxnsl_lib_widget == NULL)
	{
	  cerr << "create_cmd_message_widget failed to create a cmd_message\n";
	} 
	else 
	  _pxnsl_lib_widget->set_wmessage(message);

	return this;


} //End function create_widget


// End of file.
