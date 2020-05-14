/* SCCS  @(#)xnsl_tcltk_frame.C	1.1---95/08/13--21:01:50 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_frame.C:  Class that creates a tcltk bulltin board widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
//#include "xnsl_tcltk_include.h"
#include "xnsl_tcltk_frame.h"

xnsl_tcltk_frame::xnsl_tcltk_frame () : xnsl_tcltk_widget()
{
	set_type("frame");
}  // End function xnsl_tcltk_frame

xnsl_tcltk_frame::~xnsl_tcltk_frame ()
{
   // Nothing yet.
}   // End function ~xnsl_tcltk_frame

xnsl_widget*  xnsl_tcltk_frame::create_widget(const char     *wname, 
	xnsl_widget    *pxnsl_widget,int  x,int	 y,int  width,int  height,
	int,int,int,int,int,int,const char*,const char*)
{
    strcpy(_wname,wname);
    _X0			= x;
    _Y0			= y;
    _width		= width;
    _height		= height;

	nsl_string str;
//cambios EGR inicio
//	Tcl_Eval(NSL_TCL_INTERP,"source /nsl3.0/cambios/ok/plantill.tcl");
//	sprintf(str,"canvas_manager %s",wname);
//cambios EGR fin
	sprintf(str,"toplevel %s",wname);// original

	//Tcl_Eval(NSL_TCL_INTERP,str);

    return (this);

}   // End function create_widget
/*
void xnsl_tcltk_frame::set_env (const 	char*,
	int	x,int	y,int	width,int	height,
	int,int,int,int,int,int,const char*,const char*)
{
	_X0		= x;
	_Y0		= y;
	_width		= width;
	_height		= height;

}  // End of function set_env
*/	
xnsl_widget *xnsl_tcltk_frame::make_widget()
{
	return new xnsl_tcltk_frame();
}
			
// End of file.

























































































