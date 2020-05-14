/* SCCS  @(#)xnsl_display_window.C	1.1---95/08/13--21:00:38 */
//
//	xnsl_display_window.c
//

#include "xkernel.h"
#include "nsl_kernel.h" 

/*

win	read_from_database	write_to_database	display 
----------------------------------------------------------------------
panel	data=>panel		panel=>data		panel display
canvas	data=>canvas					canvas display

*/

xnsl_display_window::xnsl_display_window(xnsl_display_frame* fr,char* str) : 
	xnsl_window(str,"display_window")
{
 	m_parent = fr;
       /* aa 95/4/19 b */
       control_panel=NULL;
       window_canvas=NULL;
       /* aa 95/4/19 e */

	if (fr != NULL)
	{
		fr->add_window(this);
		_widget = fr->get_widget();
	}
	else
		cmd_error("display_window: NULL parent");

 	strcpy(graph_name,"");
	graph_type = 0;

	strcpy(layer_name,"");
	layer_type = 0;
	layer = 0;
}
xnsl_display_window::~xnsl_display_window()
{
 	delete window_canvas;
	delete control_panel;
}

int xnsl_display_window::resize(int x,int y,int w,int h)
{
 	_X0 = x;
	_Y0 = y;
	_width = w;
	_height = h;

	if (window_canvas != NULL) 
	        window_canvas->resize(x,y,w,h);
	else
	{
		cmd_error("display_window::resize");
		cmd_error("Null window canvas");
	}

	return 1;
}

int xnsl_display_window::create(int x,int y,int w,int h)
{
 	return 1;
}
int xnsl_display_window::create()
{
 	return create(_X0,_Y0,_width,_height);
}
int xnsl_display_window::reset(nsl_buffer*)
{
 	data_total = 0;
	data_list->clear();

	return 1;
}
int xnsl_display_window::init()
{
	return 1;
}
int xnsl_display_window::clear()
{
 	nsl_string overlay;;
	nsl_layer* data;

	strcpy(overlay,"OFF");

	if ((data = (nsl_layer*) 
	    data_list->get_by_name("overlay")) != NULL)
		strcpy(overlay,((nsl_str_data*) data)->get_value());

	if (strcmp(overlay,"ON") != 0)
		window_canvas->clear();

	return 1;
}

int xnsl_display_window::update()	// read and display from database
{
	window_canvas->update();
	control_panel->update();

	return 1;
}
/*
int xnsl_display_window::update_window_layer(char* str) // update layer pars
{
 	set_layer_name(str);
	update_window_layer();
}
int xnsl_display_window::update_window_layer() // update layer pars
{
 	nsl_model* model;

	if ((model = NSL_SYSTEM->get_model()) == NULL)
	{
		cmd_error("NULL MODEL");
		return;
	}

	if ((layer = model->get_layer(layer_name)) != NULL)
	{
		layer_type = layer->get_layer_type();
		set_general_data("LAYER",layer_name);
		control_panel->update("LAYER"); // read_from_database + display
	}
	else
	{
		cmd_error("Unknown Layer: ",layer_name);
		if ((layer = model->get_layer(1)) != NULL)
		{
			strcpy(layer_name,layer->get_name());
			cmd_error("Using Default Layer: ",layer_name);
			layer_type = layer->get_layer_type();
			set_general_data("LAYER",layer_name);
			control_panel->update("LAYER");
		}
		else
			cmd_error_exit("Couldn't find layer with index 1");
	}
}
void xnsl_display_window::update_window_graph(char* str) // update graph pars
{
 	set_graph_name(str);
	update_window_graph();
}
void xnsl_display_window::update_window_graph() // update graph pars
{
 	nsl_num_0* graph;
	if ((graph = XNSL_SYSTEM->get_graph(graph_name)) != NULL)
	{
		graph_type = graph->get_index();
		set_general_data("GRAPH",graph_name);
		control_panel->update("GRAPH"); // read_from_database + display
	}
	else
	{
		cmd_error("Unknown Graphr: ",graph_name);
		if ((graph = XNSL_SYSTEM->get_graph(1)) != NULL)
		{
			strcpy(graph_name,graph->get_name());
			cmd_error("Using Default Graph: ",graph_name);
			graph_type = graph->get_index();
			set_general_data("GRAPH",graph_name);
			control_panel->update("GRAPH");
		}
		else
			cmd_error_exit("Couldn't find graph with index 1");
	}
}

void xnsl_display_window::update_from_panel()
{
 // from panel to database to canvas
	control_panel->write_to_database();

 	window_canvas->read_from_database();

	char* window_overlay = "OFF";

	nsl_num_0* win_data;

	if ((win_data = get_data_obj(data_list,"window_overlay")) != NULL)
		window_overlay = win_data->get_str_value();

	if (strcmp(window_overlay,"ON") != 0)
		window_canvas->clear();

	window_canvas->display();
}
*/
int xnsl_display_window::read_from_database()
{
// 	control_panel->read_from_database();
//	window_canvas->read_from_database(); 

	return 1;
}
int xnsl_display_window::write_to_database()
{
// 	control_panel->write_to_database(); 
//	window_canvas->write_to_database();

	return 1;
}
int xnsl_display_window::display()
{
	int it = NSL_SYSTEM->getSimTimeStep();

	nsl_string overlay;
	int display_step = 1;
	nsl_layer* data;

	strcpy(overlay,"OFF");

	if ((data = 
	    (nsl_layer*) data_list->get_by_name("step")) != NULL)
		display_step = ((nsl_int_data*) data)->get_value();

	if ((data = 
	    (nsl_layer*) data_list->get_by_name("overlay")) != NULL)
		strcpy(overlay,((nsl_str_data*) data)->get_value());

	if (display_step != 0 && it%display_step == 0)
	{

 	    if (window_canvas->get_clear_fg() == 1 && 	
		strcmp(overlay,"ON") != 0)
		window_canvas->clear();

	    window_canvas->display();
	}

	return 1;
}

