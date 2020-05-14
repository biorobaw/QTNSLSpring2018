/* SCCS  @(#)nsl_cmd_exec_file_disable.C	1.1---95/10/13--16:35:11 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_file_disable.C              */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_file_disable.h"
#include "nsl_base_list.h"
#include "nsl_cmd_type.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_buf.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"
#ifndef _NSL_SET
typedef nsl_base_list nsl_list;
#endif

nsl_cmd_exec_file_disable::nsl_cmd_exec_file_disable() : 
	nsl_cmd_exec("file_disable")
{
}

nsl_cmd_exec_file_disable::~nsl_cmd_exec_file_disable()
{
}
int nsl_cmd_exec_file_disable::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

 	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("file_disable");
		return 1;
	}

	nsl >> str; // file_disable: layer,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_file_disable(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("file_disable layer",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}


	return fg;
}
int nsl_cmd_exec_file_disable::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

