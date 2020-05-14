/**************************************************************/
/*                                                            */
/*                   nsl_cmd_block_stim.C             	      */
/*                                                            */
/**************************************************************/
#include "nsl_input.h"
#include "nsl_cmd_block_stim.h"

nsl_cmd_block_stim::nsl_cmd_block_stim()
{
	set_type("block_stim");
}

nsl_cmd_block_stim::~nsl_cmd_block_stim()
{
}

int nsl_cmd_block_stim::init_data(nsl_base*)
{
	return 1;
}
int nsl_cmd_block_stim::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}

int nsl_cmd_block_stim::cmd_clear(nsl_interpreter& nsl)
{
   	nsl_cmd_stim::cmd_clear(nsl);

 	return 1;
}
int nsl_cmd_block_stim::cmd_create(nsl_interpreter& nsl)
{
   	nsl_cmd_stim::cmd_create(nsl);

	return 1;
}
int nsl_cmd_block_stim::cmd_reset(nsl_interpreter& nsl)
{
   	nsl_cmd_stim::cmd_reset(nsl);

	return 1;
}
int nsl_cmd_block_stim::cmd_update(nsl_interpreter& nsl)
{
   	nsl_cmd_stim::cmd_update(nsl);

	return 1;
}
