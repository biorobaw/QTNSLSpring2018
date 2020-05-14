/* SCCS  %W%---%E%--%U% */
/****************************************************************/
/*                                                           	*/
/*                  xnsl_window_interface.c                     */
/*                                                            	*/
/****************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_window_interface::xnsl_window_interface(const char* str) : 
	xnsl_window(str,"window_interface")
{
  	nsl_frame_list = new nsl_list("display_frame"); 
	frame_total = 0;

	m_children_list->append(nsl_frame_list);
}
xnsl_window_interface::~xnsl_window_interface()
{
	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)nsl_frame_list->next()) 
	    {
//		cmd_out("DELETE FRAME : ",win->get_index());
		delete win;
	    }
	}

	frame_total = 0;
	nsl_frame_list = 0;
}
int xnsl_window_interface::create()
{
	return create_window_interface();
}
int xnsl_window_interface::create_window_interface()
{
 	if ((_widget = new xnsl_application) != NULL)
	{
		((xnsl_application*) _widget)->create_widget("NSL2.5");
//		widget = _widget;
	}
	else
		cmd_error("window_interface: Cannot create manager");

	return 1;
}
int xnsl_window_interface::add_frame(xnsl_display_frame* fr)
{
	++frame_total;

	fr->set_index(frame_total); // ++frame_total

	if (nsl_frame_list != NULL)
		nsl_frame_list->append(fr);
	else
		cmd_error("NULL nsl_frame_list");

	return frame_total;
}
void xnsl_window_interface::handle_events()
{
	if (_widget != NULL)
		((xnsl_application*) _widget)->handle_events();
	else
		cmd_error("window_interface: NULL root window");
}
int xnsl_window_interface::update()
{
	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)nsl_frame_list->next()) 
		win->update();
	}
	return 1;
}
int xnsl_window_interface::display()
{
	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)nsl_frame_list->next()) 
		win->display();
	}
	return 1;
}
int xnsl_window_interface::clear()
{
	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    xnsl_window* win;
	    while (win = (xnsl_window*)nsl_frame_list->next()) 
		win->clear();
	}
	return 1;
}

xnsl_display_frame* xnsl_window_interface::get_display_frame(char* str)
{
	return (xnsl_display_frame*) nsl_frame_list->get_by_name(str);
}
xnsl_display_frame* xnsl_window_interface::get_display_frame(int windex)
{
	return (xnsl_display_frame*) nsl_frame_list->get_by_index(windex);
}
xnsl_display_window* xnsl_window_interface::get_display_window(char* str)
{
	if (nsl_frame_list == NULL)
		return (xnsl_display_window*) 0;

	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    nsl_list* win_list;
	    xnsl_window* fr_win;
	    xnsl_window* win;

	    while (fr_win = (xnsl_window*)nsl_frame_list->next()) 
	    {
		win_list = ((xnsl_display_frame*) fr_win)->get_window_list();
		if ((win = (xnsl_window*) win_list->get_by_name(str)) != NULL)
			return (xnsl_display_window*) win;
	    }
	}

	return (xnsl_display_window*) 0;
}
xnsl_display_window* xnsl_window_interface::get_display_window(
	int fr_index,int win_index)
{
	xnsl_display_frame* fr = 0;
	xnsl_display_window* win = 0;
	nsl_list* win_list;

	if ((fr = (xnsl_display_frame*) nsl_frame_list->
		get_by_index(fr_index)) != NULL)
	{
		win_list = fr->get_window_list();
		win = (xnsl_display_window*) win_list->get_by_index(win_index);
	}

	return win;
}

int xnsl_window_interface::print(ostream&) const
{
	return 1;
}
int xnsl_window_interface::print_status(ostream& out) const
{
	out << "// frame total: " << frame_total << "\n";
	out.flush();

 	return 1;
}

/*
int window_interface::print_frame_status(ostream& out)
{
	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    generic_window* win;
	    while (win = (generic_window*)nsl_frame_list->next()) 
		((display_frame*) win)->print_status(out);
	}
}
int window_interface::print_frame_status(ostream& out,char* name)
{
	display_frame* win;
	if ((win = (display_frame*) get_display_frame(name)) != NULL)
		win->print_status(out);
	else
		cmd_error("Unknown Frame: ",name);
}
void window_interface::print_frame_status(ostream& out,int index)
{
	display_frame* win;
	if ((win = (display_frame*) get_display_frame(index)) != NULL)
		win->print_status(out);
	else
		cmd_error("Unknown Frame Index: ",index);
}
void window_interface::print_window_status(ostream& out)
{
	nsl_list* list;

	if (nsl_frame_list != NULL)
	{
	    nsl_frame_list->wind_up();
	    generic_window* fr;
	    while (fr = (generic_window*)nsl_frame_list->next()) 
	    { 
		if ((list = ((display_frame*) fr)->get_window_list()) != NULL)
		{
		    list->wind_up();
		    generic_window* win;
		    while (win = (generic_window*)list->next()) 
			((display_window*) win)->print_status(out);
		}
	    }
	}
}
void window_interface::print_window_status(ostream& out,char* name)
{
	display_window* win;
	if ((win = (display_window*) get_display_window(name)) != NULL)
		win->print_status(out);
	else
		cmd_error("Unknown Window: ",name);
}
void window_interface::print_window_status(ostream& out,
	int fr_index,int win_index)
{
	display_window* win;
	if ((win = 
	   (display_window*) get_display_window(fr_index,win_index)) != NULL)
		win->print_status(out);
	else
		cmd_error("Unknown Window");
}

*/
int xnsl_window_interface::output(char* str)
{
	if (_widget != NULL)
		((xnsl_application*) _widget)->output(str);
	else
		cmd_error("window interface: NULL _widget");

	return 1;
}
