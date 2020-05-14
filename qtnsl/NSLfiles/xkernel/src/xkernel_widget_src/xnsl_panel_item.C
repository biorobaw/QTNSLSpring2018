/* SCCS  %W%---%E%--%U% */
//
//	xnsl_panel_item.C
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_panel_item::xnsl_panel_item(xnsl_display_panel* win) : xnsl_widget()
{
        m_parent = win;
}
xnsl_panel_item::~xnsl_panel_item()
{
}
xnsl_widget* xnsl_panel_item::make_widget()
{
	return 0;
}
xnsl_widget* xnsl_panel_item::create_widget(const char*, xnsl_widget*,
	int, int, int, int, int, int, int, int, int, int,
	const char*,const char*)
{
	return 0;
}


