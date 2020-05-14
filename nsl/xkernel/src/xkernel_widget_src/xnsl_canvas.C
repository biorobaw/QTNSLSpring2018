/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_canvas.C:Class that creates a generic canvas widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_canvas::xnsl_canvas():xnsl_widget()
{
	set_type("canvas");
} //End function xnsl_canvas

xnsl_canvas::~xnsl_canvas()
{
	//Nothing yet.

} //End function ~ xnsl_canvas

xnsl_widget * xnsl_canvas::make_widget()
{
	return new xnsl_canvas;
}

xnsl_widget * xnsl_canvas::create_widget (const char *wname, 
	xnsl_widget * pxnsl_widget,
 	int x, int y, int width, int height,
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
	if ((pwidget =  pxnsl_manager->create_manager_widget("canvas", 
		pxnsl_widget, wname, x, y, width, height,
		wx0,wy0,wx1,wy1, wx,wy,label,message)) != NULL)
	   _pxnsl_lib_widget = (xnsl_lib_widget*) pwidget;
	else
	    cerr << "create_canvas_widget failed to create a canvas.\n";
 
	return this;
} //End function create_widget

void xnsl_canvas::redraw()
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->redraw();
	else
		cmd_error("xnsl_canvas::redraw: NULL lib widget");
}
int xnsl_canvas::clear_area(xnsl_widget* widget,int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->clear_area(widget,wx0,wy0,wx1,wy1,ni,nj,pos,fg);
	else
		cmd_error("xnsl_canvas::clear_area: NULL lib widget");

	return 1;
}

// End of file.










