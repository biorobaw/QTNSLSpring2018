/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_cmd_display_canvas.C                */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 
#include "nsl_cmd_system.h"
#include "nsl_on_off_data.h"

int FONT_WIDTH = 8;
//extern TK_DRAW;

xnsl_cmd_display_canvas::xnsl_cmd_display_canvas() : xnsl_cmd_window()
{
        set_type("display_canvas");
        set_abstract_type("display_canvas");
}

xnsl_cmd_display_canvas::~xnsl_cmd_display_canvas()
{
}

int xnsl_cmd_display_canvas::cmd_create(nsl_interpreter& nsl)
{
        xnsl_display_canvas* win;
 	xnsl_window* pwin;
 	nsl_string str;

	strcpy(str,get_obj_name(nsl));

	if (m_parent != NULL && 
	     (pwin = (xnsl_window*) m_parent->get_ptr()) != NULL &&
	     (win = new xnsl_display_canvas((xnsl_display_window*) pwin,str))
		 != NULL)
        {
            set_ptr(win);
//	    win->create(pwin->get_X0(),pwin->get_Y0(),
//			pwin->get_width(),pwin->get_height());
	    create_data(win);
	    update_data(win);
 	    win->display();
        }
        else
                cmd_error("cmd_display_canvas: Unable to create new window");

        return 1;
}
// AW98 temporary change
int xnsl_cmd_display_canvas::cmd_init(nsl_interpreter&)
{
        return 1;
}
int xnsl_cmd_display_canvas::cmd_reset(nsl_interpreter&)
{
        return 1;
}
int xnsl_cmd_display_canvas::cmd_update(nsl_interpreter& nsl)
{
  	const char *lname = "",*lname0 = "";
	const char *ltype = "";
	const char *gname = "",*gname0 = "";
	nsl_string gtype;
	int lfg = 0,gfg = 0,lfg0 = 0,gfg0 = 0;
	nsl_list* list = 0;	// interpreter data
	nsl_list* dlist = 0;	// canvas data
	xnsl_text_label_canvas* cw;
	xnsl_widget_graph* cwg; 
	nsl_layer* data;
        nsl_base* pbase;
        xnsl_display_canvas* win;
 	xnsl_display_window* pwin;
 	nsl_string str;

	strcpy(str,get_obj_name(nsl));

	if (m_parent != NULL && 
	     (pwin = (xnsl_display_window*) m_parent->get_ptr()) != NULL &&
	     (win = ((xnsl_display_window*) pwin)->get_window_canvas()) != NULL)
        {
	    win->set_X0(pwin->get_X0());
	    win->set_Y0(pwin->get_Y0());
	    win->set_width(pwin->get_width());
	    win->set_height(pwin->get_height());

            set_ptr(win);

            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (list != NULL &&
 	    	(dlist = ((xnsl_window*) win)->get_data_list()) != NULL) 
            {

            	if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	    	{
                    lname = ((nsl_str_data*) data)->get_value();
		    lfg = 1;
 	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'layer' obj");
        
            	if ((cw = (xnsl_text_label_canvas*) dlist->
				get_by_name("layer")) != NULL)
	    	{
		    lname0 = cw->get_widget_value();
		    lfg0 = 1;
 	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'layer' obj");
        
           	if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
	    	{
		    gname = ((nsl_str_data*) data)->get_value();
		    gfg = 1;
 	        }
                else
                    cmd_error("cmd_display_canvas: NULL 'graph' obj");
 
           	if ((cwg = (xnsl_graph*) dlist->
				get_by_name("graph")) != NULL)
	    	{
		    lname0 = cwg->get_type();
		    gfg0 = 1;
 	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'layer' obj");
        
	    	if (lfg == 0 || gfg == 0 || lfg0 == 0 || gfg0 == 0)
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
                cmd_error("cmd_display_canvas: Unable to update canvas");

 	    win->clear();
 	    win->display();
        }
        else
                cmd_error("cmd_display_canvas: Unable to update canvas");

        return 1;
}

int xnsl_cmd_display_canvas::create_data(nsl_base* win,int x,int y,int w,int h,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
  	nsl_list* list = 0;
	const char *lname = "";
	nsl_string gtype;
	nsl_string ltype;
	nsl_string atype;
	const char *side = "";
    nsl_layer* data = 0;
    nsl_base* pbase = 0;
	nsl_base* base = 0;
	nsl_layer* layer = 0;
	nsl_model* model = 0;
	const char *str = "";
	num_type wymin,wymax,ts;
 	xnsl_window* pwin = 0;
	on_off_enum on_off;

	strcpy(gtype,"");
	strcpy(ltype,"");
	strcpy(atype,"");
  
  	if ((pwin = (xnsl_window*) m_parent->get_ptr()) != NULL && win != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (list != NULL)
            {
// create window
           	if ((data = (nsl_layer*) list->get_by_name("side")) != NULL)
	    	{
                	side = ((nsl_str_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'height' obj");

	    	((xnsl_display_canvas*) win)
			->create(pwin->get_X0(),pwin->get_Y0(),
			pwin->get_width(),pwin->get_height(),side);

// create labels: (window) name, layer
        if ((data = (nsl_layer*) list->get_by_name("name")) != NULL)
	  	{
//          name = ((nsl_str_data*) data)->get_value();
            create_top_text((xnsl_window*)win,"name",win->get_name(),1);
  	    }
            else
                cmd_error("cmd_display_canvas: NULL 'name' obj");

        if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	  	{
            lname = ((nsl_str_data*) data)->get_value();
//AW98      create_top_text((xnsl_window*)win,"layer",lname);
// should be same as window
		    if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
			{
				strcpy(atype,layer->get_abstract_type());
		      	sprintf(ltype,"display_canvas_%s",atype);
			}
	  	}
        else
			cmd_error("cmd_display_window: NULL 'layer' obj");
        
// create label: wymin, wymax, ts

             	if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL)
	    	{
	                wymin = ((nsl_num_data*) data)->get_value();
// AW98           	create_top_text((xnsl_window*)win,"wymin",wymin);
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wymin' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL)
	    	{
	                wymax = ((nsl_num_data*) data)->get_value();
// AW98              	create_top_text((xnsl_window*)win,"wymax",wymax);
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wymax' obj");

            	if ((data = (nsl_layer*) list->get_by_name("ts")) != NULL)
	    	{
	                ts = ((nsl_num_data*) data)->get_value();
// AW98              	create_top_text((xnsl_window*)win,"ts",ts);
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'ts' obj");

/*          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(ltype)) != NULL)
			((xnsl_cmd_window*) pbase)->create_data(win);
	  	else
		 	cmd_error("cmd_display_canvas: NULL type ",ltype);
*/
          	if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
                    sprintf(gtype,"display_canvas_%s_%s",
			((nsl_str_data*) data)->get_value(),atype);
          	else
                	cmd_error("cmd_display_canvas: NULL type ",gtype);

// create values: wx0,wy0, wx1, wy1, wxs, wys
             	if ((data = (nsl_layer*) list->get_by_name("wx0")) != NULL)
	    	{
	                wx0 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wx0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wx1")) != NULL)
	    	{
                	wx1 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wx1' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wy0")) != NULL)
	    	{
                	wy0 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wy0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wy1")) != NULL)
	    	{
                	wy1 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wy1' obj");
        
            	if ((data = (nsl_layer*) list->get_by_name("wxs")) != NULL)
	    	{
                	wxs = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wxs' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wys")) != NULL)
	    	{
                	wys = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wys' obj");

            	if ((data = (nsl_layer*) list->get_by_name("X0")) != NULL)
	    	{
                	x = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'X0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("Y0")) != NULL)
	    	{
                	y = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'Y0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("width")) != NULL)
	    	{
                	w = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'width' obj");

            	if ((data = (nsl_layer*) list->get_by_name("height")) != NULL)
	    	{
                	h = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'height' obj");

            	if ((data = (nsl_layer*) list->get_by_name("grid")) != NULL)
	    	{
                	on_off = ((nsl_on_off_data*) data)->get_value();
			if (on_off == NSL_ON)
			    create_grid(win,x,y,w,h,
				wx0,wy0,wx1,wy1,wxs,wys);
		}
            	else
                	cmd_error("cmd_display_canvas: NULL 'grid' obj");

            	if ((data = (nsl_layer*) list->get_by_name("x_axis")) != NULL)
	    	{
                	on_off = ((nsl_on_off_data*) data)->get_value();
			if (on_off == NSL_ON)
			    create_line(win,x,y,w,h,
				wx0,wy0,wx1,wy1,wxs,wys,wymin,wymax);
		}
            	else
                	cmd_error("cmd_display_canvas: NULL 'x_axis' obj");

          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(gtype)) != NULL)
		{
			((xnsl_cmd_window*) pbase)->create_data(win,
				x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);
			((xnsl_cmd_window*) pbase)->create_graph(win,
				x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys,layer,side);
		}
	  	else
		 	cmd_error("cmd_display_window: NULL type ",gtype);
	    }
	}
	else
		cmd_error("cmd_display_canvas: CANNOT add data to window");
 
	return 1;
}
int xnsl_cmd_display_canvas::update_data(nsl_base* win,
	int x,int y,int w,int h,int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
  	nsl_list* list = 0;
	const char *side = "";
	const char *lname = "";
	nsl_string gtype;
	nsl_string ltype;
	nsl_string atype;
        nsl_layer* data;
        nsl_base* pbase;
	nsl_layer* layer;
	nsl_model* model;
	const char *str = "";
	num_type wymin,wymax,ts;
 	xnsl_window* pwin;

	strcpy(gtype,"");
	strcpy(ltype,"");
	strcpy(atype,"");
  
  	if ((pwin = (xnsl_window*) m_parent->get_ptr()) != NULL && win != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (list != NULL)
            {

// update labels: layer, graph

        if ((data = (nsl_layer*) list->get_by_name("layer")) != NULL)
	  	{
            lname = ((nsl_str_data*) data)->get_value();
			if ((layer = (nsl_layer*) SYSTEM->get_hier_object(lname)) != NULL)
		    {
				strcpy(atype,layer->get_abstract_type());
		      	sprintf(ltype,"display_canvas_%s",atype);
		    }
	  	}
        else
            cmd_error("cmd_display_canvas: NULL 'layer' obj");
        
        if ((data = (nsl_layer*) list->get_by_name("side")) != NULL)
             side = ((nsl_str_data*) data)->get_value();
        else
             cmd_error("cmd_display_canvas: NULL type ",side);

// update label: wymin, wymax, ts
/* AW 10/1/96
             	if ((data = (nsl_layer*) list->get_by_name("wymin")) != NULL)
	    	{
	                wymin = ((nsl_num_data*) data)->get_value();
           		update_text((xnsl_window*)win,"wymin",wymin);
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wymin' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wymax")) != NULL)
	    	{
	                wymax = ((nsl_num_data*) data)->get_value();
           		update_text((xnsl_window*)win,"wymax",wymax);
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wymax' obj");

            	if ((data = (nsl_layer*) list->get_by_name("ts")) != NULL)
	    	{
	                ts = ((nsl_num_data*) data)->get_value();
           		update_text((xnsl_window*)win,"ts",ts);
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'ts' obj");

          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(ltype)) != NULL)
			((xnsl_cmd_window*) pbase)->update_data(win);
	  	else
		 	cmd_error("cmd_display_canvas: NULL type ",ltype);
*/
          	if ((data = (nsl_layer*) list->get_by_name("graph")) != NULL)
                    sprintf(gtype,"display_canvas_%s_%s",
			((nsl_str_data*) data)->get_value(),atype);
          	else
                	cmd_error("cmd_display_canvas: NULL type ",gtype);

// update values: wx0,wy0, wx1, wy1, wxs, wys
             	if ((data = (nsl_layer*) list->get_by_name("wx0")) != NULL)
	    	{
	                wx0 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wx0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wx1")) != NULL)
	    	{
                	wx1 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wx1' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wy0")) != NULL)
	    	{
                	wy0 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wy0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wy1")) != NULL)
	    	{
                	wy1 = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wy1' obj");
        
            	if ((data = (nsl_layer*) list->get_by_name("wxs")) != NULL)
	    	{
                	wxs = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wxs' obj");

            	if ((data = (nsl_layer*) list->get_by_name("wys")) != NULL)
	    	{
                	wys = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'wys' obj");

            	if ((data = (nsl_layer*) list->get_by_name("X0")) != NULL)
	    	{
                	x = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'X0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("Y0")) != NULL)
	    	{
                	y = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'Y0' obj");

            	if ((data = (nsl_layer*) list->get_by_name("width")) != NULL)
	    	{
                	w = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'width' obj");

            	if ((data = (nsl_layer*) list->get_by_name("height")) != NULL)
	    	{
                	h = ((nsl_int_data*) data)->get_value();
  	    	}
            	else
                	cmd_error("cmd_display_canvas: NULL 'height' obj");

          	if ((pbase = SYSTEM->get_cmd_system()->get_m_children_list()->
		    get_mi_by_type(gtype)) != NULL)
		{
			((xnsl_cmd_window*) pbase)->update_data(win,
				x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys);
			((xnsl_cmd_window*) pbase)->update_graph(win,
				x,y,w,h,wx0,wy0,wx1,wy1,wxs,wys,layer,side);
		}
	  	else
		 	cmd_error("cmd_display_window: NULL type ",gtype);
	    }
	}
	else
		cmd_error("cmd_display_canvas: CANNOT update data in window");
 
	return 1;
}
int xnsl_cmd_display_canvas::create_text(nsl_base* win,
	xnsl_text_label_canvas* cw,const char* wname,const char* value,
	int fg,int mode)
{
	xnsl_widget* canvas;
 	nsl_list* list = 0;
	nsl_string label;
	static int x_loc;
	static int y_loc;
	nsl_string str;
   
  	if (win != NULL && 
 	    (list = ((xnsl_window*) win)->get_data_list()) != NULL &&
	    (canvas = ((xnsl_window*) win)->get_widget()) != NULL)
	{
	    int w = ((xnsl_window*) win)->get_width();
	    int h = ((xnsl_window*) win)->get_height();

 	    if (mode == 1 && fg == 1)
	    {
		y_loc = h - 12;
 	    	x_loc = 5;
	    } 
 	    else if (mode == 2 && fg == 1)
	    {
		y_loc = 5;
 	    	x_loc = 5;
	    }

	    strcpy(str,win->get_name());

 	    if (cw != NULL)
	    {
//AW98          ((xnsl_window*) win)->add_data(cw);
//AW98		sprintf(label,"%s:",wname);
		sprintf(label,"");
		cw->set_wname(str);				
		cw->set_name(wname);	
		cw->set_widget_value(value);
 		cw->create_widget(str,canvas,x_loc,y_loc,w,h,0,0,0,0,0,0,label);

// AW98 display now if retained
		cw->display();
	    }

 	    x_loc = x_loc + (strlen(wname)+strlen(value)+2)*FONT_WIDTH;
	}
	else
		cmd_error("cmd_display_canvas: Cannot create text");

 	return 1;
}
int xnsl_cmd_display_canvas::update_text(nsl_base* win,
	const char* wname,const char* value)
{
 	nsl_list* list = 0;
   	xnsl_text_label_canvas* cw;

  	if (win != NULL && 
 	    (list = ((xnsl_window*) win)->get_data_list()) != NULL &&
	    (cw = (xnsl_text_label_canvas*) list->get_by_name(wname)) != NULL)
	{
		cw->set_widget_value(value);
	}
	else
		cmd_error("cmd_display_canvas: Cannot update text");

 	return 1;
}
int xnsl_cmd_display_canvas::update_text(nsl_base* win,
	const char* wname,num_type value)
{
	nsl_string str;

	sprintf(str,"%f",value);
	update_text(win,wname,str);

 	return 1;
}
int xnsl_cmd_display_canvas::update_text(nsl_base* win,
	const char* wname,int value)
{
	nsl_string str;

	sprintf(str,"%d",value);
	update_text(win,wname,str);

 	return 1;
}
int xnsl_cmd_display_canvas::create_top_text(nsl_base* win,
	const char* wname,const char* value,int fg)
{
  	xnsl_text_label_canvas* cw;
  
  	if (win != NULL)
	{
            cw = new xnsl_str_label_canvas((xnsl_display_canvas*) win);
            
	    create_text(win,cw,wname,value,fg,1);
	}
	else
		cmd_error("cmd_display_canvas: Cannot create top text");

 	return 1;
}
int xnsl_cmd_display_canvas::create_bot_text(nsl_base* win,
	const char* wname,const char* value,int fg)
{
 	xnsl_text_label_canvas* cw;
  
  	if (win != NULL)
	{
            cw = new xnsl_str_label_canvas((xnsl_display_canvas*) win);

	    create_text(win,cw,wname,value,fg,2);
	}
	else
		cmd_error("cmd_display_canvas: Cannot create bot text");

 	return 1;
}
int xnsl_cmd_display_canvas::create_top_text(nsl_base* win,
	const char* wname,int val,int fg)
{
  	xnsl_text_label_canvas* cw;
	nsl_string value;
  
  	if (win != NULL)
	{
            cw = new xnsl_int_label_canvas((xnsl_display_canvas*) win);
            
	    sprintf(value,"%d",val);

	    create_text(win,cw,wname,value,fg,1);
	}
	else
		cmd_error("cmd_display_canvas: Cannot create top text");

 	return 1;
}
int xnsl_cmd_display_canvas::create_bot_text(nsl_base* win,
	const char* wname,int val,int fg)
{
 	xnsl_text_label_canvas* cw;
	nsl_string value;

  	if (win != NULL)
	{
            cw = new xnsl_int_label_canvas((xnsl_display_canvas*) win);

	    sprintf(value,"%d",val);

	    create_text(win,cw,wname,value,fg,2);
	}
	else
		cmd_error("cmd_display_canvas: Cannot create bot text");

 	return 1;
}
int xnsl_cmd_display_canvas::create_top_text(nsl_base* win,
	const char* wname,num_type val,int fg)
{
  	xnsl_text_label_canvas* cw;
	nsl_string value;
  
  	if (win != NULL)
	{
            cw = new xnsl_num_label_canvas((xnsl_display_canvas*) win);
            
	    sprintf(value,"%f",val);

	    create_text(win,cw,wname,value,fg,1);
	}
	else
		cmd_error("cmd_display_canvas: Cannot create top text");

 	return 1;
}
int xnsl_cmd_display_canvas::create_bot_text(nsl_base* win,
	const char* wname,num_type val,int fg)
{
 	xnsl_text_label_canvas* cw;
	nsl_string value;

  	if (win != NULL)
	{
            cw = new xnsl_num_label_canvas((xnsl_display_canvas*) win);

	    sprintf(value,"%f",val);

	    create_text(win,cw,wname,value,fg,2);
	}
	else
		cmd_error("cmd_display_canvas: Cannot create bot text");

 	return 1;
}
int xnsl_cmd_display_canvas::create_grid(nsl_base* win,
	int x, int y,int width,int height,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,on_off_enum tfg)
{
 	xnsl_widget* canvas;
 	xnsl_grid* cw;
 	nsl_list* dlist = 0;
	nsl_string str;

 	if (win != NULL && 
	    (dlist = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
        cw = new xnsl_grid((xnsl_display_canvas*) win);
// AW98 not add to avoid redisplay
		//if (TK_DRAW == 0) // add to display list on XLIB draw only //commented out -bn7
          //   ((xnsl_window*) win)->add_data(cw);

	    strcpy(str,win->get_name());

  	    if (cw != NULL && (canvas = ((xnsl_window*) win)->
						get_widget()) != NULL)
	    {
			cw->set_name("grid");  // data name in data list
			cw->set_text_fg(tfg); // text in grid
   			cw->create_widget(str,canvas,
			x,y,width,height,wx0,wy0,wx1,wy1,wxs,wys);
// AW98 display now if retained
			cw->display();
	    }
  	    else
		cmd_error("cmd_display_canvas: Cannot create grid");
	}
  	else
		cmd_error("cmd_display_canvas: NULL window");

 	return 1;
}
int xnsl_cmd_display_canvas::create_line(nsl_base* win,
	int x,int y,int width,int height,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,
	num_type wymin, num_type wymax)
{
 	xnsl_widget* canvas;
 	xnsl_line* cw;
 	nsl_list* dlist = 0;
	nsl_string str;

 	if (win != NULL && 
	    (dlist = ((xnsl_window*) win)->get_data_list()) != NULL)
	{
            cw = new xnsl_line((xnsl_display_canvas*) win);
// AW98 not add to avoid redisplay
		//if (TK_DRAW == 0) // add to display list on XLIB draw only
         //   ((xnsl_window*) win)->add_data(cw);

	    strcpy(str,win->get_name());

  	    if (cw != NULL && (canvas = ((xnsl_window*) win)->
						get_widget()) != NULL)
	    {
		cw->set_name("line");	// data name in data list
   		cw->create_widget(str,canvas,
			x,y,width,height,wx0,wy0,wx1,wy1,wxs,wys);

		cw->set_wymin(wymin);
		cw->set_wymax(wymax);

// AW98 display now if retained
		cw->display();
	    }
  	    else
		cmd_error("cmd_display_canvas: Cannot create line");
	}
  	else
		cmd_error("cmd_display_canvas: NULL window");

 	return 1;
}
int xnsl_cmd_display_canvas::create_graph(nsl_base* win,
	int x,int y,int width,int height,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer* layer,
	const char* side)
{
 	return 1;
} 
int xnsl_cmd_display_canvas::update_graph(nsl_base* win,
	int x,int y,int width,int height,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys,nsl_layer*,const char*)
{
//update wymin, wymax

	xnsl_widget_graph* cw;
 	nsl_list* list = 0;
	nsl_list* dlist = 0;
    nsl_base* pbase;
	num_type wymin = 0, wymax = 1;
	nsl_layer* data;

   	if (win != NULL &&
	    (list = ((xnsl_window*) win)->get_data_list()) != NULL &&
	    (cw = (xnsl_graph*) list->get_by_name("graph")) != NULL)
	{
            pbase = SYSTEM->get_cmd_system()->
             	get_m_children_list()->get_mi_by_type(get_base_type());
            if (pbase != NULL)
                dlist = ((nsl_cmd_type*) pbase)->get_data_list();
            else
                cmd_error("cmd: NULL parent type");

       	    if (dlist != NULL)
            {
            	if ((data = (nsl_layer*) dlist->get_by_name("wymin")) != NULL)
	    	{
	            wymin = ((nsl_num_data*) data)->get_value();
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'wymin' obj");

            	if ((data = (nsl_layer*) dlist->get_by_name("wymax")) != NULL)
	    	{
	            wymax = ((nsl_num_data*) data)->get_value();
  	    	}
            	else
                    cmd_error("cmd_display_canvas: NULL 'wymax' obj");

	    }

/*	    cw->set_wx0(wx0);
	    cw->set_wx1(wx1);
	    cw->set_wy0(wy0);
	    cw->set_wy1(wy1);
	    cw->set_wxs(wxs);
	    cw->set_wys(wys);

	    cw->set_width(width);
	    cw->set_height(height);
*/
	    cw->set_wymin(wymin);
	    cw->set_wymax(wymax);

//	    cw->clear();
  	}
  	else
		cmd_error("cmd_display_canvas: NULL window");

 	return 1;
} 
