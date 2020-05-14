/* SCCS  @(#)xnsl_tcltk_panel_item.C	1.1---95/08/13--21:01:52 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_panel_item.C: Class that creates a tcltk menu bar widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
//#include "xnsl_tcltk_include.h"
#include "xnsl_tcltk_panel_item.h"

xnsl_tcltk_panel_item::xnsl_tcltk_panel_item () : xnsl_tcltk_widget()
{
	set_type("panel_item");
}  // End function xnsl_tcltk_panel_item

xnsl_tcltk_panel_item::~xnsl_tcltk_panel_item ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_panel_item

xnsl_widget*  xnsl_tcltk_panel_item::create_widget(const char *wname, 
	xnsl_widget    *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
    strcpy(_wname,wname);
    _X0			= x;
    _Y0			= y;
    _width		= width;
    _height		= height;

   return (this);
}   // End function create_widget

int xnsl_tcltk_panel_item::get_env (char*)
{
	return 0;
}

xnsl_widget *xnsl_tcltk_panel_item::make_widget()
{
	return new xnsl_tcltk_panel_item();
}

void xnsl_tcltk_panel_item::set_bitmap (const char *bitmap, 
	int width, int height)
{
	_width		= width;
	_height		= height;
	_bitmap 	= strdup (bitmap);
}

void xnsl_tcltk_panel_item::set_menu(xnsl_widget* m)
{
	_menu = m;
}

void xnsl_tcltk_panel_item::set_callback(xnsl_callback* callback)
{
		_callback = callback;
}

void xnsl_tcltk_panel_item::set_value(const char* value)
{
		_value = strdup (value);
}

// End of file.
