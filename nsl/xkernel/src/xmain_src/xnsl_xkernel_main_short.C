/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                     xnsl_xkernel_main.C                    */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

void xnsl_main_init()
{
 	nsl_cmd_buf* CMD_SHELL;
	if ((CMD_SHELL = (nsl_cmd_buf*) 
		NSL.get_shell_list()->get_top()) == NULL)
	{
		cmd_error("kernel_init: NULL CMD_SHELL");
		return;
	}

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;
 
// add macros to set cmd
	const char* tstr = "xkernel";
	const char* dstr = "XNSL/xkernel/doc";
	nsl_cmd_macro* cmd_macro;
	nsl_cmd_exec* cmd_exec;
	if ((cmd_exec = CMD_SHELL->get_cmd("set")) != NULL)
	     cmd_exec->add_help_file(tstr,dstr);
	
	cmd_macro = new nsl_cmd_macro("frame_name","window name");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_name","window name");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("frame_X0","window X0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_X0","window X0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("frame_Y0","window Y0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_Y0","window Y0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("frame_width","window width");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_width","window width");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("frame_height","window height");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_height","window height");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("frame_rows","window rows");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("frame_cols","window cols");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_layer","window layer");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_layer_i0","window i0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_layer_i1","window i1");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_layer_j0","window j0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_layer_j1","window j1");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_graph","window graph");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_wymin","window wymin");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_wymax","window wymax");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_t0","window t0");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("window_t1","window t1");
	CMD_SHELL->add_macro(cmd_macro);

// check variable args here

	nsl_cmd_type* cmd_type;
	nsl_layer* dset;

// system
	cmd_type = new xnsl_cmd_system;
	CMD_SHELL->add_type_m_parent(cmd_type,"system");

