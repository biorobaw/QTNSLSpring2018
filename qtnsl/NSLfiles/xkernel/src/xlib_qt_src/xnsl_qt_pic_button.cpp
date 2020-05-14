#include "xnsl_qt_pic_button.h"

xnsl_qt_pic_button::xnsl_qt_pic_button () : xnsl_qt_panel_item()
{
	set_type("pic_button");
}  // End function xnsl_tcltk_pic_button

xnsl_qt_pic_button::~xnsl_qt_pic_button ()
{
   // Nothing yet.

}  // End function ~xnsl_tcltk_pic_button

xnsl_widget*  xnsl_qt_pic_button::create_widget (const char *wname,
	xnsl_widget *pxnsl_widget,int x,int y,int width,int height,
	int,int,int,int,int,int,const char* label,const char* message)
{
	strcpy(_wname,wname);
	_X0 = x;
	_Y0 = y;
	_width = width;
	_height = height;
//	_callback = pxnsl_procedure;
//	_bitmap = strdup(bitmap);

	return (this);

} //End function create_widget

xnsl_widget *xnsl_qt_pic_button::make_widget()
{
	return new xnsl_qt_pic_button();
}
