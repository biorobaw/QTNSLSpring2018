/**************************************************************/
/*                                                            */
/*                   nsl_cmd_stim_data.C             	      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_stim_data.h"
#include "nsl_input.h"

nsl_cmd_stim_data::nsl_cmd_stim_data()
{
	set_type("stim_data");
}

nsl_cmd_stim_data::~nsl_cmd_stim_data()
{
}

int nsl_cmd_stim_data::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_stim_data::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_data::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_data::cmd_update(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_stim_data::init_data(nsl_base* base)
{
	nsl_cmd_stim::init_data(base);

 	return 1;
}
int nsl_cmd_stim_data::update_data(nsl_base* base,
	int,int,int,int,int,int,int,int,int,int)
{
 	nsl_cmd_stim::update_data(base);

	return 1;
}