// mouse input

int xnsl_display_window::input(int x_pos,int y_pos,int fg)
{
 	return window_canvas->input(x_pos,y_pos,fg);
}
int xnsl_display_window::output(int x_pos,int y_pos)
{
 	return window_canvas->output(x_pos,y_pos);
}

// print window data

int xnsl_display_window::print_status(ostream& out) const
{
	xnsl_window::print_status(out);

	print_display_window_status(out);

//	out << "// layer:\t" << layer_name << "\n";
//	out << "// graph:\t" << graph_name << "\n";
//  	out << "\n";
//	out.flush();

	return 1;
}
int xnsl_display_window::print_display_window_status(ostream& out) const
{
 	if (data_list != NULL)
	{
	   out << "// window data list\n";
	   data_list->wind_up();
	   nsl_layer* data;
	   while (data = (nsl_layer*) data_list->next()) 
	   {
 		data->print_status(out);
 		data->print(out);
	   }
  	}
	return 1;
}
int xnsl_display_window::print_display_window_status(ostream& out,
	int windex) const
{
 	if (data_list != NULL)
	{
	   data_list->wind_up();
	   nsl_layer* data;
	   while (data = (nsl_layer*) data_list->next()) 
 	      if (windex == data->get_index())
	      	  data->print_status(out);
	}
	return 1;
}
int xnsl_display_window::print_display_window_status(ostream& out,
	char* str) const
{
 	if (data_list != NULL)
	{
	   data_list->wind_up();
	   nsl_layer* data;
	   while (data = (nsl_layer*)data_list->next()) 
 	      if (strcmp(str,data->get_name()) == 0)
	      	  data->print_status(out);
 	}

	return 1;
}
int xnsl_display_window::print(ostream& out) const
{
	xnsl_window::print(out);

 	print_display_window(out);

 	out << "\nupdate display_window\n\n";

	if (window_canvas != NULL)
		window_canvas->print(out);

	if (control_panel != NULL)
		control_panel->print(out);

	return 1;
}
int xnsl_display_window::print_display_window(ostream& out) const
{
 	if (data_list != NULL)
	{
	   data_list->wind_up();
	   nsl_layer* data;
	   while (data = (nsl_layer*)data_list->next()) 
	   {
 		out << "set window ";
		data->print(out);
 	   }
 	}
	return 1;
}
int xnsl_display_window::print_canvas_status(ostream& out) const
{
 	return window_canvas->print_status(out);
}
int xnsl_display_window::print_panel_status(ostream& out) const
{
 	return control_panel->print_status(out);
}
