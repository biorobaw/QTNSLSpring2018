/* SCCS  @(#)xnsl_tcltk_text_label_input.C	1.1---95/08/13--21:01:55 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_text_label_input.C: Class that creates a tcltk label widget
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "xnsl_tcltk_text_label_input.h"

xnsl_tcltk_text_label_input::xnsl_tcltk_text_label_input () : 
	xnsl_tcltk_panel_item()
{
	set_type("text_label_input");
}  // End function xnsl_tcltk_text_label_input

xnsl_tcltk_text_label_input::~xnsl_tcltk_text_label_input ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_text_label_input

xnsl_widget*  xnsl_tcltk_text_label_input::create_widget(const char *wname, 
	xnsl_widget    *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
	return (this);

} //End function create_label_widget

xnsl_widget *xnsl_tcltk_text_label_input::make_widget()
{
	return new xnsl_tcltk_text_label_input();
}

// End of file.
