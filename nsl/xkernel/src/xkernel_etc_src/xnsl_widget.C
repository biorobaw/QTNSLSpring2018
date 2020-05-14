/* SCCS  @(#)xnsl_widget.C	1.1---95/08/13--21:03:38 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_widget.C: Base class for ANY type of widget, irrespective of
//                 user interface toolkit used.
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_widget::xnsl_widget() 
{
   set_base_type("widget");

	_X0=0; 
	_Y0=0; 
	_width=100; 
	_height=50;
	_init_fg = 0;

}  

xnsl_widget::~xnsl_widget()
{

}  

void xnsl_widget::show_widget()
{
}
void xnsl_widget::unshow_widget()
{
}

void xnsl_widget::destroy_widget()
{
}
int xnsl_widget::display()
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->display();
	else
		cmd_error("widget: NULL lib widget");

	return 1;
}
int xnsl_widget::read_from_database()
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->read_from_database();
	else
		cmd_error("widget: NULL lib widget");

	return 1;
}
int xnsl_widget::write_to_database()
{
	if (_pxnsl_lib_widget != NULL)
		_pxnsl_lib_widget->write_to_database();
	else
		cmd_error("widget: NULL lib widget");

	return 1;
}
xnsl_widget* xnsl_widget::make_widget()
{
	return 0;
}
xnsl_widget* xnsl_widget::create_widget(const char*,xnsl_widget*,
	int,int,int,int,int,int,int,int,int,int,const char*,const char*)
{
	return 0;
}

// print

int xnsl_widget::print(ostream& out) const
{
	nsl_base::print(out);

	out << "set window X0 " << _X0 << endl;
	out << "set window Y0 " << _Y0 << endl;
	out << "set window width " << _width << endl;
	out << "set window height " << _height << endl;
	out << endl;
  	out.flush();

	return 1;
}
int xnsl_widget::print_status(ostream& out) const
{
	nsl_base::print_status(out);

	out << "// X0:\t\t" << _X0 << endl;
	out << "// Y0:\t\t" << _Y0 << endl;
	out << "// width:\t" << _width << endl;
	out << "// height:\t" << _height << endl;
	out << endl;
	out.flush();

	return 1;
}

// End of file.
