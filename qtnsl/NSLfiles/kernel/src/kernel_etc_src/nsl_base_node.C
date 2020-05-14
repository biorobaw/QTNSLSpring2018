/* SCCS  @(#)nsl_base_node.C	1.1---95/10/13--16:36:57 */
//
// nsl_base_node.C
//
#include "nsl_kernel.h"
#include "nsl_base_node.h"
#include "nsl_base.h"

nsl_base_node::nsl_base_node(nsl_base* p)
{
	ptr = p;
	next = 0;
	prev = 0;
}
nsl_base_node::~nsl_base_node()
{
}

