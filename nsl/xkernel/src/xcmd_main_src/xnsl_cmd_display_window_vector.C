/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*              xnsl_cmd_display_window_vector.C              */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_vector::xnsl_cmd_display_window_vector()
{
        set_type("display_window_vector");
}

xnsl_cmd_display_window_vector::~xnsl_cmd_display_window_vector()
{
}
int xnsl_cmd_display_window_vector::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_vector::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_vector::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_vector::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_vector::set_win_sector(xnsl_window* win,
	int,int,int,int,int,int)
{
 	int i0 = 0,i1 = 0,imax = 1;
 	row_col_enum vec_type = NSL_ROW;
    nsl_layer* data = 0;
    nsl_base* bdat = 0;
	nsl_layer* layer = 0;
    nsl_list* list = 0;
	nsl_model* model = 0;
	const char *lname = "",*ltype = "";
	nsl_cmd_type* cmd_obj = 0; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
	   ->get_mi_by_type(get_base_type())) != NULL &&
	   (list = cmd_obj->get_data_list()) != NULL)
	{
          if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	  {
             lname = ((nsl_str_data*) data)->get_value();
	     if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
			ltype = layer->get_abstract_type();
	     else
		cmd_error("cmd_display_window_vector: Bad layer name: ",lname);
	  }
          else
               cmd_error("cmd_display_window_vector: NULL 'layer' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("vec_type")) != NULL)
             	vec_type = ((nsl_row_col_data*) data)->get_value();
          else
                cmd_error("cmd_display_window: NULL 'vec_type' obj");

          if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL)
          {
                imax = ((nsl_int_data*) data)->get_value();
		if (imax <= 0)
		{
		    imax = ((nsl_vector_layer*) layer)->get_imax();
		    if ((bdat = ((xnsl_window*) win)->get_data("imax")) != NULL)
			((nsl_int_data*) bdat)->set_value(imax);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'imax' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'imax' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("i0")) != NULL)
          {
		i0 = ((nsl_int_data*) data)->get_value();
		if (i0 >= imax || i0 < 0)
		{
		    i0 = ((nsl_vector_layer*) layer)->get_i0();
		    if ((bdat = ((xnsl_window*) win)->get_data("i0")) != NULL)
			((nsl_int_data*) bdat)->set_value(i0);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'i0' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'i0' obj");

          if ((data = (nsl_layer*) list->get_by_name("i1")) != NULL)
          {
		i1 = ((nsl_int_data*) data)->get_value();
		if (i1 >= imax || i1 < i0 || i1 < 0)
		{
		    i1 = ((nsl_vector_layer*) layer)->get_i1();
		    if ((bdat = ((xnsl_window*) win)->get_data("i1")) != NULL)
			((nsl_int_data*) bdat)->set_value(i1);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'i1' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'i1' obj");

	  if (strcmp(ltype,"vector") == 0)
	  {
		if (vec_type == 0) // update window sector
			xnsl_cmd_display_window::set_win_sector(
				win,0,i0,0,i1,1,imax);
		else
			xnsl_cmd_display_window::set_win_sector(
				win,i0,0,i1,0,imax,1);
	  }
	}
	else
		cmd_error("cmd_display_window_vector::set_win_sector NULL obj");

 	return 1;
}
int xnsl_cmd_display_window_vector::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        nsl_layer* data;
        nsl_layer* dset;
	nsl_list* list = 0;
	const char *lname = "";
	nsl_layer* layer;
	nsl_model* model;
	num_type /* int */ i1 = 0,imax = 0;
	nsl_cmd_type* cmd_obj; 

	if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   	SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   	&& (list = cmd_obj->get_data_list()) != NULL)
        {

            if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	    {
                lname = ((nsl_str_data*) data)->get_value();
		if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
		{
			imax = ((nsl_num_1*) layer)->get_imax();
			i1 = ((nsl_num_1*) layer)->get_i1();
		}
	    }
            else
                cmd_error("cmd_display_window: NULL 'layer' obj");

            if ((data = (nsl_layer*) list->get_by_name("i1")) != NULL)
            {
		    ((nsl_int_data*) data)->set_value(i1);
            }
            else
                    cmd_error("cmd_display_window: NULL 'i1' obj");

            if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL)
            {
		    ((nsl_int_data*) data)->set_value(imax);
            }
            else
                    cmd_error("cmd_display_window: NULL 'imax' obj");

	    if ((list = ((xnsl_window*) win)->get_data_list()) != NULL)
 	    {
 	        dset = new nsl_int_data("i0");
		dset->set_flag(1);
	        ((xnsl_window*) win)->add_data(dset);
	        dset = new nsl_int_data("i1",i1);
		dset->set_flag(1);
	        ((xnsl_window*) win)->add_data(dset);
	        dset = new nsl_int_data("imax",imax);
		dset->set_flag(1);
	        ((xnsl_window*) win)->add_data(dset);
	        dset = new nsl_row_col_data("vec_type");
		dset->set_flag(1);
	        ((xnsl_window*) win)->add_data(dset);
        	dset = new nsl_num_data("elem_i");
		dset->set_flag(1);
        	((xnsl_window*) win)->add_data(dset);
	    }
            else
                cmd_error("cmd: NULL list");
	}
	else
		cmd_error("cmd_display_window: CANNOT add data to window");

	return 1;
}
int xnsl_cmd_display_window_vector::init_data(nsl_base* win)
{
        int ival;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	row_col_enum row = NSL_ROW;
	nsl_cmd_type* cmd_obj; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("i0")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("i0")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'i0' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'i0' obj");

          if ((data = (nsl_layer*) list->get_by_name("i1")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("i1")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'i1' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'i1' obj");

          if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("imax")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'imax' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'imax' obj");

          if ((data = (nsl_layer*) list->get_by_name("elem_i")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("elem_i")) != NULL)
		    ival = ((nsl_int_data*) bdat)->get_value();
           	else
                    cmd_error("cmd_display_window: NULL bdat 'elem_i' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'elem_i' obj");

          if ((data = (nsl_layer*) list->get_by_name("vec_type")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("vec_type")) != NULL)
		     ival = ((nsl_row_col_data*) bdat)->get_value();
           	else
                     cmd_error("cmd_display_window: NULL bdat 'vec_type' obj");
		((nsl_row_col_data*) data)->set_value(row);
          }
          else
                cmd_error("cmd_display_window: NULL 'vec_type' obj");
	}

        return 1;
}
int xnsl_cmd_display_window_vector::reset_data(nsl_base*)
{
        nsl_layer* data;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 

        if ((cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
	   ->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("i0")) != NULL)
          {
  		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'i0' obj");

          if ((data = (nsl_layer*) list->get_by_name("i1")) != NULL)
          {
  		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'i1' obj");

          if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL)
          {
  		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'imax' obj");

          if ((data = (nsl_layer*) list->get_by_name("elem_i")) != NULL)
          {
 		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'elem_i' obj");

          if ((data = (nsl_layer*) list->get_by_name("vec_type")) != NULL)
          {
  		((nsl_row_col_data*) data)->set_value(NSL_ROW);
          }
          else
                cmd_error("cmd_display_window: NULL 'vec_type' obj");
	}

        return 1;
}
int xnsl_cmd_display_window_vector::update_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        int ival;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	row_col_enum row = NSL_ROW;
	nsl_cmd_type* cmd_obj; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("i0")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("i0")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'i0' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'i0' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("i1")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("i1")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'i1' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'i1' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("imax")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'imax' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'imax' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("elem_i")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("elem_i")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'elem_i' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'elem_i' obj");

          if ((data = (nsl_layer*) list->get_by_name("vec_type")) != NULL &&
		data->get_flag() == 1)
          {
                row = ((nsl_row_col_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("vec_type")) != NULL)
		    ((nsl_int_data*) bdat)->set_value(row);
           	else
                    cmd_error("cmd_display_window: NULL bdat 'vec_type' obj");
          }
//          else
//               cmd_error("cmd_display_window: NULL 'vec_type' obj");
	}

        return 1;
}

