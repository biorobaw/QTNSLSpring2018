/* SCCS  @(#)nsl_cmd_buf.C	1.2---95/10/13--16:28:00 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_buf.C                            */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_buf.h"
#include "nsl_interpreter.h"
#include "nsl_base.h"
#include "nsl_cmd_exec.h"
#include "nsl_kernel.h"

nsl_cmd_buf::nsl_cmd_buf()
{
	set_type("cmd_buf");
	set_base_type("cmd_shell");

	macro_total = 0;
	macro_list = new nsl_list;

	cmd_total = 0;
	cmd_list = new nsl_list;

	type_total = 0;
	type_list = new nsl_list;

	m_children_list->append(macro_list);
	m_children_list->append(cmd_list);
	m_children_list->append(type_list);
}

nsl_cmd_buf::~nsl_cmd_buf()
{
}

int nsl_cmd_buf::init()
{
//	cmd_error("NSL_CMD_BUF: Nothing to Init");

	return 1;
}

//qt_run
/*
 * This function uses a string as its argument to run through
 * the cmd_list in the same way that user stream input does.
 * However it does not extract the input from the cmd_buffer,
 * the argument is directly passed as the command.
 */
//===========================================================+
int nsl_cmd_buf::qt_run(nsl_interpreter *nsl, char *incmd)
{
  	nsl_cmd_exec* cmd;

	int fg = 2; // 0 - quit,1 - OK, 2 - no cmd

	if (incmd[0] == '\0' || incmd[0] == '\n' ||
		incmd[0] == ' ' || incmd[0] == '\t')
		return 1; // str is discarded

 	if ((cmd = (nsl_cmd_exec*) cmd_list->get_by_type(incmd)) != 0)
	{
		fg = cmd->exec(*nsl);
		return fg;
	}

	return fg;
}


int nsl_cmd_buf::run(nsl_interpreter* nsl)
{
	nsl_string str;
  	nsl_cmd_exec* cmd;
 
	int fg = 2; // 0 - quit,1 - OK, 2 - no cmd

 	*nsl >> str; // create,etc

	if (str[0] == '\0' || str[0] == '\n' || 
		str[0] == ' ' || str[0] == '\t') 
			return 1; // str is discarded

 	if ((cmd = (nsl_cmd_exec*) cmd_list->get_by_type(str)) != 0)
	{
		fg = cmd->exec(*nsl);
		return fg;
	}

	return fg;
}

// macro

int nsl_cmd_buf::add_macro(nsl_cmd_macro* obj)
{
	obj->set_index(++macro_total);
	macro_list->append(obj);
	obj->set_m_parent(this);

	return macro_total;
}

// cmd

int nsl_cmd_buf::add_cmd(nsl_cmd_exec* obj)
{
	obj->set_index(++cmd_total);
	cmd_list->append(obj);
	obj->set_m_parent(this);

	return cmd_total;
}
int nsl_cmd_buf::add_cmd_children(nsl_cmd_exec* obj,const char* lname)
{
	int total = 0;
	cmd_list->wind_up();
	nsl_list* list;

	nsl_cmd_exec* cmd;

	if ((cmd = (nsl_cmd_exec*) cmd_list->get_by_type(lname)) != NULL)
	{
		list = cmd->get_i_children_list();
		list->append(obj); 
		total = list->get_total();
	}

	return total;
}
nsl_cmd_exec* nsl_cmd_buf::get_cmd(const int lindex)
{
	return (nsl_cmd_exec*) cmd_list->get_by_index(lindex);
}
nsl_cmd_exec* nsl_cmd_buf::get_cmd(const char* lname)
{
	return (nsl_cmd_exec*) cmd_list->get_by_type(lname);
}

int nsl_cmd_buf::print_cmd(ostream& out)
{
	cmd_list->print(out);
	return 1;
}

// type

int nsl_cmd_buf::add_type(nsl_cmd_type* obj)
{
	obj->set_index(++type_total);
	type_list->append(obj);
	obj->set_m_parent(this);

	return type_total;
}
int nsl_cmd_buf::add_type_m_parent(nsl_cmd_type* obj,const char* lname)
{
	type_list->wind_up();
	nsl_list* clist;

	nsl_cmd_type* ltype;

	if ((ltype = (nsl_cmd_type*) type_list->get_mi_by_type(lname)) != NULL)
	{
		clist = ltype->get_m_children_list();
		clist->append(obj);
		obj->set_m_parent(ltype);
	}
	else
		cmd_error("Cannot find object of type: ",lname);

	return 1;
}
int nsl_cmd_buf::add_type_m_children(nsl_cmd_type* obj,const char* lname)
{
	type_list->wind_up();
	nsl_list* plist;

	nsl_cmd_type* ltype;

	if ((ltype = (nsl_cmd_type*) type_list->get_mi_by_type(lname)) != NULL)
	{
		ltype->set_m_parent(obj);
		plist = (nsl_list*) obj->get_m_children_list();
		plist->append(ltype);
	}
	else
		cmd_error("Cannot find object of type: ",lname);

	return 1;
}
int nsl_cmd_buf::add_type_i_parent(nsl_cmd_type* obj,const char* lname)
{
	type_list->wind_up();
	nsl_list* clist;
	nsl_list* plist;

	nsl_cmd_type* ltype;

	if ((ltype = (nsl_cmd_type*) type_list->get_mi_by_type(lname)) != NULL)
	{
		clist = ltype->get_i_parent_list();
		clist->append(obj);
		plist = obj->get_i_children_list();
		plist->append(ltype);
	}
	else
		cmd_error("Cannot find object of type: ",lname);

	return 1;
}
int nsl_cmd_buf::add_type_i_children(nsl_cmd_type* obj,const char* lname)
{
	type_list->wind_up();
	nsl_list* clist;
	nsl_list* plist;

	nsl_cmd_type* ltype;

	if ((ltype = (nsl_cmd_type*) type_list->get_mi_by_type(lname)) != NULL)
	{
		clist = ltype->get_i_children_list();
		clist->append(obj);
		plist = obj->get_i_parent_list();
		plist->append(ltype);
	}
	else
		cmd_error("Cannot find object of type: ",lname);

	return 1;
}
nsl_cmd_type* nsl_cmd_buf::get_type_cmd(const int lindex)
{
	return (nsl_cmd_type*) type_list->get_mi_by_index(lindex);
}
nsl_cmd_type* nsl_cmd_buf::get_type_cmd(const char* lname)
{
	return (nsl_cmd_type*) type_list->get_mi_by_type(lname);
}

int nsl_cmd_buf::print_type(ostream& out)
{
	type_list->print(out);
	return 1;
}

int nsl_cmd_buf::print_cmd_buf(ostream& out) const
{
	print_base(out);
	return 1;
}
int nsl_cmd_buf::print(ostream& out) const // virtual
{
	print_cmd_buf(out);
	return 1;
}
