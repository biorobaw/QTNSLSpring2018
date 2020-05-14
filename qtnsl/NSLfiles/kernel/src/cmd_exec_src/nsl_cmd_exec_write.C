/* SCCS  @(#)nsl_cmd_exec_write.C	1.1---95/10/13--16:35:18 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_write.C                     */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_write.h"
#include "nsl_kernel.h"

typedef nsl_base_list nsl_list;

nsl_cmd_exec_write::nsl_cmd_exec_write() : nsl_cmd_exec("write")
{
}

nsl_cmd_exec_write::~nsl_cmd_exec_write()
{
}
int nsl_cmd_exec_write::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("write");
		return 1;
	}

	nsl >> str; // write: layer,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_write(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("write layer",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_write::help(const char*)
{
	return 1;
}

