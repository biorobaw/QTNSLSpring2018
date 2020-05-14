/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*        xnsl_cmd_display_window_area_level_matrix.C         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_area_level_matrix::
	xnsl_cmd_display_window_area_level_matrix()
{
        set_type("display_window_area_level_graph_matrix");
}

xnsl_cmd_display_window_area_level_matrix::
	~xnsl_cmd_display_window_area_level_matrix()
{
}
int xnsl_cmd_display_window_area_level_matrix::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_matrix::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_matrix::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_matrix::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level_matrix::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
 	return 1;
}
int xnsl_cmd_display_window_area_level_matrix::init_data(nsl_base* win)
{
   	int ival;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
 
        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
 	}

        return 1;
}
int xnsl_cmd_display_window_area_level_matrix::reset_data(nsl_base*)
{
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
 
        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
 	}

        return 1;
}
int xnsl_cmd_display_window_area_level_matrix::update_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
