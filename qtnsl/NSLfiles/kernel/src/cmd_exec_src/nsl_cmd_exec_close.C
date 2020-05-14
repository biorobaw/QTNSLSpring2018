/* SCCS  @(#)nsl_cmd_exec_close.C	1.1---95/10/13--16:35:08 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_close.C                     */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_close.h"
#include "nsl_interpreter.h"
#include "nsl_base_list.h"
#include "nsl_cmd_buf.h"
#include "nsl_stream.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
#ifndef _NSL_SET
typedef nsl_base_list nsl_list;
#endif

nsl_cmd_exec_close::nsl_cmd_exec_close() : nsl_cmd_exec("close")
{
}

nsl_cmd_exec_close::~nsl_cmd_exec_close()
{
}
int nsl_cmd_exec_close::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("close");
		return 1;
	}

	nsl >> str; // close: file,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_close(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("close file",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_close::help(const char*)
{
	return 1;
}

