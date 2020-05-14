/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*             xnsl_cmd_display_window_spatial_3.C            */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_spatial_3::xnsl_cmd_display_window_spatial_3()
{
        set_type("display_window_spatial_graph_3");
}

xnsl_cmd_display_window_spatial_3::~xnsl_cmd_display_window_spatial_3()
{
}
int xnsl_cmd_display_window_spatial_3::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_spatial_3::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        nsl_layer* data;
	nsl_list* list = 0;

	if (win != NULL)
	{
	   if ((list = ((xnsl_window*) win)->get_data_list()) != NULL)
	   {
        	data = new nsl_on_off_data("hidden",NSL_ON);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
        	data = new nsl_num_data("sx",1.0);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
        	data = new nsl_num_data("sy",1.0);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
        	data = new nsl_num_data("sz",1.0);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
        	data = new nsl_num_data("ax",1.0);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
        	data = new nsl_num_data("by",1.0);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
        	data = new nsl_num_data("cz",1.0);
		data->set_flag(1);
        	((xnsl_window*) win)->add_data(data);
	   }
	   else
		cmd_error("cmd_display_window: NULL data list");
	}
	else
		cmd_error("cmd_display_window: NULL window");
		
        return 1;
}
int xnsl_cmd_display_window_spatial_3::init_data(nsl_base* win)
{
        num_type fval;
        nsl_layer* data = 0;
        nsl_base* bdat = 0;
        nsl_list* list = 0;
	on_off_enum on = NSL_OFF;
	nsl_cmd_type* cmd_obj = 0; 
  
        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("hidden")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("hidden")) != NULL)
			on = ((nsl_on_off_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'hidden' obj");
		((nsl_on_off_data*) data)->set_value(on);
          }
          else
                cmd_error("cmd_display_window: NULL 'hidden' obj");

          if ((data = (nsl_layer*) list->get_by_name("sx")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("sx")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'sx' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'sx' obj");

          if ((data = (nsl_layer*) list->get_by_name("sy")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("sy")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'sy' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'sy' obj");

          if ((data = (nsl_layer*) list->get_by_name("sz")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("sz")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'sz' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_window: NULL 'sz' obj");

          if ((data = (nsl_layer*) list->get_by_name("ax")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("ax")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'ax' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'ax' obj");

          if ((data = (nsl_layer*) list->get_by_name("by")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("by")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'by' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'by' obj");

          if ((data = (nsl_layer*) list->get_by_name("cz")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("cz")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'cz' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'cz' obj");
 	}

        return 1;
}
int xnsl_cmd_display_window_spatial_3::reset_data(nsl_base*)
{
        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
  
        if ((cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("window")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("hidden")) != NULL)
          {
 		((nsl_on_off_data*) data)->set_value(NSL_ON);
          }
          else
                cmd_error("cmd_display_window: NULL 'hidden' obj");

          if ((data = (nsl_layer*) list->get_by_name("sx")) != NULL)
          {
 		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'sx' obj");

          if ((data = (nsl_layer*) list->get_by_name("sy")) != NULL)
          {
   		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'sy' obj");

          if ((data = (nsl_layer*) list->get_by_name("sz")) != NULL)
          {
 		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'sz' obj");

          if ((data = (nsl_layer*) list->get_by_name("ax")) != NULL)
          {
  		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'ax' obj");

          if ((data = (nsl_layer*) list->get_by_name("by")) != NULL)
          {
 		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'by' obj");

          if ((data = (nsl_layer*) list->get_by_name("cz")) != NULL)
          {
 		((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'cz' obj");
 	}

        return 1;
}
int xnsl_cmd_display_window_spatial_3::update_data(nsl_base* win,
	int,int,int,int,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
        num_type fval;
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
          if ((data = (nsl_layer*) list->get_by_name("hidden")) != NULL &&
		data->get_flag() == 1)
          {
                on = ((nsl_on_off_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("hidden")) != NULL)
			((nsl_on_off_data*) bdat)->set_value(on);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'hidden' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'hidden' obj");

          if ((data = (nsl_layer*) list->get_by_name("sx")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("sx")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'sx' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'sx' obj");
        
         if ((data = (nsl_layer*) list->get_by_name("sy")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("sy")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'sy' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'sy' obj");
        
         if ((data = (nsl_layer*) list->get_by_name("sz")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("sz")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'sz' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'sz' obj");
        
         if ((data = (nsl_layer*) list->get_by_name("ax")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("ax")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'ax' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'ax' obj");
        
         if ((data = (nsl_layer*) list->get_by_name("by")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("by")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'by' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'by' obj");
        
         if ((data = (nsl_layer*) list->get_by_name("cz")) != NULL &&
		data->get_flag() == 1)
          {
                fval = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("cz")) != NULL)
			((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'cz' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'cz' obj");
        }

        return 1;
}


