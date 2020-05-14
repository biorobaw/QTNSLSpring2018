/* SCCS  %W%---%E%--%U% */
//
//	nsl_stim_data.c
//
#include "nsl_input.h"
#include "nsl_stim_data.h"
#include "nsl_input_data.h"
#include "nsl_time_interval.h"

extern void cmd_error(const char *);
extern void cmd_out(const char *);

nsl_stim_data::nsl_stim_data(nsl_input_data* l) : nsl_stim(l)
{
	set_type("stim_data");
	set_base_type("stim");
}
nsl_stim_data::~nsl_stim_data()
{
}

int nsl_stim_data::proc()
{
	return 1;
}
int nsl_stim_data::run()
{
 	float dt = 0;
	float ts = 0;
	int its = 0;

/*AW99	nsl_model* model = SYSTEM->get_model();
	if (model != NULL)
	{
		dt = model->getSimDelta();
		ts = model->getSimTime();
		its = model->getSimTimeStep();
	}
	else
		cmd_error("NULL MODEL");
*/
	if (NSL_SYSTEM != NULL)
	{
		dt = NSL_SYSTEM->getSimDelta();
		ts = NSL_SYSTEM->getSimTime();
		its = NSL_SYSTEM->getSimTimeStep();
	}
	else
		cmd_error("NULL NSL_SYSTEM");

	if (mode == 0)
		proc(); // virtual
	else if (time_list != NULL)
	{
	   time_list->wind_up();
	   nsl_time_interval* time_obj;
	   while (time_obj = (nsl_time_interval*)time_list->next())
	   {
	    	if (time_obj->get_able_fg() == 0)
			continue;

		float t0 = time_obj->get_t0();
		float t1 = time_obj->get_t1();

		if ((ts >= t0 && ts <= t1))
		{
			proc(); // virtual
		}
	   }
	}
	else
	   cmd_out("NULL 'time_list'");

	return 1;
}
int nsl_stim_data::print(std::ostream& out) const
{
	return print_stim_data(out);
}
int nsl_stim_data::print_stim_data(std::ostream& out) const
{
	return print_stim(out);
}
int nsl_stim_data::print_status(std::ostream& out) const
{
	return print_stim_data_status(out);
}
int nsl_stim_data::print_stim_data_status(std::ostream& out) const
{
	return print_stim_status(out);
}

