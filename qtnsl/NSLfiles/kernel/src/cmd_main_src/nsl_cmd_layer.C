/* SCCS  @(#)nsl_cmd_layer.C	1.3---95/10/13--16:29:05 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_layer.C                          */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_cmd_layer.h"
#include "nsl_layer.h"
#include "nsl_model.h"
#include "nsl_base_list.h"
#include "nsl_interpreter.h"
#include "nsl_cmd_buf.h"
#include "nsl_system.h"


nsl_cmd_layer::nsl_cmd_layer() : nsl_cmd_type("layer")
{
	init_cmd_layer();
}

nsl_cmd_layer::nsl_cmd_layer(const char* str) : nsl_cmd_type(str)
{
	init_cmd_layer();
}

nsl_cmd_layer::~nsl_cmd_layer()
{
}

int nsl_cmd_layer::init_cmd_layer()
{
	return set_cmd_layer();
}
int nsl_cmd_layer::set_cmd_layer()
{
	nsl_layer* l;

	set_base_type("layer");

	nsl_model* model = SYSTEM->get_model();

	if (model == NULL)
	{
//		cmd_error("CMD LAYER: Null Model");
		return 1;
	}
	if ((l = (nsl_layer*) model->get_data()) != NULL)
		OBJ = l;
//	else
//		cmd_error("CMD LAYER: Null Layer");

 	return 1;
}

// commands
/*
int nsl_cmd_layer::cmd_assign(nsl_interpreter& nsl)
{
	nsl_string str;
	int index = 0;
	nsl_list* mlist;
	nsl_layer* layer;
 
	if (m_parent == NULL) // cmd_model
	{
		cmd_error("CMD TYPE: Null Parent");
		return 1;
	}

 	const char* stype = m_parent->get_base_type();
	// pbase is m_parent for local type (e.g model parent to layer)
//	nsl_base* pbase = SYSTEM->get_m_children_list()->get_mi_by_type(stype);
	nsl_base* pbase = m_parent->get_ptr(); // cmd_model current OBJ 
	int type = strcmp(stype,"system");

	if (pbase == NULL && type != 0)
	{
		cmd_error("CMD LAYER: Null Type Parent");
		return 1;
	}

	if (strcmp(stype,"model") != 0)
	{
		cmd_error("CMD LAYER: Bad LAYER parent type: ",stype);
		return 1;
	}

	nsl >> str; // layer name or index

 	// get layer list
	if ((mlist = (nsl_list*) 
	    pbase->get_m_children_list()->get_m_by_name("layer")) == 0)
	{
		cmd_error("nsl_cmd_layer: Null List");
		return 1;
	}
	if ((index = atoi(str)) != 0)
	{
		if ((layer = (nsl_layer*) mlist->get_by_index(index)) == NULL)
 			cmd_error("Bad Index");
	}
 	else
	{
		if ((layer = (nsl_layer*) mlist->get_by_name(str)) == NULL)
 			cmd_error("Bad Layer Name");
	}

 	if (layer == NULL)
	{
		cmd_error("CMD LAYER: Null Layer");
		return 1;
	}

	nsl >> *layer;

	return 1;
}
*/
int nsl_cmd_layer::cmd_connect(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_layer::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_layer::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_layer::cmd_elem(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex = 0,fg = 2;
	nsl_list* mlist;
	nsl_layer* layer;
 
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
		cmd_error("CMD LAYER: Null Type Parent");
		return 1;
	}

	if (strcmp(stype,"model") != 0)
	{
		cmd_error("CMD LAYER: Bad LAYER parent type: ",stype);
		return 1;
	}

	nsl >> str; // layer name or index

 	// get layer list
	if ((mlist = (nsl_list*) 
	    pbase->get_m_children_list()->get_m_by_name("layer")) == 0)
	{
		cmd_error("nsl_cmd_layer: Null List");
		return 1;
	}
	if ((lindex = atoi(str)) != 0)
	{
		if ((layer = (nsl_layer*) mlist->get_by_index(lindex)) == NULL)
 			cmd_error("Bad Index");
	}
 	else
	{
		if ((layer = (nsl_layer*) mlist->get_by_name(str)) == NULL)
 			cmd_error("Bad Layer Name");
	}

 	if (layer == NULL)
	{
		cmd_error("CMD LAYER: Null Layer");
		return 1;
	}

	const char* tstr = layer->get_type();
	if (get_i_children_list()->get_i_by_type(tstr) != NULL)
	{
		nsl.get_buffer().reset_rewind_marker();
 		nsl.putback(str,1);
 		nsl.putback(tstr,1);
		nsl.putback("elem",1);
		fg = ((nsl_cmd_buf*) m_parent)->run(&nsl);
	}

	return fg;
}
int nsl_cmd_layer::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_layer::cmd_file_disable(nsl_interpreter& nsl)
{
	cmd_type_file_disable(nsl);

	return 1;
}
int nsl_cmd_layer::cmd_file_enable(nsl_interpreter& nsl)
{
	cmd_type_file_enable(nsl);

	return 1;
}
int nsl_cmd_layer::cmd_get(nsl_interpreter& nsl)
{
 	return cmd_type_get(nsl);
}
int nsl_cmd_layer::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_layer::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_layer::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_layer::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}

// local print

int nsl_cmd_layer::print_cmd_layer(ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_layer::print(ostream& out) const // virtual
{
	print_cmd_layer(out);
	return 1;
}




