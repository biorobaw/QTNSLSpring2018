#ifndef _XKERNEL_H
#define _XKERNEL_h

# include "xnsl_cmd_window.h"

# include "xnsl_cmd_display_window.h"
# include "xnsl_cmd_display_window_data.h"
# include "xnsl_cmd_display_window_vector.h"
# include "xnsl_cmd_display_window_matrix.h"
# include "xnsl_cmd_display_window_3.h"
# include "xnsl_cmd_display_window_4.h"
# include "xnsl_cmd_display_window_area_level.h"
# include "xnsl_cmd_display_window_area_level_data.h"
# include "xnsl_cmd_display_window_area_level_vector.h"
# include "xnsl_cmd_display_window_area_level_matrix.h"
# include "xnsl_cmd_display_window_area_level_3.h"
# include "xnsl_cmd_display_window_area_level_4.h"
# include "xnsl_cmd_display_window_spatial_2.h"
# include "xnsl_cmd_display_window_spatial_2_data.h"
# include "xnsl_cmd_display_window_spatial_2_vector.h"
# include "xnsl_cmd_display_window_spatial_2_matrix.h"
# include "xnsl_cmd_display_window_spatial_3.h"
# include "xnsl_cmd_display_window_spatial_3_data.h"
# include "xnsl_cmd_display_window_spatial_3_vector.h"
# include "xnsl_cmd_display_window_spatial_3_matrix.h"
# include "xnsl_cmd_display_window_temporal.h"
# include "xnsl_cmd_display_window_temporal_data.h"
# include "xnsl_cmd_display_window_temporal_vector.h"
# include "xnsl_cmd_display_window_temporal_matrix.h"

//additional headers
# include "xnsl_area_level_graph.h"
# include "xnsl_area_level_graph_data.h"
# include "xnsl_area_level_graph_vector.h"
# include "xnsl_area_level_graph_matrix.h"
# include "xnsl_spatial_graph_2.h"
# include "xnsl_spatial_graph_2_data.h"
# include "xnsl_spatial_graph_2_vector.h"
# include "xnsl_spatial_graph_2_matrix.h"
# include "xnsl_spatial_graph_3.h"
# include "xnsl_spatial_graph_3_data.h"
# include "xnsl_spatial_graph_3_vector.h"
# include "xnsl_spatial_graph_3_matrix.h"
# include "xnsl_temporal_graph.h"
# include "xnsl_temporal_graph_data.h"
# include "xnsl_temporal_graph_vector.h"
# include "xnsl_temporal_graph_matrix.h"

# include "xnsl_callback.h"
# include "xnsl_application.h"
# include "xnsl_canvas.h"
# include "xnsl_canvas_item.h"
# include "xnsl_frame.h"
# include "xnsl_panel_item.h"
# include "xnsl_panel.h"
# include "xnsl_pic_button.h"
# include "xnsl_push_button.h"
# include "xnsl_scrollable_panel.h"
# include "xnsl_scrollable_canvas.h"
# include "xnsl_menu.h"
# include "xnsl_graph.h"
# include "xnsl_grid.h"
# include "xnsl_line.h"
# include "xnsl_cmd_message.h"
# include "xnsl_text_label_canvas.h"
# include "xnsl_text_label_input.h"
# include "xnsl_text_label_panel.h"
# include "xnsl_text_menu_button.h"


#include "xnsl_manager.h"
#include "xnsl_system.h"
#include "xnsl_xpublic.h"
//end

# include "xnsl_cmd_display_frame.h"

