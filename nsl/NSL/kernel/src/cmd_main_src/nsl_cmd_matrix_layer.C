/* SCCS  @(#)nsl_cmd_matrix_layer.C	1.1---95/10/13--16:34:20 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_matrix_layer.C                   */
/*                                                            */
/**************************************************************/


#include "nsl_cmd_matrix_layer.h"
#include "nsl_matrix_layer.h"
#include "nsl_int_data.h"
#include "nsl_base.h"
#include "nsl_base_list.h"
#include "nsl_cmd_type.h"
#include "nsl_stream.h"
#include "nsl_kernel.h"

typedef nsl_base_list nsl_list;

nsl_cmd_matrix_layer::nsl_cmd_matrix_layer() : nsl_cmd_layer("matrix_layer")
{
}
nsl_cmd_matrix_layer::nsl_cmd_matrix_layer(const char* str) : nsl_cmd_layer(str)
{
}

int nsl_cmd_matrix_layer::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_matrix_layer::cmd_elem(nsl_interpreter& nsl)
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

	int imax = ((nsl_matrix_layer*) layer)->get_imax();
	int jmax = ((nsl_matrix_layer*) layer)->get_jmax();
	int i = 0,j = 0;

	int i0 = ((nsl_matrix_layer*) layer)->get_i0();
	int i1 = ((nsl_matrix_layer*) layer)->get_i1();
	int j0 = ((nsl_matrix_layer*) layer)->get_j0();
	int j1 = ((nsl_matrix_layer*) layer)->get_j1();

	nsl_layer* dobj;
	
	if (nsl.get_str_cnt() > 1)
	{
		nsl >> i;
		nsl >> j;
	}
	else
	{
		nsl_cmd_type* cl = 0;
		nsl_list* list = 0;
		if ((cl = (nsl_cmd_type*) get_i_parent_list()->
		   get_by_type("layer")) != NULL)
			list = cl->get_data_list();
		else
			cmd_error("cmd_matrix_layer: NULL i_parent type");
		if (list != NULL)
		{
	    	   if ((dobj = (nsl_layer*) list->get_by_name("elem_i")) != 0)
                	i = ((nsl_int_data*) dobj)->get_value();
		   else
			cmd_error("nsl_cmd_matrix_layer: NULL 'elem_i' obj");
	    	   if ((dobj = (nsl_layer*) list->get_by_name("elem_j")) != 0)
                	j = ((nsl_int_data*) dobj)->get_value();
		   else
			cmd_error("nsl_cmd_matrix_layer: NULL 'elem_j' obj");
		}
	}

	if (i < 0 || j < 0 || i > imax || j > jmax)
	{
		cmd_error("Bad layer element");
		return 1;
	}

	((nsl_matrix_layer*) layer)->set_i0(i);
	((nsl_matrix_layer*) layer)->set_i1(i);
	((nsl_matrix_layer*) layer)->set_j0(j);
	((nsl_matrix_layer*) layer)->set_j1(j);

	nsl >> *layer;

	((nsl_matrix_layer*) layer)->set_i0(i0);
	((nsl_matrix_layer*) layer)->set_i1(i1);
	((nsl_matrix_layer*) layer)->set_j0(j0);
	((nsl_matrix_layer*) layer)->set_j1(j1);

	return 1;
}
nsl_cmd_matrix_layer::~nsl_cmd_matrix_layer()
{
}
int nsl_cmd_matrix_layer::print_cmd_matrix_layer(std::ostream& out) const
{
	print_cmd_layer(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_matrix_layer::print(std::ostream& out) const // virtual
{
	print_cmd_matrix_layer(out);
	return 1;
}

