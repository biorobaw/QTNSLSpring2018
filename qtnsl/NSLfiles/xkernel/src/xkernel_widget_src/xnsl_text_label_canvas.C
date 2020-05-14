/* SCCS  %W%---%E%--%U% */
//////////////////////////////////////////////////////////////////////////
//
//xnsl_text_label_canvas.C:Class that creates a generic text_label_canvas
//
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_text_label_canvas::xnsl_text_label_canvas(xnsl_display_canvas* win) : 
	xnsl_widget_graph(win)
{
	strcpy(_value,"");

} //End function xnsl_text_label_canvas

xnsl_text_label_canvas::~xnsl_text_label_canvas()
{
	//Nothing yet.

} //End function ~ xnsl_text_label_canvas

xnsl_widget * xnsl_text_label_canvas::make_widget()
{
	return new xnsl_text_label_canvas;
}

xnsl_widget * xnsl_text_label_canvas::create_widget (const char *wname,
 	xnsl_widget * pxnsl_widget,int x,int y,int width,int height,
 	int,int,int,int,int,int,const char* label,const char* message) 
{
	xnsl_manager	*pxnsl_manager;
 
	strcpy(_wname,wname);
	strcpy(_wlabel,label);
	_X0 = x;
	_Y0 = y;

	if (pxnsl_widget == NULL)
	{
		cmd_error("text_label_canvas: NULL parent");
		return this;
	}

	pxnsl_manager = XSYSTEM->get_xnsl_manager();
	if ((_pxnsl_lib_widget = (xnsl_lib_widget*) 
		pxnsl_manager->create_manager_widget("graph", pxnsl_widget, 
		wname, x, y,width,height,0,0,0,0,0,0,label,message)) != NULL)
	   _pxnsl_lib_widget->set_wlabel(label);
	else
 	   cmd_error("create_text_label_canvas_widget failed");

	return this;
} //End function create_widget

int xnsl_text_label_canvas::read_from_database()
{
	return 1;
}
int xnsl_text_label_canvas::write_to_database()
{
	return 1;
}
int xnsl_text_label_canvas::display()
{
	int FONT_DX = 8;
	int FONT_DY = 8;
	nsl_string str;

//	int lenx = strlen(_wlabel); // FONT_DX*strlen(_wlabel)
//	int leny = FONT_DY;
//	clear_area(_widget,_X0,_Y0-10,_X0+lenx,_Y0); 
//	draw_text(_widget,_X0,_Y0,_wlabel);
//	draw_text(_widget,_X0+lenx,_Y0,_value);
	
	sprintf(str,"\"%s %s\"",_wlabel,_value);
	draw_text(_widget,_X0,_Y0,str);
	xflush();

	return 1;
}  

// int text

xnsl_int_label_canvas::xnsl_int_label_canvas(xnsl_display_canvas* win) : 
	xnsl_text_label_canvas(win)
{
}
xnsl_int_label_canvas::~xnsl_int_label_canvas()
{
}
xnsl_widget * xnsl_int_label_canvas::make_widget ()
{
	return new xnsl_int_label_canvas;
}
int xnsl_int_label_canvas::read_from_database()
{
	int i = 0;
        nsl_list* list = 0;
        xnsl_display_canvas* canvas = 0;
        xnsl_display_window* window = 0;
        nsl_layer* data;

        if ((canvas = (xnsl_display_canvas*) m_parent) != NULL && 
           (window = (xnsl_display_window*) m_parent->get_m_parent()) != NULL)
                list = window->get_data_list();
        else
                cmd_error("xnsl_int_label_canvas: NULL parent window");

        if (list != NULL)
        {
             if ((data = (nsl_layer*) list->get_by_name(get_name())) != NULL)
             {
                i = ((nsl_int_data*) data)->get_value();
		sprintf(_value,"%d",i);
             }
             else
                cmd_error("xnsl_int_label_canvas: NULL obj ",get_name());
	}
        else
                cmd_error("xnsl_int_label_canvas: NULL data list");


	return 1;
}
int xnsl_int_label_canvas::write_to_database()
{
	return 1;
}

// num text

xnsl_num_label_canvas::xnsl_num_label_canvas(xnsl_display_canvas* win) : 
	xnsl_text_label_canvas(win)
{
}
xnsl_num_label_canvas::~xnsl_num_label_canvas()
{
}
xnsl_widget * xnsl_num_label_canvas::make_widget ()
{
	return new xnsl_num_label_canvas;
}
int xnsl_num_label_canvas::read_from_database()
{
	num_type r = 0;
        nsl_list* list = 0;
        xnsl_display_canvas* canvas = 0;
        xnsl_display_window* window = 0;
        nsl_layer* data;

        if ((canvas = (xnsl_display_canvas*) m_parent) != NULL && 
           (window = (xnsl_display_window*) m_parent->get_m_parent()) != NULL)
                list = window->get_data_list();
        else
                cmd_error("xnsl_num_label_canvas: NULL parent window");

        if (list != NULL)
        {
             if ((data = (nsl_layer*) list->get_by_name(get_name())) != NULL)
             {
                r = ((nsl_num_data*) data)->get_value();
		sprintf(_value,"%f",r);
             }
             else
                cmd_error("xnsl_num_label_canvas: NULL obj ",get_name());
	}
        else
                cmd_error("xnsl_num_label_canvas: NULL data list");


	return 1;
}
int xnsl_num_label_canvas::write_to_database()
{
	return 1;
}

// str text

xnsl_str_label_canvas::xnsl_str_label_canvas(xnsl_display_canvas* win) : 
	xnsl_text_label_canvas(win)
{
}
xnsl_str_label_canvas::~xnsl_str_label_canvas()
{
}
xnsl_widget * xnsl_str_label_canvas::make_widget ()
{
	return new xnsl_str_label_canvas;
}
int xnsl_str_label_canvas::read_from_database()
{
        nsl_list* list = 0;
        xnsl_display_canvas* canvas = 0;
        xnsl_display_window* window = 0;
        nsl_layer* data;

        if ((canvas = (xnsl_display_canvas*) m_parent) != NULL && 
           (window = (xnsl_display_window*) m_parent->get_m_parent()) != NULL)
                list = window->get_data_list();
        else
                cmd_error("xnsl_str_label_canvas: NULL parent window");

        if (list != NULL)
        {
            if ((data = (nsl_layer*) list->get_by_name(get_name())) != NULL)
 		strcpy(_value,((nsl_str_data*) data)->get_value());
            else
                cmd_error("xnsl_str_label_canvas: NULL obj ",get_name());
	}
        else
                cmd_error("xnsl_str_label_canvas: NULL data list");


	return 1;
}
int xnsl_str_label_canvas::write_to_database()
{
	return 1;
}
