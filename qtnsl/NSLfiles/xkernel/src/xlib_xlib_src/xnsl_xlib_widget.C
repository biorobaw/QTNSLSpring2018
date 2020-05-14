/* SCCS  @(#)xnsl_xlib_widget.C	1.1---95/08/13--21:05:33 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_xlib_widget.C: Base class for ANY type of widget, irrespective of
//                 user interface toolkit used.
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 
# include "xnsl_xlib_include.h"

xnsl_xlib_widget::xnsl_xlib_widget() 
{
   set_type("xlib_widget");
   set_abstract_type("xlib_widget");
   set_base_type("widget");
 
}  // End function xnsl_xlib_widget

xnsl_xlib_widget::~xnsl_xlib_widget()
{

}   

int xnsl_xlib_widget::display()
{
 	return 1;
}
int xnsl_xlib_widget::xflush()
{
 	return 1;
}
int xnsl_xlib_widget::clear_area(xnsl_widget*,int,int,int,int,int,int,int,int)
{
 	return 1;
}
int xnsl_xlib_widget::fill_rectangle(xnsl_widget*,int,int,int,int,int,int,int,int)
{
 	return 1;
}
int xnsl_xlib_widget::draw_line(xnsl_widget*,int,int,int,int,int,int,int,int,const char*,int)
{
 	return 1;
}
xnsl_widget* xnsl_xlib_widget::make_widget()
{
	return 0;
}
xnsl_widget* xnsl_xlib_widget::create_widget(const char*,xnsl_widget *,
	int,int,int,int,int,int,int,int,int,int,
	const char*, const char*)
{
	return 0;
}

// End of file.
