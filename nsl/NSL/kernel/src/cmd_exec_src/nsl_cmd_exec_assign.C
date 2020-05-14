/* SCCS  @(#)nsl_cmd_exec_assign.C	1.1---95/10/13--16:35:07 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_assign.C                    */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_assign.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"

nsl_cmd_exec_assign::nsl_cmd_exec_assign() : nsl_cmd_exec("assign")
{
// set data_value
}

nsl_cmd_exec_assign::~nsl_cmd_exec_assign()
{
}
int nsl_cmd_exec_assign::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("assign");
		return 1;
	}

	nsl >> str; // assign: layer,etc

	// look in complete management/inheritance hierarchy for type 'str'
	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_assign(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("assign layer",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_assign::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

