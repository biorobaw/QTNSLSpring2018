/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_pic_button.C:Class that creates a generic push_button widget.
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_pic_button::xnsl_pic_button(xnsl_display_panel* win):xnsl_panel_item(win)
{

} //End function xnsl_pic_button

xnsl_pic_button::~xnsl_pic_button()
{

} //End function ~ xnsl_pic_button

xnsl_widget * xnsl_pic_button::make_widget ()
{
	return new xnsl_pic_button;
}

xnsl_widget *xnsl_pic_button::create_widget(const char *wname,
	xnsl_widget *pxnsl_widget,int x,int y,int width,int height,
	int wx0,int wy0,int wx1,int wy1,int wx,int wy,
	const char* label,const char* message)
{
	xnsl_manager	*pxnsl_manager;
	xnsl_widget	*pwidget;

	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	pwidget =  pxnsl_manager->create_manager_widget("pic_button", 
			pxnsl_widget, wname, x, y, width,height,
			wx0,wy0,wx1,wy1,wx,wy,label,message);

	_pxnsl_lib_widget = (xnsl_lib_widget *)pwidget;

	if (_pxnsl_lib_widget != NULL) {
//		_pxnsl_lib_widget->set_env(wname, x, y, width, height);
		_pxnsl_lib_widget->set_bitmap(_bitmap, width ,height);
	}
	
	return this;
} //End function create_widget

// End of file.
