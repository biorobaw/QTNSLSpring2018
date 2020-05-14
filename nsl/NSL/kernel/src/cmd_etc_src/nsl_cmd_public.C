/* SCCS  @(#)nsl_cmd_public.C	1.1---95/10/13--16:36:56 */
//
// nsl_cmd_public.C
//
#include "nsl_kernel.h"
#include "nsl_cmd_public.h"
#include "nsl_base_list.h"

nsl_cmd_public::nsl_cmd_public(const char* str,int level) : nsl_base(str,level)
{
	init_cmd_public(level);
}
nsl_cmd_public::nsl_cmd_public(int level) : nsl_base(level)
{
	init_cmd_public(level);
}
nsl_cmd_public::~nsl_cmd_public()
{
}
void nsl_cmd_public::init_cmd_public(int level)
{
	if (level == 0) // avoid infinite initialization recursion
	{
		i_parent_list = new nsl_base_list(++level);
		i_parent_list->set_name("i_parent");
		i_children_list = new nsl_base_list(++level);
		i_children_list->set_name("i_children");
		m_parent = 0;
		m_children_list = new nsl_base_list(++level);
		m_children_list->set_name("m_children");
	}
}

