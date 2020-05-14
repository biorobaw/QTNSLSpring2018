/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*            xnsl_cmd_display_window_area_level.C            */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_area_level::xnsl_cmd_display_window_area_level()
{
        set_type("display_window_area_level_graph");
}

xnsl_cmd_display_window_area_level::~xnsl_cmd_display_window_area_level()
{
}
int xnsl_cmd_display_window_area_level::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_area_level::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        nsl_layer* dset = 0;
	nsl_list* list = 0;

/*	if (win != NULL && 
		(list = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
         	dset = new nsl_num_data("val_in");
		dset->set_flag(1);
            	((xnsl_window*) win)->add_data(dset);
         	dset = new nsl_num_data("val_out");
		dset->set_flag(1);
            	((xnsl_window*) win)->add_data(dset);
	}
        else
                cmd_error("cmd: NULL list");
*/
        return 1;
}
int xnsl_cmd_display_window_area_level::init_data(nsl_base* win)
{
        num_type fval;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
 
/*        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("val_in")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("val_in")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'val_in' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'val_in' obj");

          if ((data = (nsl_layer*) list->get_by_name("val_out")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("val_out")) != NULL)
		     fval = ((nsl_num_data*) bdat)->get_value();
           	else
                     cmd_error("cmd_display_window: NULL bdat 'val_out' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'val_out' obj");
  	}
*/
        return 1;
}
int xnsl_cmd_display_window_area_level::reset_data(nsl_base*)
{
        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
 
/*        if ((cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("val_in")) != NULL)
          {
  		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'val_in' obj");

          if ((data = (nsl_layer*) list->get_by_name("val_out")) != NULL)
          {
  		((nsl_num_data*) data)->set_value(0.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'val_out' obj");
  	}
*/
        return 1;
}
int xnsl_cmd_display_window_area_level::update_data(nsl_base* win,
	int,int,int,int,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
        num_type fval;
        nsl_layer* data = 0;
        nsl_base* bdat = 0;
        nsl_list* list = 0;
		nsl_cmd_type* cmd_obj = 0; 
 
/*        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("val_in")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_num_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("val_in")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'val_in' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'val_in' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("val_out")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_num_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("val_out")) != NULL)
		     ((nsl_num_data*) bdat)->set_value(fval);
           	else
                     cmd_error("cmd_display_window: NULL bdat 'val_out' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'val_out' obj");
       	}
*/
        return 1;
}
