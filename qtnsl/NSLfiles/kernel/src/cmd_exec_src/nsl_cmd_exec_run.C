/* SCCS  @(#)nsl_cmd_exec_run.C	1.1---95/10/13--16:35:15 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_run.C                       */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//#include "../../incl/nsl_cmd_exec_run.h"
#include "nsl_cmd_exec_run.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
nsl_cmd_exec_run::nsl_cmd_exec_run() : nsl_cmd_exec("run")
{
}

nsl_cmd_exec_run::~nsl_cmd_exec_run()
{
}
int nsl_cmd_exec_run::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;
	
//	cmd_out("&&&&&&&&& ENTRO AL NSL_CMD_EXEC:EXEC");

 	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"model");
	}
	else
		nsl >> str; // run: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
//		cmd_out("&&&&&&&&& ENTRO AL SEGUNDO IF DE NSL_CMD_EXEC_RUN");
		fg = obj->cmd_run(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("run model",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_run::help(const char*)
{
	return 1;
}

