/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_cmd_display_panel.C                 */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_panel::xnsl_cmd_display_panel() : xnsl_cmd_window()
{
        set_type("display_panel");
        set_abstract_type("display_panel");
}

xnsl_cmd_display_panel::~xnsl_cmd_display_panel()
{
}

int xnsl_cmd_display_panel::cmd_create(nsl_interpreter& nsl)
{
        xnsl_display_panel* win;
 	xnsl_display_window* pwin; 
	xnsl_display_frame *frwin;
	xnsl_cmd_window* pfr; // cmd_display_frame
 	nsl_string str;

	static int p_width = 240;
	static int p_height = 250; // 150
	static int p_X0 = 0;
	static int p_Y0 = 120;

	static int panel_X0 = 0;
	static int panel_Y0 = 120;

	if (panel_Y0 >= 700)
	{
		panel_Y0 = panel_Y0 + 20;
		panel_X0 = panel_X0 + 20;
	}
	if (panel_Y0 >= 700 && panel_X0 >= 800)
	{
		panel_Y0 = p_Y0;
		panel_X0 = p_X0;
	}

	strcpy(str,get_obj_name(nsl));

	if (m_parent != NULL &&  // first parent is cmd_display_window
	   (pfr = (xnsl_cmd_window*) m_parent->get_m_parent()) != NULL &&
	   (frwin = (xnsl_display_frame*) pfr->get_ptr()) != NULL &&
	   (pwin = frwin->get_display_window(str)) != NULL &&
	   (win = new xnsl_display_panel((xnsl_display_window*) pwin,str)) 
		!= NULL)
        {
		// copy all window data to cmd window
		m_parent->set_ptr(pwin); // update display window
		((xnsl_cmd_display_window*) m_parent)->init_data(pwin); 	
            	set_ptr(win); // update display_panel

	    	win->set_X0(panel_X0);
	   	win->set_Y0(panel_Y0);
	   	win->set_width(p_width-10);
	    	win->set_height(p_height);

	    	panel_Y0 = panel_Y0 + p_height;

	    	win->create();
	    	create_data(win);
//          	update_data(win);
 	    	win->display();
        }
        else
                cmd_error("cmd_display_panel: Unable to create new panel");

        return 1;
}
int xnsl_cmd_display_panel::cmd_init(nsl_interpreter&)
{
        return 1;
}
int xnsl_cmd_display_panel::cmd_reset(nsl_interpreter&)
{
        return 1;
}
int xnsl_cmd_display_panel::cmd_update(nsl_interpreter&)
{
  	const char *lname = "",*lname0 = "";
	const char *ltype = "";
	const char *gname = "",*gname0 = "";
	nsl_string gtype;
	int lfg = 0,gfg = 0;
	nsl_list* list = 0;
	nsl_layer* data;
        nsl_base* bdat;
	nsl_cmd_type* cmd_obj; 

        xnsl_display_panel* win;
	xnsl_display_window* pwin;
 	nsl_string str;

	if (m_parent != NULL && 
	     (pwin = (xnsl_display_window*) m_parent->get_ptr()) != NULL &&
	     (win = ((xnsl_display_window*) pwin)->get_control_panel()) != NULL)
        {
            set_ptr(win);

/*            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

*/
           if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   		SYSTEM->get_cmd_system()->get_m_children_list()
			->get_mi_by_type("window")) != NULL &&	
	   	(list = cmd_obj->get_data_list()) != NULL)

           {
            	if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	    	{
                   lname = ((nsl_str_data*) data)->get_value();
//		   lname0 = ((xnsl_window*) pwin)->get_str_data("layer");
		   if ((bdat = ((xnsl_window*) win)->get_data("layer")) != NULL)
			lname0 = ((nsl_str_data*) bdat)->get_value();
           	   else
                	cmd_error("cmd_display_window: NULL bdat 'layer' obj");
		   lfg = 1;
 	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'layer' obj");
        
           	if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
	    	{
		   gname = ((nsl_str_data*) data)->get_value();
//		   gname0 = ((xnsl_window*) pwin)->get_str_data("graph");
		   if ((bdat = ((xnsl_window*) win)->get_data("graph")) != NULL)
			gname0 = ((nsl_str_data*) bdat)->get_value();
           	   else
                	cmd_error("cmd_display_window: NULL bdat 'graph' obj");
		   gfg = 1;
 	        }
                else
                    cmd_error("cmd_display_canvas: NULL 'graph' obj");
 
	    	if (lfg == 0 || gfg == 0)
		{
		    cmd_error("cmd_display_canvas: CANNOT create canvas data");
		    return -1;
		}

		if (strcmp(lname,lname0) != 0 || strcmp(gname,gname0) != 0)
	    	{
 		    win->reset();
		    create_data(win);
	    	} 
//		win->update(); // needed ??
	    	update_data(win);
            }
            else
                cmd_error("cmd_display_panel: Unable to update panel");
        }
        else
                cmd_error("cmd_display_panel: Unable to update control panel");

        return 1;
}
int xnsl_cmd_display_panel::create_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
  	nsl_list* list = 0;
	const char *lname = "";
	const char *gname = "";
	nsl_string gtype;
	nsl_string ltype;
	nsl_string atype;
    nsl_layer* data = 0;
    nsl_base* pbase = 0;
	nsl_layer* layer = 0;
	nsl_model* model = 0;
	const char *str = "";
	num_type wymin,wymax,ts;
 	xnsl_display_window* pwin = 0;
  	xnsl_panel_item* pw = 0;
  
	strcpy(gtype,"");
	strcpy(ltype,"");
	strcpy(atype,"");
  
  	if ((pwin = (xnsl_display_window*) m_parent->get_ptr()) != NULL 
		&& win != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd_display_panel: NULL parent type");

       	    if (list != NULL)
            {
// create labels: graph, layer
          	if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
	  	{
                  gname = ((nsl_str_data*) data)->get_value();
		  pw = new xnsl_text_label_panel((xnsl_display_panel*)win);
		  create_panel_item(win,pw,"graph",gname,1);
		}
          	else
                	cmd_error("cmd_display_panel: NULL 'graph' obj");

          	if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	  	{
                  lname = ((nsl_str_data*) data)->get_value();
		  pw = new xnsl_text_label_panel((xnsl_display_panel*)win);
		  create_panel_item(win,pw,"layer",lname);

		  if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
		    {
			strcpy(atype,layer->get_abstract_type());
		      	sprintf(ltype,"display_panel_%s",atype);
                  	sprintf(gtype,"display_panel_%s_%s",gname,atype);
		    }
	  	}
          	else
                	cmd_error("cmd_display_panel: NULL 'layer' obj");
        
// create label: wymin, wymax, ts
             	if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL)
	    	{
	              wymin = ((nsl_num_data*) data)->get_value();
		      pw = new xnsl_text_label_input((xnsl_display_panel*)win);
		      create_panel_item(win,pw,"wymin",wymin);
		}
            	else
                	cmd_error("cmd_display_panel: NULL 'wymin' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL)
	    	{
	              wymax = ((nsl_num_data*) data)->get_value();
		      pw = new xnsl_text_label_input((xnsl_display_panel*)win);
		      create_panel_item(win,pw,"wymax",wymax);
  	    	}
            	else
                	cmd_error("cmd_display_panel: NULL 'wymax' obj");

          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(ltype)) != NULL)
			((xnsl_cmd_window*) pbase)->create_data(win);
	  	else
		 	cmd_error("cmd_display_panel: NULL type ",ltype);

          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(gtype)) != NULL)
			((xnsl_cmd_window*) pbase)->create_data(win);
	  	else
		 	cmd_error("cmd_display_panel: NULL type ",gtype);
	    }
	}
	else
		cmd_error("cmd_display_panel: CANNOT add data to window");
 
	return 1;
}
int xnsl_cmd_display_panel::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
} 
int xnsl_cmd_display_panel::create_panel_item(nsl_base* win,
	xnsl_panel_item* pw,const char* wname,float value,int fg)
{
	nsl_string str;

	sprintf(str,"%f",value);

	return create_panel_item(win,pw,wname,str,fg);
}
int xnsl_cmd_display_panel::create_panel_item(nsl_base* win,
	xnsl_panel_item* pw,const char* wname,int value,int fg)
{
	nsl_string str;

	sprintf(str,"%d",value);

	return create_panel_item(win,pw,wname,str,fg);
}
int xnsl_cmd_display_panel::create_panel_item(nsl_base* win,
	xnsl_panel_item* pw,const char* wname,const char* value,int fg)
{
	xnsl_widget* panel;
 	nsl_list* list = 0;
	nsl_string label;
	static int x_loc = 0;
	static int y_loc = 0;
   
  	if (win != NULL && 
 	    (list = ((xnsl_window*) win)->get_data_list()) != NULL &&
	    (panel = ((xnsl_window*) win)->get_widget()) != NULL)
	{
 	    if (pw != NULL)
	    {

		if (fg == 1) // reseet loc to beginning
			y_loc = 0;

                ((xnsl_window*) win)->add_data(pw);
		sprintf(label,"%s:",wname);
		pw->set_name(wname);
		pw->set_value(value);
		pw->set_wlabel(label);
		pw->set_wname(wname);
 		pw->create_widget(wname,panel,0,0,0,0,
			x_loc,y_loc,0,0,0,0,label,value);
	    }

 	    y_loc = y_loc + 40; // 5
	}
	else
		cmd_error("cmd_display_panel: Cannot create text");

	return 1;
}

