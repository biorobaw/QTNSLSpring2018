/* SCCS  @(#)nsl_cmd_type.C	1.1---95/08/13--18:38:26 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_type.C                           */
/*                                                            */
/**************************************************************/
#include "nsl_cmd_type.h"
#include "nsl_base_list.h"
#include "nsl_interpreter.h"
#include "nsl_layer.h"
#include "nsl_system.h"
#include "nsl_str_data.h"
#include "nsl_int_data.h"
#include "nsl_cmd_system.h"
#include "nsl_file.h"
#include "nsl_kernel.h"

#ifndef _NSL_SET
typedef nsl_base_list nsl_list;
#endif


nsl_cmd_type::nsl_cmd_type(const char* str) : nsl_cmd_public(str)
{
	init_cmd_type();
}

nsl_cmd_type::nsl_cmd_type(): nsl_cmd_public("")
{
	init_cmd_type();
}

nsl_cmd_type::~nsl_cmd_type()
{
}

int nsl_cmd_type::init_cmd_type()
{
	data_total = 0;
	data_list = new nsl_list("data");

 	return 1;
}

// virtual data

int nsl_cmd_type::create_data(nsl_base*,int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}
int nsl_cmd_type::init_data(nsl_base*)
{
	return 1;
}
int nsl_cmd_type::reset_data(nsl_base*)
{
	return 1;
}
int nsl_cmd_type::update_data(nsl_base*,int,int,int,int,int,int,int,int,int,int)
{
	return 1;
}

// cmd virtual

int nsl_cmd_type::cmd_assign(nsl_interpreter& nsl)
{
	return cmd_type_assign(nsl);
}
int nsl_cmd_type::cmd_clear(nsl_interpreter& nsl)
{
	return cmd_type_clear(nsl);
}
int nsl_cmd_type::cmd_close(nsl_interpreter& nsl)
{
	return cmd_type_close(nsl);
}
int nsl_cmd_type::cmd_connect(nsl_interpreter& nsl)
{
	return cmd_type_connect(nsl);
}
int nsl_cmd_type::cmd_cont(nsl_interpreter& nsl)
{
	return cmd_type_cont(nsl);
}
int nsl_cmd_type::cmd_create(nsl_interpreter& nsl)
{
	return cmd_type_create(nsl);
}
int nsl_cmd_type::cmd_disable(nsl_interpreter& nsl)
{
	return cmd_type_disable(nsl);
}
int nsl_cmd_type::cmd_elem(nsl_interpreter& nsl)
{
	return cmd_type_elem(nsl);
}
int nsl_cmd_type::cmd_enable(nsl_interpreter& nsl)
{
	return cmd_type_enable(nsl);
}
int nsl_cmd_type::cmd_exec(nsl_interpreter& nsl)
{
	return cmd_type_exec(nsl);
}
int nsl_cmd_type::cmd_file_disable(nsl_interpreter& nsl)
{
	return cmd_type_file_disable(nsl);
}
int nsl_cmd_type::cmd_file_enable(nsl_interpreter& nsl)
{
	return cmd_type_file_enable(nsl);
}
int nsl_cmd_type::cmd_get(nsl_interpreter& nsl)
{
	return cmd_type_get(nsl);
}
int nsl_cmd_type::cmd_help(nsl_interpreter& nsl)
{
	return cmd_type_help(nsl);
}
int nsl_cmd_type::cmd_init(nsl_interpreter& nsl)
{
	return cmd_type_init(nsl);
}
int nsl_cmd_type::cmd_load(nsl_interpreter& nsl)
{
	return cmd_type_load(nsl);
}
int nsl_cmd_type::cmd_makeconn(nsl_interpreter& nsl)
{
	return cmd_type_makeconn(nsl);
}
int nsl_cmd_type::cmd_open(nsl_interpreter& nsl)
{
	return cmd_type_open(nsl);
}
int nsl_cmd_type::cmd_print(nsl_interpreter& nsl)
{
	return cmd_type_print(nsl);
}
int nsl_cmd_type::cmd_reset(nsl_interpreter& nsl)
{
	return cmd_type_reset(nsl);
}
int nsl_cmd_type::cmd_run(nsl_interpreter& nsl)
{
	return cmd_type_run(nsl);
}
int nsl_cmd_type::cmd_set(nsl_interpreter& nsl)
{
	return cmd_type_set(nsl);
}
int nsl_cmd_type::cmd_status(nsl_interpreter& nsl)
{
	return cmd_type_status(nsl);
}
int nsl_cmd_type::cmd_step(nsl_interpreter& nsl)
{
	return cmd_type_step(nsl);
}
int nsl_cmd_type::cmd_stop(nsl_interpreter& nsl)
{
	return cmd_type_stop(nsl);
}
int nsl_cmd_type::cmd_train(nsl_interpreter& nsl)
{
	return cmd_type_train(nsl);
}
int nsl_cmd_type::cmd_update(nsl_interpreter& nsl)
{
	return cmd_type_update(nsl);
}
int nsl_cmd_type::cmd_write(nsl_interpreter& nsl)
{
	return cmd_type_write(nsl);
}