// window
	cmd_type = new xnsl_cmd_window;
	CMD_SHELL->add_type_m_parent(cmd_type,"xsystem");

 	dset = new nsl_str_data("name","");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("index");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_int_data("X0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("Y0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_int_data("width",100.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("height",100.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("rows");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("cols");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_str_data("side","top");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_num_data("t0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("t1",1.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("ts");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("wxmin");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("wxmax",1.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("wxstep",1.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("wymin");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_num_data("wymax",1.0);
  	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("wystep",1.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_str_data("model","");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_str_data("layer","");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_str_data("graph","");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_on_off_data("overlay",NSL_OFF);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_on_off_data("pulse",NSL_OFF);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_on_off_data("hidden",NSL_OFF);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_on_off_data("grid",NSL_OFF);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_on_off_data("x_axis",NSL_OFF);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_on_off_data("y_axis",NSL_OFF);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_num_data("ax",1.0);
 	cmd_type->add_data(dset);
 	dset->set_flag(1);
 	dset = new nsl_num_data("by",1.0);
 	cmd_type->add_data(dset);
 	dset->set_flag(1);
 	dset = new nsl_num_data("cz",1.0);
 	cmd_type->add_data(dset);
 	dset->set_flag(1);
 	dset = new nsl_num_data("sx",1.0);
 	cmd_type->add_data(dset);
 	dset->set_flag(1);
 	dset = new nsl_num_data("sy",1.0);
 	cmd_type->add_data(dset);
 	dset->set_flag(1);
 	dset = new nsl_num_data("sz",1.0);
 	cmd_type->add_data(dset);
 	dset->set_flag(1);
  	dset = new nsl_int_data("step",1.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_int_data("i0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("j0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_int_data("i1");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("j1");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_int_data("imax");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("jmax");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("elem_i");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("elem_j");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_row_col_data("vec_type",NSL_ROW);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
  	dset = new nsl_int_data("wx0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("wy0");
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
 	dset = new nsl_int_data("wx1",100.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("wy1",100.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("wxs",100.0);
 	dset->set_flag(1);
 	cmd_type->add_data(dset);
	dset = new nsl_int_data("wys",100.0);
  	dset->set_flag(1);
	cmd_type->add_data(dset);

// window interface
	cmd_type = new xnsl_cmd_window_interface;
	CMD_SHELL->add_type_m_parent(cmd_type,"xsystem");
	CMD_SHELL->add_type_i_children(cmd_type,"window");

// display frame
	cmd_type = new xnsl_cmd_display_frame;
 	CMD_SHELL->add_type_m_parent(cmd_type,"window_interface");
	CMD_SHELL->add_type_i_children(cmd_type,"window");

// display window
	cmd_type = new xnsl_cmd_display_window;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"window");

	cmd_type = new xnsl_cmd_display_window_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_3;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_4;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_area_level;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_spatial_2;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_spatial_3;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

	cmd_type = new xnsl_cmd_display_window_temporal;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_frame");
	CMD_SHELL->add_type_i_children(cmd_type,"display_window");

// display canvas
	cmd_type = new xnsl_cmd_display_canvas;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"window");

	cmd_type = new xnsl_cmd_display_canvas_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_3;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_4;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_area_level;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_area_level_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_area_level_graph");

	cmd_type = new xnsl_cmd_display_canvas_area_level_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_area_level_graph");

	cmd_type = new xnsl_cmd_display_canvas_area_level_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_area_level_graph");

	cmd_type = new xnsl_cmd_display_canvas_area_level_3;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_area_level_graph");

	cmd_type = new xnsl_cmd_display_canvas_area_level_4;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_area_level_graph");

	cmd_type = new xnsl_cmd_display_canvas_spatial_2;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_spatial_2_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_spatial_graph_2");

	cmd_type = new xnsl_cmd_display_canvas_spatial_2_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_spatial_graph_2");

	cmd_type = new xnsl_cmd_display_canvas_spatial_2_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_spatial_graph_2");

	cmd_type = new xnsl_cmd_display_canvas_spatial_3;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_spatial_3_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_spatial_graph_3");

	cmd_type = new xnsl_cmd_display_canvas_spatial_3_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_spatial_graph_3");

	cmd_type = new xnsl_cmd_display_canvas_spatial_3_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_spatial_graph_3");

	cmd_type = new xnsl_cmd_display_canvas_temporal;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_canvas");

	cmd_type = new xnsl_cmd_display_canvas_temporal_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_temporal_graph");

	cmd_type = new xnsl_cmd_display_canvas_temporal_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_temporal_graph");

	cmd_type = new xnsl_cmd_display_canvas_temporal_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_canvas_temporal_graph");

// display panel
	cmd_type = new xnsl_cmd_display_panel;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"window");

	cmd_type = new xnsl_cmd_display_panel_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_area_level;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_area_level_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_area_level_graph");

	cmd_type = new xnsl_cmd_display_panel_area_level_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_area_level_graph");

	cmd_type = new xnsl_cmd_display_panel_area_level_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_area_level_graph");

	cmd_type = new xnsl_cmd_display_panel_spatial_2;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_spatial_2_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_spatial_graph_2");

	cmd_type = new xnsl_cmd_display_panel_spatial_2_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_spatial_graph_2");

	cmd_type = new xnsl_cmd_display_panel_spatial_2_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_spatial_graph_2");

	cmd_type = new xnsl_cmd_display_panel_spatial_3;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_spatial_3_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_spatial_graph_3");

	cmd_type = new xnsl_cmd_display_panel_spatial_3_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_spatial_graph_3");

	cmd_type = new xnsl_cmd_display_panel_spatial_3_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_spatial_graph_3");

	cmd_type = new xnsl_cmd_display_panel_temporal;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,"display_panel");

	cmd_type = new xnsl_cmd_display_panel_temporal_data;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_temporal_graph");

	cmd_type = new xnsl_cmd_display_panel_temporal_vector;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_temporal_graph");

	cmd_type = new xnsl_cmd_display_panel_temporal_matrix;
 	CMD_SHELL->add_type_m_parent(cmd_type,"display_window");
	CMD_SHELL->add_type_i_children(cmd_type,
		"display_panel_temporal_graph");
}
