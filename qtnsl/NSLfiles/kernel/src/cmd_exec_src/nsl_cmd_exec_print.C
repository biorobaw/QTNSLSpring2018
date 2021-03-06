/* SCCS  @(#)nsl_cmd_exec_print.C	1.1---95/10/13--16:35:14 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_print.C                     */
/*                                                            */
/**************************************************************/

#include "nsl.h"
#include "nsl_cmd_exec_print.h"
#include "nsl_interpreter.h"
#include "nsl_base_list.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
extern void cmd_error(const char *);

typedef nsl_base_list nsl_list;

nsl_cmd_exec_print::nsl_cmd_exec_print() : nsl_cmd_exec("print")
{
}

nsl_cmd_exec_print::~nsl_cmd_exec_print()
{
}
int nsl_cmd_exec_print::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"model");
	}
	else
		nsl >> str; // print: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_print(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("print layer",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_print::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

