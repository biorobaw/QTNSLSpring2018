/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_frame.C:Class that creates a generic frame widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 
#include "xnsl_frame.h"

xnsl_frame::xnsl_frame():xnsl_widget()
{
	set_type("frame");

} //End function xnsl_frame

xnsl_frame::~xnsl_frame()
{

	//Nothing yet.

} //End function ~ xnsl_frame

xnsl_widget* xnsl_frame::make_widget()
{
	return new xnsl_frame;
}

xnsl_widget* xnsl_frame::create_widget (const char *wname,
 		xnsl_widget * pxnsl_widget,
 		int x,int y,int width,int height, 
		int wx0, int wy0, int wx1, int wy1, int wx, int wy,
		const char* label,const char* message)
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;
 
	strcpy(_wname,wname);
	_X0 = x;
	_Y0 = y;
	_width = width;
	_height = height;

 	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	if ((pwidget = pxnsl_manager->create_manager_widget("frame", 
		pxnsl_widget,wname,x,y,width,height,
		wx0,wy0,wx1,wy1,wx,wy,label,message)) != NULL)
	{
		pwidget->set_m_parent(this);
		_pxnsl_lib_widget = (xnsl_lib_widget *) pwidget;
	}
	else
 		cmd_error("frame: create_widget failed");

	return this;

} //End function create_widget


// End of file.
