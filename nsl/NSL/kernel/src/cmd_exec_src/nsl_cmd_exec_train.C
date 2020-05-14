/* SCCS  @(#)nsl_cmd_exec_train.C	1.1---95/10/13--16:35:15 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_train.C                       */
/*                                                            */
/**************************************************************/

# include "nsl_cmd_exec_train.h"
#include "nsl_kernel.h"

nsl_cmd_exec_train::nsl_cmd_exec_train() : nsl_cmd_exec("train")
{
}

nsl_cmd_exec_train::~nsl_cmd_exec_train()
{
}
int nsl_cmd_exec_train::exec(nsl_interpreter& nsl)
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
		nsl >> str; // train: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_train(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("train model",2);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_train::help(const char*)
{
	return 1;
}

