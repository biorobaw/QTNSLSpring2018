#include "nsl_kernel.h"
#include "xkernel.h"
#include "xnsl_qt_text_label_input.h"

xnsl_qt_text_label_input::xnsl_qt_text_label_input () :
	xnsl_qt_panel_item()
{
	set_type("text_label_input");
}  // End function xnsl_tcltk_text_label_input

xnsl_qt_text_label_input::~xnsl_qt_text_label_input ()
{
   // Nothing yet.

}  // End function ~xnsl_qt_text_label_input

xnsl_widget*  xnsl_qt_text_label_input::create_widget(const char *wname,
	xnsl_widget    *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
	return (this);

} //End function create_label_widget

xnsl_widget *xnsl_qt_text_label_input::make_widget()
{
	return new xnsl_qt_text_label_input();
}
