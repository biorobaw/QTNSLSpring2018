/* SCCS  @(#)nsl_base_node.h	1.1---95/08/13--23:36:35 */
//
//	nsl_base_node.h
//


#ifndef _NSL_SET
class nsl_base;
#endif

#ifndef _NSL_BASE_NODE_H
#define _NSL_BASE_NODE_H
class nsl_base_node
{
private:
	friend class nsl_base_list;
	nsl_base_node *prev;
	nsl_base_node *next;	
	nsl_base* ptr;
public:
	nsl_base_node(nsl_base* p = 0);
	~nsl_base_node();
};
#endif
