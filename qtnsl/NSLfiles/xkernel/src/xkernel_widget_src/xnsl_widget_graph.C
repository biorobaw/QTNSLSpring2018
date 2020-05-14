/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_widget_graph.C:Class that creates a generic graph
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h"

extern int nsl_rint(num_type s);

xnsl_widget_graph::xnsl_widget_graph(xnsl_display_canvas* win) : xnsl_canvas_item(win)
{
	data_list = new nsl_list("data");
	data_total = 0;
}

xnsl_widget_graph::~xnsl_widget_graph()
{
}


int xnsl_widget_graph::coord_transform(num_type s,num_type s0,num_type s1,
	num_type vu0,num_type vu)
{
    s = vu0 + vu*(s-s0)/(s1-s0); // vu = vu1 - vu0

    return(nsl_rint(s));
}

xnsl_widget * xnsl_widget_graph::make_widget()
{
	return new xnsl_widget_graph;
}

xnsl_widget * xnsl_widget_graph::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,int x,int y,int width,int height,
	int wx0, int wy0, int wx1, int wy1, int wx, int wy,
	const char* label,const char* message)
{
	xnsl_manager	*pxnsl_manager;

	strcpy(_wname,wname);
	_X0 = x;
	_Y0 = y;
	_width = width;
	_height = height;

	_wx0 = wx0;
	_wy0 = wy0;
	_wx1 = wx1;
	_wy1 = wy1;
	_wxs = wx;
	_wys = wy;

	if (pxnsl_widget == NULL)
	{
		cmd_error("graph: NULL parent");
		return this;
	}

	pxnsl_manager = XSYSTEM->get_xnsl_manager();

    if ((_pxnsl_lib_widget = (xnsl_lib_widget*)
                pxnsl_manager->create_manager_widget(
                "graph", pxnsl_widget,wname,x,y,width,height,
				wx0,wy0,wx1,wy1,wx,wy,label,message)) != NULL)
				_widget = pxnsl_widget->get_lib_widget();
	else
       cmd_error("graph::create_widget: failed creation");

	return this;
} //End function create_widget

int xnsl_widget_graph::clear()
{
	return 1;
}
int xnsl_widget_graph::display()
{
	return 1;
}
int xnsl_widget_graph::clear_area(xnsl_widget* widget, int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
	if (_pxnsl_lib_widget != NULL)
	    _pxnsl_lib_widget->clear_area(widget,wx0,wy0,wx1,wy1,ni,nj,pos,fg);
	else
		cmd_error("xnsl_widget_graph::clear_area: NULL widget");

	return 1;
}
int xnsl_widget_graph::fill_rectangle(xnsl_widget* widget, int wx0,int wy0,int wx1,int wy1,
	int ni,int nj,int pos,int fg)
{
	if (_pxnsl_lib_widget != NULL)
	    _pxnsl_lib_widget->fill_rectangle(widget,wx0,wy0,wx1,wy1,ni,nj,pos,fg);
	else
		cmd_error("xnsl_widget_graph::fill_rectangle: NULL widget");

	return 1;
}
int xnsl_widget_graph::draw_line(xnsl_widget* widget, int wx0,int wy0,int wx1,int wy1,
	int tt,int ni, int nj, int pos,const char* color,int fg)
{
	if (_pxnsl_lib_widget != NULL)
	    _pxnsl_lib_widget->draw_line(widget,wx0,wy0,wx1,wy1,tt,ni,nj,pos,color,fg);
	else
		cmd_error("xnsl_widget_graph::draw_line: NULL widget");

//	xflush();

	return 1;
}
int xnsl_widget_graph::draw_grid(xnsl_widget* widget, int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type x0, num_type y0, num_type x1, num_type y1,
	num_type xs, num_type ys,int fg)
{
	if (_pxnsl_lib_widget != NULL)
	    _pxnsl_lib_widget->draw_grid(widget,wx0,wy0,wx1,wy1,wxs,wys,
		x0,y0,x1,y1,xs,ys,fg);
	else
		cmd_error("xnsl_widget_graph::draw_grid: NULL widget");

	return 1;
}
int xnsl_widget_graph::draw_text(xnsl_widget* widget, int x,int y,const char* str)
{
	if (_pxnsl_lib_widget != NULL)
	    _pxnsl_lib_widget->draw_text(widget,x,y,str);
	else
		cmd_error("xnsl_widget_graph::draw_text: NULL widget");

	return 1;
}
int xnsl_widget_graph::xflush()
{
	if (_pxnsl_lib_widget != NULL)
	    _pxnsl_lib_widget->xflush();
	else
		cmd_error("xnsl_widget_graph::xflush: NULL widget");

	return 1;
}


