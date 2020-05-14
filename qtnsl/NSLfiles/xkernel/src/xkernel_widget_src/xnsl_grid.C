/* SCCS  @(#)xnsl_grid.C	1.1---95/08/13--21:03:17 */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_grid.C:Class that creates a generic grid
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_grid::xnsl_grid(xnsl_display_canvas* win) : xnsl_widget_graph(win)
{
	set_type("grid");
	text_fg = NSL_OFF;
} 
xnsl_grid::~xnsl_grid()
{
} 

xnsl_widget * xnsl_grid::make_widget()
{
	return new xnsl_grid;
}

xnsl_widget * xnsl_grid::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget, int x, int y, int width, int height,
 	int wx0, int wy0, int wx1, int wy1, int wx, int wy,
	const char* label,const char* message)
{
	xnsl_manager	*pxnsl_manager;
 
	strcpy(_wname,wname);
	_wx0 = wx0;
	_wy0 = wy0;
	_wx1 = wx1;
	_wy1 = wy1;
	_wxs = wx;
	_wys = wy;

	_X0 = x;
	_Y0 = y;
	_width = width;
	_height = height;

	if (pxnsl_widget == NULL)
	{
		cmd_error("grid: NULL parent");
		return this;
	}

	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	if ((_pxnsl_lib_widget = (xnsl_lib_widget*) 
			pxnsl_manager->create_manager_widget("graph",pxnsl_widget,wname,
			x,y,width,height,wx0,wy0,wx1,wy1,wx,wy,label,message)) != NULL)
		_widget = pxnsl_widget->get_lib_widget();
	else
	    cmd_error("create_grid_widget failed");
  
	return this;
} 

int xnsl_grid::display()
{
//  	set_env("",_X0,_Y0,_width,_height,_wx0,_wy0,_wx1,_wy1,_wxs,_wys); 

	if (_wxs == 0 || _wys == 0 || _wx0 == _wx1 || _wy0 == _wy1)
	{
		cmd_error("xnsl_grid::display: Bad grid values");
		return 1;
	}

	if (text_fg == NSL_OFF)
	{
		draw_grid(_widget,_wx0,_wy0,_wx1,_wy1,_wxs,_wys);	
	}
	else if (text_fg == NSL_ON)
	{
        draw_grid(_widget,_wx0,_wy0,_wx0+_wxs,_wy0+_wys,_wxs,_wys,
			_wxmin,_wymin,_wxmax,_wymax,_wxstep,_wystep,1);	
    }
	
	xflush();
	
	return 1;
} 


