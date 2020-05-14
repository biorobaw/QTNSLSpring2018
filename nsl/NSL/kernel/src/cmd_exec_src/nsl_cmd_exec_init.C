/* SCCS  @(#)nsl_cmd_exec_init.C	1.1---95/10/13--16:35:13 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_init.C                      */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_init.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
extern void cmd_error(const char *);

nsl_cmd_exec_init::nsl_cmd_exec_init() : nsl_cmd_exec("init")
{
}

nsl_cmd_exec_init::~nsl_cmd_exec_init()
{
}
int nsl_cmd_exec_init::exec(nsl_interpreter& nsl)
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
		nsl >> str; // init: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_init(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("init model",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_init::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

