/* SCCS  @(#)nsl_cmd_exec_reset.C	1.1---95/10/13--16:35:15 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_reset.C                     */
/*                                                            */
/**************************************************************/
#include "nsl_cmd_exec_reset.h"
#include "nsl_cmd_buf.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
nsl_cmd_exec_reset::nsl_cmd_exec_reset() : nsl_cmd_exec("reset")
{
}

nsl_cmd_exec_reset::~nsl_cmd_exec_reset()
{
}
int nsl_cmd_exec_reset::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("reset");
		return 1;
	}

	nsl >> str; // create: layer,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_reset(nsl);
		return fg;
	}

	return fg;
}
int nsl_cmd_exec_reset::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

