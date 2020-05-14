/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_window.C                         */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_window::xnsl_cmd_window() : nsl_cmd_type()
{
        set_base_type("window");
        set_type("window");

	XSYSTEM = XNSL_SYSTEM;

//	create_data(); // create all data for all types
}

xnsl_cmd_window::~xnsl_cmd_window()
{
}

int xnsl_cmd_window::cmd_clear(nsl_interpreter& nsl)
{
        cmd_type_clear(nsl);

        return 1;
}
int xnsl_cmd_window::cmd_create(nsl_interpreter& nsl)
{
        cmd_type_create(nsl);

        return 1;
}
int xnsl_cmd_window::cmd_init(nsl_interpreter& nsl)
{
        cmd_type_init(nsl);

        return 1;
}
int xnsl_cmd_window::cmd_reset(nsl_interpreter& nsl)
{
        cmd_type_reset(nsl);

        return 1;
}
int xnsl_cmd_window::cmd_update(nsl_interpreter& nsl)
{
        cmd_type_update(nsl);

        return 1;
}

int xnsl_cmd_window::create_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
        return 1;
}
int xnsl_cmd_window::init_data(nsl_base* win)
{
        int ival;
	const char* sval;
        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 

        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("name")) != NULL)
          {
                sval = ((xnsl_window*) win)->get_name();
		((nsl_str_data*) data)->set_value(sval);
          }
          else
                cmd_error("cmd_window: NULL 'name' obj");

          if ((data = (nsl_layer*) list->get_by_name("X0")) != NULL)
          {
                ival = ((xnsl_window*) win)->get_X0();
		((nsl_int_data*) data)->set_value(ival);
          }
         else
                cmd_error("cmd_window: NULL 'X0' obj");

          if ((data = (nsl_layer*) list->get_by_name("Y0")) != NULL)
          {
                ival = ((xnsl_window*) win)->get_Y0();
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_window: NULL 'Y0' obj");

          if ((data = (nsl_layer*) list->get_by_name("width")) != NULL)
          {
                ival = ((xnsl_window*) win)->get_width();
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_window: NULL 'width' obj");

          if ((data = (nsl_layer*) list->get_by_name("height")) != NULL)
          {
                ival = ((xnsl_window*) win)->get_height();
		((nsl_int_data*) data)->set_value(ival);
          }
          else
                cmd_error("cmd_window: NULL 'height' obj");
        }

        return 1;
}
int xnsl_cmd_window::reset_data(nsl_base*)
{
         return 1;
}
int xnsl_cmd_window::update_data(nsl_base* win,int,int,int,int,
	int wx0,int wy0,int wx1,int wy1,int wxs,int wys)
{
        int ival;
	const char* sval;
        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 

        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type(get_base_type())) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
/*          if ((data = (nsl_layer*) list->get_by_name("name")) != NULL &&
		data->get_flag() == 1)
          {
                sval = ((nsl_str_data*) data)->get_value();
                ((xnsl_window*) win)->set_name(sval);
          }
//          else
//                cmd_error("xnsl_window: NULL 'name' obj");
*/
          if ((data = (nsl_layer*) list->get_by_name("X0")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
                ((xnsl_window*) win)->set_X0(ival);
          }
//          else
//               cmd_error("xnsl_window: NULL 'X0' obj");

          if ((data = (nsl_layer*) list->get_by_name("Y0")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
                ((xnsl_window*) win)->set_Y0(ival);
          }
//          else
//                cmd_error("xnsl_window: NULL 'Y0' obj");

          if ((data = (nsl_layer*) list->get_by_name("width")) != NULL &&
		data->get_flag() == 1L)
          {
                ival = ((nsl_int_data*) data)->get_value();
                ((xnsl_window*) win)->set_width(ival);
          }
//          else
//                cmd_error("xnsl_window: NULL 'width' obj");

          if ((data = (nsl_layer*) list->get_by_name("height")) != NULL &&
		data->get_flag() == 1)
          {
                ival = ((nsl_int_data*) data)->get_value();
                ((xnsl_window*) win)->set_height(ival);
          }
//          else
//                cmd_error("xnsl_window: NULL 'height' obj");
 
        }

        return 1;
}
int xnsl_cmd_window::create_graph(nsl_base*,int,int,int,int,
	int,int,int,int,int,int,nsl_layer*,const char*)
{
        return 1;
}
int xnsl_cmd_window::update_graph(nsl_base*,int,int,int,int,
	int,int,int,int,int,int,nsl_layer*,const char*)
{
        return 1;
}
