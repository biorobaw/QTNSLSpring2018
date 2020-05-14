/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*              xnsl_cmd_display_window_4.C                   */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window_4::xnsl_cmd_display_window_4()
{
        set_type("display_window_4");
}

xnsl_cmd_display_window_4::~xnsl_cmd_display_window_4()
{
}
int xnsl_cmd_display_window_4::cmd_create(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_4::cmd_init(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_4::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_4::cmd_update(nsl_interpreter&)
{
	return 1;
}
int xnsl_cmd_display_window_4::set_win_sector(xnsl_window* win,
	int,int,int,int,int,int)
{
 	int i0,i1,imax;
	int j0,j1,jmax;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	nsl_layer* layer;
	nsl_model* model;
	const char *lname = "",*ltype = "";
	nsl_cmd_type* cmd_obj; 

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
		cmd_error("cmd_display_window_4: Bad layer name: ",lname);
	  }
          else
                cmd_error("cmd_display_window_4: NULL 'layer' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("imax")) != NULL)
          {
                imax = ((nsl_int_data*) data)->get_value();
		if (imax <= 0)
		{
		    imax = ((nsl_matrix_layer*) layer)->get_imax();
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
		    i0 = ((nsl_matrix_layer*) layer)->get_i0();
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
		    i1 = ((nsl_matrix_layer*) layer)->get_i1();
		    if ((bdat = ((xnsl_window*) win)->get_data("i1")) != NULL)
			((nsl_int_data*) bdat)->set_value(i1);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'i1' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'i1' obj");

          if ((data = (nsl_layer*) list->get_by_name("jmax")) != NULL)
          {
                jmax = ((nsl_int_data*) data)->get_value();
		if (jmax <= 0)
		{
		    jmax = ((nsl_matrix_layer*) layer)->get_jmax();
		    if ((bdat = ((xnsl_window*) win)->get_data("jmax")) != NULL)
			((nsl_int_data*) bdat)->set_value(imax);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'jmax' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'jmax' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("j0")) != NULL)
          {
		j0 = ((nsl_int_data*) data)->get_value();
		if (j0 >= jmax || j0 < 0)
		{
		    j0 = ((nsl_matrix_layer*) layer)->get_j0();
		    if ((bdat = ((xnsl_window*) win)->get_data("j0")) != NULL)
			((nsl_int_data*) bdat)->set_value(i0);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'j0' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'j0' obj");

          if ((data = (nsl_layer*) list->get_by_name("j1")) != NULL)
          {
		j1 = ((nsl_int_data*) data)->get_value();
		if (j1 >= jmax || j1 < j0 || j1 < 0)
		{
		    j1 = ((nsl_matrix_layer*) layer)->get_j1();
		    if ((bdat = ((xnsl_window*) win)->get_data("j1")) != NULL)
			((nsl_int_data*) bdat)->set_value(i1);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'j1' obj");
		}
          }
          else
                cmd_error("cmd_display_window: NULL 'j1' obj");

 	  if (strcmp(ltype,"4") == 0)
	  {
 		xnsl_cmd_display_window::set_win_sector(
			win,i0,j0,i1,j1,imax,jmax); 
 	  }
	}
	else
		cmd_error("cmd_display_window_matrix: NULL window");

 	return 1;
}
int xnsl_cmd_display_window_4::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        nsl_layer* data;
        nsl_layer* dset;
	nsl_list* list = 0;
	const char *lname = "";
	nsl_layer* layer;
	nsl_model* model;
	num_type /* int */i1 = 0,imax = 0;
	num_type /* int */j1 = 0,jmax = 0;
	num_type /* int */k1 = 0,kmax = 0;
	num_type /* int */l1 = 0,lmax = 0;
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
			imax = ((nsl_4_layer*) layer)->get_imax();
			i1 = ((nsl_4_layer*) layer)->get_i1();
			jmax = ((nsl_4_layer*) layer)->get_jmax();
			j1 = ((nsl_4_layer*) layer)->get_j1();
			kmax = ((nsl_4_layer*) layer)->get_kmax();
			k1 = ((nsl_4_layer*) layer)->get_k1();
			lmax = ((nsl_4_layer*) layer)->get_lmax();
			l1 = ((nsl_4_layer*) layer)->get_l1();
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

          	if ((data = (nsl_layer*) list->get_by_name("j1")) != NULL)
          	{
		    ((nsl_int_data*) data)->set_value(j1);
          	}
          	else
                    cmd_error("cmd_display_window: NULL 'j1' obj");

          	if ((data = (nsl_layer*) list->get_by_name("jmax")) != NULL)
          	{
		    ((nsl_int_data*) data)->set_value(jmax);
          	}
          	else
                    cmd_error("cmd_display_window: NULL 'jmax' obj");

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
        	    dset = new nsl_int_data("j0");
		    dset->set_flag(1);
        	    ((xnsl_window*) win)->add_data(dset);
        	    dset = new nsl_int_data("j1",j1);
		    dset->set_flag(1);
        	    ((xnsl_window*) win)->add_data(dset);
        	    dset = new nsl_int_data("jmax",jmax);
		    dset->set_flag(1);
        	    ((xnsl_window*) win)->add_data(dset);
        	    dset = new nsl_num_data("elem_i");
		    dset->set_flag(1);
        	    ((xnsl_window*) win)->add_data(dset);
        	    dset = new nsl_num_data("elem_j");
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
int xnsl_cmd_display_window_4::init_data(nsl_base* win)
{
        int ival;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
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

          if ((data = (nsl_layer*) list->get_by_name("j0")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("j0")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'j0' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'j0' obj");

          if ((data = (nsl_layer*) list->get_by_name("j1")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("j1")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'j1' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'j1' obj");

          if ((data = (nsl_layer*) list->get_by_name("jmax")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("jmax")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'jmax' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'jmax' obj");

          if ((data = (nsl_layer*) list->get_by_name("elem_i")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("elem_i")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'elem_i' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'elem_j' obj");

          if ((data = (nsl_layer*) list->get_by_name("elem_j")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("elem_j")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'elem_j' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'elem_j' obj");
 	}

        return 1;
}
int xnsl_cmd_display_window_4::reset_data(nsl_base*)
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

         if ((data = (nsl_layer*) list->get_by_name("j0")) != NULL)
          {
  		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'j0' obj");

          if ((data = (nsl_layer*) list->get_by_name("j1")) != NULL)
          {
  		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'j1' obj");

          if ((data = (nsl_layer*) list->get_by_name("jmax")) != NULL)
          {
  		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'jmax' obj");

          if ((data = (nsl_layer*) list->get_by_name("elem_i")) != NULL)
          {
   		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'elem_i' obj");

          if ((data = (nsl_layer*) list->get_by_name("elem_j")) != NULL)
          {
   		((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'elem_j' obj");
	}

        return 1;
}
int xnsl_cmd_display_window_4::update_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        int ival;
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
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
        
          if ((data = (nsl_layer*) list->get_by_name("j0")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("j0")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'j0' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'j0' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("j1")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("j1")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'j1' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'j1' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("jmax")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("jmax")) != NULL)
			((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'jmax' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'jmax' obj");

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

          if ((data = (nsl_layer*) list->get_by_name("elem_j")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("elem_j")) != NULL)
		     ((nsl_int_data*) bdat)->set_value(ival);
           	else
                     cmd_error("cmd_display_window: NULL bdat 'elem_j' obj");
          }
//          else
//                cmd_error("cmd_display_window: NULL 'elem_j' obj");
  	}

        return 1;
}
