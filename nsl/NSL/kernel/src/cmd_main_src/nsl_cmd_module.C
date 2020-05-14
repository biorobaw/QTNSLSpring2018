/* SCCS  @(#)nsl_cmd_module.C	1.2---95/10/13--16:28:02 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_module.C                         */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_module.h"
#include "nsl_interpreter.h"
#include "nsl_module.h"
#include "nsl_model.h"
#include "nsl_system.h"
nsl_cmd_module::nsl_cmd_module() : nsl_cmd_type("module")
{
	init_cmd_module();
}

nsl_cmd_module::~nsl_cmd_module()
{
	init_cmd_module();
}

int nsl_cmd_module::init_cmd_module()
{
	return set_cmd_module();
}
int nsl_cmd_module::set_cmd_module()
{
	set_base_type("module");

	nsl_model* model = SYSTEM->get_model();

/*	if (model == NULL)
	{
		cmd_error("CMD MODEL: Null Model");
		return 1;
	}
*/			
	return 1;
}

int nsl_cmd_module::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_module::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_module::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_module::cmd_exec(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
	nsl_list* mlist;
	nsl_base* base;

	if (m_parent == NULL)
	{
		cmd_error("CMD TYPE: Null Parent");
		return 1;
	}

 	const char* stype = m_parent->get_base_type();
	// pbase is m_parent for local type (e.g model parent to layer)
	nsl_base* pbase = SYSTEM->get_m_children_list()->get_mi_by_type(stype);
	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD MODULE: Null Type Parent");
		return 1;
	}

	if (nsl.get_str_cnt() == 0)
	{
		cmd_error("exec: Bad Usage");
//		cmd_type_help("exec");
	}
	else if (ltype != 0)
	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = module list)
		if ((mlist = (nsl_list*) 
		  pbase->get_m_children_list()->get_m_by_name("module")) == 0)
		{
			cmd_error("nsl_cmd_module: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				((nsl_module*) base)->exec();
			else
				cmd_error("Bad Index");
		}
 		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				((nsl_module*) base)->exec();
			else
				cmd_error("Bad Obj Name");
		}
	}
	else
		cmd_error("Bad Command");

	return 1;
}
int nsl_cmd_module::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_module::cmd_set(nsl_interpreter& nsl)
{
	return cmd_type_set(nsl);
}
int nsl_cmd_module::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}

// local print

int nsl_cmd_module::print_cmd_module(ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_module::print(ostream& out) const // virtual
{
	print_cmd_module(out);
	return 1;
}
