/* SCCS  @(#)nsl_cmd_exec_update.C	1.1---95/10/13--16:35:18 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_update.C                    */
/*                                                            */
/**************************************************************/

#include "nsl.h"
#include "nsl_cmd_exec_update.h"
#include "nsl_base_list.h"
#include "nsl_cmd_type.h"
#include "nsl_cmd_buf.h"
#include "nsl_stream.h"
#include "nsl_interpreter.h"
#include "nsl_kernel.h"
typedef nsl_base_list nsl_list;

nsl_cmd_exec_update::nsl_cmd_exec_update() : nsl_cmd_exec("update")
{
}

nsl_cmd_exec_update::~nsl_cmd_exec_update()
{
}
int nsl_cmd_exec_update::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;
//	nsl_cmd_macro* macro;
 
	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		help("update");
		return 1;
	}

	nsl >> str; // update: layer,etc

 	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_update(nsl);
		return fg;
	}

	return fg;
}
int nsl_cmd_exec_update::help(const char*)
{
	return 1;
}

