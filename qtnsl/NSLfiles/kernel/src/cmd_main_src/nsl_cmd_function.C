#include "nsl_cmd_function.h"
#include "nsl_kernel.h"

nsl_cmd_function::nsl_cmd_function() : nsl_cmd_type("function")
{
	init_cmd_function();
}

nsl_cmd_function::~nsl_cmd_function()
{
	init_cmd_function();
}

int nsl_cmd_function::init_cmd_function()
{
	return set_cmd_function();
}
int nsl_cmd_function::set_cmd_function()
{
	set_base_type("function");

	return 1;
}

int nsl_cmd_function::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_function::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_function::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_function::cmd_exec(nsl_interpreter& nsl)
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
		// (e.g. for model, mlist = function list)
		if ((mlist = (nsl_list*)
		  pbase->get_m_children_list()->get_m_by_name("function")) == 0)
		{
			cmd_error("nsl_cmd_function: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				((nsl_function*) base)->exec();
			else
				cmd_error("Bad Index");
		}
 		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				((nsl_function*) base)->exec();
			else
				cmd_error("Bad Obj Name");
		}
	}
	else
		cmd_error("Bad Command");

	return 1;
}
int nsl_cmd_function::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_function::cmd_set(nsl_interpreter& nsl)
{
	return cmd_type_set(nsl);
}
int nsl_cmd_function::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}

// local print

int nsl_cmd_function::print_cmd_function(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_function::print(std::ostream& out) const // virtual
{
	print_cmd_function(out);
	return 1;
}
