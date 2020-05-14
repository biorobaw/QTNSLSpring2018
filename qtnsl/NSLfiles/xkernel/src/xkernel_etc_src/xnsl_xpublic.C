/* SCCS  %W%---%E%--%U% */
//
//	xnsl_xpublic.c
//

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_xpublic::xnsl_xpublic(const char* str) : nsl_public(str)
{
	_widget = 0;
}
xnsl_xpublic::~xnsl_xpublic()
{
}
int xnsl_xpublic::display()
{
	return 1;
}
