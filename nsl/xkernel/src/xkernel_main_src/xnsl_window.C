/* SCCS  @(#)xnsl_window.C	1.1---95/08/13--21:00:40 */
//
//	xnsl_window.CC
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_window::xnsl_window(const char* str,const char* wtype) 
{
	set_type(wtype);
	set_base_type("window");
	set_name(str);
	set_wname(str); // have to get rid of one of these 'name' sets
	done_fg = NSL_OFF;
	redraw_fg = NSL_OFF;
	resize_fg = NSL_ON; 
//	init_fg = NSL_OFF;
// needs to instantiate data list
	data_list = 0;
	data_list = new nsl_list("data");
// needed ??
	item_list = 0;
	item_list = new nsl_list("item");

	m_children_list->append(item_list);
}
xnsl_window::~xnsl_window()
{
	done_fg = NSL_ON;
}

// get item (take out ?)

xnsl_widget* xnsl_window::get_item(const int windex)
{
 	if (item_list != NULL)
	{
	    item_list->wind_up();
	    xnsl_widget* item;
	    while (item = (xnsl_widget*)item_list->next()) 
		if (windex == item->get_index())
		    return item;
	}
	else
	{
	    cmd_error("window::get_item");
	    cmd_error("NULL item_list");
	}
 
	return 0;
}
xnsl_widget* xnsl_window::get_item(const char* wname)
{
 	if (item_list != NULL)
	{
	    item_list->wind_up();
	    xnsl_widget* item;
	    while (item = (xnsl_widget*)item_list->next()) 
		if (strcmp(wname,item->get_name()) == 0)
		    return item;
	}
	else
	{
	    cmd_error("window::get_item");
	    cmd_error("NULL item_list");
	}

	return 0;
}

// enable

int xnsl_window::enable_item(const int windex)
{
 	xnsl_widget* item;

 	if ((item = (xnsl_widget*)item_list->get_by_index(windex)) != NULL)
		item->enable();
	else
		cmd_error("Cannot get item index: ",windex); 

	return 1;
}
int xnsl_window::enable_item(const char* str)
{
 	xnsl_widget* item;

	if ((item = (xnsl_widget*)item_list->get_by_name(str)) != NULL)
		item->enable();
	else
		cmd_error("Cannot get item: ",str); 

	return 1;
}
int xnsl_window::enable_all_item()
{
 	if (item_list != NULL)
	{
	    item_list->wind_up();
	    xnsl_widget* item;
	    while (item = (xnsl_widget*)item_list->next()) 
		item->enable();
	}
	return 1;
}

// disable

int xnsl_window::disable_item(const int windex)
{
 	xnsl_widget* item;

 	if ((item = (xnsl_widget*) item_list->get_by_index(windex)) != NULL)
		item->disable();
	else
		cmd_error("Cannot get item index: ",windex); 

	return 1;
}
int xnsl_window::disable_item(const char* str)
{
 	xnsl_widget* item;

	if ((item = (xnsl_widget*) item_list->get_by_name(str)) != NULL)
		item->disable();
	else
		cmd_error("Cannot get canvas item: ",str); 

	return 1;
}
int xnsl_window::disable_all_item()
{
 	if (item_list != NULL)
	{
	    item_list->wind_up();
	    xnsl_widget* item;
	    while (item = (xnsl_widget*)item_list->next()) 
		item->disable();
	}

	return 1;
}