# include "xnsl_cmd_display_canvas.h"
# include "xnsl_cmd_display_canvas_data.h"
# include "xnsl_cmd_display_canvas_vector.h"
# include "xnsl_cmd_display_canvas_matrix.h"
# include "xnsl_cmd_display_canvas_3.h"
# include "xnsl_cmd_display_canvas_4.h"
# include "xnsl_cmd_display_canvas_area_level.h"
# include "xnsl_cmd_display_canvas_area_level_data.h"
# include "xnsl_cmd_display_canvas_area_level_vector.h"
# include "xnsl_cmd_display_canvas_area_level_matrix.h"
# include "xnsl_cmd_display_canvas_area_level_3.h"
# include "xnsl_cmd_display_canvas_area_level_4.h"
# include "xnsl_cmd_display_canvas_spatial_2.h"
# include "xnsl_cmd_display_canvas_spatial_2_data.h"
# include "xnsl_cmd_display_canvas_spatial_2_vector.h"
# include "xnsl_cmd_display_canvas_spatial_2_matrix.h"
# include "xnsl_cmd_display_canvas_spatial_3.h"
# include "xnsl_cmd_display_canvas_spatial_3_data.h"
# include "xnsl_cmd_display_canvas_spatial_3_vector.h"
# include "xnsl_cmd_display_canvas_spatial_3_matrix.h"
# include "xnsl_cmd_display_canvas_temporal.h"
# include "xnsl_cmd_display_canvas_temporal_data.h"
# include "xnsl_cmd_display_canvas_temporal_vector.h"
# include "xnsl_cmd_display_canvas_temporal_matrix.h"

# include "xnsl_cmd_display_panel.h"
# include "xnsl_cmd_display_panel_data.h"
# include "xnsl_cmd_display_panel_vector.h"
# include "xnsl_cmd_display_panel_matrix.h"
# include "xnsl_cmd_display_panel_area_level.h"
# include "xnsl_cmd_display_panel_area_level_data.h"
# include "xnsl_cmd_display_panel_area_level_vector.h"
# include "xnsl_cmd_display_panel_area_level_matrix.h"
# include "xnsl_cmd_display_panel_spatial_2.h"
# include "xnsl_cmd_display_panel_spatial_2_data.h"
# include "xnsl_cmd_display_panel_spatial_2_vector.h"
# include "xnsl_cmd_display_panel_spatial_2_matrix.h"
# include "xnsl_cmd_display_panel_spatial_3.h"
# include "xnsl_cmd_display_panel_spatial_3_data.h"
# include "xnsl_cmd_display_panel_spatial_3_vector.h"
# include "xnsl_cmd_display_panel_spatial_3_matrix.h"
# include "xnsl_cmd_display_panel_temporal.h"
# include "xnsl_cmd_display_panel_temporal_data.h"
# include "xnsl_cmd_display_panel_temporal_vector.h"
# include "xnsl_cmd_display_panel_temporal_matrix.h"

# include "xnsl_cmd_window_interface.h"
# include "xnsl_cmd_system.h"

# include "xnsl_system.h"
# include "xnsl_window.h"

# include "xnsl_window_interface.h"

# include "xnsl_display_panel.h"
# include "xnsl_display_canvas.h"
# include "xnsl_display_window.h"
# include "xnsl_display_frame.h"

# include "xnsl_motif_widget.h"
# include "xnsl_motif_callback.h"
# include "xnsl_motif_panel_item.h"
# include "xnsl_motif_canvas_item.h"
# include "xnsl_motif_text_menu_button.h"
# include "xnsl_motif_application.h"
# include "xnsl_motif_canvas.h"
# include "xnsl_motif_canvas_functions.h"
# include "xnsl_motif_pic_button.h"
# include "xnsl_motif_frame.h"
# include "xnsl_motif_panel.h"
# include "xnsl_motif_menu.h"
# include "xnsl_motif_cmd_message.h"
# include "xnsl_motif_push_button.h"
# include "xnsl_motif_scrollable_panel.h"
# include "xnsl_motif_scrollable_canvas.h"
# include "xnsl_motif_text_label_panel.h"
# include "xnsl_motif_text_label_input.h"

#include "xnsl_cmd_display_panel_area_level_vector.h"
#include "xnsl_cmd_display_canvas_spatial_3_vector.h"
extern xnsl_system* XNSL_SYSTEM;
#endif