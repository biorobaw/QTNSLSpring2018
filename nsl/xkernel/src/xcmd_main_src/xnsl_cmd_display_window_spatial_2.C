/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*             	xnsl_cmd_display_window_spatial_2.C           */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_spatial_2::xnsl_cmd_display_window_spatial_2()
{
        set_type("display_window_spatial_graph_2");
}

xnsl_cmd_display_window_spatial_2::~xnsl_cmd_display_window_spatial_2()
{
}
int xnsl_cmd_display_window_spatial_2::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_2::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
	nsl_list* list = 0;
        nsl_layer* data;

	if (win != NULL && 
		(list = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
            data = new nsl_on_off_data("pulse",NSL_OFF);
	    data->set_flag(1);
            ((xnsl_window*) win)->add_data(data);
	}
	else
		cmd_error("cmd_display_window: CANNOT add data to window");

	return 1;
}
int xnsl_cmd_display_window_spatial_2::init_data(nsl_base* win)
{
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
 	on_off_enum on = NSL_OFF;
	nsl_cmd_type* cmd_obj; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("pulse")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("pulse")) != NULL)
			on = ((nsl_on_off_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'pulse' obj");
		((nsl_on_off_data*) data)->set_value(on);
          }
          else
                cmd_error("cmd_display_window: NULL 'pulse' obj");
  	}

        return 1;
}
int xnsl_cmd_display_window_spatial_2::reset_data(nsl_base*)
{
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
  
        if ((cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("pulse")) != NULL)
          {
   		((nsl_on_off_data*) data)->set_value(NSL_OFF);
          }
          else
                cmd_error("cmd_display_window: NULL 'pulse' obj");
  	}

        return 1;
}
int xnsl_cmd_display_window_spatial_2::update_data(nsl_base* win,
	int,int,int,int,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
 	on_off_enum on = NSL_OFF;
	nsl_cmd_type* cmd_obj; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("pulse")) != NULL &&
		data->get_flag() == 1)
          {
                on = ((nsl_on_off_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("pulse")) != NULL)
			((nsl_on_off_data*) bdat)->set_value(on);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'pulse' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'pulse' obj");
       	}

        return 1;
}

