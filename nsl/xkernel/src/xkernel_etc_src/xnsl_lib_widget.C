/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_lib_widget.C: Base class for ANY type of widget, irrespective of
//                 user interface toolkit used.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"

xnsl_lib_widget::xnsl_lib_widget() 
{

}  // End function xnsl_widget

xnsl_lib_widget::~xnsl_lib_widget()
{

}  // End function ~xnsl_widget


void xnsl_lib_widget::unshow_widget()
{
}

void xnsl_lib_widget::show_widget()
{
}
void xnsl_lib_widget::destroy_widget()
{
}
int xnsl_lib_widget::display()
{
 	return 1;
}
void xnsl_lib_widget::redraw()
{
// 	return 1;
}
int xnsl_lib_widget::xflush()
{
 	return 1;
}
int xnsl_lib_widget::clear_area(xnsl_widget*, int,int,int,int,int,int,int,int)
{
 	return 1;
}
int xnsl_lib_widget::fill_rectangle(xnsl_widget*,int,int,int,int,int,int,int,int)
{
 	return 1;
}
int xnsl_lib_widget::draw_line(xnsl_widget*,int,int,int,int,int,int,int,int,const char*,int)
{
 	return 1;
}
int xnsl_lib_widget::draw_grid(xnsl_widget*,int,int,int,int,int,int,
	num_type,num_type,num_type,num_type,num_type,num_type,int)
{
 	return 1;
}
int xnsl_lib_widget::draw_text(xnsl_widget*,int,int,const char*) 
{
	return 1;
}
int xnsl_lib_widget::read_from_database()
{
 	return 1;
}
int xnsl_lib_widget::write_to_database()
{
 	return 1;
}
xnsl_widget* xnsl_lib_widget::make_widget()
{
	return 0;
}
xnsl_widget* xnsl_lib_widget::create_widget(const char*,xnsl_widget*,
	int,int,int,int,int,int,int,int,int,int,const char*,const char*)
{
	return 0;
}
int xnsl_lib_widget::output(char*)
{
	return 0;
}
// End of file.
