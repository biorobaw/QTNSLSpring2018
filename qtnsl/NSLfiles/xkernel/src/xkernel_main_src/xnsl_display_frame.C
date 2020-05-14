/* SCCS  @(#)xnsl_display_frame.C	1.1---95/08/13--21:00:37 */
//
//	xnsl_display_frame.c
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_display_frame::xnsl_display_frame(xnsl_window* fr,char* str) :
	xnsl_window(str,"display_frame")
{
	if (fr != NULL)
		m_parent = fr;	   
	else
		m_parent = 0;		   

	window_list = new nsl_list("display_window"); 

	m_children_list->append(window_list);

	reset(); 

	window_cols = 0;
	window_rows = 1;
}

xnsl_display_frame::~xnsl_display_frame()
{
	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
	    {
//		cmd_out("DELETE WIN: ",win->get_index());
		delete  win;
	    }
	}

	window_total = 0;
	window_list = 0; 

	done_fg = NSL_ON; // dead display frame

//	frame->destroy_widget();
}

int xnsl_display_frame::add_window(xnsl_display_window* win)
{ 
 	if (win == NULL || window_list == NULL)
	{
		cmd_error("display_frame::add_window");
		cmd_error("Unable to add window to frame list");
		return 0;
	}

	++window_total;

	win->set_index(window_total);
	window_list->append(win); 

	return window_total;
}

int xnsl_display_frame::clear()
{
 	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
		((xnsl_display_window*) win)->clear();
	}

	return 1;
}
int xnsl_display_frame::resize(int x,int y,int w,int h)
{
 	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

//	((xnsl_lib_widget*) _widget)->set_env(get_wname(),x,y,w,h);

	return 1;
}
int xnsl_display_frame::resize()
{
 	xnsl_display_canvas* can;
	int x,y;
	int i;


// make sure there is no division by 0
	if (window_rows <= 0)
		window_rows = window_total;
	if (window_cols <= 0)
		window_cols = 1;

	_width = _widget->get_width();
	_height = _widget->get_height();

	int hoff = (_height)%window_rows;
	int h = (_height - hoff)/window_rows;
	int woff = _width%window_cols;
	int w = (_width - woff)/window_cols;

	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
	    {
		i = win->get_index();

		x = (w)*((i-1)%window_cols);
		y = (h)*((i-1)/window_cols);

		if ((can = 
		   ((xnsl_display_window*) win)->get_window_canvas()) != NULL)
		{
			((xnsl_display_window*) win)->resize(x,y,w,h);
// set_win_sector() = set_win_sector(x,y,w,h) + layer size auto updates
//			((xnsl_display_window*) win)->set_win_sector();
			can->update();
		}
	    }
	}

	return 1;
}
int xnsl_display_frame::create(int x,int y,int w,int h)
{
 	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

  	if ((_widget = new xnsl_frame) == NULL)
	{
		cmd_error("display_frame: CANNOT create frame");
		return -1;
	}

	_widget->set_m_parent(this);
	
 	if (m_parent != NULL)
	{
 		_widget->create_widget(get_wname(),
			((xnsl_window*) m_parent)->get_widget(),x,y,w,h);
 		done_fg = NSL_OFF;	// alive
 	}
	else
		_widget->create_widget(get_wname(),0,x,y,w,h);

	return 1;
}
int xnsl_display_frame::create()
{
 	return create(_X0,_Y0,_width,_height);
}
int xnsl_display_frame::create(int,char**)
{
 	return create();
}
int xnsl_display_frame::reset(nsl_buffer*)
{
  	window_total = 0;
	window_list->clear(); 

 	return 1;
}
int xnsl_display_frame::init()
{
	return 1;
}

int xnsl_display_frame::update()
{
 	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
		((xnsl_display_window*) win)->update();
	}

	return 1;
}
int xnsl_display_frame::update_from_panel()
{
 	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
;//		((xnsl_display_window*) win)->update_from_panel();
	}

	return 1;
}
int xnsl_display_frame::display()
{
 	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
		win->display();
	}

	return 1;
}

xnsl_display_window* xnsl_display_frame::get_display_window(char* str)
{
 	xnsl_display_window* win;

	if ((win = (xnsl_display_window*) 
	    window_list->get_by_name(str)) != NULL)
		return (xnsl_display_window*) win;

	return (xnsl_display_window*) 0;
}
xnsl_display_window* xnsl_display_frame::get_display_window(int windex)
{
	xnsl_display_window* win;

	if ((win = (xnsl_display_window*) 
	    window_list->get_by_index(windex)) != NULL)
		return (xnsl_display_window*) win;

	return (xnsl_display_window*) 0;
}

int xnsl_display_frame::print(ostream& out) const
{
	xnsl_window::print(out);

	if (resize_fg == NSL_ON)
	   out << "set display_frame auto_resize ON\n";
	else
	   out << "set display_frame auto_resize OFF\n";
	out << "set display_frame rows " << window_rows << "\n";
	out << "set display_frame cols " << window_cols << "\n";
 	out << "\nupdate display_frame\n";
	out << "\n";
	out.flush();

	print_display_frame(out);

	return 1;
}
int xnsl_display_frame::print_display_frame(ostream& out) const
{
 	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
		((xnsl_display_window*) win)->print(out);
	}

	return 1;
}
int xnsl_display_frame::print_display_frame(ostream& out,int windex) const
{
 	xnsl_display_window* win;

	if ((win = (xnsl_display_window*) 
	    window_list->get_by_index(windex)) != NULL)
		win->print(out);

	return 1;
}
int xnsl_display_frame::print_display_frame(ostream& out,char* str) const
{
	xnsl_display_window* win;

	if ((win = (xnsl_display_window*) 
	    window_list->get_by_name(str)) != NULL)
		win->print(out);

	return 1;
}

int xnsl_display_frame::print_status(ostream& out) const
{
	xnsl_window::print_status(out);

	if (resize_fg == NSL_ON)
	   out << "// auto_resize: ON\n";
	else
	   out << "// auto_resize: OFF\n";
	out << "// rows: " << window_rows << "\n";
	out << "// cols: " << window_cols << "\n";
	out << "// total windows: " << window_total << "\n";
 	out << "\n";
	out.flush();

	if (_widget != NULL)
		_widget->print_status(out);

	print_display_frame_status(out);

	return 1;
}
int xnsl_display_frame::print_display_frame_status(ostream& out) const
{
 	if (window_list != NULL)
	{
	    window_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)window_list->next()) 
		((xnsl_display_window*) win)->print_status(out);
	}

	return 1;
}
int xnsl_display_frame::print_display_frame_status(ostream& out,int windex) const
{
 	xnsl_display_window* win;

	if ((win = (xnsl_display_window*) 
	    window_list->get_by_index(windex)) != NULL)
		win->print_status(out);

	return 1;
}
int xnsl_display_frame::print_display_frame_status(ostream& out,char* str) const
{
	xnsl_display_window* win;

	if ((win = (xnsl_display_window*) 
	    window_list->get_by_name(str)) != NULL)
		win->print_status(out);

	return 1;
}
