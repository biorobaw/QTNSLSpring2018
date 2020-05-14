/* SCCS  @(#)nsl_cmd_exec_load.C	1.1---95/10/13--16:35:13 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_load.C                      */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);

nsl_cmd_exec_load::nsl_cmd_exec_load() : nsl_cmd_exec("load")
{
// macro: read
}

nsl_cmd_exec_load::~nsl_cmd_exec_load()
{
}
int nsl_cmd_exec_load::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;

 	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("load");
		return 1;
	}

	nsl >> str; // load: file,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_load(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("load file",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_load::help(const char* str)
{
	cmd_error("Command Usage:");
	help_file(str);

	return 1;
}