// get name

int nsl_cmd_type::get_obj_name(nsl_interpreter& nsl, char *buf, unsigned int sz) //updated: sz is the size of buf -bn7
{
	nsl_string str;
	nsl_base* pbase;
	nsl_list* list = 0;
 	nsl_layer* data;

	strcpy(str,"");
	if (nsl.get_str_cnt() > 0)
		nsl >> str; //get the str from cmd buffer
	else
	{
	   pbase = SYSTEM->get_cmd_system()->
	     get_m_children_list()->get_mi_by_type(get_base_type());
	   if (pbase != NULL)
		list = ((nsl_cmd_type*) pbase)->get_data_list();
	   else
		cmd_error("cmd: NULL parent type");
	   if (list != NULL)
	   {
	      if ((data = (nsl_layer*) list->get_by_name("name")) != NULL)
		strcpy(str,((nsl_str_data*) data)->get_value());
 	      else
		cmd_error("cmd: NULL 'name' obj");
	   }
	   else
		cmd_error("cmd: NULL data list");

	   strncpy(buf, str, sz);
	   return 0; //0 for failure
	}

	strncpy(buf, str, sz); //copy the string into buf
	return 1; //1 for success
}


// cmd type

// assign - sets a layer for current manipulation 
int nsl_cmd_type::cmd_type_assign(nsl_interpreter& nsl)
{
	nsl_string str;
	nsl_list* mlist;
	nsl_base* dobj;
	nsl_base* pbase;
	int lindex;

	data_list->wind_up();

	nsl_layer* data;

	nsl >> str; // set option: value, name, etc

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

 	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	else
	{
	    if (ltype == 0)
		pbase = SYSTEM;

 	    if ((mlist = (nsl_list*) pbase->get_m_children_list()->
		get_m_by_name(get_base_type())) == 0)
	    {
		cmd_error("nsl_cmd_type: Null List");
		return 1;
	    }
	    if ((lindex = atoi(str)) != 0)
	    {
		if ((dobj = mlist->get_by_index(lindex)) != 0)
		{
		    OBJ = dobj;
		    if ((data = (nsl_layer*) data_list->
			get_by_name("index")) != NULL)
	    		   ((nsl_int_data*) data)->set_value(lindex);
		    init_data(OBJ);
  		    return 1;
		}
		else
 		    cmd_error("Unkown index: ",lindex);
 	    }
 	    else
 	    {
		if ((dobj = mlist->get_by_name(str)) != 0)
		{
		    OBJ = dobj;
		    if ((data = (nsl_layer*) data_list->
			get_by_name("name")) != NULL)
	    		   ((nsl_str_data*) data)->set_value(str);
		    init_data(OBJ);
		    return 1;
		}
		else
		    cmd_error("Unknown name: ",str);
	     }
	}

	return 2;
}
int nsl_cmd_type::cmd_type_clear(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_close(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_connect(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_cont(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_create(nsl_interpreter& nsl)
{
   	nsl_base* base;
	nsl_cmd_type* cmd_type;
	nsl_string str;

	//strcpy(str,get_obj_name(nsl));
	get_obj_name(nsl, str, NSL_NAME_SIZE);

	cout << "straaa is " << str << endl;

	// change to "command_modifiers"
	cmd_init(nsl); // user assigned options on create command

	if (i_children_list != NULL && m_parent != NULL &&
		(base = (nsl_base*) m_parent->get_ptr()) != NULL &&
		(cmd_type = (nsl_cmd_type*) i_children_list->
		get_by_type_and_name(base->get_type(),get_type())) != NULL)
	{
		cmd_type->cmd_create(nsl);
	}
	else
		cmd_error("CMD: NULL OBJ");

	return 1;
}
int nsl_cmd_type::cmd_type_disable(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
	nsl_list* mlist;
	nsl_base* base;
 	nsl_base* pbase;

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

	if (nsl.get_str_cnt() > 0)
 	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
	    	if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				base->disable();
			else
				cmd_error("Bad Index");
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
		
		        mlist->disable_all();
		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				base->disable();
			else
				cmd_error("Bad Obj Name");
		}
	}
	else
		cmd_error("disable: Bad Command");

	return 1;
}
int nsl_cmd_type::cmd_type_enable(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
	nsl_list* mlist;
	nsl_base* base;
 	nsl_base* pbase;

	if (m_parent == NULL ||  (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

	if (nsl.get_str_cnt() > 0)
 	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
 	    	if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				base->enable();
			else
				cmd_error("Bad Index");
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
		
		        mlist->enable_all();
		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				base->enable();
			else
				cmd_error("Bad Obj Name");
		}
	}
	else
		cmd_error("Bad Command");

	return 1;
}
int nsl_cmd_type::cmd_type_exec(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_file_disable(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
	nsl_list* mlist;
	nsl_base* base;
 	nsl_base* pbase;

	if (m_parent == NULL ||  (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

	if (nsl.get_str_cnt() > 0)
 	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
 	    	if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				base->file_disable();
			else
				cmd_error("Bad Index");
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
		
		        mlist->file_disable_all();
		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				base->file_disable();
			else
				cmd_error("Bad Obj Name");
		}
	}
	else
		cmd_error("disable: Bad Command");

	return 1;
}
int nsl_cmd_type::cmd_type_elem(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_file_enable(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
	nsl_list* mlist;
	nsl_base* base;
 	nsl_base* pbase;

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

 	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

	if (nsl.get_str_cnt() > 0)
 	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
 	    	if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				base->file_enable();
			else
				cmd_error("Bad Index");
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
		
		        mlist->file_enable_all();
		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				base->file_enable();
			else
				cmd_error("Bad Obj Name");
		}
	}
	else
		cmd_error("Bad Command");

	return 1;
}
int nsl_cmd_type::cmd_type_get(nsl_interpreter& nsl)
{
	nsl_string str;
	nsl_list* mlist;
	nsl_layer* data;  // layer's data object
	nsl_base *pbase;
	int cmd_status = 2; // 2 - unknown commandd

	nsl >> str; // set option: value, name

 	pbase = (nsl_base*) get_ptr(); // get current obj

	if (pbase != NULL)
	{
		pbase->write(nsl.get_char_buffer()); // pbase->write(NSL_TCL_INTERP);
		cmd_status = 1;
	}
/*	else if (strcmp(str,"value") == 0) // normal
	{
 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }
	    cmd_status = 1;
	}
*/	else if (strcmp(str,"-single") == 0) // single_fg = 1
	{
	    ((nsl_layer*) pbase)->set_value_fg(1);

 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }

	    ((nsl_layer*) pbase)->set_value_fg(0);

	    cmd_status = 1;
	}
	else if (strcmp(str,"-region") == 0) // region_fg = 1
	{
	    ((nsl_layer*) pbase)->set_region_fg(1);

 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }

	    ((nsl_layer*) pbase)->set_region_fg(0);

	    cmd_status = 1;
	}
	else if (strcmp(str,"-region_single") == 0) // region/single fg = 1
	{
	    ((nsl_layer*) pbase)->set_region_fg(1);
	    ((nsl_layer*) pbase)->set_value_fg(1);

 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }

	    ((nsl_layer*) pbase)->set_region_fg(0);
	    ((nsl_layer*) pbase)->set_value_fg(0);

	    cmd_status = 1;
	}
