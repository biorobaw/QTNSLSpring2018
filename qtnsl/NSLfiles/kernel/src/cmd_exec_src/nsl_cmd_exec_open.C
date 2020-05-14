/* SCCS  @(#)nsl_cmd_exec_open.C	1.1---95/10/13--16:35:13 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_open.C                      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_open.h"
#include "nsl_base_list.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_interpreter.h"
#include "nsl_kernel.h"
extern void cmd_error(const char *);

#ifndef _NSL_SET
typedef nsl_base_list nsl_list;
#endif

extern void cmd_error(const char *);

nsl_cmd_exec_open::nsl_cmd_exec_open() : nsl_cmd_exec("open")
{
}

nsl_cmd_exec_open::~nsl_cmd_exec_open()
{
}
int nsl_cmd_exec_open::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("open");
		return 1;
	}

	nsl >> str; // open: file,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_open(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("open file",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_open::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

