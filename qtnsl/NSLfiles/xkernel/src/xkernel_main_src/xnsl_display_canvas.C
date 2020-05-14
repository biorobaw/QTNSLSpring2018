/* SCCS  %W%---%E%--%U% */
//
//	xnsl_display_canvas.c
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_display_canvas::xnsl_display_canvas(xnsl_display_window* win,char* str) : 
	xnsl_window(str,"display_canvas")
{
 	m_parent = win;		// parent display window
	if (win != NULL)
		win->set_window_canvas(this);
	else
		cmd_error("display_canvas: NULL parent window");
}
xnsl_display_canvas::~xnsl_display_canvas()
{
}

// resize

int xnsl_display_canvas::resize(int x,int y,int w,int h)
{
 	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

	if (done_fg == 1)
	   cmd_error("Cannot open canvas");
	else
	{
//	   ((xnsl_lib_widget*) _widget)->set_env(get_wname(),
//		_X0,_Y0,_width,_height);
	}

	return 1;
}

// reset

int xnsl_display_canvas::reset(nsl_buffer*)
{
	data_total = 0;
	data_list->clear();

 	return 1;
}
int xnsl_display_canvas::init()
{
 	return 1;
}

int xnsl_display_canvas::create(int x,int y,int w,int h,const char* label)
{
 	_X0 = x; _Y0 = y; _width = w; _height = h;
	strcpy(_wlabel,label);

 	xnsl_widget* fr;

	if ((_widget = new xnsl_canvas) == NULL)
	{
		cmd_error("display_canvas: CANNOT create canvas");
		return -1;
	}
	
   	if (m_parent != NULL && 
		(fr = ((xnsl_window*) m_parent)->get_widget()) != NULL)
	{
 		_widget->create_widget(get_name(),fr,_X0,_Y0,_width,_height,
		0,0,100,100,10,10,label); // label used as side
	}
	else
		cmd_error("display_canvas: CANNOT create canvas");
 
	return 1;
}
int xnsl_display_canvas::create()
{
 	return create(_X0,_Y0,_width,_height,_wlabel);
}
int  xnsl_display_canvas::clear()
{
 	if (done_fg == 1)
		cmd_error("Cannot open canvas");
	else
	{
	   redraw_fg = NSL_ON;
	   if (_widget != NULL)
	   		((xnsl_canvas*) _widget)->clear_area(_widget,0,0,get_width(),get_height());
	   else
			cmd_error("xnsl_display_canvas::clear: NULL widget");
	}
	return 1;
}

// database updates
int xnsl_display_canvas::update()
{
 	read_from_database(); // init already does this
	clear();
	display();

	return 1;
}

int xnsl_display_canvas::read_from_database()
{
 	if (done_fg == 1)
		cmd_error("Cannot open canvas");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		item->read_from_database();
	}
	else
	{
	    cmd_error("display_canvas::read_from_database");
	    cmd_error("NULL data_list");
	}
	return 1;
}
int xnsl_display_canvas::write_to_database()
{
 	if (done_fg == 1)
		cmd_error("Cannot open canvas");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		item->write_to_database();
	}
	else
	{
	    cmd_error("display_canvas::write_to_database");
	    cmd_error("NULL data_list");
	}
	return 1;
}

// display
int xnsl_display_canvas::display()
{
 	if (done_fg == 1)
		cmd_error("Cannot open canvas");
	else if (data_list != NULL)
	{
//AW99
//		clear();
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
			item->display();
	    if (_widget != NULL)
	  		((xnsl_canvas*) _widget)->redraw();
	    else
			cmd_error("display_canvas: NULL widget");
	}
	else
	{
	    cmd_error("display_canvas::display");
	    cmd_error("NULL data_list");
	}
	return 1;
}

// mouse input
int xnsl_display_canvas::input(int x_pos,int y_pos,int button)
{
 	if (done_fg == 1)
		cmd_error("Cannot open canvas");
 
//	graph_canvas->input(x_pos,y_pos,button);

	return 1;
}
int xnsl_display_canvas::output(int x_pos,int y_pos)
{
 	if (done_fg == 1)
		cmd_error("Cannot open canvas");
 
//	graph_canvas->output(x_pos,y_pos);

	return 1;
}
int xnsl_display_canvas::print_status(ostream& out) const
{
 	xnsl_window::print_status(out);

 	out << "// total canvas objects : " << item_total << "\n";

	print_display_canvas_status(out);

	if (_widget != NULL)
		_widget->print_status(out);

  	return 1;
}
int xnsl_display_canvas::print_display_canvas_status(ostream& out) const
{
 	out << "\n// total canvas_items: " << item_total << "\n";

	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		item->print_status(out);
	    out << "update display_canvas\n";
	    out << "\n";
 	    out.flush();
	}
	else
	    cmd_error("NULL canvas list");

	return 1;
}
int xnsl_display_canvas::print(ostream& out) const
{
 	xnsl_window::print(out);

  	print_display_canvas(out);

  	return 1;
}
int xnsl_display_canvas::print_display_canvas(ostream& out) const
{
  	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		item->print(out);
	    out << "update display_canvas\n";
	    out << "\n";
	    out.flush();
 	}
	else
	    cmd_error("NULL canvas list");

	return 1;
}
int xnsl_display_canvas::print_display_canvas_status(ostream& out,
	int windex) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		if (windex == item->get_index())
	    	   item->print_status(out);
	    out << "\nupdate display_canvas\n";
	    out.flush();
	}
	else
	    cmd_error("NULL canvas list");

	return 1;
}
int xnsl_display_canvas::print_display_canvas_status(ostream& out,
	char* str) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		if (strcmp(str,item->get_name()) == 0)
	    	   item->print_status(out);
	    out << "\nupdate display_canvas\n";
	    out.flush();
	}
	else
	    cmd_error("NULL canvas list");

	return 1;
}
int xnsl_display_canvas::print_display_canvas(ostream& out,
	int windex) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		if (windex == item->get_index())
	    	   item->print(out);
	    out << "\nupdate display_canvas\n";
	    out.flush();
	}
	else
	    cmd_error("NULL canvas list");

	return 1;
}
int xnsl_display_canvas::print_display_canvas(ostream& out,
	char* str) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_canvas_item* item;
	    while (item = (xnsl_canvas_item*)data_list->next()) 
		if (strcmp(str,item->get_name()) == 0)
	    	   item->print(out);
	    out << "\nupdate display_canvas\n";
	    out.flush();
	}
	else
	    cmd_error("NULL canvas list");

	return 1;
}
