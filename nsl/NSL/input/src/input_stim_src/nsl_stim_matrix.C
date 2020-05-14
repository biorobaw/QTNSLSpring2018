/* SCCS  %W%---%E%--%U% */
//
//	nsl_stim_matrix.c
//

#include "nsl_input.h"
#include "nsl_stim_matrix.h"

extern void cmd_error(const char *);


nsl_stim_matrix::nsl_stim_matrix(nsl_input_matrix* l) : nsl_stim(l),
	x0("x0",this,1), y0("y0",this,1),	// stim original corner location
	tx0("tx0",this,1), ty0("ty0",this,1),	// stim current corner location
	xc("xc",this,1), yc("yc",this,1),	// stim original center location
	txc("txc",this,1), tyc("tyc",this,1),	// stim current center location
	dx("dx",this,1), dy("dy",this,1), 	// stim size
	vx("vx",this,1), vy("vy",this,1) 	// stim speed
{
	set_type("stim_matrix");
	set_base_type("stim");

 	x0 = 0;
	y0 = 0;
	tx0 = 0;
	ty0 = 0;
	xc = 0;
	yc = 0;
	txc = 0;
	tyc = 0;

	vx = 0.0;
	vy = 0.0;
}
nsl_stim_matrix::~nsl_stim_matrix()
{

}

int nsl_stim_matrix::proc()
{
	return 1;
}

int  nsl_stim_matrix::run()
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

	int dt0 = step;		// recalculation frequency
	if (dt0 == 0 && ts == 0.0)
	{
		txc = xc;
		tyc = yc;
		tx0 = x0;
		ty0 = y0;
	}
	else if (dt0 != 0 && its%step == 0)
	{
		txc = xc + ts*vx;
		tyc = yc + ts*vy;
		tx0 = x0 + ts*vx;
		ty0 = y0 + ts*vy;
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
int nsl_stim_matrix::print(ostream& out) const
{
 	return print_stim_matrix(out);
}
int nsl_stim_matrix::print_stim_matrix(ostream& out) const
{
	print_stim(out);

	out << "set stim x0 " << x0.get_value() << "\n";
	out << "set stim y0 " << y0.get_value() << "\n";
 	out << "set stim xc " << xc.get_value() << "\n";
	out << "set stim yc " << yc.get_value() << "\n";
 	out << "set stim vx " << vx.get_value() << "\n";
	out << "set stim vy " << vy.get_value() << "\n";
	out.flush();

	return 1;
}
int nsl_stim_matrix::print_status(ostream& out) const
{
 	return print_stim_matrix_status(out);
}
int nsl_stim_matrix::print_stim_matrix_status(ostream& out) const
{
	print_stim_status(out);

 	out << "// stim tx0: " << tx0.get_value() << "\n";
	out << "// stim ty0: " << ty0.get_value() << "\n";
	out << "// stim txc: " << txc.get_value() << "\n";
	out << "// stim tyc: " << tyc.get_value() << "\n";
	out.flush();

	return 1;
}

