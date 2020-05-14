/* SCCS  @(#)nsl_cmd_vector_layer.C	1.1---95/10/13--16:33:54 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_vector_layer.C                   */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"

#include "nsl_cmd_vector_layer.h"
#include "nsl_vector_layer.h"
#include "nsl_int_data.h"
#include "nsl_kernel.h"

extern void cmd_error(const char *);

nsl_cmd_vector_layer::nsl_cmd_vector_layer() : nsl_cmd_layer("vector_layer")
{
}
nsl_cmd_vector_layer::nsl_cmd_vector_layer(const char* str) : nsl_cmd_layer(str)
{
}

nsl_cmd_vector_layer::~nsl_cmd_vector_layer()
{
}
int nsl_cmd_vector_layer::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_vector_layer::cmd_elem(nsl_interpreter& nsl)
{
	nsl_string str;
	int lindex = 0;
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

	int imax = ((nsl_vector_layer*) layer)->get_imax();
 	int i = 0;

	int i0 = ((nsl_vector_layer*) layer)->get_i0();
	int i1 = ((nsl_vector_layer*) layer)->get_i1();
 
	nsl_layer* dobj;
	
	if (nsl.get_str_cnt() > 1)
	{
		nsl >> i;
 	}
	else
	{
		nsl_cmd_type* cl = 0;
		nsl_list* list = 0;
		if ((cl = (nsl_cmd_type*) get_i_parent_list()->
		   get_by_type("layer")) != NULL)
			list = cl->get_data_list();
		else
			cmd_error("cmd_vector_layer: NULL i_parent type");
		if (list != NULL)
		{
	    	   if ((dobj = (nsl_layer*) list->get_by_name("elem_i")) != 0)
                	i = ((nsl_int_data*) dobj)->get_value();
		   else
			cmd_error("cmd_vector_layer: NULL 'elem_i' obj");
 		}
	}

	if (i < 0 || i > imax)
	{
		cmd_error("Bad layer element");
		return 1;
	}

	((nsl_vector_layer*) layer)->set_i0(i);
	((nsl_vector_layer*) layer)->set_i1(i);
 
	nsl >> *layer;

	((nsl_vector_layer*) layer)->set_i0(i0);
	((nsl_vector_layer*) layer)->set_i1(i1);
 
	return 1;
}
int nsl_cmd_vector_layer::print_cmd_vector_layer(std::ostream& out) const
{
	print_cmd_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_vector_layer::print(std::ostream& out) const // virtual
{
	print_cmd_vector_layer(out);
	return 1;
}

