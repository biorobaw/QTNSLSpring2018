/* SCCS  @(#)nsl_cmd_exec_set.C	1.1---95/10/13--16:35:16 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec_set.C                       */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include <stddef.h>
#include "nsl_cmd_exec_set.h"
#include "nsl_base_list.h"
#include "nsl_cmd_macro.h"
#include "nsl_cmd_buf.h"
#include "nsl_base.h"
#include "nsl_cmd_type.h"
#include "nsl.h"
#include "nsl_kernel.h"
extern void cmd_error(const char *);


nsl_cmd_exec_set::nsl_cmd_exec_set() : nsl_cmd_exec("set")
{
	macro_total = 0;
	macro_list = new nsl_list;

	m_children_list->append(macro_list);
}

nsl_cmd_exec_set::~nsl_cmd_exec_set()
{
}
int nsl_cmd_exec_set::exec(nsl_interpreter& nsl)
{
	nsl_string str;
	const char* mstr;
	const char* nstr;
	int fg = 2;
	nsl_cmd_type* obj;
	nsl_cmd_macro* macro;
	int cnt;
	int model_fg = 0;

	nsl_list* list = ((nsl_cmd_buf*) m_parent)->get_type_list();

	if (nsl.get_str_cnt() == 0)
	{
		strcpy(str,"model");
	}
	else
		nsl >> str; // set obj from types: model,layer,etc

 	if ((macro = (nsl_cmd_macro*) macro_list->get_by_type(str)) != 0)
	{
		mstr = macro->get_name();
		cnt = macro->get_str_cnt();
		nsl.get_buffer().reset_rewind_marker();
//		nsl.exec(mstr);
		nsl.putback(mstr,cnt);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl); 
		return fg;
	}		

	nsl_base* lobj = get_hier_object(str,0);

// AW98	nsl_base* lobj = nsl.get_object(str); // get specified object

	if (lobj != NULL) { // get class name and type from object
		mstr = lobj->get_type(); // layer, model, etc.
		nstr = lobj->get_name(); // layer, model, etc.
		if (strcmp(nstr,"model") == 0)
			model_fg = 1;
	}
	else // get a class type instead 
	{
		// used in nsl_cmd_type::cmd_type_set to avoid updates of objs
		// unless it is not "system"
		if (strcmp(str,"system") != 0)
			nsl.set_flag(1); 
		mstr = str;
	}

	if ((obj = (nsl_cmd_type*) list->get_mi_by_type(mstr)) != 0)
	{
		if (lobj != NULL)
			obj->set_ptr(lobj);
		fg = obj->cmd_set(nsl);
		if (model_fg == 1 && NSL_SYSTEM != NULL) {
//			NSL_SYSTEM->setApplicationModel();
			NSL_SYSTEM->makeModelInstance(); // model name (first letter should be lower case)
		}
		return fg;
	}

	cmd_error("cmd_set: Bad Attribute");

	return fg;
}

int nsl_cmd_exec_set::add_macro(nsl_cmd_macro* obj)
{
	obj->set_index(++macro_total);
	macro_list->append(obj);
	obj->set_m_parent(this);

	return macro_total;
}

int nsl_cmd_exec_set::help(const char*)
{
	return 2;
}

