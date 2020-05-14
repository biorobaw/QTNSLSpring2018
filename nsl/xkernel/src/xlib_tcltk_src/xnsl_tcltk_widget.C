/* SCCS  @(#)xnsl_tcltk_widget.C	1.1---95/08/13--21:01:59 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_widget.C: Base class for tcltk widgtes. 
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

xnsl_tcltk_widget::xnsl_tcltk_widget () 
{
   set_type("tcltk_widget");
   set_abstract_type("tcltk_widget");
   set_base_type("widget");

}  // End function xnsl_tcltk_widget

xnsl_tcltk_widget::~xnsl_tcltk_widget ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_widget



void  xnsl_tcltk_widget::redraw()
{
}

void  xnsl_tcltk_widget::show_widget()
{

}   // End function show_widget

void  xnsl_tcltk_widget::unshow_widget()
{

}   // End function unshow_widget

void  xnsl_tcltk_widget::destroy_widget ()
{

}   // End function destroy_widget

int  xnsl_tcltk_widget::get_env_width ()
{
   return _width;

}   // End function get_widget_width

int  xnsl_tcltk_widget::get_env_height()
{
   return _height;


}   // End function get_widget_height
xnsl_widget* xnsl_tcltk_widget::create_widget (const char*,xnsl_widget*,
	int,int,int,int,int,int,int,int,int,int,const char*,const char*)
{
	return 0;
}
		
xnsl_widget* xnsl_tcltk_widget::make_widget() 
{
	return 0;
}

void xnsl_tcltk_widget::set_env_x(int x) 
{
}

void xnsl_tcltk_widget::set_env_y(int y) 
{
}
	
void xnsl_tcltk_widget::set_env_width(int) 
{
}

void xnsl_tcltk_widget::set_env_height(int)
{ 
}

void xnsl_tcltk_widget::set_env_name(const char *) 
{
}


// End of file.






