/* SCCS  @(#)nsl_cmd_input_stim.C	1.1---95/08/13--20:52:41 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_input_stim.C                     */
/*                                                            */
/**************************************************************/

//no class header? -bn7
#include "nsl_cmd_type.h"
class nsl_cmd_input_stim : public nsl_cmd_type
{
nsl_cmd_input_stim();
~nsl_cmd_input_stim();
int cmd_clear(nsl_interpreter&);
int cmd_create(nsl_interpreter&);
int cmd_reset(nsl_interpreter&);
int cmd_update(nsl_interpreter&);
};

nsl_cmd_input_stim::nsl_cmd_input_stim() : nsl_cmd_type("input_stim")
{
}

nsl_cmd_input_stim::~nsl_cmd_input_stim()
{
}

int nsl_cmd_input_stim::cmd_clear(nsl_interpreter&)
{
 	return 1;
}
int nsl_cmd_input_stim::cmd_create(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_stim::cmd_reset(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_input_stim::cmd_update(nsl_interpreter&)
{
 	return 1;
}