/*	else if ((data = (nsl_layer*) get_ip_data(str,this)) != NULL)
	{
		cmd_out("CMD TYPE(default): ",str);
	     	data->read(nsl.get_buffer());
		data->set_flag(1); // set_update_fg in nsl_public.h
		// 1: used for set class data, 0: used for set obj data
		if (nsl.get_flag() == 0)
		{
			cmd_update(nsl); // update current obj
//	     		update_data(data); // update current object
		}
		else
			nsl.set_flag(1); // get back to normal
		cmd_status = 1;
	}
	else
		cmd_error("cmd_type: BAD data: ",str);
*/
/*	else
	{
 	    if (pbase != NULL)
 	    {
// 	        nsl.putback(str,1); // return str to nsl to read back to layer
	    	nsl << *((nsl_layer*) pbase); // num
	    }
	    else
	    {
			cmd_error("CMD TYPE: Null Layer Value");
	    }
	    cmd_status = 1;
	}
*/
	return cmd_status;
}
int nsl_cmd_type::cmd_type_help(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_init(nsl_interpreter& nsl)
{
 	char* str;
	char* str0;
 	nsl_string tmp;
	nsl_list* list;
	nsl_layer* data;
	nsl_cmd_type* cmd_obj;

        if ((cmd_obj = (nsl_cmd_type*)
	   		SYSTEM->get_cmd_system()->get_m_children_list()
			->get_mi_by_type(get_base_type())) != NULL &&
	   	(list = cmd_obj->get_data_list()) != NULL)
        {
	    while (nsl.get_str_cnt() > 0) {

		nsl >> tmp;

      		if ((str0 = (char *) strrchr(tmp,'-')) != NULL)
		{
		    str = str0 + 1; // pointer 1 after sname

        	    if ((data = (nsl_layer*) list->get_by_name(str)) != NULL)
	     		data->read(nsl.get_buffer());
          	    else
                	cmd_error("cmd_type: NULL 'layer' obj");
		}
	    }

	}
        else
                cmd_error("cmd_type: cmd_init: NULL object");


       	return 1;
}
int nsl_cmd_type::cmd_type_load(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_makeconn(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_open(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_print(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
 	nsl_list* mlist;
	int fg;
 	nsl_base* pbase;

	fstream& log = nsl.get_log0();

	if (nsl.get_str_cnt() == 0 && OBJ != NULL)
	{
		OBJ->print(log);
		return 1;
	}

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

  	if (nsl.get_str_cnt() > 0)
	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
 	    	if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
	    	if ((lindex = atoi(str)) != 0)
		{
			if ((fg = mlist->print_by_index(log,lindex)) == 0)
				cmd_error("Unkown index: ",lindex);
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
			mlist->print_all(log);
		else
 		{
			if ((fg = mlist->print_by_name(log,str)) == 0)
				cmd_error("Unknown name: ",str);
		}
	}
 
	return 1;
}
int nsl_cmd_type::cmd_type_reset(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
 	nsl_list* mlist;
	nsl_base* base;
	nsl_base* pbase;

	nsl_buffer& buf = nsl.get_buffer();

 	if (nsl.get_str_cnt() == 0 && OBJ != NULL)
	{
		OBJ->reset(&buf);
		return 1;
	}

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

  	if (nsl.get_str_cnt() > 0)
	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
 	    	if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
		if ((lindex = atoi(str)) != 0)
		{
			if ((base = mlist->get_by_index(lindex)) != NULL)
				base->reset(&buf);
			else
				cmd_error("Bad Obj Index");
		}
 		else
		{
			if ((base = mlist->get_by_name(str)) != NULL)
				base->reset(&buf);
			else
				cmd_error("Bad Obj Name");
		}
	}
 
	return 1;
}
int nsl_cmd_type::cmd_type_run(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_set(nsl_interpreter& nsl)
{
	nsl_string str;
	nsl_list* mlist;
	nsl_layer* data;  // layer's data object
	nsl_base *pbase;
	int cmd_status = 2; // 2 - unknown commandd

	nsl >> str; // set option: value, name

 	pbase = (nsl_base*) get_ptr(); // get current obj

	if (pbase != NULL && (mlist = pbase->get_m_children_list()) != NULL &&
		(data = (nsl_layer*) mlist->get_m_by_name(str)) != NULL)
	{
		cmd_out("CMD TYPE(1): ",str);
	     	data->read(nsl.get_buffer());
		cmd_status = 1;
	}
/*	else if (strcmp(str,"value") == 0) // normal
	{
 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }
	    cmd_status = 1;
	}
*/	else if (strcmp(str,"-single") == 0) // single_fg = 1
	{
	    ((nsl_layer*) pbase)->set_value_fg(1);

 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }

	    ((nsl_layer*) pbase)->set_value_fg(0);

	    cmd_status = 1;
	}
	else if (strcmp(str,"-region") == 0) // region_fg = 1
	{
	    ((nsl_layer*) pbase)->set_region_fg(1);

 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }

	    ((nsl_layer*) pbase)->set_region_fg(0);

	    cmd_status = 1;
	}
	else if (strcmp(str,"-region_single") == 0) // region/single fg = 1
	{
	    ((nsl_layer*) pbase)->set_region_fg(1);
	    ((nsl_layer*) pbase)->set_value_fg(1);

 	    if (pbase != NULL)
	    	nsl >> *((nsl_layer*) pbase); // num
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }

	    ((nsl_layer*) pbase)->set_region_fg(0);
	    ((nsl_layer*) pbase)->set_value_fg(0);

	    cmd_status = 1;
	}
/*	else if ((data = (nsl_layer*) get_ip_data(str,this)) != NULL)
	{
		cmd_out("CMD TYPE(default): ",str);
	     	data->read(nsl.get_buffer());
		data->set_flag(1); // set_update_fg in nsl_public.h
		// 1: used for set class data, 0: used for set obj data
		if (nsl.get_flag() == 0) 
		{
			cmd_update(nsl); // update current obj
//	     		update_data(data); // update current object
		}
		else
			nsl.set_flag(1); // get back to normal
		cmd_status = 1;
	}
	else
		cmd_error("cmd_type: BAD data: ",str);
*/
	else
	{
 	    if (pbase != NULL)
 	    {
 	        nsl.putback(str,1); // return str to nsl to read back to layer
	    	nsl >> *((nsl_layer*) pbase); // num
	    }
	    else
	    {
		cmd_error("CMD TYPE: Null Layer Value");
	    }
	    cmd_status = 1;
	}

	return cmd_status;
}
int nsl_cmd_type::cmd_type_status(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
 	nsl_list* mlist;
	int fg;
        nsl_layer* dobj;
	nsl_base* pbase;

 	fstream& log = nsl.get_log0();

 	if (nsl.get_str_cnt() == 0 && OBJ != NULL)
	{
		OBJ->print_status(log);
		return 1;
	}

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

 	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

  	if (nsl.get_str_cnt() > 0)
	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
		if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
	    	if ((lindex = atoi(str)) != 0)
 		{
			if ((fg = mlist->print_status_by_index(log,lindex)) == 0)
				cmd_error("Unkown index: ",lindex);
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
			mlist->print_all_status(log);
		else
		{
			if ((fg = mlist->print_status_by_name(log,str)) == 0)
				cmd_error("Unknown name: ",str);
		}
	}
 
 	log << "\nBuffer:\n";

	data_list->wind_up();
        while ((dobj = (nsl_layer*) data_list->next()) != NULL)
 	 	dobj->print(log);
  
 	log << "\nType Status:\n";
	log.flush();

	return 1;
}
int nsl_cmd_type::cmd_type_step(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_stop(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_train(nsl_interpreter&)
{
	return 1;
}
int nsl_cmd_type::cmd_type_update(nsl_interpreter& nsl)
{
   	nsl_base* base;
	nsl_cmd_type* cmd_type;

/*	if (i_children_list != NULL && m_parent != NULL &&
		(base = (nsl_base*) m_parent->get_ptr()) != NULL &&
		(cmd_type = (nsl_cmd_type*) i_children_list->
		get_by_type_and_name(base->get_type(),get_type())) != NULL)
	{
		cmd_type->cmd_update(nsl);
	}
	else
		cmd_error("CMD: NULL OBJ");
*/
	return 1;
}
int nsl_cmd_type::cmd_type_write(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex;
 	nsl_list* mlist;
	int fg;
 	nsl_base* pbase;

	nsl_file* file;
	fstream* log;

	if ((file = nsl.get_output_file()) != NULL)
 		log = file->get_file_stream();
	else
	{
		cmd_error("NULL output file stream");
		return 1;
	}

	if (nsl.get_str_cnt() == 0 && OBJ != NULL)
	{
		OBJ->print(*log);
		return 1;
	}

	if (m_parent == NULL || (pbase = m_parent->get_ptr()) == NULL)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}

	// pbase is m_parent for local type (e.g model parent to layer)
	const char* stype = pbase->get_type();

	int ltype = strcmp(stype,"system");

	if (pbase == NULL && ltype != 0)
	{
		cmd_error("CMD: Null Parent OBJ");
		return 1;
	}
	if (ltype == 0)
		pbase = SYSTEM;

  	if (nsl.get_str_cnt() > 0)
 	{
		nsl >> str;
		// local type is list name in m_parent 
		// (e.g. for model, mlist = layer list, local type = layer)
		if ((mlist = (nsl_list*) pbase->get_m_children_list()->
			get_m_by_name(get_base_type())) == 0)
		{
			cmd_error("nsl_cmd_type: Null List");
			return 1;
		}
	    	if ((lindex = atoi(str)) != 0)
		{
			if ((fg = mlist->print_by_index(*log,lindex)) == 0)
				cmd_error("Unkown index: ",lindex);
		}
		else if (strcmp("*",str) == 0 || strcmp("ALL",str) == 0)
			mlist->print_all(*log);
		else
 		{
			if ((fg = mlist->print_by_name(*log,str)) == 0)
				cmd_error("Unknown name: ",str);
		}
	}
 
	return 1;
}

// local print

int nsl_cmd_type::print_cmd_type(ostream& out) const
{
	print_base(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_type::print(ostream& out) const // virtual
{
	print_cmd_type(out);
	return 1;
}



