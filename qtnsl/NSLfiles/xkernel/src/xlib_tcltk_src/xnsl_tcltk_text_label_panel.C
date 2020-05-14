/* SCCS  @(#)xnsl_tcltk_text_label_panel.C	1.1---95/08/13--21:01:56 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_tcltk_text_label_panel.C: Class that creates a tcltk label widget
//             
//////////////////////////////////////////////////////////////////////////

#include "nsl_all_kernel_include.h"
#include "xkernel.h"
#include "xnsl_tcltk_include.h"

xnsl_tcltk_text_label_panel::xnsl_tcltk_text_label_panel () : 
	xnsl_tcltk_panel_item()
{
	set_type("text_label_panel");
}  // End function xnsl_tcltk_text_label_panel

xnsl_tcltk_text_label_panel::~xnsl_tcltk_text_label_panel ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_text_label_panel

xnsl_widget*  xnsl_tcltk_text_label_panel::create_widget(const char *wname, 
	xnsl_widget    *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
	strcpy(_wname,wname);
	strcpy(_wlabel,label);
	_X0 = x;
	_Y0 = y;
 
	return (this);

} //End function create_label_widget

xnsl_widget *xnsl_tcltk_text_label_panel::make_widget()
{
	return new xnsl_tcltk_text_label_panel();
}
		
// End of file.
