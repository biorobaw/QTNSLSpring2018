/* SCCS  @(#)nsl_cmd_exec_connect.C	1.1---95/10/13--16:35:08 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_connect.C                   */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_connect.h"
#include "nsl_cmd_buf.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_type.h"
#include "nsl_kernel.h"
nsl_cmd_exec_connect::nsl_cmd_exec_connect() : nsl_cmd_exec("connect")
{
}

nsl_cmd_exec_connect::~nsl_cmd_exec_connect()
{
}
int nsl_cmd_exec_connect::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
 	nsl_cmd_type* obj;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"neural_network"); // model
	}
	else
		nsl >> str; // connect: model,etc

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_connect(nsl);
		return fg;
	}
	else
	{
		nsl.get_buffer().reset_rewind_marker();
		nsl.putback(str,1);
		nsl.putback("connect neural_network",2); // model
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
 	}

	return fg;
}
int nsl_cmd_exec_connect::help(const char*)
{
	return 1;
}

