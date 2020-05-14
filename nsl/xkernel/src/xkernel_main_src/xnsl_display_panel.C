/* SCCS  %W%---%E%--%U% */
//
//	xnsl_display_panel.c
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_display_panel::xnsl_display_panel(xnsl_display_window* win,char* str) : 
	xnsl_window(str,"display_panel")
{
	m_parent = win;	   
	if (win != NULL)
		win->set_control_panel(this);
	else
		cmd_error("display_panel: NULL parent window");
}

xnsl_display_panel::~xnsl_display_panel()
{
}

// resize

int xnsl_display_panel::resize(int x,int y,int w,int h)
{
 	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

	if (done_fg == 1)
		cmd_error("Cannot open panel");
	else
;//		((xnsl_lib_widget*) _widget)->set_env(get_name(),x,y,w,h);

	return 1;
}

// reset

int xnsl_display_panel::reset(nsl_buffer*)
{
 	return 1;
}
 
// clear

int xnsl_display_panel::clear()
{
	if (done_fg == 1)
		cmd_out("Cannot open panel");

	return 1;
}

// init

int xnsl_display_panel::init()
{
	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
		item->init();
	}

	return 1;
}
 
// create

int xnsl_display_panel::create(int x,int y,int w,int h)
{
 	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

	if ((_widget = new xnsl_panel) == NULL)
	{
		cmd_error("display_panel: CANNOT create panel");
		return -1;
	}

	_widget->set_m_parent(this);
	
 	if (m_parent != NULL)
	{
		_widget->create_widget(get_wname(),
			((xnsl_window*) m_parent)->get_widget(),x,y,w,h);
 	}
	else
		_widget->create_widget(get_wname(),0,x,y,w,h);

	return 1;
}
int xnsl_display_panel::create()
{
 	return create(_X0,_Y0,_width,_height);
}
 
// display

int xnsl_display_panel::display()
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
		item->display();
	}
	return 1;
}
int xnsl_display_panel::display(char* wname)
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    	if (strcmp(wname,item->get_name()) == 0) 
		    item->display();
	}
	return 1;
}

// update

int xnsl_display_panel::update()
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else
	{
		read_from_database();
 		display();
	}
	return 1;
}
int xnsl_display_panel::update(char* wname)
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else
	{
		read_from_database(wname);
		display(wname);
	}
	return 1;
}

// database

int xnsl_display_panel::read_from_database()
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
		item->read_from_database();
	}
	else
	{
	    cmd_error("display_panel::read_from_database");
	    cmd_error("NULL data_list");
	}
	return 1;
}
int xnsl_display_panel::write_to_database()
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
		item->write_to_database();
	}
	else
	{
	    cmd_error("display_panel::write_to_database");
	    cmd_error("NULL data_list");
	}
	return 1;
}
int xnsl_display_panel::read_from_database(char* wname)
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    	if (strcmp(wname,item->get_name()) == 0) 
		    item->read_from_database();
	}
	return 1;
}
int xnsl_display_panel::write_to_database(char* wname)
{
 	if (done_fg == 1)
		cmd_out("Cannot open panel");
	else if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    	if (strcmp(wname,item->get_name()) == 0) 
		    item->write_to_database();
	}
	return 1;
}

// print

int xnsl_display_panel::print_status(ostream& out) const
{
 	xnsl_window::print_status(out);

	print_display_panel_status(out);

	if (_widget != NULL)
		_widget->print_status(out);

	return 1;
}
int xnsl_display_panel::print_display_panel_status(ostream& out) const
{
  	out << "// total panel objects : " << item_total << "\n";
 
	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
		item->print(out);
	    out << "\nupdate display_panel\n";
	    out.flush();
	}
	else
	    cmd_error("NULL panel list");

	out << "update display_panel\n";
	out << "\n";
	out.flush();

	return 1;
}
int xnsl_display_panel::print(ostream& out) const
{
	print_display_panel(out);

	return 1;
}
int xnsl_display_panel::print_display_panel(ostream& out) const
{
  	out << "\n// total panel_items: " << item_total << "\n";

	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
		item->print(out);
	    out << "\nupdate display_panel\n";
	    out.flush();
	}
	else
	    cmd_error("NULL panel list");

	return 1;
}
int xnsl_display_panel::print_display_panel_status(ostream& out,
	int windex) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    {
		if (windex == item->get_index())
		    item->print_status(out);
	    }
	    out << "\nupdate display_panel\n";
	    out.flush();
	}
	else
	    cmd_error("NULL panel list");

	return 1;
}
int xnsl_display_panel::print_display_panel_status(ostream& out,
	char* str) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    {
		if (strcmp(str,item->get_name()) == 0)
		    item->print_status(out);
	    }
	    out << "\nupdate display_panel\n";
	    out.flush();
	}
	else
	    cmd_error("NULL data list");

	return 1;
}
int xnsl_display_panel::print_display_panel(ostream& out,int windex) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    {
		if (windex == item->get_index())
		    item->print(out);
	    }
	    out << "\nupdate display_panel\n";
	    out.flush();
	}
	else
	    cmd_error("NULL data list");

	return 1;
}
int xnsl_display_panel::print_display_panel(ostream& out,char* str) const
{
 	if (data_list != NULL)
	{
	    data_list->wind_up();
	    xnsl_panel_item* item;
	    while (item = (xnsl_panel_item*)data_list->next()) 
	    {
		if (strcmp(str,item->get_name()) == 0)
		    item->print(out);
	    }
	    out << "\nupdate display_panel\n";
	    out.flush();
	}
	else
	    cmd_error("NULL data list");

	return 1;
}
