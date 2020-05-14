/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_base_stack.C                         */
/*                                                            */
/**************************************************************/
#include "nsl_kernel.h"
#include "nsl_base_stack.h"

nsl_base_stack::nsl_base_stack(int level) : nsl_base_list(level)
{
	set_type("stack");
}
nsl_base_stack::~nsl_base_stack()
{
}
	
void nsl_base_stack::push(nsl_base *p)
{
	wind_up();
	insert(p);
}

nsl_base* nsl_base_stack::pop()
{
	wind_up();
	return return_cur();
}

// print base

int nsl_base_stack::print_base_stack(std::ostream& out) const
{
	print_base_list(out);

	return 1;
}
int nsl_base_stack::print(std::ostream& out) const
{
	print_base_stack(out);

	return 1;
}

