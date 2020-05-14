/* SCCS  @(#)nsl_cmd_system.C	1.2---95/10/13--16:28:03 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_system.C                         */
/*                                                            */
/**************************************************************/

#include "nsl_kernel.h"
#include "nsl_num_data.h"

nsl_cmd_system::nsl_cmd_system() : nsl_cmd_type("system")
{
	init_cmd_system();
}

nsl_cmd_system::~nsl_cmd_system()
{
	init_cmd_system();
}

int nsl_cmd_system::init_cmd_system()
{
	return set_cmd_system();
}
int nsl_cmd_system::set_cmd_system()
{
	set_base_type("system");

	OBJ = SYSTEM;

	SYSTEM->set_cmd_system(this);

	m_parent = SYSTEM;
 
	return 1;
}

/* modeify cmd_set to call this method similar to nsl_cmd_diff
int nsl_cmd_system::update_data()
{
}
*/

int nsl_cmd_system::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_system::cmd_cont(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_system::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_system::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_system::cmd_init(nsl_interpreter&)
{
	SYSTEM->init();

	return 1;
}
int nsl_cmd_system::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_system::cmd_run(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_system::cmd_set(nsl_interpreter& nsl)
{
	 return cmd_type_set(nsl);
}
int nsl_cmd_system::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_system::cmd_step(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_system::cmd_update(nsl_interpreter& nsl)
{
	int fg = 2;
        nsl_layer* data;
        nsl_list* list = 0;
	nsl_cmd_type* cmd_obj; 
	num_type t;

        if (OBJ != NULL && (list = get_data_list()) != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("delta")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		NSL_SYSTEM->setSimDelta(t);
	  }
//          else
//                cmd_error("cmd_system NULL 'delta' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("current_time")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		NSL_SYSTEM->setSimCurrentTime(t);
	  }
//          else
//                cmd_error("cmd_system: NULL 'current_time' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("end_time")) != NULL &&
		data->get_flag() == 1)
	  {
		data->set_flag(0);
                t = ((nsl_num_data*) data)->get_value();
		NSL_SYSTEM->setSimEndTime(t);
	  }
//          else
//                cmd_error("cmd_system: NULL 'end_time' obj");
        }

	return fg;
}

// local print

int nsl_cmd_system::print_cmd_system(ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_system::print(ostream& out) const // virtual
{
	print_cmd_system(out);
	return 1;
}
