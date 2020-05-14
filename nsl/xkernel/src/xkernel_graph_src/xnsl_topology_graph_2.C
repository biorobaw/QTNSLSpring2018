/* SCCS  %W%---%E%--%U% */
//
//	topology_graph_2.c
//

# include "nsl.h"

//TODO: uncomment when display_window, display_canvas, etc. are defined -bn7

/*
extern nsl_num_0* get_data_obj(data_type_list*,char*);
extern nsl_model* NSL_MODEL; // model pointer

void (*INIT_USER_DISPLAY_CANVAS)(display_canvas*); // extern graphics
void (*INIT_USER_DISPLAY_WINDOW)(display_window*); // extern graphics

void init_topology_graph_window(display_window* WIN)
{
	// 1 - int, 2 - float, 3 - string

	WIN->init_general_data("LAYER2",3);
// 	nsl_layer* layer = NSL_MODEL->get_layer(layer_name);
}

void init_topology_graph_canvas(display_canvas* canvas_win)
{
	display_window* parent_window = canvas_win->get_parent_window();
	nsl_layer* ptr = parent_window->get_layer();

	topology_graph_2_mat* obj;

	if ((obj = new topology_graph_2_mat(window,(nsl_num_2*) ptr))
	{
		canvas_win->set_canvas_graph(obj);
		int object_total = CANVAS->get_object_total();
		obj->set_index(++object_total);
		canvas_win->set_object_total(object_total);
	}
	else
      	{
              cmd_error("*** init_topology_graph_canvas ***");
              cmd_error("Unable to create canvas object");
      	}
}

topology_graph_2::topology_graph_2(display_window* window)
	: display_graph(window,"topology_graph_2")
{
}
void topology_graph_2::read_from_database()
{
	display_graph::read_from_database();
}
void topology_graph_2::write_to_database()
{
	display_graph::write_to_database();
}

topology_graph_2_mat::topology_graph_2_mat(display_window* window,
	nsl_num_2* m) : topology_graph_2(window)
{
	layer0_ptr = m;
	layer_ptr = m;
}
void topology_graph_2_mat::read_from_database()
{
	parent_window->get_general_data("i0",&i0);
	parent_window->get_general_data("i1",&i1);
	parent_window->get_general_data("j0",&j0);
	parent_window->get_general_data("j1",&j1);

	parent_window->get_general_data("wxmin",&wxmin);
	parent_window->get_general_data("wxmax",&wxmax);
	parent_window->get_general_data("wymin",&wymin);
	parent_window->get_general_data("wymax",&wymax);

	i1max = ((nsl_num_2*) layer0_ptr)->get_imax();
	j1max = ((nsl_num_2*) layer0_ptr)->get_jmax();
	i2max = ((nsl_num_2*) layer1_ptr)->get_imax();
	j2max = ((nsl_num_2*) layer1_ptr)->get_jmax();

	if ((i1max != i2max) || (j1max != j2max))
		cmd_error("The two matrices are of different size");
	else
	{
		if (i0 < 0) 
		{
			i0 = 0;
			parent_window->set_general_data("i0",i0);
		}
		if (i1 > i1max-1) 
		{
			i1 = i1max-1;
			parent_window->set_general_data("i1",i1);
		}
		if (i1 < i0)
		{
			i0 = 0;
			i1 = i1max-1;
			parent_window->set_general_data("i0",i0);
			parent_window->set_general_data("i1",i1);
		}

		if (j0 < 0) 
		{
			j0 = 0;
			parent_window->set_general_data("j0",j0);
		}
		if (j1 > jmax-1) 
		{
			j1 = j1max-1;
			parent_window->set_general_data("j1",j1);
		}
		if (j1 < j0)
		{
			j0 = 0;
			j1 = j1max-1;
			parent_window->set_general_data("j0",j0);
			parent_window->set_general_data("j1",j1);
		}	

		parent_window->set_win_sector(i0,j0,i1,j1,i1max,j1max);
		topology_graph_2::read_from_database();
	}
}
void topology_graph_2_mat::write_to_database()
{
	topology_graph_2::write_to_database();
}
void topology_graph_2_mat::display()
{
	int fg;
	num_type** m1 = ((nsl_num_2*) layer0_ptr)->get_matrix();
	num_type** m2 = ((nsl_num_2*) layer_ptr)->get_matrix();

	if ((fg = parent_canvas->get_redraw_fg()) == 1)
		parent_canvas->set_redraw_fg(0);

	draw_matrix_topology(canvas, m1, m2, wx0, wy0, wx1, wy1, i0, i1,
				j0, j1, wxmin, wxmax, wymin, wymax);
}
*/
