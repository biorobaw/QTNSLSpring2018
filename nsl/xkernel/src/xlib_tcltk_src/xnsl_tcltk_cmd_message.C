/* SCCS  @(#)xnsl_tcltk_cmd_message.C	1.1---95/08/13--21:01:50 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_cmd_message.C:  Class that creates a tcltk bulltin board widget.
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_cmd_message.h"
//#include "xnsl_tcltk_include.h"

xnsl_tcltk_cmd_message::xnsl_tcltk_cmd_message () : xnsl_tcltk_widget()
{
	set_type("cmd_message");
}  // End function xnsl_tcltk_cmd_message

xnsl_tcltk_cmd_message::~xnsl_tcltk_cmd_message ()
{

}   // End function ~xnsl_tcltk_cmd_message

xnsl_widget*  xnsl_tcltk_cmd_message::create_widget (const char *wname, 
	xnsl_widget    *pxnsl_widget,int  x,int	 y,int  width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
    strcpy(_wname,wname);
    _X0			= x;
    _Y0			= y;
    _width		= width;
    _height		= height;

    return (this);

}   // End function create_widget
	
xnsl_widget *xnsl_tcltk_cmd_message::make_widget()
{
	return new xnsl_tcltk_cmd_message();
}
			
void xnsl_tcltk_cmd_message::set_message (const char	*message)
{
 	set_message(message);

}  // End of function set_env


// End of file.
