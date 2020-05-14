/* SCCS  @(#)nsl_cmd_exec_status.C	1.1---95/10/13--16:35:16 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_status.C                    */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_status.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_base_list.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"
typedef nsl_base_list nsl_list;

nsl_cmd_exec_status::nsl_cmd_exec_status() : nsl_cmd_exec("status")
{
}

nsl_cmd_exec_status::~nsl_cmd_exec_status()
{
}
int nsl_cmd_exec_status::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = (nsl_list*) ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"model");
	}
	else
		nsl >> str; // status: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_status(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("status layer",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_status::help(const char*)
{
	return 1;
}

