/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_cmd_display_window.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_window::xnsl_cmd_display_window() : xnsl_cmd_window()
{
        set_type("display_window");
        set_abstract_type("display_window");
}

xnsl_cmd_display_window::~xnsl_cmd_display_window()
{
}

int xnsl_cmd_display_window::cmd_clear(nsl_interpreter&)
{
        return 1;
}
int xnsl_cmd_display_window::cmd_create(nsl_interpreter& nsl)
{
        xnsl_display_window* win;
 	xnsl_window* pwin;
 	nsl_string str;
	nsl_string cstr;

	strcpy(str,get_obj_name(nsl));

	// change to "command_modifiers"
	cmd_init(nsl); // user assigned options on create command

	if (m_parent != NULL && 
	     (pwin = (xnsl_window*) m_parent->get_ptr()) != NULL &&
	     (win = new xnsl_display_window((xnsl_display_frame*) pwin,str))
		 != NULL)
        {
// AW98 get read of next line
	    nsl.add_object(win);
            set_ptr(win);
 	    create_data(win);
            update_data(win);
//	    win->create();
//	    win->init();

	    sprintf(cstr,"create display_canvas %s",str);
 	    NSL.exec(cstr);
        }
        else
                cmd_error("cmd_display_window: Unable to create new window");

        return 1;
}
int xnsl_cmd_display_window::cmd_init(nsl_interpreter& nsl)
{
/*	char* str;
	char* str0;
 	nsl_string tmp;
	nsl_list* list;
	nsl_layer* data;
	nsl_cmd_type* cmd_obj; 

        if ((cmd_obj = (nsl_cmd_type*) 
	   		SYSTEM->get_cmd_system()->get_m_children_list()
			->get_mi_by_type(get_base_type())) != NULL &&	
	   	(list = cmd_obj->get_data_list()) != NULL)
        {
	    while (nsl.get_str_cnt() > 0) {

		nsl >> tmp;
 
      		if ((str0 = (char *) strrchr(tmp,'-')) != NULL)
		{
		    str = str0 + 1; // pointer 1 after sname

        	    if ((data = (nsl_layer*) list->get_by_name(str)) != NULL)
	     		data->read(nsl.get_buffer());
          	    else
                	cmd_error("cmd_display_window: NULL 'layer' obj");
		}
	    }

	}
        else
                cmd_error("cmd_display_window: cmd_init: NULL object");

*/	nsl_cmd_type::cmd_type_init(nsl);

        return 1;
}
int xnsl_cmd_display_window::cmd_reset(nsl_interpreter&)
{
        return 1;
}
int xnsl_cmd_display_window::cmd_update(nsl_interpreter& nsl)
{
    xnsl_display_window* win = 0;
 	xnsl_window* pwin = 0;
 	nsl_string str;
	const char *lname = "",*lname0 = "";
	const char *ltype = "";
	const char *gname = "",*gname0 = "";
	nsl_string gtype;
	int lfg = 0,gfg = 0;
	nsl_list* list = 0;
	nsl_layer* data = 0;
    nsl_base* bdat = 0;
	nsl_cmd_type* cmd_obj = 0; 

	strcpy(str,get_obj_name(nsl));

        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   		SYSTEM->get_cmd_system()->get_m_children_list()
			->get_mi_by_type(get_base_type())) != NULL)	
	   	list = cmd_obj->get_data_list();
        else
                cmd_error("cmd_display_window: NULL object");

	if (m_parent != NULL && list != NULL && 
	     (pwin = (xnsl_window*) m_parent->get_ptr()) != NULL &&
	     (win = ((xnsl_display_frame*) pwin)->get_display_window(str)) 
	     != NULL)
        {
            set_ptr(win);

            if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL &&
		data->get_flag() == 1)
	    {
                lname = ((nsl_str_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("layer")) != NULL)
			lname0 = ((nsl_str_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'layer' obj");
		lfg = 1;
 	    }
        
            if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL &&
		data->get_flag() == 1)
	    {
		gname = ((nsl_str_data*) data)->get_value();
		if ((bdat = ((xnsl_window*) win)->get_data("graph")) != NULL)
			gname0 = ((nsl_str_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'graph' obj");
		gfg = 1;
 	    }
 
	    if (lfg == 0 || gfg == 0)
	    {
		cmd_error("cmd_display_window: CANNOT update window");
		return -1;
	    }

	    if (strcmp(lname,lname0) != 0 || strcmp(gname,gname0) != 0)
	    {
		win->reset();		// data clear
		create_data(win);
	    } 
	    update_data(win);
        }
        else
                cmd_error("cmd_display_window: Unable to update window");

        return 1;
}
int xnsl_cmd_display_window::set_win_sector(xnsl_window* win,
	int i0,int j0,int i1,int j1,int imax,int jmax)
{
        nsl_layer* data;
        nsl_base* bdat;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()->
	   get_mi_by_type(get_base_type())) != NULL &&	
	   (list = cmd_obj->get_data_list()) != NULL)
	{
 		int xoff, yoff;
		int width = 100,height = 100;

// imax, jmax are crossed
//		int tx0 = (i0 >= 0 && i0 < imax) ? i0 : 0;
//		int ty0 = (j0 >= 0 && j0 < jmax) ? j0 : 0;
//		int ti1 = (i1 >= 0 && i1 >= i0 && i1 < imax) ? i1 : imax - 1;
//		int ty1 = (j1 >= 0 && j1 >= j0 && j1 < jmax) ? j1 : jmax - 1;

		int tj0 = (i0 >= 0 && i0 < imax) ? i0 : 0;
		int ti0 = (j0 >= 0 && j0 < jmax) ? j0 : 0;
		int tj1 = (i1 >= 0 && i1 >= i0 && i1 < imax) ? i1 : imax - 1;
		int ti1 = (j1 >= 0 && j1 >= j0 && j1 < jmax) ? j1 : jmax - 1;

		int dimax = ti1 - ti0 + 1;
		int djmax = tj1 - tj0 + 1;
	
          	if ((data = (nsl_layer*) list->get_by_name("width")) != NULL)
          	{
                	width = ((xnsl_window*) win)->get_width();
           	}
          	else
                	cmd_error("cmd_window: NULL 'width' obj");

          	if ((data = (nsl_layer*) list->get_by_name("height")) != NULL)
          	{
               		height = ((xnsl_window*) win)->get_height();
 	        }
          	else
                	cmd_error("cmd_window: NULL 'height' obj");

		int ux0 = 40;		
		int ux1 = width - 40;

		int vy0 = 20; 			
		int vy1 = height  - 20;

		int width_sector = ux1 - ux0;
		int height_sector = vy1 - vy0;

		int xoff0 = width_sector%dimax;
		int yoff0 = height_sector%djmax;

		if (xoff0%2 == 0)
			xoff = xoff0/2;
		else
			xoff = (xoff0-1)/2;
		if (yoff0%2 == 0)
			yoff = yoff0/2;
		else
			yoff = (yoff0-1)/2;

		int wx0 = ux0 + xoff;
		int wy0 = vy0 + yoff0 - yoff;
		int wx1 = ux1 - (xoff0 - xoff);
		int wy1 = vy1 - yoff;
		int wxs = (width_sector-xoff0)/dimax;
		int wys = (height_sector-yoff0)/djmax;

           	if ((data = (nsl_layer*) list->get_by_name("wx0")) != NULL)
	  	{
 		    ((nsl_int_data*) data)->set_value(wx0);
		    if ((bdat = ((xnsl_window*) win)->get_data("wx0")) != NULL)
			((nsl_int_data*) bdat)->set_value(wx0);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'wx0' obj");
         	}
          	else
                	cmd_error("cmd_display_window: NULL 'wx0' obj");

          	if ((data = (nsl_layer*) list->get_by_name("wx1")) != NULL)
	  	{
 		    ((nsl_int_data*) data)->set_value(wx1);
		    if ((bdat = ((xnsl_window*) win)->get_data("wx1")) != NULL)
			((nsl_int_data*) bdat)->set_value(wx1);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'wx1' obj");
          	}
          	else
                	cmd_error("cmd_display_window: NULL 'wx1' obj");

          	if ((data = (nsl_layer*) list->get_by_name("wy0")) != NULL)
	  	{
 		    ((nsl_int_data*) data)->set_value(wy0);
		    if ((bdat = ((xnsl_window*) win)->get_data("wy0")) != NULL)
			((nsl_int_data*) bdat)->set_value(wy0);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'wy0' obj");
          	}
          	else
                	cmd_error("cmd_display_window: NULL 'wy0' obj");

          	if ((data = (nsl_layer*) list->get_by_name("wy1")) != NULL)
	  	{
 		    ((nsl_int_data*) data)->set_value(wy1);
		    if ((bdat = ((xnsl_window*) win)->get_data("wy1")) != NULL)
			((nsl_int_data*) bdat)->set_value(wy1);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'wy1' obj");
         	}
          	else
                	cmd_error("cmd_display_window: NULL 'wy1' obj");

          	if ((data = (nsl_layer*) list->get_by_name("wxs")) != NULL)
	  	{
 		    ((nsl_int_data*) data)->set_value(wxs);
		    if ((bdat = ((xnsl_window*) win)->get_data("wxs")) != NULL)
			((nsl_int_data*) bdat)->set_value(wxs);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'wxs' obj");
          	}
          	else
                	cmd_error("cmd_display_window: NULL 'wxs' obj");

          	if ((data = (nsl_layer*) list->get_by_name("wys")) != NULL)
	  	{
 		    ((nsl_int_data*) data)->set_value(wys);
		    if ((bdat = ((xnsl_window*) win)->get_data("wys")) != NULL)
			((nsl_int_data*) bdat)->set_value(wxs);
           	    else
                	cmd_error("cmd_display_window: NULL bdat 'wys' obj");
          	}
          	else
                	cmd_error("cmd_display_window: NULL 'wys' obj");
	}
	else
		cmd_error("cmd_display_window::set_win_sector: NULL object");

	return 1;
}
int xnsl_cmd_display_window::create_data(nsl_base* win,
	int,int,int,int,int,int,int,int,int,int)
{
        nsl_layer* dset;
	nsl_list* list = 0;
	const char *lname = "";
	const char *latype = "";
	nsl_string gtype;
	nsl_string ltype;
        nsl_layer* data;
        nsl_base* pbase;
	nsl_layer* layer;
	nsl_model* model;
	nsl_cmd_type* cmd_obj; 

	strcpy(gtype,"");
	strcpy(ltype,"");

	if (win != NULL)
	{
//	    if ((list = ((xnsl_window*) win)->get_data_list()) != NULL)
//	    {

// create data list for new window
        dset = new nsl_str_data("model","");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_str_data("layer","");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_str_data("graph","");
 		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_str_data("name","");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_str_data("side","");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
       	dset = new nsl_int_data("step",1.0);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_on_off_data("overlay",NSL_OFF);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_on_off_data("grid",NSL_OFF);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_on_off_data("x_axis",NSL_OFF);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_on_off_data("y_axis",NSL_OFF);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("wxmin");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("wxmax");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("wxstep",1.0);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("wymin");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("wymax");
		dset->set_flag(1);
		((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("wystep",1.0);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_int_data("wx0");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_int_data("wy0");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_int_data("wx1");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_int_data("wy1");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_int_data("wxs");
 		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_int_data("wys");
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("val_in",1.0);
		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("val_out",1.0);
 		dset->set_flag(1);
      	((xnsl_window*) win)->add_data(dset);
        dset = new nsl_num_data("ts");
 		dset->set_flag(1);
        ((xnsl_window*) win)->add_data(dset);
//	    }
//            else
//                cmd_error("cmd: NULL list");

// get data from default cmd_window list
            if ((cmd_obj = (nsl_cmd_type*) 
	    SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	    && (list = cmd_obj->get_data_list()) != NULL)
            {
          	if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	  	{
			lname = ((nsl_str_data*) data)->get_value();
			if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
			{
				latype = layer->get_abstract_type();
		      	sprintf(ltype,"display_window_%s", latype);
			}
	  	}
          	else
                	cmd_error("cmd_display_window: NULL 'layer' obj");
        
         	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
			get_mi_by_type(ltype)) != NULL)
	  	{
			((xnsl_cmd_window*) pbase)->create_data(win); // layer
 	  	}
	  	else
		 	cmd_error("cmd_display_window: NULL type ",ltype);
 
          	if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
             	    sprintf(gtype,"display_window_%s",
			((nsl_str_data*) data)->get_value());
          	else
                	cmd_error("cmd_display_window: NULL 'graph' obj");

//AW98 display_window_*graph* not doing anything
 
          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(gtype)) != NULL)
			((xnsl_cmd_window*) pbase)->create_data(win); // graph
	  	else
		 	cmd_error("cmd_display_window: NULL type ",gtype);
	    }
	}
	else
		cmd_error("cmd_display_window: CANNOT add data to window");
 
        return 1;
}
int xnsl_cmd_display_window::init_data(nsl_base* win)
{
        int ival;
	num_type fval;
        nsl_layer* data;
	nsl_base* bdat;
        nsl_list* list = 0;
	on_off_enum on = NSL_OFF;
	const char *side = "";
	const char *lname = "";
	const char *gname = "";
	nsl_cmd_type* cmd_obj; 

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("layer")) != NULL)
			lname = ((nsl_str_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'layer' obj");
		((nsl_str_data*) data)->set_value(lname);
          }
          else
                cmd_error("cmd_display_window: NULL 'layer' obj");

          if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("graph")) != NULL)
			gname = ((nsl_str_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'graph' obj");
		((nsl_str_data*) data)->set_value(gname);
          }
          else
                cmd_error("cmd_display_window: NULL 'graph' obj");

          if ((data = (nsl_layer*) list->get_by_name("side")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("side")) != NULL)
			side = ((nsl_str_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'side' obj");
		((nsl_str_data*) data)->set_value(side);
          }
          else
                cmd_error("cmd_display_window: NULL 'graph' obj");

          if ((data = (nsl_layer*) list->get_by_name("step")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("step")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'step' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'step' obj");

          if ((data = (nsl_layer*) list->get_by_name("overlay")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("overlay")) != NULL)
		     on = ((nsl_on_off_data*) bdat)->get_value();
           	else
                     cmd_error("cmd_display_window: NULL bdat 'overlay' obj");
		((nsl_on_off_data*) data)->set_value(on);
          }
          else
               cmd_error("cmd_display_window: NULL 'overlay' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxmin")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wxmin")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxmin' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxmin' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxmax")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wxmax")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxmax' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxmax' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxstep")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wxstep")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxstep' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxstep' obj");

          if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wymin")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wymin' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'wymin' obj");

          if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wymax")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wymax' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'wymax' obj");

          if ((data = (nsl_layer*) list->get_by_name("wystep")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wystep")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wystep' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'wystep' obj");

          if ((data = (nsl_layer*) list->get_by_name("ts")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("ts")) != NULL)
			fval = ((nsl_num_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'ts' obj");
		((nsl_num_data*) data)->set_value(fval);
          }
          else
                cmd_error("cmd_display_window: NULL 'ts' obj");

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

          if ((data = (nsl_layer*) list->get_by_name("wx0")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wx0")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wx0' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'wx0' obj");

          if ((data = (nsl_layer*) list->get_by_name("wy0")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wy0")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wy0' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'wy0' obj");

          if ((data = (nsl_layer*) list->get_by_name("wx1")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wx1")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wx1' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
               cmd_error("cmd_display_window: NULL 'wx1' obj");

          if ((data = (nsl_layer*) list->get_by_name("wy1")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wy1")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wy1' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'wy1' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxs")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wxs")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxs' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxs' obj");

          if ((data = (nsl_layer*) list->get_by_name("wys")) != NULL)
          {
		if ((bdat = ((xnsl_window*) win)->get_data("wys")) != NULL)
			ival = ((nsl_int_data*) bdat)->get_value();
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wys' obj");
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_display_window: NULL 'wys' obj");
        }

        return 1;
}
int xnsl_cmd_display_window::reset_data(nsl_base*)
{
        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
		nsl_cmd_type* cmd_obj; 

        if ((cmd_obj = (nsl_cmd_type*) SYSTEM->get_cmd_system()->get_m_children_list()
			->get_mi_by_type(get_base_type())) != NULL && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("step")) != NULL)
          {
  			((nsl_int_data*) data)->set_value(1);
          }
          else
             cmd_error("cmd_display_window: NULL 'step' obj");

          if ((data = (nsl_layer*) list->get_by_name("overlay")) != NULL)
          {
 			((nsl_on_off_data*) data)->set_value(NSL_OFF);
          }
          else
                cmd_error("cmd_display_window: NULL 'overlay' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxmin")) != NULL)
          {
 			((nsl_num_data*) data)->set_value(0.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxmin' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxmax")) != NULL)
          {
 			((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxmax' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxstep")) != NULL)
          {
 			((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxstep' obj");

          if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL)
          {
 			((nsl_num_data*) data)->set_value(0.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wymin' obj");

          if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL)
          {
 			((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wymax' obj");

          if ((data = (nsl_layer*) list->get_by_name("wystep")) != NULL)
          {
 			((nsl_num_data*) data)->set_value(1.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wystep' obj");

          if ((data = (nsl_layer*) list->get_by_name("ts")) != NULL)
          {
  			((nsl_num_data*) data)->set_value(0.0);
          }
          else
                cmd_error("cmd_display_window: NULL 'ts' obj");

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
 
          if ((data = (nsl_layer*) list->get_by_name("wx0")) != NULL)
          {
   			((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wx0' obj");

          if ((data = (nsl_layer*) list->get_by_name("wy0")) != NULL)
          {
 			((nsl_int_data*) data)->set_value(0);
          }
          else
                cmd_error("cmd_display_window: NULL 'wy0' obj");

          if ((data = (nsl_layer*) list->get_by_name("wx1")) != NULL)
          {
 			((nsl_int_data*) data)->set_value(100);
          }
          else
                cmd_error("cmd_display_window: NULL 'wx1' obj");

          if ((data = (nsl_layer*) list->get_by_name("wy1")) != NULL)
          {
  			((nsl_int_data*) data)->set_value(100);
          }
          else
                cmd_error("cmd_display_window: NULL 'wy1' obj");

          if ((data = (nsl_layer*) list->get_by_name("wxs")) != NULL)
          {
   			((nsl_int_data*) data)->set_value(10);
          }
          else
                cmd_error("cmd_display_window: NULL 'wxs' obj");

          if ((data = (nsl_layer*) list->get_by_name("wys")) != NULL)
          {
 			((nsl_int_data*) data)->set_value(10);
          }
          else
                cmd_error("cmd_display_window: NULL 'wys' obj");
        }

        return 1;
}
int xnsl_cmd_display_window::update_data(nsl_base* win,
	int,int,int,int,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
    int ival;
	int rows,cols,width,height;
	num_type fval,fval0,fval1;
	nsl_layer* layer = 0;
	nsl_model* model = 0;
	const char *side = "";
	const char *lname = "";
	const char *latype = "";
	const char *gname = "";
	nsl_string gtype;
	nsl_string ltype;
    nsl_layer* data = 0;
    nsl_base* bdat = 0;
    nsl_base* pbase = 0;
    nsl_list* list = 0;
	on_off_enum on = NSL_OFF;
	nsl_cmd_type* cmd_obj = 0; 

	strcpy(gtype,"");
	strcpy(ltype,"");

        if (win != NULL && (cmd_obj = (nsl_cmd_type*) SYSTEM->get_cmd_system()->get_m_children_list()
			->get_mi_by_type(get_base_type())) != NULL && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("rows")) != NULL)
                rows = ((nsl_int_data*) data)->get_value();
          else
                cmd_error("cmd_display_window: NULL 'rows' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("cols")) != NULL)
                cols = ((nsl_int_data*) data)->get_value();
          else
                cmd_error("cmd_display_window: NULL 'cols' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("width")) != NULL)
                width = ((nsl_int_data*) data)->get_value();
          else
                cmd_error("cmd_display_window: NULL 'width' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("height")) != NULL)
                height = ((nsl_int_data*) data)->get_value();
          else
                cmd_error("cmd_display_window: NULL 'height' obj");
        
	  if (rows <= 0)
		rows = 1;
	  if (cols <= 0)
		cols = 1;

// AW98: do not recalculate according to rows and cols, both set to 1
	  rows = 1;
	  cols = 1;

	  int windex = win->get_index();
	  int hoff = height%rows;
	  int new_height = (height - hoff)/rows;

	  int woff = width%cols;
	  int new_width = (width - woff)/cols;
 
    	  int new_X0 = (new_width)*((windex-1)%cols);
    	  int new_Y0 = (new_height)*((windex-1)/cols);


	  ((xnsl_window*) win)->set_X0(new_X0);
	  ((xnsl_window*) win)->set_Y0(new_Y0);
	  ((xnsl_window*) win)->set_width(new_width);
	  ((xnsl_window*) win)->set_height(new_height);

       if ((data = (nsl_layer*) list->get_by_name("side")) != NULL &&
		data->get_flag() == 1)
		{
	     side = ((nsl_str_data*) data)->get_value();
	     if ((bdat = ((xnsl_window*) win)->get_data("side")) != NULL)
			((nsl_str_data*) bdat)->set_value(side);
         else
             cmd_error("cmd_display_window: NULL bdat 'side' obj");
		}
//          else
//                cmd_error("cmd_display_window: NULL 'side' obj");
 
        if ((data = (nsl_layer*) list->get_by_name("step")) != NULL && data->get_flag() == 1)
        {
            ival = ((nsl_int_data*) data)->get_value();
			if (ival == 0)
				ival = 1;
			if ((bdat = ((xnsl_window*) win)->get_data("step")) != NULL)
				((nsl_int_data*) bdat)->set_value(ival);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'step' obj");
        }
//          else
//               cmd_error("cmd_display_window: NULL 'step' obj");
        
        if ((data = (nsl_layer*) list->get_by_name("overlay")) != NULL && data->get_flag() == 1)
        {
            on = ((nsl_on_off_data*) data)->get_value();
			if ((bdat = ((xnsl_window*) win)->get_data("overlay")) != NULL)
				((nsl_on_off_data*) bdat)->set_value(on);
           	else
                   cmd_error("cmd_display_window: NULL bdat 'overlay' obj");
        }
//          else
//                cmd_error("cmd_display_window: NULL 'overlay' obj");

        if ((data = (nsl_layer*) list->get_by_name("wxmin")) != NULL && data->get_flag() == 1)
        {
            fval0 = ((nsl_num_data*) data)->get_value();
			if ((bdat = ((xnsl_window*) win)->get_data("wxmin")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval0);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxmin' obj");
        }

        if ((data = (nsl_layer*) list->get_by_name("wxmax")) != NULL && data->get_flag() == 1)
        {
            fval1 = ((nsl_num_data*) data)->get_value();
			if (fval0 == fval1)
				fval1 = fval0 + 1.0;
			if ((bdat = ((xnsl_window*) win)->get_data("wxmax")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval1);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxmax' obj");
        }

        if ((data = (nsl_layer*) list->get_by_name("wxstep")) != NULL && data->get_flag() == 1)
        {
            fval = ((nsl_num_data*) data)->get_value();
			if (fval < fval0 || fval > fval1)
				fval = fval1;
			if ((bdat = ((xnsl_window*) win)->get_data("wxstep")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wxstep' obj");
        }

        if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL && data->get_flag() == 1)
        {
            fval0 = ((nsl_num_data*) data)->get_value();
			if ((bdat = ((xnsl_window*) win)->get_data("wymin")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval0);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wymin' obj");
        }

        if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL && data->get_flag() == 1)
        {
            fval1 = ((nsl_num_data*) data)->get_value();
			if (fval0 == fval1)
				fval1 = fval0 + 1.0;
			if ((bdat = ((xnsl_window*) win)->get_data("wymax")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval1);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wymax' obj");
        }

        if ((data = (nsl_layer*) list->get_by_name("wystep")) != NULL && data->get_flag() == 1)
        {
            fval = ((nsl_num_data*) data)->get_value();
			if (fval < fval0 || fval > fval1)
				fval = fval1;
			if ((bdat = ((xnsl_window*) win)->get_data("wystep")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'wystep' obj");
        }

        if ((data = (nsl_layer*) list->get_by_name("ts")) != NULL && data->get_flag() == 1)
        {
            fval = ((nsl_num_data*) data)->get_value();
	 		if (fval <= 0.0)
				fval = 0.0;
			if ((bdat = ((xnsl_window*) win)->get_data("ts")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'ts' obj");
        }
//          else
//                cmd_error("cmd_display_window: NULL 'ts' obj");

        if ((data = (nsl_layer*) list->get_by_name("val_in")) != NULL && data->get_flag() == 1)
        {
            fval = ((nsl_num_data*) data)->get_value();
			if ((bdat = ((xnsl_window*) win)->get_data("val_in")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval);
           	else
                	cmd_error("cmd_display_window: NULL bdat 'val_in' obj");
        }
//          else
//                cmd_error("cmd_display_window: NULL 'val_in' obj");
        
        if ((data = (nsl_layer*) list->get_by_name("val_out")) != NULL && data->get_flag() == 1)
        {
            fval = ((nsl_num_data*) data)->get_value();
			if ((bdat = ((xnsl_window*) win)->get_data("val_out")) != NULL)
				((nsl_num_data*) bdat)->set_value(fval);
           	else
                     cmd_error("cmd_display_window: NULL bdat 'val_out' obj");
        }
//          else
//                cmd_error("cmd_display_window: NULL 'val_out' obj");
 
        if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL && data->get_flag() == 1)
		{
            lname = ((nsl_str_data*) data)->get_value();
			if ((bdat = ((xnsl_window*) win)->get_data("layer")) != NULL)
				((nsl_str_data*) bdat)->set_value(lname);
            else
                cmd_error("cmd_display_window: NULL bdat 'layer' obj");

			if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
			{
				latype = layer->get_abstract_type();
				sprintf(ltype,"display_window_%s", latype);
			}
        
			if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
				get_mi_by_type(ltype)) != NULL)
			{
				((xnsl_cmd_window*) pbase)->update_data(win); // layer
				((xnsl_cmd_display_window*) pbase)->set_win_sector((xnsl_window*) win);
			}
			else
				cmd_error("cmd_display_window: NULL type ",ltype);
 
			if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL && data->get_flag() == 1)
			{
				gname = ((nsl_str_data*) data)->get_value();
				sprintf(gtype,"display_window_%s",gname);
				if ((bdat = ((xnsl_window*) win)->get_data("graph")) != NULL)
					((nsl_str_data*) bdat)->set_value(gname);
				else
					cmd_error("cmd_display_window: NULL bdat 'graph' obj");
			}
//          else
//                cmd_error("cmd_display_window: NULL 'graph' obj");
 
			if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
				get_mi_by_type(gtype)) != NULL)
				((xnsl_cmd_window*) pbase)->update_data(win); // graph
			else
				cmd_error("cmd_display_window: NULL type ",gtype);
		}
	}

       return 1;
}