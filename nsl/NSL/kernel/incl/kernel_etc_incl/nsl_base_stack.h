/* SCCS  @(#)nsl_base_stack.h	1.1---95/08/13--23:36:36 */
//
//	nsl_base_stack.h
//

#ifndef _NSL_BASE_STACK_H
#define _NSL_BASE_STACK_H
#include "nsl_base_list.h"
class nsl_base_stack : public nsl_base_list
{
public:
	nsl_base_stack(int = 0);
	~nsl_base_stack();
	
	void push(nsl_base*);		// insert on top
	nsl_base* pop();		// get from top

	int print_base_stack(std::ostream&) const;	// print top stack
	virtual int print(std::ostream&) const;	// print virtual stack
};
#endif
