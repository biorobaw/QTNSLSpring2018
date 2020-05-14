/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_manager.C: Base class for all managers
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_manager::xnsl_manager () : xnsl_widget ()
{
	set_type("manager");

	widget_list = new nsl_base_list;
	lib_widget_list = new nsl_base_list;
}

xnsl_manager::~xnsl_manager ()
{
}

xnsl_widget* xnsl_manager::make_widget()
{
	return new xnsl_manager;
}

xnsl_widget* xnsl_manager::create_widget(const char *wtype,
	xnsl_widget *pxnsl_widget,int x,int y,
	int width,int height,int wx0,int wy0,
	int wx1, int wy1, int wx, int wy,
	const char* label,const char* message)
{
	return create_manager_widget(wtype,pxnsl_widget,"",x,y,width,height,
		wx0, wy0, wx1, wy1,wx,wy,label,message);
}
xnsl_widget* xnsl_manager::create_manager_widget(const char *wtype,
	xnsl_widget *pxnsl_widget,
	const char* wname,int x,int y,int width,int height,
	int wx0, int wy0, int wx1, int wy1, int wx,int wy,
	const char* label,const char* message)
{
	xnsl_widget* new_w = 0;
	xnsl_widget* w = get_manager_lib_widget(wtype); // xlib widget
	if (w != NULL && (new_w = w->make_widget()) != NULL)
	{
	    if (pxnsl_widget != NULL)
 		new_w->create_widget(wname,
			pxnsl_widget->get_lib_widget(),x,y,width,height,
			wx0,wy0,wx1,wy1,wx,wy,label,message);
	    else
		new_w->create_widget(wname,0,x,y,width,height,
			wx0,wy0,wx1,wy1,wx,wy,label,message);
	}
	else
		cmd_error("manager: CANNOT create widget type ",wtype);

	return new_w;
} 

void xnsl_manager::add_manager_widget(xnsl_widget * pxnsl_widget)
{
	if (widget_list != NULL && pxnsl_widget != NULL)
		widget_list->append(pxnsl_widget);
	else
		cmd_error("manager: NULL obj");

} 

xnsl_widget* xnsl_manager::get_manager_widget(const char *wtype)
{
	return (xnsl_widget*) widget_list->get_by_type(wtype);
} 

void xnsl_manager::add_manager_lib_widget(xnsl_lib_widget * pxnsl_widget)
{
	if (lib_widget_list != NULL && pxnsl_widget != NULL)
		lib_widget_list->append(pxnsl_widget);
	else
		cmd_error("manager: NULL obj");
} 

xnsl_lib_widget* xnsl_manager::get_manager_lib_widget(const char *wtype)
{
	return (xnsl_lib_widget*) lib_widget_list->get_by_type(wtype);
} 
