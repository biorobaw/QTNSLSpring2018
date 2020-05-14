/* SCCS  %W%---%E%--%U% */
//
//	nsl_stim_vector.c
//

#include "nsl_stim_vector.h"
#include "nsl_input.h"


nsl_stim_vector::nsl_stim_vector(nsl_input_vector* l) : nsl_stim(l),
	x0("x0",this,1),	// stim original corner location
	tx0("tx0",this,1),	// stim current corner location
	xc("xc",this,1),	// stim original center location
	txc("txc",this,1),	// stim current center location
	dx("dx",this,1), 	// stim size
	vx("vx",this,1)		// stim speed
{
	set_type("stim_vector");
	set_base_type("stim");

 	x0 = 0;
	tx0 = 0;
	xc = 0;
	txc = 0;

	vx = 0.0;
}
nsl_stim_vector::~nsl_stim_vector()
{
}

int nsl_stim_vector::proc()
{
	return 1;
}

int nsl_stim_vector::run()
{
 	float dt = 0;
	float ts = 0;
	int its = 0;

/*	nsl_model* model = SYSTEM->get_model();
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

	int dt0 = step;		// recalculation frequency
	if (dt0 == 0 && ts == 0.0)
	{
		txc = xc;
		tx0 = x0;
	}
	else if (dt0 != 0 && its%step == 0)
	{
		txc = xc + ts*vx;
		tx0 = x0 + ts*vx;
	}

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
int nsl_stim_vector::print(std::ostream& out) const
{
 	return print_stim_vector(out);
}
int nsl_stim_vector::print_stim_vector(std::ostream& out) const
{
	print_stim(out);

	out << "set stim x0 " << x0.get_value() << "\n";
 	out << "set stim xc " << xc.get_value() << "\n";
 	out << "set stim vx " << vx.get_value() << "\n";
	out.flush();

	return 1;
}
int nsl_stim_vector::print_status(std::ostream& out) const
{
 	return print_stim_vector_status(out);
}
int nsl_stim_vector::print_stim_vector_status(std::ostream& out) const
{
	print_stim_status(out);

 	out << "// tx0:\t" << tx0.get_value() << "\n";
	out << "// txc:\t" << txc.get_value() << "\n";
	out.flush();

	return 1;
}


