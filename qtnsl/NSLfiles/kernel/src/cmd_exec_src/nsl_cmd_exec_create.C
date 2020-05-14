/* SCCS  @(#)nsl_cmd_exec_create.C	1.1---95/10/13--16:35:09 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_create.C                    */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_exec_create.h"
#include "nsl_cmd_buf.h"
#include "nsl_cmd_type.h"
#include "nsl_stream.h"
#include "nsl_base_list.h"
#include "nsl_kernel.h"
nsl_cmd_exec_create::nsl_cmd_exec_create() : nsl_cmd_exec("create")
{
}

nsl_cmd_exec_create::~nsl_cmd_exec_create()
{
}
int nsl_cmd_exec_create::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int fg = 2;
	nsl_cmd_type* obj;
//	nsl_cmd_macro* macro;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	nsl >> str; // create: layer,etc

 	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(str)) != 0)
	{
		fg = obj->cmd_create(nsl);
		return fg;
	}

	return fg;
}
int nsl_cmd_exec_create::help(const char*)
{
	return 1;
}

