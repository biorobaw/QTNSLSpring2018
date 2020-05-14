/* SCCS  %W%---%E%--%U% */
//
// 	xnsl_xpublic.h
//
#ifndef XNSL_XPUBLIC_H
#define XNSL_XPUBLIC_H
#include "nsl_public.h"
class xnsl_system;
class xnsl_widget;
class xnsl_xpublic : public nsl_public
{
protected:
 	static xnsl_system* XSYSTEM;
	xnsl_widget* _widget;
public:
		xnsl_xpublic(const char* = "");
		~xnsl_xpublic();

	void set_widget(xnsl_widget* w) { _widget = w; }
	xnsl_widget* get_widget() { return _widget; }

	virtual int display();
};
#endif
